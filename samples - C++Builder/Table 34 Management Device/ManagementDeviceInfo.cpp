//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetManagementDeviceInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Management Device" << std::endl;
        std::cout << "-----------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 3) && SMBios->HasManagementDeviceInfo)
        {
            for (int Index = 0; Index < SMBios->ManagementDeviceInfo.Length; ++Index)
            {
                TManagementDeviceInformation* Info = SMBios->ManagementDeviceInfo[Index];
                std::cout << "Description   " << Info->GetDescriptionStr().c_str() << std::endl;
                std::cout << "Device Type   " << IntToHex(Info->RAWManagementDeviceInfo->DeviceType, 2).c_str()
                          << " - " << Info->GetDeviceTypeStr().c_str() << std::endl;
                std::cout << "Address       " << IntToHex(static_cast<int>(Info->RAWManagementDeviceInfo->Address), 8).c_str() << std::endl;
                std::cout << "Address Type  " << IntToHex(Info->RAWManagementDeviceInfo->AddressType, 2).c_str()
                          << " - " << Info->GetAddressTypeStr().c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Management Device Info was found" << std::endl;
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
        GetManagementDeviceInfo();
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
