//-------------------------------------------------------------------------------------------------
//
//  File : service.cpp
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

/*

Service type 2 - Return data array compose of 16 bits value. Array size define by SERVICE_TYPE2_SIZE_LIST
Service type 3 - Return link to new page
                        INVALID_LINK  - that instruct GUI to do nothing
                        REMOVE_WIDGET - remove the widget from the list of widget to refresh
Service type 4 - Return string array pointer. Array size define by SERVICE_TYPE4_SIZE_LIST
Service type 5 - Return data for an image -> Address, Size, Pixel format
Service type 6 - Return data to override position of a widget
Service type 7 - Return data to override position of a widget (Must be a memory block by allocation, it will be freed by widget)
*/

//-------------------------------------------------------------------------------------------------
// Include file(s)
//-------------------------------------------------------------------------------------------------`

#include "lib_digini.h"
#ifdef DIGINI_USE_GRAFX

//-------------------------------------------------------------------------------------------------
//
//  Name:           SERV_COVR
//
//  Parameter(s):   ServiceEvent_e*  pServiceState
//  Return          ServiceReturn_t
//
//  Description:    This function return data to display spectrum audio analyzer, 16 x 12
//
//-------------------------------------------------------------------------------------------------
/*
static ServiceReturn_t* SERV_COVR(ServiceEvent_e* pServiceState)
{
static uint16_t Count;
ImageInfo_t ImageInfo;

    ServiceReturn_t* pService = nullptr;

    if(*pServiceState != SERVICE_FINALIZE)
    {
        // if(A_NewIsToBeDisplayed == true)
        {

Count++;
if(Count >= 1000)
{
    Count = 0;
}

if((Count % 500) == 0)
{
            pService = GetServiceStruct(SERVICE_RETURN_TYPE5, 0);
            if(pService != nullptr)
            {


if(Count <= 250) DB_Central.Get(&ImageInfo, GFX_IMAGE_INFO, COVER_QUEEN_1, 0);
else             DB_Central.Get(&ImageInfo, GFX_IMAGE_INFO, COVER_QUEEN_2, 0);

               ((ServiceType5_t*)pService)->pAddress    = ImageInfo.pPointer;
               ((ServiceType5_t*)pService)->Size.Width  = 100,
               ((ServiceType5_t*)pService)->Size.Height = 100,
               ((ServiceType5_t*)pService)->PixelFormat = ARGB8888;

                *pServiceState = SERVICE_REFRESH;
            }

}
        }
    }

    return pService;
}
*/

//-------------------------------------------------------------------------------------------------
//
//  Name:           SERV_SPEK
//
//  Parameter(s):   ServiceEvent_e*  pServiceState
//  Return          ServiceReturn_t
//
//  Description:    This function return data to display spectrum audio analyzer, 16 x 12
//
//-------------------------------------------------------------------------------------------------
/*
uint8_t spectrum[20][16] =
{
    { 12, 4,  3, 2, 3, 4, 1, 1, 1, 2, 3, 3, 4, 4,  10, 5 },
    { 10, 12, 5, 4, 4, 5, 2, 2, 2, 3, 3, 3, 4, 4,  8, 3 },
    { 10, 12, 5, 5, 5, 5, 3, 3, 3, 4, 4, 5, 7, 12, 7, 2 },
    { 5,  9,  6, 6, 7, 3, 4, 3, 2, 4, 4, 4, 4, 4,  2, 1 },
    { 5,  7,  5, 5, 6, 4, 5, 4, 4, 5, 5, 5, 5, 4,  2, 4 },
    { 4,  6,  4, 4, 5, 4, 6, 5, 5, 6, 6, 5, 5, 4,  2, 4 },
    { 3,  5,  3, 3, 4, 5, 7, 5, 4, 5, 4, 3, 2, 1,  2, 5 },
    { 2,  2,  2, 2, 3, 2, 8, 4, 3, 4, 3, 2, 1, 0,  2, 4 },
    { 4,  1,  3, 1, 2, 3, 4, 5, 5, 6, 5, 5, 4, 4,  2, 3 },
    { 7,  4,  4, 2, 3, 2, 5, 5, 6, 7, 6, 6, 5, 4,  2, 2 },
    { 10, 6,  5, 3, 4, 3, 6, 4, 2, 3, 3, 3, 4, 4,  8, 5 },
    { 12, 10, 7, 4, 5, 5, 7, 4, 3, 4, 4, 4, 4, 4,  10, 6 },
    { 10, 12, 8, 7, 8, 5, 8, 6, 4, 7, 8, 9, 11, 12, 12, 5 },
    { 6,  12, 9, 4, 5, 6, 4, 4, 5, 6, 6, 5, 5, 4,  11, 2 },
    { 4,  8,  5, 3, 5, 2, 5, 4, 3, 4, 4, 4, 4, 4,  7, 4 },
    { 3,  4,  6, 2, 4, 3, 6, 5, 4, 5, 5, 5, 5, 4,  3, 4 },
    { 2,  3,  4, 1, 3, 4, 7, 6, 5, 6, 4, 3, 2, 1,  2, 5 },
    { 1,  2,  3, 2, 2, 5, 8, 5, 3, 7, 5, 3, 1, 0,  2, 4 },
    { 2,  1,  2, 3, 5, 6, 1, 2, 2, 2, 3, 3, 3, 4,  3, 4 },
    { 3,  0,  1, 5, 7, 2, 2, 3, 4, 5, 4, 4, 4, 4,  1, 3 },
};


static ServiceReturn_t* SERV_SPEK(ServiceEvent_e* pServiceState)
{
    static uint8_t* pDataSpectrum;
    static uint8_t Count  = 0;

    ServiceReturn_t* pService = nullptr;

    if(*pServiceState == SERVICE_REFRESH)
    {
        pService = GetServiceStruct(SERVICE_RETURN_TYPE7, 0);
        if(pService != nullptr)
        {
            Count++;
            if(Count>=20)Count = 0;

            for(int i = 0; i < 16; i++)
            {
                *(pDataSpectrum + i) = spectrum[Count][i];
            }

            ((ServiceType7_t*)pService)->pData = (void*)pDataSpectrum;
            ((ServiceType7_t*)pService)->Size  = 16;
            *pServiceState = SERVICE_REFRESH;
        }
    }
    else if(*pServiceState == SERVICE_START)
    {
        pDataSpectrum = (uint8_t*)pMemory->Alloc(sizeof(ServiceType7_t));
        pService      = GetServiceStruct(SERVICE_RETURN_TYPE7, 0);
        if(pService != nullptr)
        {
            for(int i = 0; i < 16; i++)
            {
                (*(pDataSpectrum + i)) = i;
                if(*(pDataSpectrum + i) > 12)
                {
                    *(pDataSpectrum + i) = 6 - i;
                }
            }

            ((ServiceType7_t*)pService)->pData = (void*)pDataSpectrum;
            ((ServiceType7_t*)pService)->Size  = 16;
        }
    }
    else if(*pServiceState == SERVICE_FINALIZE)
    {
        pMemory->Free((void**)&pDataSpectrum);
    }

    return pService;
}
*/

//-------------------------------------------------------------------------------------------------
//
//  Name:           SERV_VOLU
//
//  Parameter(s):   ServiceEvent_e*  pServiceState
//  Return          ServiceReturn_t
//
//  Description:    This function return data to display spectrum audio analyzer, 16 x 12
//
//-------------------------------------------------------------------------------------------------
/*
static ServiceReturn_t* SERV_VOLU(ServiceEvent_e* pServiceState)
{
    static uint8_t Count;

    ServiceReturn_t* pService = nullptr;

    if(*pServiceState != SERVICE_FINALIZE)
    {
        pService = GetServiceStruct(SERVICE_RETURN, 0);
        if(*pServiceState != SERVICE_PRESSED)
        {
            if(pService != nullptr)
            {
                Count++;

                if(Count > 10 && Count < 15)
                {
                    pService->IndexState = 2;
                }
                else
                {
                    pService->IndexState = 0;
                }

                if(Count > 15) Count = 0;


                *pServiceState = SERVICE_REFRESH;
            }
        }
    }

    return pService;
}
*/

//-------------------------------------------------------------------------------------------------
//
//  Name:           ServiceCallApp
//  Parameter(s):   Service_t*       pService
//                  ServiceEvent_e*  pServiceState
//  Return:         ServiceReturn_t
//
//  Description:    Callback service provided for application side
//
//  Note(s):        Will Call any service from TaskGUI that are not generic
//
//-------------------------------------------------------------------------------------------------
ServiceReturn_t* ServiceCallApp(Service_t* pService, ServiceEvent_e* pServiceState)
{
    ServiceReturn_t* pServiceReturn = nullptr;
    struct32_t       ServiceRange;

    ServiceRange.u_32 = pService->ID;

    switch(ServiceRange.u8_Array[0])        // To speed up process
    {
        case 'C':
        {
            switch(pService->ID)
            {
//                case SERV_ID_COVR:  pServiceReturn = SERV_COVR(pServiceState);  break;
            }
            break;
        }

        case 'S':
        {
            switch(pService->ID)
            {
//                case SERV_ID_SPEK:  pServiceReturn = SERV_SPEK(pServiceState);  break;
            }
            break;
        }

        case 'V':
        {
            switch(pService->ID)
            {
//                case SERV_ID_VOLU:  pServiceReturn = SERV_VOLU(pServiceState);  break;
            }
            break;
        }
    }

    return pServiceReturn;
}


//-------------------------------------------------------------------------------------------------

#endif // DIGINI_USE_GRAFX
