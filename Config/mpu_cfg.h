//-------------------------------------------------------------------------------------------------
//
//  File :mpu_cfg.h
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
// Global Define(s)
//-------------------------------------------------------------------------------------------------

#define MPU_DEF(X_MPU)	\
	X_MPU(MPU_REGION_0, 0x00000000, MPU_SIZE_4GB,  	MPU_REGION_NO_ACCESS, 	MPU_ACCESS_NOT_BUFFERABLE, MPU_ACCESS_NOT_CACHEABLE, 	MPU_ACCESS_SHAREABLE, 		MPU_TEX_LEVEL_0,	MPU_INSTRUCTION_ACCESS_DISABLE, 0x87)	\
	X_MPU(MPU_REGION_1, 0xD0000000, MPU_SIZE_16MB, 	MPU_REGION_FULL_ACCESS, MPU_ACCESS_BUFFERABLE,     MPU_ACCESS_CACHEABLE,     	MPU_ACCESS_NOT_SHAREABLE,	MPU_TEX_LEVEL_0, 	MPU_INSTRUCTION_ACCESS_ENABLE, 	0x00)	\

//-------------------------------------------------------------------------------------------------
