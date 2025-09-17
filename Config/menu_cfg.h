//-------------------------------------------------------------------------------------------------
//
//  File : Menu_cfg.h
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

//-------------------------------------------------------------------------------------------------
//  Global Variable(s)
//-------------------------------------------------------------------------------------------------

#ifdef GFX_GLOBAL

const PageWidget_t PageMainDisplay     [6] =  { {   BACK_LOADING,           INVALID_LINK        },
                                                {   LABEL_SKIN_LOADING,     INVALID_LINK        },
                                                {   LABEL_TIME,             INVALID_LINK        },
                                                {   LABEL_DATE,             INVALID_LINK        },
                                                {   PROGRESS_LOADING,       INVALID_LINK        },
                                                {   INVALID_WIDGET,         INVALID_LINK        }
                                              };

//const PageWidget_t PageMainHub         [2] =  { {   VIRTUAL_MAIN_HUB,        INVALID_LINK        },
//                                                {   INVALID_WIDGET,          INVALID_LINK        }
//                                              };

#else

extern const PageWidget_t PageMainDisplay      [6];
//extern const PageWidget_t PageMainHub          [2];

#endif  // GFX_GLOBAL

//-------------------------------------------------------------------------------------------------
