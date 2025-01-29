
this is the configuration for H7






void SystemInit_ExtMemCtl(void)
{
  __IO uint32_t tmp = 0;

  register uint32_t tmpreg = 0;
  register __IO uint32_t index;

  
  
  
/*-- FMC Configuration ------------------------------------------------------*/

  /*SDRAM Timing and access interface configuration*/
  /*LoadToActiveDelay  = 2
    ExitSelfRefreshDelay = 6
    SelfRefreshTime      = 4
    RowCycleDelay        = 6
    WriteRecoveryTime    = 2
    RPDelay              = 2
    RCDDelay             = 2
    SDBank             = FMC_SDRAM_BANK2
    ColumnBitsNumber   = FMC_SDRAM_COLUMN_BITS_NUM_8            (0x00000000)
    RowBitsNumber      = FMC_SDRAM_ROW_BITS_NUM_12              (0x00000004)
    MemoryDataWidth    = FMC_SDRAM_MEM_BUS_WIDTH_16             (0x00000010)
    InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4           (0x00000040)
    CASLatency         = FMC_SDRAM_CAS_LATENCY_2                (0x00000100)
    WriteProtection    = FMC_SDRAM_WRITE_PROTECTION_DISABLE     (0x00000000)
    SDClockPeriod      = FMC_SDRAM_CLOCK_PERIOD_2               (0x00000800)
    ReadBurst          = FMC_SDRAM_RBURST_ENABLE                (0x00001000)
    ReadPipeDelay      = FMC_SDRAM_RPIPE_DELAY_0                (0x00000000) */
  FMC_Bank5_6_R->SDCR[0] = 0x00001800;
  FMC_Bank5_6_R->SDCR[1] = 0x00000154;
  
  FMC_Bank5_6_R->SDTR[0] = 0x00105000;
  FMC_Bank5_6_R->SDTR[1] = 0x01010351;


  // SDRAM initialization sequence
  FMC_Bank5_6_R->SDCMR = 0x00000009;                                // Clock enable command
  
  for (index = 0; index<5000; index++);                             // Delay

  FMC_Bank5_6_R->SDCMR = 0x0000000A;                                // PALL command
  FMC_Bank5_6_R->SDCMR = 0x000000EB;
  FMC_Bank5_6_R->SDCMR = 0x0004400C;

  SET_BIT(FMC_Bank5_6_R->SDRTR, (0x00000603 << 1));                 // Set refresh count

  /* Disable write protection */
  tmpreg = FMC_Bank5_6_R->SDCR[1];
  FMC_Bank5_6_R->SDCR[1] = (tmpreg & 0xFFFFFDFF);

  FMC_Bank1_R->BTCR[0]  |= 0x80000000;                              // FMC controller Enable
