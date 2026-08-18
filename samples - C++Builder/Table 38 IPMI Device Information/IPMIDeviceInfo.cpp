//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetIPMIDeviceInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "IPMI Device Information" << std::endl;
        std::cout << "-----------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 3) && SMBios->HasIPMIDeviceInfo)
        {
            for (int Index = 0; Index < SMBios->IPMIDeviceInfo.Length; ++Index)
            {
                TIPMIDeviceInformation* Info = SMBios->IPMIDeviceInfo[Index];
                std::cout << "Interface Type  " << Info->GetInterfaceTypeStr().c_str() << std::endl;
                std::cout << "IPMI Version    " << Info->GetSpecificationVersionStr().c_str() << std::endl;
                std::cout << "I2C Address     " << IntToHex(Info->RAWIPMIDeviceInfo->I2CSlaveAddress, 2).c_str() << std::endl;
                std::cout << "NV Address      " << IntToHex(Info->RAWIPMIDeviceInfo->NVStorageDeviceAddress, 2).c_str() << std::endl;
                std::cout << "Base Address    " << IntToHex(Info->RAWIPMIDeviceInfo->BaseAddress, 16).c_str() << std::endl;
                std::cout << "Interrupt       " << static_cast<int>(Info->RAWIPMIDeviceInfo->InterruptNumber) << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No IPMI Device Info was found" << std::endl;
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
        GetIPMIDeviceInfo();
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
