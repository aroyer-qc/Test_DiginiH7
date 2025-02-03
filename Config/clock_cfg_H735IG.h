//-------------------------------------------------------------------------------------------------
//
//  File : clock_cfg_H735IG.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2025 Alain Royer.
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
#define CFG_SYS_CLOCK_MUX                           CFG_RCC_CFGR_SW_PLL1            // CFG_RCC_CFGR_SW_x   -> HSI, CSI, HSE or PLL1
#define CFG_MUX_PLL_SOURCE                          CFG_RCC_PLLCKSELR_PLLSRC_HSE    // CFG_RCC_PLLCKSELR_x -> HSI, CSI or HSE
#define CFG_FREQ_PLL_SOURCE                         CFG_HSE_VALUE
#define CFG_SYSTEM_CLOCK_NUMBER_OF_RETRY            1000

//-------------------------------------------------------------------------------------------------
// multiplier and Prescaler

#define CFG_PLL1_M_DIVIDER                          5
#define CFG_PLL1_N_MULTIPLIER                       110
#define CFG_PLL1_P_DIVIDER                          1
#define CFG_PLL1_Q_DIVIDER                          4
#define CFG_PLL1_R_DIVIDER                          2
#define CFG_PLL1_FRACTIONAL_VALUE                   0                               // 0 Disable the Sigma-Delta modulator (Range: 0 - 8191)

// Arbitrary value at this configure as needed by peripheral
#define CFG_PLL2_M_DIVIDER                          25
#define CFG_PLL2_N_MULTIPLIER                       150
#define CFG_PLL2_P_DIVIDER                          6
#define CFG_PLL2_Q_DIVIDER                          30
#define CFG_PLL2_R_DIVIDER                          6
#define CFG_PLL2_FRACTIONAL_VALUE                   0                               // 0 Disable the Sigma-Delta modulator (Range: 0 - 8191)

#define CFG_PLL3_M_DIVIDER                          25
#define CFG_PLL3_N_MULTIPLIER                       192                             // Needed to configure LTDC correct spee
#define CFG_PLL3_P_DIVIDER                          24
#define CFG_PLL3_Q_DIVIDER                          4
#define CFG_PLL3_R_DIVIDER                          20                              // LTDC source 9.6 MHz
#define CFG_PLL3_FRACTIONAL_VALUE                   0                               // 0 Disable the Sigma-Delta modulator (Range: 0 - 8191)

#define CFG_ENABLE_PLL1P                            1
#define CFG_ENABLE_PLL1Q                            1
#define CFG_ENABLE_PLL1R                            0

#define CFG_ENABLE_PLL2P                            0
#define CFG_ENABLE_PLL2Q                            1
#define CFG_ENABLE_PLL2R                            1

#define CFG_ENABLE_PLL3P                            0
#define CFG_ENABLE_PLL3Q                            1
#define CFG_ENABLE_PLL3R                            1

#define CFG_HPRE_DIVIDER                            CFG_RCC_HPRE_DIV2               // (HPRE Prescaler) CFG_RCC_HPRE_DIVx -> 1,2,4,8,16,64,128,256,512
#define CFG_D1CPRE_DIVIDER                          CFG_RCC_D1CPRE_DIV1             // (D1CPRE Prescaler) CFG_RCC_D1CPRE_DIVx -> 1,2,4,8,16,64,128,256,512
#define CFG_D1PPRE_DIVIDER                          CFG_RCC_D1PPRE_DIV2             // (D1PPRE Prescaler) CFG_RCC_D1PPRE_DIVx   -> 1,2,4,8,16
#define CFG_D2PPRE1_DIVIDER                         CFG_RCC_D2PPRE1_DIV2            // (D2PPRE1 Prescaler) CFG_RCC_D2PPRE1_DIVx -> 1,2,4,8,16
#define CFG_D2PPRE2_DIVIDER                         CFG_RCC_D2PPRE2_DIV2            // (D2PPRE2 Prescaler) CFG_RCC_D2PPRE2_DIVx -> 1,2,4,8,16
#define CFG_D3PPRE_DIVIDER                          CFG_RCC_D3PPRE_DIV2             // (D2PPRE3 Prescaler) CFG_RCC_D2PPRE3_DIVx -> 1,2,4,8,16

#define CFG_MCO_1_DIVIDER                           CFG_RCC_MCO1PRE_DIV5            // (MCO1 Prescaler) CFG_RCC_CFGR_MCO1PRE_DIVx -> 0 to 15, if set to 0 prescaler is disabled
#define CFG_MCO_2_DIVIDER                           CFG_RCC_MCO2PRE_DIV5            // (MCO1 Prescaler) CFG_RCC_CFGR_MCO2PRE_DIVx -> 0 to 15, if set to 0 prescaler is disabled

//-------------------------------------------------------------------------------------------------
// multiplexer clock source

// Define the MUX for module that you will need.        See lib_STM32H7_system_clock for clock selection option.
#define CFG_PER_SOURCE_MUX                          CFG_RCC_D1CCIPR_PER_HSI_KER
#define CFG_ADC_SOURCE_MUX                          CFG_RCC_D3CCIPR_ADC_PLL2P
#define CFG_CEC_SOURCE_MUX                          CFG_RCC_D2CCIP2R_CEC_LSE
#define CFG_DFSDM_SOURCE_MUX                        CFG_RCC_D2CCIP1R_DFSDM_PLCK2
#define CFG_FDCAN_SOURCE_MUX                        CFG_RCC_D2CCIP1R_FDCAN_HSE
#define CFG_FMC_SOURCE_MUX                          CFG_RCC_D1CCIPR_FMC_PLL1Q
#define CFG_I2C1235_SOURCE_MUX                      CFG_RCC_D2CCIP2R_I2C1235_PCLK1
#define CFG_I2C4_SOURCE_MUX                         CFG_RCC_D3CCIPR_I2C4_PCLK4
#define CFG_HRTIM_SOURCE_MUX                        CFG_RCC_CFGR_HRTIM_TIM_CLK
#define CFG_LPTIM1_SOURCE_MUX                       CFG_RCC_D2CCIP2R_LPTIM1_PCLK1
#define CFG_LPTIM2_SOURCE_MUX                       CFG_RCC_D3CCIPR_LPTIM2_PCLK4
#define CFG_LPTIM345_SOURCE_MUX                     CFG_RCC_D3CCIPR_LPTIM345_PCLK4
#define CFG_LPUART1_SOURCE_MUX                      CFG_RCC_D3CCIPR_LPUART1_PCLK3
#define CFG_MCO1_SOURCE_MUX                         CFG_RCC_CFGR_MCO1_SYS_CLK
#define CFG_MCO2_SOURCE_MUX                         CFG_RCC_CFGR_MCO2_SYS_CLK
#define CFG_OSPI_SOURCE_MUX                         CFG_RCC_D1CCIPR_OSPI_PLL1Q
#define CFG_RNG_SOURCE_MUX                          CFG_RCC_D2CCIP2R_RNG_HSI48
#define CFG_RTC_SOURCE_MUX                          CFG_RCC_BDCR_RTC_LSE
#define CFG_SAI1_SOURCE_MUX                         CFG_RCC_D2CCIP1R_SAI1_PLL1Q
#define CFG_SAI23_SOURCE_MUX                        CFG_RCC_D2CCIP1R_SAI23_PLL1Q
#define CFG_SAI4A_SOURCE_MUX                        CFG_RCC_D3CCIPR_SAI4A_PLL1Q
#define CFG_SAI4B_SOURCE_MUX                        CFG_RCC_D3CCIPR_SAI4B_PLL1Q
#define CFG_SDMMC_SOURCE_MUX                        CFG_RCC_D1CCIPR_SDMMC_PLL2R
#define CFG_SPDIF_SOURCE_MUX                        CFG_RCC_D2CCIP1R_SPDIF_PLL1Q
#define CFG_SPI1235_SOURCE_MUX                      CFG_RCC_D2CCIP1R_SPI1235_PLL1Q
#define CFG_SPI4_SOURCE_MUX                         CFG_RCC_D2CCIP1R_SPI4_PLCK2
#define CFG_SPI6_SOURCE_MUX                         CFG_RCC_D3CCIPR_SPI6_PLCK4
#define CFG_SWP_SOURCE_MUX                          CFG_RCC_D2CCIP1R_SWP_PCLK1
#define CFG_UART16910_SOURCE_MUX                    CFG_RCC_D2CCIP2R_USART16910_PCLK2
#define CFG_UART234578_SOURCE_MUX                   CFG_RCC_D2CCIP2R_USART234578_PLL3Q
#define CFG_USB_SOURCE_MUX                          CFG_RCC_D2CCIP2R_USB_PLL3Q

//-------------------------------------------------------------------------------------------------
