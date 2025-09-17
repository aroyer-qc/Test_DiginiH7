//-------------------------------------------------------------------------------------------------
//
//  File :  hyper_ram_var.h
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

//-------------------------------------------------------------------------------------------------
// Constant(s)
//-------------------------------------------------------------------------------------------------

#ifdef HYPER_RAM_DRIVER_GLOBAL

// S70KL1281 memory used on the STM32H735-DK
const HYPER_RAM_Info_t HYPER_RAM_Info =
{
    .pInstance              = OCTOSPI2,
    .FifoThreshold          = 4,
    .DeviceSize             = 24,                               // Hyper Ram Size   24 bits = 16Mb
    .ChipSelectHighTime     = 8,
    .ClockPrescaler         = 4,
    .SampleShifting         = OSPI_SAMPLE_SHIFTING_NONE,
    .DelayHoldQuarterCycle  = OSPI_DHQC_ENABLE,
    .DelayBlockBypass       = OSPI_DELAY_BLOCK_USED,
    .ChipSelectBoundary     = 23,
    .Refresh                = 250,

    .RW_RecoveryTime        = 3,
    .AccessTime             = 6,
    .WriteZeroLatency       = OSPI_LATENCY_ON_WRITE,
    .LatencyMode            = OSPI_FIXED_LATENCY,

    .DQS_Mode               = OSPI_DQS_ENABLE,
    .Address                = 0,
    .NbData                 = 1,

    .TimeOutActivation      = OSPI_TIMEOUT_COUNTER_DISABLE,
};

#else // HYPER_RAM_DRIVER_GLOBAL

extern const HYPER_RAM_Info_t HYPER_RAM_Info;

#endif // HYPER_RAM_DRIVER_GLOBAL

//-------------------------------------------------------------------------------------------------
