//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetManagementDeviceThresholdInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Management Device Threshold Data" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 3) && SMBios->HasManagementDeviceThresholdDataInfo)
        {
            for (int Index = 0; Index < SMBios->ManagementDeviceThresholdDataInfo.Length; ++Index)
            {
                TManagementDeviceThresholdDataInformation* Info = SMBios->ManagementDeviceThresholdDataInfo[Index];
                std::cout << "Lower Non-critical      " << Info->RAWManagementDeviceThresholdDataInfo->LowerThresholdNonCritical << std::endl;
                std::cout << "Upper Non-critical      " << Info->RAWManagementDeviceThresholdDataInfo->UpperThresholdNonCritical << std::endl;
                std::cout << "Lower Critical          " << Info->RAWManagementDeviceThresholdDataInfo->LowerThresholdCritical << std::endl;
                std::cout << "Upper Critical          " << Info->RAWManagementDeviceThresholdDataInfo->UpperThresholdCritical << std::endl;
                std::cout << "Lower Non-recoverable   " << Info->RAWManagementDeviceThresholdDataInfo->LowerThresholdNonRecoverable << std::endl;
                std::cout << "Upper Non-recoverable   " << Info->RAWManagementDeviceThresholdDataInfo->UpperThresholdNonRecoverable << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Management Device Threshold Data Info was found" << std::endl;
    }
    __finally
    {
        delete SMBios;
    }
}

int main()
{
    try
    {
        GetManagementDeviceThresholdInfo();
    }
    catch (Exception& E)
    {
        std::cout << AnsiString(E.ClassName()).c_str() << ": " << AnsiString(E.Message).c_str() << std::endl;
    }

    std::cout << "Press Enter to exit" << std::endl;
    std::cin.get();
    return 0;
}

//---------------------------------------------------------------------------
