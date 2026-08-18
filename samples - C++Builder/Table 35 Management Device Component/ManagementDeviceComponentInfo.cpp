//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetManagementDeviceComponentInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Management Device Component" << std::endl;
        std::cout << "---------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 3) && SMBios->HasManagementDeviceComponentInfo)
        {
            for (int Index = 0; Index < SMBios->ManagementDeviceComponentInfo.Length; ++Index)
            {
                TManagementDeviceComponentInformation* Info = SMBios->ManagementDeviceComponentInfo[Index];
                std::cout << "Description               " << Info->GetDescriptionStr().c_str() << std::endl;
                std::cout << "Management Device Handle  " << IntToHex(Info->RAWManagementDeviceComponentInfo->ManagementDeviceHandle, 4).c_str() << std::endl;
                std::cout << "Component Handle          " << IntToHex(Info->RAWManagementDeviceComponentInfo->ComponentHandle, 4).c_str() << std::endl;
                std::cout << "Threshold Handle          " << IntToHex(Info->RAWManagementDeviceComponentInfo->ThresholdHandle, 4).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Management Device Component Info was found" << std::endl;
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
        GetManagementDeviceComponentInfo();
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
