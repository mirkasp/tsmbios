//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetTPMDeviceInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "TPM Device Information" << std::endl;
        std::cout << "----------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 3, 1) && SMBios->HasTPMDeviceInfo)
        {
            for (int Index = 0; Index < SMBios->TPMDeviceInfo.Length; ++Index)
            {
                TTPMDeviceInformation* Info = SMBios->TPMDeviceInfo[Index];
                std::cout << "Vendor ID       " << Info->VendorIDStr().c_str() << std::endl;
                std::cout << "TPM Version     " << Info->GetSpecificationVersionStr().c_str() << std::endl;
                std::cout << "Firmware 1      " << IntToHex(static_cast<int>(Info->RAWTPMDeviceInfo->FirmwareVersion1), 8).c_str() << std::endl;
                std::cout << "Firmware 2      " << IntToHex(static_cast<int>(Info->RAWTPMDeviceInfo->FirmwareVersion2), 8).c_str() << std::endl;
                std::cout << "Description     " << Info->DescriptionStr().c_str() << std::endl;
                std::cout << "OEM Defined     " << IntToHex(static_cast<int>(Info->RAWTPMDeviceInfo->OEMDefined), 8).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No TPM Device Info was found" << std::endl;
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
        GetTPMDeviceInfo();
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
