//-------------------------------------------------------------------------------------------------
//
//  File : taskTest1.cpp
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
// Include file(s)
//-------------------------------------------------------------------------------------------------

#include "./lib_digini.h"

#define TASK_TEST1_GLOBAL
#include "taskTest1.h"
#undef  TASK_TEST1_GLOBAL

//-------------------------------------------------------------------------------------------------
//
//   Static Variables
//
//-------------------------------------------------------------------------------------------------

nOS_Thread ClassTest1::m_Test1Handle;
nOS_Stack  ClassTest1::m_Test1Stack[TASK_TEST1_STACK_SIZE];

//-------------------------------------------------------------------------------------------------
//
//  Name:           TaskNetwork_Wrapper
//
//  Parameter(s):   void* pvParameters
//  Return:         void
//
//  Description:    main() for the taskNetwork
//
//-------------------------------------------------------------------------------------------------
extern "C" void TaskTest1_Wrapper(void* pvParameters)
{
    (static_cast<ClassTest1*>(pvParameters))->Run();
}


//-------------------------------------------------------------------------------------------------
//
//  Name:           Initialize
//
//  Parameter(s):   void
//  Return:         SystemState_e
//
//-------------------------------------------------------------------------------------------------


SystemState_e ClassTest1::Initialize(void)
{
    nOS_Error Error = NOS_OK;

  #if (DIGINI_USE_STACKTISTIC == DEF_ENABLED)
    myStacktistic.Register(&m_Test1Stack[0], TASK_TEST1_STACK_SIZE, "Test 1");
  #endif

    Error = nOS_ThreadCreate(&m_Test1Handle,
                             TaskTest1_Wrapper,
                             this,
                             &m_Test1Stack[0],
                             TASK_TEST1_STACK_SIZE,
                             TASK_TEST1_PRIO
                            );

    nOS_SemCreate(&m_TestSem, 0, 1);

    return (Error != NOS_OK) ? SYS_ERROR : SYS_READY;  // TODO  improve error handling
}

//-------------------------------------------------------------------------------------------------
//
//  Name:           Run
//
//  Parameter(s):   void
//  Return:         void
//
//  Description:    main() loop of Test1 task
//
//  Note(s):
//
//-------------------------------------------------------------------------------------------------
void ClassTest1::Run(void)
{
    while(1)
    {
        while(nOS_SemTake(&m_TestSem, NOS_WAIT_INFINITE) != NOS_OK){};
        
      #ifdef KIT_7B3LI
        IO_TogglePin(IO_LED_BLUE);
      #else
        IO_TogglePin(IO_LED_GREEN);
      #endif
    }
}

//-------------------------------------------------------------------------------------------------
