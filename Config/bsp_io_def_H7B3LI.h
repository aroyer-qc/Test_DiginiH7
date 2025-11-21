//-------------------------------------------------------------------------------------------------
//
//  File : bsp_io_def_H7B3LI.h
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
//          IO_CFG_DEF(X_IO_CFG)
//
//          This is common configuration for IO_DEF pin declaration.
//          It help reduce code size by sharing configuration.
//
//          Parameter 1:  ENUM ID of the configuration
//
//          Parameter 2:  MODE for the pin
//                          IO_MODE_INPUT
//                          IO_MODE_OUTPUT
//                          IO_MODE_ALTERNATE
//                          IO_MODE_ANALOG
//          Parameter 3:  TYPE for the pin
//                          IO_TYPE_PIN_DRIVE_MASK
//                          IO_TYPE_PIN_DRIVE_SHIFT
//                          IO_TYPE_PIN_PP
//                          IO_TYPE_PIN_OD
//          Parameter 4:  SPEED for the pin
//                          IO_SPEED_FREQ_LOW
//                          IO_SPEED_FREQ_MEDIUM
//                          IO_SPEED_FREQ_HIGH
//                          IO_SPEED_FREQ_VERY_HIGH
//          Parameter 5:  EXTRA info for the pin
//                          If mode is IO_MODE_INPUT,        This is not used. Put 0 there
//                          If mode is IO_MODE_OUTPUT,       This is the default level on the pin at initialization. Put level HALIO_LEVEL_0 or HALIO_LEVEL_1 or HALIO_LEVEL_HIGH_Z
//                          If mode is IO_MODE_ALTERNATE,    This is the alternate setting
//                                                               Example: GPIO_AF7_USART3  -  See lib_STM32H7_io.h
//                          If mode is IO_MODE_ANALOG,       This is used to select the ADC input               // to be validated!!!
//
//-------------------------------------------------------------------------------------------------

#define IO_CFG_DEF(X_IO_CFG) \
/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/\
/*            ENUM ID IO CFG,                           Mode,               Pin type,                                  IO Speed,                 Pin Option           */\
/* input IO's CFG ----------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_INPUT_NP_LS,                       IO_MODE_INPUT,      IO_TYPE_PIN_NO_PULL,                       IO_SPEED_FREQ_LOW,        0)                     \
/* Output IO's CFG ---------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_OUTPUT_PP_LS_DEF0,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,                            IO_SPEED_FREQ_LOW,        0)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_LS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,                            IO_SPEED_FREQ_LOW,        1)                     \
    X_IO_CFG( IO_CFG_OUTPUT_PP_HS_DEF1,                 IO_MODE_OUTPUT,     IO_TYPE_PIN_PP,                            IO_SPEED_FREQ_HIGH,       1)                     \
/* I2Cx IO's CFG -----------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_I2C4_PORT_AF4,                     IO_MODE_ALTERNATE,  IO_TYPE_PIN_OD,                            IO_SPEED_FREQ_MEDIUM,     IO_AF4_I2C4)           \
/* LCD IO's CFG ------------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_LCD_PORT_AF14,                     IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,                            IO_SPEED_FREQ_VERY_HIGH,  IO_AF14_LTDC)          \
/* OCTOSPI IO's CFG --------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_OSPI_AF9,                          IO_MODE_ALTERNATE,  (IO_TYPE_PIN_PP | IO_TYPE_PIN_PULL_UP),    IO_SPEED_FREQ_VERY_HIGH,  IO_AF9)                \
    X_IO_CFG( IO_CFG_OSPI_AF10,                         IO_MODE_ALTERNATE,  (IO_TYPE_PIN_PP | IO_TYPE_PIN_PULL_UP),    IO_SPEED_FREQ_VERY_HIGH,  IO_AF10)               \
/* SDIO IO's CFG -----------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_SDMMC1_AF12,                       IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,                            IO_SPEED_FREQ_VERY_HIGH,  IO_AF12_SDMMC1)        \
/* SDRAM IO's CFG ----------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_SDRAM_AF12,                        IO_MODE_ALTERNATE,  (IO_TYPE_PIN_PP | IO_TYPE_PIN_PULL_UP),    IO_SPEED_FREQ_VERY_HIGH,  IO_AF12_FMC)           \
/* SPI IO's CFG ------------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_SPI_AF5,                           IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,                            IO_SPEED_FREQ_HIGH,       IO_AF5_SPI)            \
/* UART IO's CFG -----------------------------------------------------------------------------------------------------------------------------------------------------*/\
    X_IO_CFG( IO_CFG_UART1_AF7,                         IO_MODE_ALTERNATE,  IO_TYPE_PIN_PP,                            IO_SPEED_FREQ_LOW,        IO_AF7_USART1)         \
/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//-------------------------------------------------------------------------------------------------
//
//          IO_DEF(X_IO)
//
//          Parameter 1:  This is the ID of the IO pin
//          Parameter 2:  Port for the PIN
//                          GPIOx
//          Parameter 3:  IO number for the PIN
//          Parameter 4:  IO CFG to used for this pin
//
//-------------------------------------------------------------------------------------------------

#define IO_DEF(X_IO) \
/* ---------------------------------------------------------------------------------------------*/\
/*        ENUM ID of the IO,     IO Port,    IO Pin,        IO ConfigMode                       */\
/* input IO's ----------------------------------------------------------------------------------*/\
    X_IO( IO_USER_BUTTON,        GPIOC,      IO_PIN_13,     IO_CFG_INPUT_NP_LS)                   \
    X_IO( IO_SD_DETECT,          GPIOI,      IO_PIN_8,      IO_CFG_INPUT_NP_LS)                   \
/* Output IO's ---------------------------------------------------------------------------------*/\
    X_IO( IO_LED_RED,            GPIOG,      IO_PIN_11,     IO_CFG_OUTPUT_PP_LS_DEF0)             \
    X_IO( IO_LED_BLUE,           GPIOG,      IO_PIN_2,      IO_CFG_OUTPUT_PP_LS_DEF1)             \
/* SPI IO's ------------------------------------------------------------------------------------*/\
/*  X_IO( IO_SPI3_CLK,           GPIOxx,     IO_PIN_3,      IO_CFG_SPI_AF5)*/                     \
/*  X_IO( IO_SPI3_MOSI,          GPIOxx,     IO_PIN_5,      IO_CFG_SPI_AF5)    */                 \
/*  X_IO( IO_SPI1_CLK,           GPIOxx,     IO_PIN_5,      IO_CFG_SPI_AF5)      */               \
/*  X_IO( IO_SPI1_MOSI,          GPIOxx,     IO_PIN_7,      IO_CFG_SPI_AF5)        */             \
/*  X_IO( IO_SPI1_CS,            GPIOxx,     IO_PIN_9,      IO_CFG_OUTPUT_PP_HS_DEF1)*/           \
/* LCD -----------------------------------------------------------------------------------------*/\
    X_IO( IO_LCD_TFT_DISPLAY,    GPIOA,      IO_PIN_2,      IO_CFG_OUTPUT_PP_HS_DEF1)             \
    X_IO( IO_LCD_TFT_BL_CTRL,    GPIOA,      IO_PIN_1,      IO_CFG_OUTPUT_PP_HS_DEF1)             \
    X_IO( LCD_INT,               GPIOH,      IO_PIN_2,      IO_CFG_INPUT_NP_LS)                   \
/* ---------------------------------------------------------------------------------------------*/


//-------------------------------------------------------------------------------------------------
//
//  IO_GROUP is useful for pin sharing configuration and they are not used individually at run time
//  because they are control by module.
//
//    Examples: LCD, SDRAM, ETH, etc...
//
//  Notes : Some group might share same config
//
//-------------------------------------------------------------------------------------------------

//----------------------------
// I2C4 grouping configuration

#define I2C4_PIN_ON_PORT_D_ALT_4        (IO_PIN_12 | IO_PIN_13)

//---------------------------
// LCD grouping configuration

#define LCD_PIN_ON_PORT_I_ALT_14        (IO_PIN_12 | IO_PIN_13 | IO_PIN_14 | IO_PIN_15)
#define LCD_PIN_ON_PORT_J_ALT_14        (IO_PIN_ALL)
#define LCD_PIN_ON_PORT_K_ALT_14        (IO_PIN_0  | IO_PIN_1  | IO_PIN_2  | IO_PIN_3  | IO_PIN_4  | IO_PIN_5  | IO_PIN_6  | IO_PIN_7)

//-------------------------------
// OCTOSPI grouping configuration

#define OSPI_PIN_ON_PORT_B_ALT_9        (IO_PIN_2)
#define OSPI_PIN_ON_PORT_C_ALT_10       (IO_PIN_1  | IO_PIN_5)
#define OSPI_PIN_ON_PORT_D_ALT_9        (IO_PIN_11)
#define OSPI_PIN_ON_PORT_D_ALT_10       (IO_PIN_7)
#define OSPI_PIN_ON_PORT_F_ALT_10       (IO_PIN_6  | IO_PIN_7  | IO_PIN_9)
#define OSPI_PIN_ON_PORT_G_ALT_9        (IO_PIN_9)
#define OSPI_PIN_ON_PORT_G_ALT_10       (IO_PIN_6)
#define OSPI_PIN_ON_PORT_H_ALT_9        (IO_PIN_3)

//----------------------------
// SDIO grouping configuration

#define SDMMC1_PIN_ON_PORT_C_ALT12      (IO_PIN_8  | IO_PIN_9  | IO_PIN_10 | IO_PIN_11 | IO_PIN_12)
#define SDMMC1_PIN_ON_PORT_D_ALT12      (IO_PIN_2)

//-----------------------------
// SDRAM grouping configuration

#define SDRAM_PIN_ON_PORT_D_ALT_12      (IO_PIN_0  | IO_PIN_1  | IO_PIN_8  | IO_PIN_9  | IO_PIN_10 | IO_PIN_14 | IO_PIN_15)
#define SDRAM_PIN_ON_PORT_E_ALT_12      (IO_PIN_0  | IO_PIN_1  | IO_PIN_7  | IO_PIN_8  | IO_PIN_9  | IO_PIN_10 | IO_PIN_11 | IO_PIN_12 | IO_PIN_13 | IO_PIN_14 | IO_PIN_15)
#define SDRAM_PIN_ON_PORT_F_ALT_12      (IO_PIN_0  | IO_PIN_1  | IO_PIN_2  | IO_PIN_3  | IO_PIN_4  | IO_PIN_5  | IO_PIN_11 | IO_PIN_12 | IO_PIN_13 | IO_PIN_14 | IO_PIN_15)
#define SDRAM_PIN_ON_PORT_G_ALT_12      (IO_PIN_0  | IO_PIN_1  | IO_PIN_4  | IO_PIN_5  | IO_PIN_8  | IO_PIN_15)
#define SDRAM_PIN_ON_PORT_H_ALT_12      (IO_PIN_5  | IO_PIN_6  | IO_PIN_7)

//----------------------------
// UART grouping configuration
#define UART1_PIN_ON_PORT_A_ALT_7       (IO_PIN_9 | IO_PIN_10)

//-------------------------------------------------------------------------------------------------

#define IO_GROUP_DEF(X_IO_GROUP) \
/* ---------------------------------------------------------------------------------------------------------------*/\
/*              ENUM ID of the Group,       IO Port,    IO Group Pin,                   IO ConfigMode             */\
/* I2C4 ----------------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_I2C4_ON_PORT_D_ALT4,     GPIOD,      I2C4_PIN_ON_PORT_D_ALT_4,       IO_CFG_I2C4_PORT_AF4)       \
/* LCD -----------------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_LCD_ON_PORT_I,           GPIOI,      LCD_PIN_ON_PORT_I_ALT_14,       IO_CFG_LCD_PORT_AF14)       \
    X_IO_GROUP( IO_LCD_ON_PORT_J,           GPIOJ,      LCD_PIN_ON_PORT_J_ALT_14,       IO_CFG_LCD_PORT_AF14)       \
    X_IO_GROUP( IO_LCD_ON_PORT_K,           GPIOK,      LCD_PIN_ON_PORT_K_ALT_14,       IO_CFG_LCD_PORT_AF14)       \
/* OSPI ----------------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_OSPI_ON_PORT_B_ALT9,     GPIOB,      OSPI_PIN_ON_PORT_B_ALT_9,       IO_CFG_OSPI_AF9)            \
    X_IO_GROUP( IO_OSPI_ON_PORT_C_ALT10,    GPIOC,      OSPI_PIN_ON_PORT_C_ALT_10,      IO_CFG_OSPI_AF10)           \
    X_IO_GROUP( IO_OSPI_ON_PORT_D_ALT9,     GPIOD,      OSPI_PIN_ON_PORT_D_ALT_9,       IO_CFG_OSPI_AF9)            \
    X_IO_GROUP( IO_OSPI_ON_PORT_D_ALT10,    GPIOD,      OSPI_PIN_ON_PORT_D_ALT_10,      IO_CFG_OSPI_AF10)           \
    X_IO_GROUP( IO_OSPI_ON_PORT_F_ALT10,    GPIOF,      OSPI_PIN_ON_PORT_F_ALT_10,      IO_CFG_OSPI_AF10)           \
    X_IO_GROUP( IO_OSPI_ON_PORT_G_ALT9,     GPIOG,      OSPI_PIN_ON_PORT_G_ALT_9,       IO_CFG_OSPI_AF9)            \
    X_IO_GROUP( IO_OSPI_ON_PORT_G_ALT10,    GPIOG,      OSPI_PIN_ON_PORT_G_ALT_10,      IO_CFG_OSPI_AF10)           \
    X_IO_GROUP( IO_OSPI_ON_PORT_H_ALT9,     GPIOH,      OSPI_PIN_ON_PORT_H_ALT_9,       IO_CFG_OSPI_AF9)            \
/* SDIO ----------------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_SDMMC1_ON_PORT_C_AF12,   GPIOC,      SDMMC1_PIN_ON_PORT_C_ALT12,     IO_CFG_SDMMC1_AF12)         \
    X_IO_GROUP( IO_SDMMC1_ON_PORT_D_AF12,   GPIOD,      SDMMC1_PIN_ON_PORT_D_ALT12,     IO_CFG_SDMMC1_AF12)         \
/* SDRAM ---------------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_SDRAM_ON_PORT_D,         GPIOD,      SDRAM_PIN_ON_PORT_D_ALT_12,     IO_CFG_SDRAM_AF12)          \
    X_IO_GROUP( IO_SDRAM_ON_PORT_E,         GPIOE,      SDRAM_PIN_ON_PORT_E_ALT_12,     IO_CFG_SDRAM_AF12)          \
    X_IO_GROUP( IO_SDRAM_ON_PORT_F,         GPIOF,      SDRAM_PIN_ON_PORT_F_ALT_12,     IO_CFG_SDRAM_AF12)          \
    X_IO_GROUP( IO_SDRAM_ON_PORT_G,         GPIOG,      SDRAM_PIN_ON_PORT_G_ALT_12,     IO_CFG_SDRAM_AF12)          \
    X_IO_GROUP( IO_SDRAM_ON_PORT_H,         GPIOH,      SDRAM_PIN_ON_PORT_H_ALT_12,     IO_CFG_SDRAM_AF12)          \
/* UART ----------------------------------------------------------------------------------------------------------*/\
    X_IO_GROUP( IO_UART1_ON_PORT_A,         GPIOB,      UART1_PIN_ON_PORT_A_ALT_7,      IO_CFG_UART1_AF7)           \
/* ---------------------------------------------------------------------------------------------------------------*/



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
//          Parameter 4:    Priority
//
//          Parameter 5:    IO_EXTI_TRIGGER_RISING
//                          IO_EXTI_TRIGGER_FALLING
//                          IO_EXTI_TRIGGER_RISING_FALLING
//
//          Parameter 6:    Callback function pointer
//
//          Parameter 7:    Argument pointer for callback
//
//-------------------------------------------------------------------------------------------------

#if 0
#define IO_IRQ_DEF(X_IO_IRQ) \
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------*/\
/*         Enum ID                 Pin ID              EXTI Pin Source  Priority    Trigger                             CallBack                Argument    */\
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------*/\

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------*/


#endif

//-------------------------------------------------------------------------------------------------
