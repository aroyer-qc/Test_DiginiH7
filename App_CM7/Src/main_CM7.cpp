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

//#include "common.h"

/* Private variables ---------------------------------------------------------*/
//UART_HandleTypeDef huart3;

/* Ringbuffer variables */
//volatile ringbuff_t* rb_cm4_to_cm7 = (void *)BUFF_CM4_TO_CM7_ADDR;
//volatile ringbuff_t* rb_cm7_to_cm4 = (void *)BUFF_CM7_TO_CM4_ADDR;

/* Private function prototypes -----------------------------------------------*/
//void SystemClock_Config(void);
//static void MX_GPIO_Init(void);
//static void MX_USART3_UART_Init(void);
//static void led_init(void);

//uint32_t time, t1;


uint32_t swap(uint32_t in)
{
 //uint32_t out ;

  in = __builtin_bswap32(in);
 //out = (in >> 16) | (in << 16);
  return in;
}

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
    uint32_t testID = 0x00123456;
    uint32_t SwaptestID;
    SwaptestID = swap(testID);

//printf("allo");
  //  uint8_t* pTestID = (void*)&testID;

    ISR_Disable();
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



    #if 0

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

    /* Initialize buffers that are used as shared memory */
    ringbuff_init(rb_cm7_to_cm4, (void *)BUFFDATA_CM7_TO_CM4_ADDR, BUFFDATA_CM7_TO_CM4_LEN);
    ringbuff_init(rb_cm4_to_cm7, (void *)BUFFDATA_CM4_TO_CM7_ADDR, BUFFDATA_CM4_TO_CM7_LEN);

    /* Wakeup CPU2 */
    __HAL_RCC_HSEM_CLK_ENABLE();
    HSEM_TAKE_RELEASE(HSEM_WAKEUP_CPU2);
    WAIT_COND_WITH_TIMEOUT(__HAL_RCC_GET_FLAG(RCC_FLAG_D2CKRDY) == RESET, 0xFFFF);

    /*
     * Initialize other things, not being important for second core
     *
     * It is important to wakeup D2 domain before accessing any
     * peripherals that are linked there, otherwise clock is disabled
     * and any attempt will result to undefined write/read
     */

    /* Init LED1 */
    led_init();

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_USART3_UART_Init();

    /* Send test message */
    HAL_UART_Transmit(&huart3, (void *)"[CM7] Core ready\r\n", 18, 100);

    /* Set default time */
    time = t1 = HAL_GetTick();
    while (1) {
        size_t len;
        void* addr;

        time = HAL_GetTick();

        /* Check if CPU2 sent some data to CPU1 core */
        while ((len = ringbuff_get_linear_block_read_length(rb_cm4_to_cm7)) > 0) {
            addr = ringbuff_get_linear_block_read_address(rb_cm4_to_cm7);

            /* Transmit data */
            HAL_UART_Transmit(&huart3, addr, len, 1000);

            /* Mark buffer as read */
            ringbuff_skip(rb_cm4_to_cm7, len);
        }

        /* Toggle LED */
        if (time - t1 >= 500) {
            t1 = time;
            HAL_GPIO_TogglePin(LD1_GPIO_PORT, LD1_GPIO_PIN);
        }

        /*
         * If CPU1 wants to send data to CPU2,
         * it uses second buffer pipe, rb_cm7_to_cm4
         * is written by CPU1 and read by CPU2.
         */
        ringbuff_write(rb_cm7_to_cm4, "my_data", 7);
    }


    #endif


}

#if 0
/**
 * \brief           Initialize LEDs controlled by core
 */
void
led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    LD1_GPIO_CLK_EN();

    GPIO_InitStruct.Pin = LD1_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LD1_GPIO_PORT, &GPIO_InitStruct);
}

/**
 * \brief           System Clock Configuration
 */
void
SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

    /* Supply configuration update enable */
    HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

    /* Configure the main internal regulator output voltage */
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
    while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

    /** Initializes the CPU, AHB and APB busses clocks */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    /* Initializes the CPU, AHB and APB busses clocks */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                  | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2
                                  | RCC_CLOCKTYPE_D3PCLK1 | RCC_CLOCKTYPE_D1PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
    RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) {
        Error_Handler();
    }

    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3;
    PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_D2PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) {
        Error_Handler();
    }
}

/**
 * \brief           USART3 Initialization Function
 */
static void
MX_USART3_UART_Init(void) {
    huart3.Instance = USART3;
    huart3.Init.BaudRate = 115200;
    huart3.Init.WordLength = UART_WORDLENGTH_8B;
    huart3.Init.StopBits = UART_STOPBITS_1;
    huart3.Init.Parity = UART_PARITY_NONE;
    huart3.Init.Mode = UART_MODE_TX_RX;
    huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart3.Init.OverSampling = UART_OVERSAMPLING_16;
    huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
    huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    HAL_UART_Init(&huart3);
    HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_8);
    HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_8);
    HAL_UARTEx_DisableFifoMode(&huart3);
}

/**
 * \brief           GPIO Initialization function
 */
static void
MX_GPIO_Init(void) {
    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOD_CLK_ENABLE();
}

#endif

#if 0


/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 400000000 (CM7 CPU Clock)
  *            HCLK(Hz)                       = 200000000 (CM4 CPU, AXI and AHBs Clock)
  *            AHB Prescaler                  = 2
  *            D1 APB3 Prescaler              = 2 (APB3 Clock  100MHz)
  *            D2 APB1 Prescaler              = 2 (APB1 Clock  100MHz)
  *            D2 APB2 Prescaler              = 2 (APB2 Clock  100MHz)
  *            D3 APB4 Prescaler              = 2 (APB4 Clock  100MHz)
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 5
  *            PLL_N                          = 160
  *            PLL_P                          = 2
  *            PLL_Q                          = 4
  *            PLL_R                          = 2
  *            VDD(V)                         = 3.3
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;

  /*!< Supply configuration update enable */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.CSIState = RCC_CSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;

  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;

  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }

  /* Select PLL as system clock source and configure  bus clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_D1PCLK1 | RCC_CLOCKTYPE_PCLK1 | \
                                 RCC_CLOCKTYPE_PCLK2  | RCC_CLOCKTYPE_D3PCLK1);

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;
  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }
}

/**
  * @brief LCD Configuration.
  * @note  This function Configure the LTDC peripheral :
  *        1) Configure the Pixel Clock for the LCD
  *        2) Configure the LTDC Timing and Polarity
  *        3) Configure the LTDC Layer 1 :
  *           - indirect color (L8) as pixel format
  *           - The frame buffer is located at FLASH memory
  *           - The Layer size configuration : 320x240
  *        4) Configure the LTDC Layer 2 :
  *           - The frame buffer is located at FLASH memory
  *           - The Layer size configuration : 320x240
  *        5) Load 256 colors in CLUT address for Layer 1
  * @retval
  *  None
 */
static void LCD_Config(void)
{
  RCC_PeriphCLKInitTypeDef periph_clk_init_struct;

  LTDC_LayerCfgTypeDef      pLayerCfg;
  LTDC_LayerCfgTypeDef      pLayerCfg1;

/* LTDC Initialization -------------------------------------------------------*/

  /*## LTDC Clock Configuration ###########################################*/
  /* RK043FN48H LCD clock configuration */
  /* LCD clock configuration */
  /* PLL3_VCO Input = HSE_VALUE/PLL3M = 5 Mhz */
  /* PLL3_VCO Output = PLL3_VCO Input * PLL3N = 800 Mhz */
  /* PLLLCDCLK = PLL3_VCO Output/PLL3R = 800/83 = 9.63 Mhz */
  /* LTDC clock frequency = PLLLCDCLK = 9.63 Mhz */
  periph_clk_init_struct.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
  periph_clk_init_struct.PLL3.PLL3M = 5;
  periph_clk_init_struct.PLL3.PLL3N = 160;
  periph_clk_init_struct.PLL3.PLL3FRACN = 0;
  periph_clk_init_struct.PLL3.PLL3P = 2;
  periph_clk_init_struct.PLL3.PLL3Q = 2;
  periph_clk_init_struct.PLL3.PLL3R = 83;
  periph_clk_init_struct.PLL3.PLL3VCOSEL = RCC_PLL3VCOWIDE;
  periph_clk_init_struct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_2;
  HAL_RCCEx_PeriphCLKConfig(&periph_clk_init_struct);

  /* LTDC Initialization -------------------------------------------------------*/
  /* DeInit */
  LtdcHandle.Instance = LTDC;
  HAL_LTDC_DeInit(&LtdcHandle);

  /* Polarity configuration */
  /* Initialize the horizontal synchronization polarity as active low */
  LtdcHandle.Init.HSPolarity = LTDC_HSPOLARITY_AL;
  /* Initialize the vertical synchronization polarity as active low */
  LtdcHandle.Init.VSPolarity = LTDC_VSPOLARITY_AL;
  /* Initialize the data enable polarity as active low */
  LtdcHandle.Init.DEPolarity = LTDC_DEPOLARITY_AL;
  /* Initialize the pixel clock polarity as input pixel clock */
  LtdcHandle.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
  /* Timing configuration */
  /* The LCD AMPIRE 640x480 is selected */
  /* Timing configuration */
  LtdcHandle.Init.HorizontalSync = (RK043FN48H_HSYNC - 1);
  LtdcHandle.Init.VerticalSync = (RK043FN48H_VSYNC - 1);
  LtdcHandle.Init.AccumulatedHBP = (RK043FN48H_HSYNC + RK043FN48H_HBP - 1);
  LtdcHandle.Init.AccumulatedVBP = (RK043FN48H_VSYNC + RK043FN48H_VBP - 1);
  LtdcHandle.Init.AccumulatedActiveH = (RK043FN48H_HEIGHT + RK043FN48H_VSYNC + RK043FN48H_VBP - 1);
  LtdcHandle.Init.AccumulatedActiveW = (RK043FN48H_WIDTH + RK043FN48H_HSYNC + RK043FN48H_HBP - 1);
  LtdcHandle.Init.TotalHeigh = (RK043FN48H_HEIGHT + RK043FN48H_VSYNC + RK043FN48H_VBP + RK043FN48H_VFP - 1);
  LtdcHandle.Init.TotalWidth = (RK043FN48H_WIDTH + RK043FN48H_HSYNC + RK043FN48H_HBP + RK043FN48H_HFP - 1);

  /* Configure R,G,B component values for LCD background color */
  LtdcHandle.Init.Backcolor.Blue = 0;
  LtdcHandle.Init.Backcolor.Green = 0;
  LtdcHandle.Init.Backcolor.Red = 0;

  LtdcHandle.Instance = LTDC;

/* Layer1 Configuration ------------------------------------------------------*/

  /* Windowing configuration */
  pLayerCfg.WindowX0 = 0;
  pLayerCfg.WindowX1 = 320;
  pLayerCfg.WindowY0 = 0;
  pLayerCfg.WindowY1 = 240;

  /* Pixel Format configuration*/
  pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_L8;

  /* Start Address configuration : frame buffer is located at FLASH memory */
  pLayerCfg.FBStartAdress = (uint32_t)&L8_320x240;

  /* Alpha constant (255 totally opaque) */
  pLayerCfg.Alpha = 255;

  /* Default Color configuration (configure A,R,G,B component values) */
  pLayerCfg.Alpha0 = 0;
  pLayerCfg.Backcolor.Blue = 0;
  pLayerCfg.Backcolor.Green = 0;
  pLayerCfg.Backcolor.Red = 0;

  /* Configure blending factors */
  pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_PAxCA;
  pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_PAxCA;

  /* Configure the number of lines and number of pixels per line */
  pLayerCfg.ImageWidth = 320;
  pLayerCfg.ImageHeight = 240;

/* Layer2 Configuration ------------------------------------------------------*/

  /* Windowing configuration */
  pLayerCfg1.WindowX0 = 160;
  pLayerCfg1.WindowX1 = 480;
  pLayerCfg1.WindowY0 = 32;
  pLayerCfg1.WindowY1 = 272;

  /* Pixel Format configuration*/
  pLayerCfg1.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;

  /* Start Address configuration : frame buffer is located at FLASH memory */
  pLayerCfg1.FBStartAdress = (uint32_t)&RGB565_320x240;

  /* Alpha constant (255 totally opaque) */
  pLayerCfg1.Alpha = 200;

  /* Default Color configuration (configure A,R,G,B component values) */
  pLayerCfg1.Alpha0 = 0;
  pLayerCfg1.Backcolor.Blue = 0;
  pLayerCfg1.Backcolor.Green = 0;
  pLayerCfg1.Backcolor.Red = 0;

  /* Configure blending factors */
  pLayerCfg1.BlendingFactor1 = LTDC_BLENDING_FACTOR1_PAxCA;
  pLayerCfg1.BlendingFactor2 = LTDC_BLENDING_FACTOR2_PAxCA;

  /* Configure the number of lines and number of pixels per line */
  pLayerCfg1.ImageWidth = 320;
  pLayerCfg1.ImageHeight = 240;

  /* Configure the LTDC */
  if(HAL_LTDC_Init(&LtdcHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /* Configure the Background Layer*/
  if(HAL_LTDC_ConfigLayer(&LtdcHandle, &pLayerCfg, 0) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /* Configure the Foreground Layer*/
  if(HAL_LTDC_ConfigLayer(&LtdcHandle, &pLayerCfg1, 1) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
}

#endif

