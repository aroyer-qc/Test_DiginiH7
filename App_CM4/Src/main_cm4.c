//           The application entry point
int main(void)
{

    /* CPU2 goes to STOP mode and waits CPU1 to initialize all the steps first */
    /* CPU1 will wakeup CPU2 with semaphore take and release events */
    /* HW semaphore Clock enable */
 //   __HAL_RCC_HSEM_CLK_ENABLE();
 //   HSEM_ActivateNotification(HSEM_WAKEUP_CPU2_MASK);
  //  HAL_PWREx_ClearPendingEvent();

#ifndef DEBUG
    // In debug mode we use the free running CPU
    HAL_PWREx_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_STOPENTRY_WFE, PWR_D2_DOMAIN);
#endif

  //  HSEM_CLEAR_FLAG(HSEM_WAKEUP_CPU2_MASK);

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
   // HAL_Init();

    /* Init LED3 */
   // led_init();

#if 0
    /*
     * Wait for buffers to be ready by CPU1
     *
     * This should not wait and should go straight through
     */
    while (!ringbuff_is_ready(rb_cm4_to_cm7) || !ringbuff_is_ready(rb_cm7_to_cm4)) {}

    /* Write message to buffer */
    ringbuff_write(rb_cm4_to_cm7, "[CM4] Core ready\r\n", 18);

    /* Set default time */
    time = t1 = t2 = HAL_GetTick();
    while (1) {
        size_t len;
        void* addr;

        time = HAL_GetTick();

        /* Send data to CPU1 */
        if (time - t1 >= 1000) {
            t1 = time;
            char c = '0' + (++i % 10);

            /* Write to buffer from CPU2 to CPU1 */
            ringbuff_write(rb_cm4_to_cm7, "[CM4] Number: ", 14);
            ringbuff_write(rb_cm4_to_cm7, &c, 1);
            ringbuff_write(rb_cm4_to_cm7, "\r\n", 2);
        }

        /* Toggle LED */
        if (time - t2 >= 500) {
            t2 = time;
            HAL_GPIO_TogglePin(LD3_GPIO_PORT, LD3_GPIO_PIN);
        }

        /* Check if CPU1 sent some data to CPU2 core */
        while ((len = ringbuff_get_linear_block_read_length(rb_cm7_to_cm4)) > 0) {
            addr = ringbuff_get_linear_block_read_address(rb_cm7_to_cm4);

            /*
             * `addr` holds pointer to beginning of data array
             * which can be used directly in linear form.
             *
             * Its length is `len` bytes
             */
            /* Process data here */

            /* Mark buffer as read to allow other writes from CPU1 */
            ringbuff_skip(rb_cm7_to_cm4, len);
        }
    }
    #endif
}

