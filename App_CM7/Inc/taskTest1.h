//-------------------------------------------------------------------------------------------------
//
//  File : taskTest1.h
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
// Global Macro
//-------------------------------------------------------------------------------------------------

#ifdef TASK_TEST1_GLOBAL
    #define TASK_TEST1_EXTERN
#else
    #define TASK_TEST1_EXTERN extern
#endif

//-------------------------------------------------------------------------------------------------
// Define(s)
//-------------------------------------------------------------------------------------------------

#define TASK_TEST1_STACK_SIZE               256
#define TASK_TEST1_PRIO                     4

//-------------------------------------------------------------------------------------------------
// Class definition(s)
//-------------------------------------------------------------------------------------------------

class ClassTest1
{
  public:


    // Task
    void            Run                         (void);
    SystemState_e   Initialize                  (void);
    void            GiveToRunTest1              (void)     { nOS_SemGive(&m_TestSem); }

  private:

    static nOS_Thread      m_Test1Handle;
    static nOS_Stack       m_Test1Stack         [TASK_TEST1_STACK_SIZE];
    nOS_Sem                m_TestSem;
};

//-------------------------------------------------------------------------------------------------
// Global variable(s) and constant(s)
//-------------------------------------------------------------------------------------------------

TASK_TEST1_EXTERN   class ClassTest1    TaskTest1;

#ifdef TASK_TEST1_GLOBAL
                    class ClassTest1*   pTaskTest1 = &TaskTest1;
#else
    extern          class ClassTest1*   pTaskTest1;
#endif

//-------------------------------------------------------------------------------------------------
// Function prototype(s)
//-------------------------------------------------------------------------------------------------

extern "C" void TaskTest1_Wrapper           (void* pvParameters);

//-------------------------------------------------------------------------------------------------
