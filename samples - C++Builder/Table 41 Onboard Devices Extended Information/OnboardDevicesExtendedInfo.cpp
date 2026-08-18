//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static const char* BoolText(bool Value)
{
    return Value ? "True" : "False";
}

static void GetOnboardDevicesExtendedInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Onboard Devices Extended Information" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 6) && SMBios->HasOnboardDevicesExtendedInfo)
        {
            for (int Index = 0; Index < SMBios->OnboardDevicesExtendedInfo.Length; ++Index)
            {
                TOnboardDevicesExtendedInformation* Info = SMBios->OnboardDevicesExtendedInfo[Index];
                std::cout << "Designation     " << Info->ReferenceDesignationStr().c_str() << std::endl;
                std::cout << "Device Type     " << Info->GetDeviceTypeStr().c_str() << std::endl;
                std::cout << "Enabled         " << BoolText(Info->Enabled()) << std::endl;
                std::cout << "Type Instance   " << static_cast<int>(Info->RAWOnboardDevicesExtendedInfo->DeviceTypeInstance) << std::endl;
                std::cout << "PCI Location    " << IntToHex(Info->RAWOnboardDevicesExtendedInfo->SegmentGroupNumber, 4).c_str()
                          << ":" << IntToHex(Info->RAWOnboardDevicesExtendedInfo->BusNumber, 2).c_str()
                          << ":" << IntToHex(Info->GetDeviceNumber(), 2).c_str()
                          << "." << static_cast<int>(Info->GetFunctionNumber()) << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Onboard Devices Extended Info was found" << std::endl;
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
        GetOnboardDevicesExtendedInfo();
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
