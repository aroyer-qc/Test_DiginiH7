//-------------------------------------------------------------------------------------------------
//
//  File :  uart_var.h
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
//
//  Notes : UART variables for STM32H7xx
//
//  For each UART, any DMA_REQUEST in DMA 1 can be used. But only only once per DMA Stream.
//
//-------------------------------------------------------------------------------------------------

#ifdef UART_DRIVER_GLOBAL

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define UART_STANDARD_CONFIGURATION_RX ( DMA_MODE_CIRCULAR              | \
                                         DMA_PERIPHERAL_TO_MEMORY       | \
                                         DMA_PERIPHERAL_NO_INCREMENT    | \
                                         DMA_MEMORY_INCREMENT           | \
                                         DMA_PERIPHERAL_SIZE_8_BITS     | \
                                         DMA_MEMORY_SIZE_8_BITS         | \
                                         DMA_PERIPHERAL_BURST_SINGLE    | \
                                         DMA_MEMORY_BURST_SINGLE        | \
                                         DMA_PRIORITY_LEVEL_HIGH)

#define UART_STANDARD_CONFIGURATION_TX ( DMA_MODE_NORMAL                | \
                                         DMA_MEMORY_TO_PERIPHERAL       | \
                                         DMA_PERIPHERAL_NO_INCREMENT    | \
                                         DMA_MEMORY_INCREMENT           | \
                                         DMA_PERIPHERAL_SIZE_8_BITS     | \
                                         DMA_MEMORY_SIZE_8_BITS         | \
                                         DMA_PERIPHERAL_BURST_SINGLE    | \
                                         DMA_MEMORY_BURST_SINGLE        | \
                                         DMA_PRIORITY_LEVEL_HIGH)

//-------------------------------------------------------------------------------------------------
// Constant(s)
//-------------------------------------------------------------------------------------------------

const UART_Info_t UART_Info[NB_OF_UART_DRIVER] =
{
  #if (UART_DRIVER_SUPPORT_UART1_CFG == DEF_ENABLED)
    {
        USART1,                                             // USARTx
        USART1_IRQn,                                        // IRQn_Channel
        7,                                                  // PreempPrio
        UART_Config_e(UART_CFG_N_8_1 | UART_CFG_OVER_8 | UART_CFG_ENABLE_RX_TX),
        UART_BAUD_115200,
        UART_WAIT_ON_BUSY,


         // DMA_RX
        {
            UART_STANDARD_CONFIGURATION_RX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_USART1_RX,
            0,                                              // RX_IT_Flag
            (uint32_t*)DMA1_Stream2,                        // RX_DMA_TypeDef
            ISR_IRQn_NONE,                                  // RX_IRQn
        },

        // DMA_TX
        {
            UART_STANDARD_CONFIGURATION_TX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_USART1_TX,
            DMA_LIFCR_CTCIF3,                               // TX_IT_Flag
            (uint32_t*)DMA1_Stream3,                        // TX_DMA_TypeDef
            DMA1_Stream3_IRQn,                              // TX_IRQn
            4,
        },
    },
  #endif

  #if (UART_DRIVER_SUPPORT_UART2_CFG == DEF_ENABLED)
    {
        USART2,                                             // USARTx
        USART2_IRQn,                                        // IRQn_Channel
        7,                                                  // PreempPrio
        UART_Config_e(UART_CFG_N_8_1),
        UART_BAUD_115200,
        UART_WAIT_ON_BUSY,

        // DMA_RX
        {
            UART_STANDARD_CONFIGURATION_RX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_USART2_RX,
            0,                                              // RX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // RX_DMA_TypeDef
            ISR_IRQn_NONE,                                  // RX_IRQn
        },

        // DMA_TX
        {
            UART_STANDARD_CONFIGURATION_TX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_USART2_TX,
            DMA_xIFCR_CTCIFx,                               // TX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // TX_DMA_TypeDef
            DMA1_Streamx_IRQn,                              // TX_IRQn
        },
    },
  #endif

  #if (UART_DRIVER_SUPPORT_UART3_CFG == DEF_ENABLED)
    {
        USART3,                                             // USARTx
        USART3_IRQn,                                        // IRQn_Channel
        7,                                                  // PreempPrio
        UART_Config_e(UART_CFG_N_8_1 | UART_CFG_OVER_8 | UART_CFG_ENABLE_RX_TX),
        UART_BAUD_115200,
        UART_WAIT_ON_BUSY,

        // DMA_RX
        {
            UART_STANDARD_CONFIGURATION_RX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_USART3_RX,
            0,                                              // RX_IT_Flag
            (uint32_t*)DMA1_Stream0,                        // RX_DMA_TypeDef
            ISR_IRQn_NONE,                                  // RX_IRQn
        },

        // DMA_TX
        {
            UART_STANDARD_CONFIGURATION_TX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_USART3_TX,                          // MUX Request
            DMA_LIFCR_CTCIF1,                               // TX_IT_Flag
            (uint32_t*)DMA1_Stream1,                        // DMA Stream or BDMA Channel
            DMA1_Stream1_IRQn,                              // TX_IRQn
        },
    },
  #endif

  #if (UART_DRIVER_SUPPORT_UART4_CFG == DEF_ENABLED)
    {
        UART4,                                              // USARTx
        USART4_IRQn,                                        // IRQn_Channel
        7,                                                  // PreempPrio
        UART_Config_e(UART_CFG_N_8_1 | UART_CFG_ENABLE_RX_TX),
        UART_BAUD_115200,
        UART_WAIT_ON_BUSY,

        // DMA_RX
        {
            UART_STANDARD_CONFIGURATION_RX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_UART4_RX,
            0,                                              // RX_IT_Flag
            DMA_xIFCR_CTCIFx,                               // RX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // RX_DMA_TypeDef
            ISR_IRQn_NONE,                                  // RX_IRQn
        },

        // DMA_TX
        {
            UART_STANDARD_CONFIGURATION_TX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_UART4_TX,
            DMA_xIFCR_CTCIFx,                               // TX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // TX_DMA_TypeDef
            DMA1_Streamx_IRQn,                              // TX_IRQn
        },
    },
  #endif

  #if (UART_DRIVER_SUPPORT_UART5_CFG == DEF_ENABLED)
    {
        UART5,                                              // USARTx
        UART5_IRQn,                                         // IRQn_Channel
        7,                                                  // PreempPrio
        UART_Config_e(UART_CFG_N_8_1 | UART_CFG_ENABLE_RX_TX),
        UART_BAUD_115200,
        UART_WAIT_ON_BUSY,

        // DMA_RX
        {
            UART_STANDARD_CONFIGURATION_RX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_UART5_RX,
            0,                                              // RX_IT_Flag
            DMA_xIFCR_CTCIFx,                               // RX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // RX_DMA_TypeDef
            ISR_IRQn_NONE,                                  // RX_IRQn
        },

        // DMA_TX
        {
            UART_STANDARD_CONFIGURATION_TX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_UART5_TX,
            DMA_xIFCR_CTCIFx,                               // TX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // TX_DMA_TypeDef
            DMA1_Streamx_IRQn,                              // TX_IRQn
        },
    },
  #endif

  #if (UART_DRIVER_SUPPORT_UART6_CFG == DEF_ENABLED)
    {
        USART6,                                             // USARTx
        ISR_IRQn_NONE,                                      // IRQn_Channel
        7,                                                  // PreempPrio
        UART_Config_e(TEST_CONFIG | UART_CFG_ENABLE_TX),
        UART_BAUD_115200,
        UART_WAIT_ON_BUSY,

        // DMA_RX
        {
            UART_STANDARD_CONFIGURATION_RX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_USART6_RX,
            0,                                              // RX_IT_Flag
            DMA_xIFCR_CTCIFx,                               // RX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // RX_DMA_TypeDef
            ISR_IRQn_NONE,                                  // RX_IRQn
        },

        // DMA_TX
        {
            UART_STANDARD_CONFIGURATION_TX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_USART6_TX,
            DMA_xIFCR_CTCIFx,                               // TX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // TX_DMA_TypeDef
            DMA1_Streamx_IRQn,                              // TX_IRQn
        },
    },
  #endif

  #if (UART_DRIVER_SUPPORT_UART7_CFG == DEF_ENABLED)
    {
        UART7,                                              // USARTx
        UART7_IRQn,                                         // IRQn_Channel
        7,                                                  // PreempPrio
        UART_Config_e(UART_CFG_N_8_1),
        UART_BAUD_115200,
        UART_WAIT_ON_BUSY,

        // DMA_RX
        {
            UART_STANDARD_CONFIGURATION_RX,                 // Configuration
            DMA_REQUEST_UART7_RX,
            0,                                              // RX_IT_Flag
            DMA_xIFCR_CTCIFx,                               // RX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // RX_DMA_TypeDef
            ISR_IRQn_NONE,                                  // RX_IRQn
        },

        // DMA_TX
        {
            UART_STANDARD_CONFIGURATION_TX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_UART7_TX,
            DMA_xIFCR_CTCIFx,                               // TX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // TX_DMA_TypeDef
            DMA1_Streamx_IRQn,                              // TX_IRQn
        },
    },
  #endif

  #if (UART_DRIVER_SUPPORT_UART8_CFG == DEF_ENABLED)
    {
        UART8,                                              // USARTx
        UART8_IRQn,                                         // IRQn_Channel
        7,                                                  // PreempPrio
        UART_Config_e(UART_CFG_N_8_1),
        UART_BAUD_115200,
        UART_WAIT_ON_BUSY,

        // DMA_RX
        {
            UART_STANDARD_CONFIGURATION_RX,                 // Configuration
            DMA_REQUEST_UART8_RX,
            0,                                              // RX_IT_Flag
            DMA_xIFCR_CTCIFx,                               // RX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // RX_DMA_TypeDef
            ISR_IRQn_NONE,                                  // RX_IRQn
        },

        // DMA_TX
        {
            UART_STANDARD_CONFIGURATION_TX,                 // Configuration
            DMA_FIFOMODE_DISABLE,                           // FIFO Config
            DMA_REQUEST_UART8_TX,
            DMA_xIFCR_CTCIFx,                               // TX_IT_Flag
            (uint32_t*)DMA1_Streamx,                        // TX_DMA_TypeDef
            DMA1_Streamx_IRQn,                              // TX_IRQn
        },
    },
  #endif
};

//-------------------------------------------------------------------------------------------------

class UART_Driver myUART_Terminal(TERMINAL_SERIAL);

#else // UART_DRIVER_GLOBAL

extern class UART_Driver myUART_Terminal;

#endif // UART_DRIVER_GLOBAL

//-------------------------------------------------------------------------------------------------
