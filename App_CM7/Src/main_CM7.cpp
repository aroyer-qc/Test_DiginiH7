//-------------------------------------------------------------------------------------------------
//
//  File : main_CM7.cpp
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

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------

#include "./lib_digini.h"
#include "taskIdle.h"
#include "bsp.h"

//-------------------------------------------------------------------------------------------------
//
// Name:           main
// Parameter(s):   void
// Return:         int
//
// Description:    main() what more can be said
//
// Note(s):        Here we create the task that will start all the other
//
//-------------------------------------------------------------------------------------------------
int main()
{
    nOS_Init();
    BSP_Initialize();                           // All hardware and system initialization
    nOS_Start();
    BSP_PostOS_Initialize();                    // All initialization that must be done after the OS is started

  #if 0 // def DEBUG
    DateAndTime_t DateTime;

    DateTime.Date.Day    = 25;
    DateTime.Date.Month  = 6;
    DateTime.Date.Year   = 2024;
    DateTime.Time.Hour   = 15;
    DateTime.Time.Minute = 30;
    DateTime.Time.Second = 1;
    LIB_SetDateAndTime(&DateTime);
  #endif

    TaskIdle();
    return 0;



    #if 0   // for 745 to switch CPU

        /*
     * To be independent on CM4 boot option bytes config,
     * application will force second core to start by setting its relevant bit in RCC registers.
     *
     * Application for second core will immediately enter to STOP mode.
     * This is done in CPU2 main.c file
     *
     * 1. Start CPU2 core
     * 2. Wait for CPU2 to enter low-power mode
     */
    HAL_RCCEx_EnableBootCore(RCC_BOOT_C2);

#ifndef DEBUG
    // In debug mode we use the free running CPU
    WAIT_COND_WITH_TIMEOUT(__HAL_RCC_GET_FLAG(RCC_FLAG_D2CKRDY) != RESET, 0xFFFF);
#endif

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Wakeup CPU2 */
    __HAL_RCC_HSEM_CLK_ENABLE();
    HSEM_TAKE_RELEASE(HSEM_WAKEUP_CPU2);
    WAIT_COND_WITH_TIMEOUT(__HAL_RCC_GET_FLAG(RCC_FLAG_D2CKRDY) == RESET, 0xFFFF);

    #endif


}
