//-------------------------------------------------------------------------------------------------
//
//  File :  sdram_cfg.h
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

// SDRAM Timing (Value 1 to 16)
#define CFG_SDRAM_LOAD_TO_ACTIVITY_DELAY        2   // Delay between a 'load mode register' command and an 'active' or 'refresh' command
#define CFG_SDRAM_EXIT_SELF_REFRESH_DELAY       6   // Delay from releasing the 'self-refresh' command to issuing the 'activate' command 
#define CFG_SDRAM_SELF_REFRESH_TIME             4   // Minimum self-refresh period
#define CFG_SDRAM_ROW_CYCLE_DELAY               6   // Delay between the 'refresh' command and the Activate command, as well as the delay between two consecutive 'refresh' command
#define CFG_SDRAM_WRITE_RECOVERY_TIME           2   // Delay between a 'write' and a 'precharge' command
#define CFG_SDRAM_RP_DELAY                      2   // Delay between a precharge command and another command
#define CFG_SDRAM_RCD_DELAY                     2   // Delay between the 'activate' command and a Read/Write command

#define CFG_SDRAM_AUTO_REFRESH_CYCLE            8   // Auto refresh cycle

#define CFG_SDRAM_MRD_WRITE_BURST_MODE          FMC_SDRAM_MRD_WRITE_BURST_MODE_SINGLE
#define CFG_SDRAM_MRD_OPERATION_MODE            FMC_SDRAM_MRD_OPERATION_MODE_STANDARD
#define CFG_SDRAM_MRD_CAS_LATENCY               FMC_SDRAM_MRD_CAS_LATENCY_2
#define CFG_SDRAM_MRD_BURST_TYPE                FMC_SDRAM_MRD_BURST_TYPE_SEQUENTIAL
#define CFG_SDRAM_MRD_BURST_LENGTH              FMC_SDRAM_MRD_BURST_LENGTH_1

// SDRAM access interface configuration
#define CFG_SDRAM_BANK                          FMC_SDRAM_BANK2
#define CFG_COLUMN_BITS_NUMBER                  FMC_SDRAM_COLUMN_BITS_NUM_8              
#define CFG_ROW_BITS_NUMBER                     FMC_SDRAM_ROW_BITS_NUM_12
#define CFG_MEMORY_DATA_WIDTH                   FMC_SDRAM_MEM_BUS_WIDTH_16
#define CFG_INTERNAL_BANK_NUMBER                FMC_SDRAM_INTERN_BANKS_NUM_4
#define CFG_SDRAM_CAS_LATENCY                   FMC_SDRAM_CAS_LATENCY_2

#define CFG_WRITE_PROTECTION                    FMC_SDRAM_WRITE_PROTECTION_DISABLE
#define CFG_SD_CLOCK_PERIOD                     FMC_SDRAM_CLOCK_PERIOD_2
#define CFG_READ_BURST                          FMC_SDRAM_RBURST_ENABLE
#define CFG_PIPE_DELAY                          FMC_SDRAM_RPIPE_DELAY_0

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
                                                                ------------
                                                      total     (0x00000154)
    
    WriteProtection    = FMC_SDRAM_WRITE_PROTECTION_DISABLE     (0x00000000)
    SDClockPeriod      = FMC_SDRAM_CLOCK_PERIOD_2               (0x00000800)
    ReadBurst          = FMC_SDRAM_RBURST_ENABLE                (0x00001000)
    ReadPipeDelay      = FMC_SDRAM_RPIPE_DELAY_0                (0x00000000)
                                                                ------------
                                                      total     (0x00001800) */  
  
   
  /*
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

  // Disable write protection
  tmpreg = FMC_Bank5_6_R->SDCR[1];
  FMC_Bank5_6_R->SDCR[1] = (tmpreg & 0xFFFFFDFF);

  FMC_Bank1_R->BTCR[0]  |= 0x80000000;                              // FMC controller Enable

*/
