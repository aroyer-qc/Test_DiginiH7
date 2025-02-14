//-------------------------------------------------------------------------------------------------
//
//  File :  uart_cfg.h
//
//-------------------------------------------------------------------------------------------------
//
// Copyright(c) 2020 Alain Royer.
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

// Enable Status will (this enable the callback)
#define UART_DRIVER_RX_PARITY_ERROR_CFG         DEF_DISABLED
#define UART_DRIVER_RX_FRAMING_ERROR_CFG        DEF_DISABLED
#define UART_DRIVER_RX_NOISE_DETECTED_CFG       DEF_DISABLED
#define UART_DRIVER_RX_OVERRUN_ERROR_CFG        DEF_DISABLED
#define UART_DRIVER_RX_IDLE_CFG                 DEF_ENABLED
#define UART_DRIVER_RX_NOT_EMPTY_CFG            DEF_DISABLED
#define UART_DRIVER_TX_COMPLETED_CFG            DEF_DISABLED            // TX complete does not work well with console.. use DMA
#define UART_DRIVER_TX_EMPTY_CFG                DEF_DISABLED
#define UART_DRIVER_DMA_TX_COMPLETED_CFG        DEF_ENABLED

#define UART_DRIVER_SUPPORT_UART1_CFG           DEF_DISABLED //DEF_ENABLED
#define UART_DRIVER_SUPPORT_UART2_CFG           DEF_DISABLED //DEF_ENABLED
#define UART_DRIVER_SUPPORT_UART3_CFG           DEF_ENABLED
#define UART_DRIVER_SUPPORT_UART4_CFG           DEF_DISABLED
#define UART_DRIVER_SUPPORT_UART5_CFG           DEF_DISABLED
#define UART_DRIVER_SUPPORT_UART6_CFG           DEF_DISABLED
#define UART_DRIVER_SUPPORT_UART7_CFG           DEF_DISABLED
#define UART_DRIVER_SUPPORT_UART8_CFG           DEF_DISABLED

#define UART_DRIVER_INTERNAL_RX_BUFFER_SIZE     64                      // this is very unsafe setting.. need to check with who is using this setting... it must be linked to the owner of the serial port

//-------------------------------------------------------------------------------------------------

#define TERMINAL_SERIAL                         UART_DRIVER_ID_3
//#define TERMINAL_SERIAL                         UART_DRIVER_ID_1

//-------------------------------------------------------------------------------------------------
