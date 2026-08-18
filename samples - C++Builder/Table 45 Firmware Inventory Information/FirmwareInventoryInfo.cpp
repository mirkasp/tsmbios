//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetFirmwareInventoryInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Firmware Inventory Information" << std::endl;
        std::cout << "------------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 3, 5) && SMBios->HasFirmwareInventoryInfo)
        {
            for (int TableIndex = 0; TableIndex < SMBios->FirmwareInventoryInfo.Length; ++TableIndex)
            {
                TFirmwareInventoryInformation* Info = SMBios->FirmwareInventoryInfo[TableIndex];
                std::cout << "Component       " << Info->FirmwareComponentNameStr().c_str() << std::endl;
                std::cout << "Version         " << Info->FirmwareVersionStr().c_str() << std::endl;
                std::cout << "Firmware ID     " << Info->FirmwareIDStr().c_str() << std::endl;
                std::cout << "Release Date    " << Info->ReleaseDateStr().c_str() << std::endl;
                std::cout << "Manufacturer    " << Info->ManufacturerStr().c_str() << std::endl;
                std::cout << "Lowest Version  " << Info->LowestSupportedFirmwareVersionStr().c_str() << std::endl;
                std::cout << "State           " << Info->GetStateStr().c_str() << std::endl;
                for (int Index = 0; Index < Info->RAWFirmwareInventoryInfo->AssociatedComponentCount; ++Index)
                    std::cout << "Component Handle " << IntToHex(Info->GetAssociatedComponentHandle(Index), 4).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Firmware Inventory Info was found" << std::endl;
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
        GetFirmwareInventoryInfo();
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
