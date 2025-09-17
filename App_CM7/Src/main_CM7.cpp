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
#include "lib_solar_tracker.h"

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
SunPosition_t Position;
SolarTracker SolarTrack;

int main()
{
  #if (USE_MPU_DRIVER == DEF_ENABLED)
    MPU_Initialize(MPU_PRIVILEGED_DEFAULT);
    CPU_CACHE_Enable();
  #endif

    nOS_Init();
    BSP_Initialize();                           // All hardware and system initialization
    nOS_Start();
    BSP_PostOS_Initialize();                    // All initialization that must be done after the OS is started

  #if 1 // def DEBUG
    DateAndTime_t DateTime;

    DateTime.Date.Day    = 4;
    DateTime.Date.Month  = 9;
    DateTime.Date.Year   = 2025;
    DateTime.Time.Hour   = 13;   // UT time  so time is 9 AM
    DateTime.Time.Minute = 50;
    DateTime.Time.Second = 0;
    LIB_SetDateAndTime(&DateTime);
  #endif

  bool UseDegrees = true;             // Input (geographic position) and output are in degrees
  bool UseNorthEqualsZero = true;     // Azimuth: false = South, pi/2 (90deg) = West  ->  true = North, pi/2 (90deg) = East
  bool ComputeRefrEquatorial = true;  // Compute refraction-corrected equatorial coordinates (Hour angle, declination): false-no, true-yes
  bool ComputeDistance = true;        // Compute the distance to the Sun in AU: false-no, true-yes

  OriginLocation_t Location;
  Location.Latitude  = 45.8944094;
  Location.Longitude = -74.0015057;  // la maison
  Location.Pressure = 101.0;     // Atmospheric pressure in kPa
  Location.Temperature = 283.0;  // Atmospheric temperature in K


  SolarTrack.SolTrack(&DateTime, &Location, &Position, UseDegrees, UseNorthEqualsZero, ComputeRefrEquatorial, ComputeDistance);


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
    SET_BIT(RCC->GCR, RCC_BOOT_C2);             // Enable boot core 2

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
