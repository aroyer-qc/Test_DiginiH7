//-------------------------------------------------------------------------------------------------
//
//  File : clock_cfg.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2023 Alain Royer.
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

#pragma once

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define CFG_LSE_VALUE                               32768
#define CFG_HSE_VALUE                               25000000

#define CFG_HSI_DIVIDER                             1                               // 1,2,4,8

#define CFG_SYSTICK_RATE                            1000

// User loop value for LIB_Delay_uSec function.. use IO to check for the right value
#define CFG_DELAY_TIMING_LOOP_VALUE_FOR_1_USEC      38 // TODO need to be set and fine tuned

// User clock selection
#define CFG_SYS_CLOCK_MUX                           CFG_RCC_CFGR_SW_PLL         // CFG_RCC_CFGR_SW_HSI, CFG_RCC_CFGR_SW_HSE or CFG_RCC_CFGR_SW_PLL
#define CFG_RCC_PLLCFGR_PLLSRC                      CFG_RCC_PLLCFGR_PLLSRC_HSE  // CFG_RCC_PLLCFGR_PLLSRC_HSI or CFG_RCC_PLLCFGR_PLLSRC_HSE
#define CFG_SYSTEM_CLOCK_NUMBER_OF_RETRY            1000

#define CFG_PLL_SOURCE                              CFG_HSE_VALUE

//-------------------------------------------------------------------------------------------------
// multiplier and Prescaler

#define CFG_PLL_DIVM1_M_DIVIDER                     25
#define CFG_PLL_DIVM1_N_MULTIPLIER                  480
#define CFG_PLL_DIVM1_P_DIVIDER                     2
#define CFG_PLL_DIVM1_Q_DIVIDER                     5
#define CFG_PLL_DIVM1_R_DIVIDER                     5

// Arbitrary value at this configure as needed by peripheral
#define CFG_PLL_DIVM2_M_DIVIDER                     25
#define CFG_PLL_DIVM2_N_MULTIPLIER                  480
#define CFG_PLL_DIVM2_P_DIVIDER                     2
#define CFG_PLL_DIVM2_Q_DIVIDER                     5
#define CFG_PLL_DIVM2_R_DIVIDER                     5

#define CFG_PLL_DIVM3_M_DIVIDER                     5
#define CFG_PLL_DIVM3_N_MULTIPLIER                  48                              // Needed to configure LTDC correct spee
#define CFG_PLL_DIVM3_P_DIVIDER                     1
#define CFG_PLL_DIVM3_Q_DIVIDER                     5
#define CFG_PLL_DIVM3_R_DIVIDER                     4                               // LTDC source

#define CFG_D1CPRE_DIVIDER                          CFG_RCC_CFGR_D1CPRE_DIV1        // (D1CPRE Prescaler) CFG_RCC_CFGR_D1CPRE_DIVx -> 1,2,4,8,16,64,128,256,512
#define CFG_HPRE_DIVIDER                            CFG_RCC_CFGR_HPRE_DIV1          // (HPRE Prescaler) CFG_RCC_CFGR_HPRE_DIVx -> 1,2,4,8,16,64,128,256,512

#define CFG_D1PPRE_DIVIDER                          CFG_RCC_CFGR_D1PPRE_DIV2        // (D1PPRE Prescaler) CFG_RCC_CFGR_D1PPRE_DIVx   -> 1,2,4,8,16
#define CFG_D2PPRE1_DIVIDER                         CFG_RCC_CFGR_D2PPRE1_DIV2       // (D2PPRE1 Prescaler) CFG_RCC_CFGR_D2PPRE1_DIVx -> 1,2,4,8,16
#define CFG_D2PPRE2_DIVIDER                         CFG_RCC_CFGR_D2PPRE2_DIV2       // (D2PPRE2 Prescaler) CFG_RCC_CFGR_D2PPRE2_DIVx -> 1,2,4,8,16
#define CFG_D2PPRE3_DIVIDER                         CFG_RCC_CFGR_D2PPRE3_DIV2       // (D2PPRE3 Prescaler) CFG_RCC_CFGR_D2PPRE3_DIVx -> 1,2,4,8,16

#define CFG_MCO_1_DIVIDER                           CFG_RCC_CFGR_MCO1PRE_DIV5       // (MCO1 Prescaler) CFG_RCC_CFGR_MCO1PRE_DIVx -> 0 to 15, if set to 0 prescaler is disabled
#define CFG_MCO_2_DIVIDER                           CFG_RCC_CFGR_MCO2PRE_DIV5       // (MCO1 Prescaler) CFG_RCC_CFGR_MCO2PRE_DIVx -> 0 to 15, if set to 0 prescaler is disabled

//-------------------------------------------------------------------------------------------------
// multiplexer clock source

// Define the MUX for module that you will need.        See lib_STM32H7_system_clock for clock selection option.
#define CFG_PER_SOURCE_MUX                          CFG_RCC_D1CCIPR_PER_HSI_KER
#define CFG_ADC_SOURCE_MUX                          CFG_RCC_D3CCIPR_ADC_PLL2P
#define CFG_CEC_SOURCE_MUX                          CFG_RCC_D2CCIP2R_CEC_LSE
#define CFG_DFSDM_SOURCE_MUX                        CFG_RCC_D2CCIP1R_DFSDM_PLCK2
#define CFG_FDCAN_SOURCE_MUX                        CFG_RCC_D2CCIP1R_FDCAN_HSE
#define CFG_FMC_SOURCE_MUX                          CFG_RCC_D1CCIPR_FMC_PLL1Q
#define CFG_I2C123_SOURCE_MUX                       CFG_RCC_D2CCIP2R_I2C123_PCLK1
#define CFG_I2C4_SOURCE_MUX                         CFG_RCC_D3CCIPR_I2C4_PCLK4
#define CFG_HRTIM_SOURCE_MUX                        CFG_RCC_CFGR_HRTIM_TIM_CLK
#define CFG_LPTIM1_SOURCE_MUX                       CFG_RCC_D2CCIP2R_LPTIM1_PCLK1
#define CFG_LPTIM2_SOURCE_MUX                       CFG_RCC_D3CCIPR_LPTIM2_PCLK4
#define CFG_LPTIM345_SOURCE_MUX                     CFG_RCC_D3CCIPR_LPTIM345_PCLK4
#define CFG_LPUART1_SOURCE_MUX                      CFG_RCC_D3CCIPR_LPUART1_PCLK3
#define CFG_MCO1_SOURCE_MUX                         CFG_RCC_CFGR_MCO1_SYS_CLK
#define CFG_MCO2_SOURCE_MUX                         CFG_RCC_CFGR_MCO2_SYS_CLK
#define CFG_QSPI_SOURCE_MUX                         CFG_RCC_D1CCIPR_QSPI_PLL1Q
#define CFG_RNG_SOURCE_MUX                          CFG_RCC_D2CCIP2R_RNG_HSI48
#define CFG_RTC_SOURCE_MUX                          CFG_RCC_BDCR_RTC_LSE
#define CFG_SAI1_SOURCE_MUX                         CFG_RCC_D2CCIP1R_SAI1_PLL1Q
#define CFG_SAI23_SOURCE_MUX                        CFG_RCC_D2CCIP1R_SAI23_PLL1Q
#define CFG_SAI4A_SOURCE_MUX                        CFG_RCC_D3CCIPR_SAI4A_PLL1Q
#define CFG_SAI4B_SOURCE_MUX                        CFG_RCC_D3CCIPR_SAI4B_PLL1Q
#define CFG_SDMMC_SOURCE_MUX                        CFG_RCC_D1CCIPR_SDMMC_PLL1Q
#define CFG_SPDIF_SOURCE_MUX                        CFG_RCC_D2CCIP1R_SPDIF_PLL1Q
#define CFG_SPI123_SOURCE_MUX                       CFG_RCC_D2CCIP1R_SPI123_PLL1Q
#define CFG_SPI45_SOURCE_MUX                        CFG_RCC_D2CCIP1R_SPI45_PLCK2
#define CFG_SPI6_SOURCE_MUX                         CFG_RCC_D3CCIPR_SPI6_PLCK4
#define CFG_SWP_SOURCE_MUX                          CFG_RCC_D2CCIP1R_SWP_PCLK1
//#define CFG_TRACE_SOURCE_MUX                        HSI //???
#define CFG_UART16_SOURCE_MUX                       CFG_RCC_D2CCIP2R_USART16_PCLK2
#define CFG_UART234578_SOURCE_MUX                   CFG_RCC_D2CCIP2R_USART234578_PCLK1
#define CFG_USB_SOURCE_MUX                          CFG_RCC_D2CCIP2R_USB_PLL3Q
//more to do!!

//-------------------------------------------------------------------------------------------------
