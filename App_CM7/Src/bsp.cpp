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

#if (DIGINI_USE_ETHERNET == DEF_ENABLED)
#include "Task_network.h"
#endif // (DIGINI_USE_ETHERNET == DEF_ENABLED)

//-------------------------------------------------------------------------------------------------

// because for now we don't have eeprom for this test board
const SystemDebugLevel_e DebugLevel = SystemDebugLevel_e(0);//SystemDebugLevel_e(SYS_DEBUG_LEVEL_ETHERNET | SYS_DEBUG_LEVEL_MEMORY_POOL);
const TempUnit_e TemperatureUnit  = TEMP_CELSIUS;
const Language_e LanguageUsed     = LANG_ENGLISH;

#if (BSP_TEST_HARDWARE == DEF_ENABLED)
void BSP_HardwareTest (void);
#endif

//-------------------------------------------------------------------------------------------------
// Local Function(s)
//-------------------------------------------------------------------------------------------------

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
    DIGINI_Initialize();
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

    // DAC
   // mySPI_ForDAC.Initialize();
   // DAC43508.Initialize();

    // VFD
    //mySPI_ForVFD.Initialize();              // SPI Driver for the data
   // myTIM_VFD.Initialize();                 // Timer Driver on top of PWM for blank line
   // myPWM_VFD_Blank.Initialize();           // PWM Driver to control blank line (dimming feature)
   // VFD.Initialize();                       // Then initialize the VFD driver
    State = DIGINI_PostInitialize();

    // WS2812 LED stream
/* H7    WS281x_LedStream.Initialize();


    WS281x_LedStream.Start();

uint8_t R,G,B;

    while(1)
    {
        WS281x_LedStream.SetLed(0, {R++,G--,B+=3});
        WS281x_LedStream.SetLed(1, {uint8_t(R++ + 10), G--,uint8_t(B-= 10)});
        WS281x_LedStream.SetLed(2, {uint8_t(R++ + 20), G--,uint8_t(B-= 20)});
        WS281x_LedStream.SetLed(3, {uint8_t(R++ + 30), G--,uint8_t(B-= 30)});
        WS281x_LedStream.SetLed(4, {uint8_t(R++ + 40), G--,uint8_t(B-= 40)});
        WS281x_LedStream.SetLed(5, {uint8_t(R++ + 50), G--,uint8_t(B-= 50)});
        WS281x_LedStream.SetLed(6, {uint8_t(R++ + 60), G--,uint8_t(B-= 60)});
        WS281x_LedStream.SetLed(7, {uint8_t(R++ + 70), G--,uint8_t(B-= 70)});
        WS281x_LedStream.SetLed(8, {uint8_t(R++ + 80), G--,uint8_t(B-= 80)});
        WS281x_LedStream.SetLed(9, {uint8_t(R++ + 90), G--,uint8_t(B-= 90)});
        WS281x_LedStream.SetLed(10,{uint8_t(R++ + 100),G--,uint8_t(B-= 100)});
        WS281x_LedStream.SetLed(11,{uint8_t(R++ + 110),G--,uint8_t(B-= 110)});
        WS281x_LedStream.SetLed(12,{uint8_t(R++ + 120),G--,uint8_t(B-= 120)});
        WS281x_LedStream.SetLed(13,{uint8_t(R++ + 130),G--,uint8_t(B-= 130)});
        WS281x_LedStream.SetLed(14,{uint8_t(R++ + 140),G--,uint8_t(B-= 140)});
        WS281x_LedStream.SetLed(15,{uint8_t(R++ + 150),G--,uint8_t(B-= 150)});
        WS281x_LedStream.SetLed(16,{uint8_t(R++ + 160),G--,uint8_t(B-= 160)});
        WS281x_LedStream.SetLed(17,{uint8_t(R++ + 170),G--,uint8_t(B-= 170)});
        WS281x_LedStream.SetLed(18,{uint8_t(R++ + 180),G--,uint8_t(B-= 180)});
        WS281x_LedStream.SetLed(19,{uint8_t(R++ + 190),G--,uint8_t(B-= 190)});
        WS281x_LedStream.SetLed(20,{uint8_t(R++ + 200),G--,uint8_t(B-= 200)});
        WS281x_LedStream.SetLed(21,{uint8_t(R++ + 210),G--,uint8_t(B-= 210)});
        WS281x_LedStream.SetLed(22,{uint8_t(R++ + 220),G--,uint8_t(B-= 220)});
        WS281x_LedStream.SetLed(23,{uint8_t(R++ + 230),G--,uint8_t(B-= 230)});
        nOS_Sleep(16);
        WS281x_LedStream.Start();
}
*/

    return State;
}

//-------------------------------------------------------------------------------------------------


void SystemInit_ExtMemCtl(void)
{
  __IO uint32_t tmp = 0;

  register uint32_t tmpreg = 0;
  register __IO uint32_t index;

  /* Enable GPIOD, GPIOE, GPIOF, GPIOG, GPIOH and GPIOI interface
      clock */
  RCC->AHB4ENR |= 0x000001F8;

  /* Delay after an RCC peripheral clock enabling */
  tmp = READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_GPIOEEN);

  /* Connect PDx pins to FMC Alternate function */
  GPIOD->AFR[0]  = 0x000000CC;
  GPIOD->AFR[1]  = 0xCC000CCC;
  /* Configure PDx pins in Alternate function mode */
  GPIOD->MODER   = 0xAFEAFFFA;
  /* Configure PDx pins speed to 100 MHz */
  GPIOD->OSPEEDR = 0xF03F000F;
  /* Configure PDx pins Output type to push-pull */
  GPIOD->OTYPER  = 0x00000000;
  /* Configure PDx pins in Pull-up */
  GPIOD->PUPDR   = 0x50150005;

  /* Connect PEx pins to FMC Alternate function */
  GPIOE->AFR[0]  = 0xC00000CC;
  GPIOE->AFR[1]  = 0xCCCCCCCC;
  /* Configure PEx pins in Alternate function mode */
  GPIOE->MODER   = 0xAAAABFFA;
  /* Configure PEx pins speed to 100 MHz */
  GPIOE->OSPEEDR = 0xFFFFC00F;
  /* Configure PEx pins Output type to push-pull */
  GPIOE->OTYPER  = 0x00000000;
  /* Configure PEx pins in Pull-up */
  GPIOE->PUPDR   = 0x55554005;

  /* Connect PFx pins to FMC Alternate function */
  GPIOF->AFR[0]  = 0x00CCCCCC;
  GPIOF->AFR[1]  = 0xCCCCC000;
  /* Configure PFx pins in Alternate function mode */
  GPIOF->MODER   = 0xAABFFAAA;
  /* Configure PFx pins speed to 100 MHz */
  GPIOF->OSPEEDR = 0xFFC00FFF;
  /* Configure PFx pins Output type to push-pull */
  GPIOF->OTYPER  = 0x00000000;
  /* Configure PFx pins in Pull-up */
  GPIOF->PUPDR   = 0x55400555;

  /* Connect PGx pins to FMC Alternate function */
  GPIOG->AFR[0]  = 0x00CC00CC;
  GPIOG->AFR[1]  = 0xC000000C;
  /* Configure PGx pins in Alternate function mode */
  GPIOG->MODER   = 0xBFFEFAFA;
 /* Configure PGx pins speed to 100 MHz */
  GPIOG->OSPEEDR = 0xC0030F0F;
  /* Configure PGx pins Output type to push-pull */
  GPIOG->OTYPER  = 0x00000000;
  /* Configure PGx pins in Pull-up */
  GPIOG->PUPDR   = 0x40010505;

  /* Connect PHx pins to FMC Alternate function */
  GPIOH->AFR[0]  = 0xCCC00000;
  GPIOH->AFR[1]  = 0xCCCCCCCC;
  /* Configure PHx pins in Alternate function mode */
  GPIOH->MODER   = 0xAAAAABFF;
  /* Configure PHx pins speed to 100 MHz */
  GPIOH->OSPEEDR = 0xFFFFFC00;
  /* Configure PHx pins Output type to push-pull */
  GPIOH->OTYPER  = 0x00000000;
  /* Configure PHx pins in Pull-up */
  GPIOH->PUPDR   = 0x55555400;

/*-- FMC Configuration ------------------------------------------------------*/
  /* Enable the FMC interface clock */
  (RCC->AHB3ENR |= (RCC_AHB3ENR_FMCEN));
  /*SDRAM Timing and access interface configuration*/
  /*LoadToActiveDelay  = 2
    ExitSelfRefreshDelay = 6
    SelfRefreshTime      = 4
    RowCycleDelay        = 6
    WriteRecoveryTime    = 2
    RPDelay              = 2
    RCDDelay             = 2
    SDBank             = FMC_SDRAM_BANK2
    ColumnBitsNumber   = FMC_SDRAM_COLUMN_BITS_NUM_8
    RowBitsNumber      = FMC_SDRAM_ROW_BITS_NUM_12
    MemoryDataWidth    = FMC_SDRAM_MEM_BUS_WIDTH_16
    InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4
    CASLatency         = FMC_SDRAM_CAS_LATENCY_2
    WriteProtection    = FMC_SDRAM_WRITE_PROTECTION_DISABLE
    SDClockPeriod      = FMC_SDRAM_CLOCK_PERIOD_2
    ReadBurst          = FMC_SDRAM_RBURST_ENABLE
    ReadPipeDelay      = FMC_SDRAM_RPIPE_DELAY_0*/

  FMC_Bank5_6_R->SDCR[0] = 0x00001800;
  FMC_Bank5_6_R->SDCR[1] = 0x00000154;
  FMC_Bank5_6_R->SDTR[0] = 0x00105000;
  FMC_Bank5_6_R->SDTR[1] = 0x01010351;

  /* SDRAM initialization sequence */
  /* Clock enable command */
  FMC_Bank5_6_R->SDCMR = 0x00000009;

  /* Delay */
  for (index = 0; index<5000; index++);

  /* PALL command */
  FMC_Bank5_6_R->SDCMR = 0x0000000A;
  FMC_Bank5_6_R->SDCMR = 0x000000EB;
  FMC_Bank5_6_R->SDCMR = 0x0004400C;

  /* Set refresh count */
  tmpreg = FMC_Bank5_6_R->SDRTR;
  FMC_Bank5_6_R->SDRTR = (tmpreg | (0x00000603<<1));

  /* Disable write protection */
  tmpreg = FMC_Bank5_6_R->SDCR[1];
  FMC_Bank5_6_R->SDCR[1] = (tmpreg & 0xFFFFFDFF);

   /*FMC controller Enable*/
  FMC_Bank1_R->BTCR[0]  |= 0x80000000;

  (void)(tmp);
}
