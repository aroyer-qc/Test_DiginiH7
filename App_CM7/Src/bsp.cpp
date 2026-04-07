//-------------------------------------------------------------------------------------------------
//
//  File : bsp.cpp
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2024 Alain Royer.
// Email: aroyer.qc@gmail.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
// AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//-------------------------------------------------------------------------------------------------

//------ Note(s) ----------------------------------------------------------------------------------
//
//  BSP - Board support package for STM32F4-DISCO
//
//  this board has 128K RAM in CPU
//                 64K CCRAM in CPU
//
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#define BSP_GLOBAL
#include "bsp.h"
#undef  BSP_GLOBAL
#include "taskTest1.h"

//-------------------------------------------------------------------------------------------------

// because for now we don't have eeprom for this test board
const SystemDebugLevel_e DebugLevel = SystemDebugLevel_e(0);//SystemDebugLevel_e(SYS_DEBUG_LEVEL_ETHERNET | SYS_DEBUG_LEVEL_MEMORY_POOL);
const TempUnit_e TemperatureUnit  = TEMP_CELSIUS;
const Language_e LanguageUsed     = LANG_ENGLISH;

//-------------------------------------------------------------------------------------------------
// Local Function(s)
//-------------------------------------------------------------------------------------------------

#if USE_HYPER_RAM_DRIVER == DEF_ENABLED     // H735 Only
const HYPER_RAM_Info_t HYPER_RAM_Info =
{
    .pInstance              = OCTOSPI2,
    .FifoThreshold          = 4,
    .DeviceSize             = 24,                               // Hyper Ram Size   24 bits = 16Mb
    .ChipSelectHighTime     = 4,
    .ClockPrescaler         = 2,
    .SampleShifting         = OSPI_SAMPLE_SHIFTING_NONE,
    .DelayHoldQuarterCycle  = OSPI_DHQC_ENABLE,
    .DelayBlockBypass       = OSPI_DELAY_BLOCK_USED,
    .ChipSelectBoundary     = 23,
    .Refresh                = 400,

    .RW_RecoveryTime        = 3,
    .AccessTime             = 6,
    .WriteZeroLatency       = OSPI_LATENCY_ON_WRITE,
    .LatencyMode            = OSPI_FIXED_LATENCY,

    .DQS_Mode               = OSPI_DQS_ENABLE,
    .Address                = 0,
    .NbData                 = 1,

    .TimeOutActivation      = OSPI_TIMEOUT_COUNTER_DISABLE,
};
#endif

//-------------------------------------------------------------------------------------------------
//
//  Name:           BSP_Initialize
//  Parameter(s):   void
//  Return:         void
//
//  Description:    This function should be called by your application before anything else
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
void BSP_Initialize(void)
{
    SysTick_Config(SYSTEM_CORE_CLOCK / CFG_SYSTICK_RATE);
    ISR_Initialize();
    IO_InitializeAll();

  #ifdef KIT_735IG
    HYPER_RAM_Initialize(&HYPER_RAM_Info);
  #endif

    IO_SetPinHigh(IO_LCD_TFT_DISPLAY);
    DIGINI_Initialize();
    TaskTest1.Initialize();
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           BSP_PostOS_Initialize
//  Parameter(s):   void
//  Return:         SystemState_e       SystemState
//
//  Description:    This function should be called by your application After OS has being started
//
//  Note(s):        Example: class or driver using Semaphore
//
//-------------------------------------------------------------------------------------------------
SystemState_e BSP_PostOS_Initialize(void)
{
    SystemState_e State = SYS_READY;

    //myUART_Terminal.Initialize(); is it in digini?

    State = DIGINI_PostInitialize();

    return State;
}

//-------------------------------------------------------------------------------------------------
