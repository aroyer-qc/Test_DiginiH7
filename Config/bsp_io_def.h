//-------------------------------------------------------------------------------------------------
//
//  File : bsp_io_def.h
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

//-------------------------------------------------------------------------------------------------
//
//          Parameter 1:  This is the ID of the IO pin
//          Parameter 2:  Port for the PIN
//                          GPIOx
//          Parameter 3:  IO number for the PIN
//          Parameter 4:  MODE for the pin
//                          IO_MODE_INPUT
//                          IO_MODE_OUTPUT
//                          IO_MODE_ALTERNATE
//                          IO_MODE_ANALOG
//          Parameter 5:  TYPE for the pin
//                          IO_TYPE_PIN_DRIVE_MASK
//                          IO_TYPE_PIN_DRIVE_SHIFT
//                          IO_TYPE_PIN_PP
//                          IO_TYPE_PIN_OD
//          Parameter 6:  SPEED for the pin
//                          IO_SPEED_FREQ_LOW
//                          IO_SPEED_FREQ_MEDIUM
//                          IO_SPEED_FREQ_HIGH
//                          IO_SPEED_FREQ_VERY_HIGH
//          Parameter 7:  EXTRA info for the pin
//                          If mode is IO_MODE_INPUT,        This is not used. Put 0 there
//                          If mode is IO_MODE_OUTPUT,       This is the default level on the pin at initialization. Put level HALIO_LEVEL_0 or HALIO_LEVEL_1 or HALIO_LEVEL_HIGH_Z
//                          If mode is IO_MODE_ALTERNATE,    This is the alternate setting
//                                                               Example: GPIO_AF7_USART3  -  See hal_io.h for your CPU
//                          If mode is IO_MODE_ANALOG,       This is used to select the ADC input               // to be validated!!!
//
//-------------------------------------------------------------------------------------------------

#define IO_DEF(X_IO) \
/*        ENUM ID of the IO,     IO Port,    IO Pin, Mode,               Pin type,              IO Speed,                 Pin Option           */\
/* input IO's ---------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_USER_BUTTON,        GPIOC,      13,     IO_MODE_INPUT,      IO_TYPE_PIN_NO_PULL,   IO_SPEED_FREQ_LOW,        0)                     \
/* Output IO's --------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_LED_RED,            GPIOJ,      2,      IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        0)                     \
    X_IO( IO_LED_GREEN,          GPIOI,      13,     IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        0)                     \
/* SPI IO's -----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_SPI3_CLK,           GPIOB,      3,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI3)           \
    X_IO( IO_SPI3_MOSI,          GPIOB,      5,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI3)           \
    X_IO( IO_SPI1_CLK,           GPIOA,      5,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI1)           \
    X_IO( IO_SPI1_MOSI,          GPIOA,      7,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF5_SPI1)           \
    X_IO( IO_SPI1_CS,            GPIOB,      9,      IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       1)                     \
/* UART IO's ----------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_UART3_RX,           GPIOD,      9,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        IO_AF7_USART3)         \
    X_IO( IO_UART3_TX,           GPIOD,      8,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        IO_AF7_USART3)         \
    X_IO( IO_UART6_RX,           GPIOxx,     7,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_LOW,        IO_AF8_USART6)/* N/U */\
    X_IO( IO_UART6_TX,           GPIOC,      6,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF8_USART6)         \
/* MCO ----------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_MCO_2,              GPIOC,      9,      IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       IO_AF0_MCO)            \
/* LCD ----------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO( IO_LCD_DISPLAY,        GPIOD,      7,      IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,        IO_SPEED_FREQ_HIGH,       1)                     \
    X_IO( LCD_INT                GPIOG,      2,      IO_MODE_INPUT,      IO_TYPE_PIN_NO_PULL,   IO_SPEED_FREQ_HIGH,       0)                     \

//-------------------------------------------------------------------------------------------------
//
//  IO_GROUP is useful for pin sharing configuration and they are not used individually at run time because they are control by module.
//      Examples: LCD, SDRAM, ETH, etc...
//

// Notes : Some group might share same config


//-------------------------------------------------------------
// SDRAM grouping configuration

#define SDRAM_ON_PORT_D_ALT_12  (IO_PIN_0  | IO_PIN_1  | IO_PIN_8  | IO_PIN_9  | IO_PIN_10 | \
                                 IO_PIN_14 | IO_PIN_15)
#define SDRAM_ON_PORT_E_ALT_12  (IO_PIN_0  | IO_PIN_1  | IO_PIN_7  | IO_PIN_8  | IO_PIN_9  | \
                                 IO_PIN_10 | IO_PIN_11 | IO_PIN_12 | IO_PIN_13 | IO_PIN_14 | \
                                 IO_PIN_15)
#define SDRAM_ON_PORT_F_ALT_12  (IO_PIN_0  | IO_PIN_1  | IO_PIN_2  | IO_PIN_3  | IO_PIN_4  | \
                                 IO_PIN_5  | IO_PIN_11 | IO_PIN_12 | IO_PIN_13 | IO_PIN_14 | \
                                 IO_PIN_15)
#define SDRAM_ON_PORT_G_ALT_12  (IO_PIN_0  | IO_PIN_1  | IO_PIN_4  | IO_PIN_5  | IO_PIN_8  | \
                                 IO_PIN_15)
#define SDRAM_ON_PORT_H_ALT_12  (IO_PIN_5  | IO_PIN_6  | IO_PIN_7)

//-------------------------------------------------------------
// ETH grouping configuration

#define ETH_ON_PORT_A_ALT_x     (IO_PIN_1  | IO_PIN_2  | IO_PIN_7)
#define ETH_ON_PORT_B_ALT_x     (IO_PIN_0  | IO_PIN_1  | IO_PIN_2)
#define ETH_ON_PORT_C_ALT_x     (IO_PIN_1  | IO_PIN_2  | IO_PIN_3  | IO_PIN_4  | IO_PIN_5)
#define ETH_ON_PORT_E_ALT_x     (IO_PIN_2)
#define ETH_ON_PORT_G_ALT_x     (IO_PIN_11 | IO_PIN_12 | IO_PIN_13)
//#define ETH_ON_PORT_H_ALT_x     (IO_PIN_2)  | IO_PIN_3))   this I think are optional
#define ETH_ON_PORT_I_ALT_x     (IO_PIN_10)

//-------------------------------------------------------------
// QSPI grouping configuration

#define QSPI_ON_PORT_C_ALT_9    (IO_PIN_11)
#define QSPI_ON_PORT_D_ALT_9    (IO_PIN_11)
#define QSPI_ON_PORT_F_ALT_9    (IO_PIN_6  | IO_PIN_7  | IO_PIN_10)
#define QSPI_ON_PORT_F_ALT_10   (IO_PIN_9)
#define QSPI_ON_PORT_G_ALT_9    (IO_PIN_9  | IO_PIN_14)
#define QSPI_ON_PORT_G_ALT_10   (IO_PIN_6)
#define QSPI_ON_PORT_H_ALT_9    (IO_PIN_2  | IO_PIN_3)

//-------------------------------------------------------------
// LCD grouping configuration

#define LCD_ON_PORT_H_ALT_14    (IO_PIN_9)
#define LCD_ON_PORT_I_ALT_14    (IO_PIN_0  | IO_PIN_1  | IO_PIN_9  | IO_PIN_12 | IO_PIN_14 | \
                                 IO_PIN_15)
#define LCD_ON_PORT_J_ALT_14    (IO_PIN_0  | IO_PIN_1  | IO_PIN_3  | IO_PIN_4  | IO_PIN_5  | \
                                 IO_PIN_6  | IO_PIN_7  | IO_PIN_8  | IO_PIN_9  | IO_PIN_10 | \
                                 IO_PIN_11 | IO_PIN_12 | IO_PIN_13 | IO_PIN_14 | IO_PIN_15)
#define LCD_ON_PORT_K_ALT_14    (IO_PIN_0  | IO_PIN_1  | IO_PIN_2  | IO_PIN_3  | IO_PIN_4  | \
                                 IO_PIN_5  | IO_PIN_6  | IO_PIN_7)

//-------------------------------------------------------------

#define IO_GROUP_DEF(X_IO_GROUP) \
/* LCD -------------------------------------------------------------------------------------------------------------------------------------------------------*/ \
    X_IO_GROUP( IO_LCD_ON_PORT_H_ALT_14,    GPIOH,      LCD_ON_PORT_H_ALT_14,       IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF14_LTDC)    \
    X_IO_GROUP( IO_LCD_ON_PORT_I_ALT_14,    GPIOI,      LCD_ON_PORT_I_ALT_14,       IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF14_LTDC)    \
    X_IO_GROUP( IO_LCD_ON_PORT_J_ALT_14,    GPIOJ,      LCD_ON_PORT_J_ALT_14,       IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF14_LTDC)    \
    X_IO_GROUP( IO_LCD_ON_PORT_K_ALT_14,    GPIOK,      LCD_ON_PORT_K_ALT_14,       IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF14_LTDC)    \
/* SDRAM -----------------------------------------------------------------------------------------------------------------------------------------------------*/ \
    X_IO_GROUP( IO_SDRAM_ON_PORT_D_ALT_12,  GPIOD,      SDRAM_ON_PORT_D_ALT_12,     IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF12_FMC)     \
    X_IO_GROUP( IO_SDRAM_ON_PORT_E_ALT_12,  GPIOE,      SDRAM_ON_PORT_E_ALT_12,     IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF12_FMC)     \
    X_IO_GROUP( IO_SDRAM_ON_PORT_F_ALT_12,  GPIOF,      SDRAM_ON_PORT_F_ALT_12,     IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF12_FMC)     \
    X_IO_GROUP( IO_SDRAM_ON_PORT_G_ALT_12,  GPIOG,      SDRAM_ON_PORT_G_ALT_12,     IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF12_FMC)     \
    X_IO_GROUP( IO_SDRAM_ON_PORT_H_ALT_12,  GPIOH,      SDRAM_ON_PORT_H_ALT_12,     IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF12_FMC)     \
/* ETH -------------------------------------------------------------------------------------------------------------------------------------------------------*/ \
    X_IO_GROUP( IO_ETH_ON_PORT_A_ALT_x,     GPIOA,      ETH_ON_PORT_A_ALT_x,        IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF)  \
    X_IO_GROUP( IO_ETH_ON_PORT_B_ALT_x,     GPIOB,      ETH_ON_PORT_B_ALT_x,        IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF)  \
    X_IO_GROUP( IO_ETH_ON_PORT_C_ALT_x,     GPIOC,      ETH_ON_PORT_C_ALT_x,        IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF)  \
    X_IO_GROUP( IO_ETH_ON_PORT_E_ALT_x,     GPIOE,      ETH_ON_PORT_E_ALT_x,        IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF)  \
    X_IO_GROUP( IO_ETH_ON_PORT_G_ALT_x,     GPIOG,      ETH_ON_PORT_G_ALT_x,        IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF)  \
  /*X_IO_GROUP( IO_ETH_ON_PORT_H_ALT_x,     GPIOH,      ETH_ON_PORT_G_ALT_x,        IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF)*/\
    X_IO_GROUP( IO_ETH_ON_PORT_I_ALT_x,     GPIOI,      ETH_ON_PORT_I_ALT_x,        IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF)  \
/* QSPI ---------------------------------------------------------------------------------------------------------------------------------------------*/ \
    X_IO_GROUP( IO_QSPI_ON_PORT_C_ALT_9,    GPIOC,      QSPI_ON_PORT_C_ALT_9,       IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF9_QUADSPI)  \
    X_IO_GROUP( IO_QSPI_ON_PORT_D_ALT_9,    GPIOD,      QSPI_ON_PORT_D_ALT_9,       IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF9_QUADSPI)  \
    X_IO_GROUP( IO_QSPI_ON_PORT_F_ALT_9,    GPIOF,      QSPI_ON_PORT_F_ALT_9,       IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF9_QUADSPI)  \
    X_IO_GROUP( IO_QSPI_ON_PORT_F_ALT_10,   GPIOF,      QSPI_ON_PORT_F_ALT_10,      IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF10_QUADSPI) \
    X_IO_GROUP( IO_QSPI_ON_PORT_G_ALT_9,    GPIOG,      QSPI_ON_PORT_G_ALT_9,       IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF9_QUADSPI)  \
    X_IO_GROUP( IO_QSPI_ON_PORT_G_ALT_10,   GPIOG,      QSPI_ON_PORT_G_ALT_10,      IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF10_QUADSPI) \
    X_IO_GROUP( IO_QSPI_ON_PORT_H_ALT_9,    GPIOH,      QSPI_ON_PORT_G_ALT_9,       IO_MODE_ALTERNATE, IO_TYPE_PIN_PP, IO_SPEED_FREQ_VERY_HIGH, IO_AF9_QUADSPI)  \


// Note(s) the pin IO_CALIB_OUT_DEBUG is only use in some debug case and must not be initialized on permanent base

//-------------------------------------------------------------------------------------------------
//
//          Parameter 1:  This is the ID of the IO IRQ pin
//
//          Parameter 2:  This is the ID of the IO pin used for this IRQ IO
//                          GPIOx
//
//          Parameter 3:    EXTI0_IRQn                  EXTI Line0 Interrupt
//                          EXTI1_IRQn                  EXTI Line1 Interrupt
//                          EXTI2_IRQn                  EXTI Line2 Interrupt
//                          EXTI3_IRQn                  EXTI Line3 Interrupt
//                          EXTI4_IRQn                  EXTI Line4 Interrupt
//                          EXTI9_5_IRQn                External Line[9:5] Interrupts
//                          EXTI15_10_IRQn              External Line[15:10] Interrupts
//
//          Parameter 4:    IO_EXTI_TRIGGER_RISING
//                          IO_EXTI_TRIGGER_FALLING
//                          IO_EXTI_TRIGGER_RISING_FALLING
//
//-------------------------------------------------------------------------------------------------

#if 0
#define IO_IRQ_DEF(X_IO_IRQ) \
/*           Enum ID                    Pin ID                 EXTI Pin Source     Trigger                         */\


#endif
//-------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------------------

