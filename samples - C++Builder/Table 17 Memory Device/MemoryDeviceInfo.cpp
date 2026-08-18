//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void WritePhysicalMemoryArray(TPhysicalMemoryArrayInformation* Info)
{
    std::cout << "  Physical Memory Array" << std::endl;
    std::cout << "  ---------------------" << std::endl;
    std::cout << "  Location         " << Info->GetLocationStr().c_str() << std::endl;
    std::cout << "  Use              " << Info->GetUseStr().c_str() << std::endl;
    std::cout << "  Error Correction " << Info->GetErrorCorrectionStr().c_str() << std::endl;
    if (Info->RAWPhysicalMemoryArrayInformation->MaximumCapacity != 0x80000000)
        std::cout << "  Maximum Capacity " << Info->RAWPhysicalMemoryArrayInformation->MaximumCapacity << " Kb" << std::endl;
    else if (Info->HasExtendedMaximumCapacity())
        std::cout << "  Maximum Capacity " << Info->GetExtendedMaximumCapacity() << " bytes" << std::endl;
    else
        std::cout << "  Maximum Capacity Unknown" << std::endl;
    std::cout << "  Memory devices   " << Info->RAWPhysicalMemoryArrayInformation->NumberofMemoryDevices << std::endl;
}

//---------------------------------------------------------------------------

static void GetMemoryDeviceInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Memory Device Information" << std::endl;
        std::cout << "-------------------------" << std::endl;
        if (SMBios->HasMemoryDeviceInfo)
        {
            for (int Index = 0; Index < SMBios->MemoryDeviceInfo.Length; ++Index)
            {
                TMemoryDeviceInformation* LMemoryDevice = SMBios->MemoryDeviceInfo[Index];

                std::cout << "Total Width    " << LMemoryDevice->RAWMemoryDeviceInfo->TotalWidth << " bits" << std::endl;
                std::cout << "Data Width     " << LMemoryDevice->RAWMemoryDeviceInfo->DataWidth << " bits" << std::endl;
                std::cout << "Size           " << LMemoryDevice->GetSize() << " Mbytes" << std::endl;
                std::cout << "Form Factor    " << LMemoryDevice->GetFormFactor().c_str() << std::endl;
                std::cout << "Device Locator " << LMemoryDevice->GetDeviceLocatorStr().c_str() << std::endl;
                std::cout << "Bank Locator   " << LMemoryDevice->GetBankLocatorStr().c_str() << std::endl;
                std::cout << "Memory Type    " << LMemoryDevice->GetMemoryTypeStr().c_str() << std::endl;
                std::cout << "Speed          " << LMemoryDevice->GetSpeed() << " MT/s" << std::endl;
                if (SMBiosAtLeast(SMBios, 2, 7) && LMemoryDevice->HasConfiguredMemorySpeed())
                    std::cout << "Configured Speed " << LMemoryDevice->GetConfiguredMemorySpeed() << " MT/s" << std::endl;
                if (SMBiosAtLeast(SMBios, 3, 2))
                {
                    if (LMemoryDevice->HasMemoryTechnology())
                        std::cout << "Technology     " << LMemoryDevice->GetMemoryTechnologyStr().c_str() << std::endl;
                    if (LMemoryDevice->HasFirmwareVersion())
                        std::cout << "Firmware       " << LMemoryDevice->FirmwareVersionStr().c_str() << std::endl;
                    if (LMemoryDevice->HasNonVolatileSize())
                        std::cout << "Non-Volatile   " << LMemoryDevice->GetNonVolatileSize() << " bytes" << std::endl;
                    if (LMemoryDevice->HasVolatileSize())
                        std::cout << "Volatile       " << LMemoryDevice->GetVolatileSize() << " bytes" << std::endl;
                    if (LMemoryDevice->HasCacheSize())
                        std::cout << "Cache          " << LMemoryDevice->GetCacheSize() << " bytes" << std::endl;
                    if (LMemoryDevice->HasLogicalSize())
                        std::cout << "Logical        " << LMemoryDevice->GetLogicalSize() << " bytes" << std::endl;
                }
                if (SMBiosAtLeast(SMBios, 3, 7) && LMemoryDevice->HasPMIC0())
                {
                    std::cout << "PMIC0 Manufacturer ID " << IntToHex(LMemoryDevice->GetPMIC0ManufacturerID(), 4).c_str() << std::endl;
                    std::cout << "PMIC0 Revision Number " << IntToHex(LMemoryDevice->GetPMIC0RevisionNumber(), 4).c_str() << std::endl;
                }
                if (SMBiosAtLeast(SMBios, 3, 7) && LMemoryDevice->HasRCD())
                {
                    std::cout << "RCD Manufacturer ID   " << IntToHex(LMemoryDevice->GetRCDManufacturerID(), 4).c_str() << std::endl;
                    std::cout << "RCD Revision Number   " << IntToHex(LMemoryDevice->GetRCDRevisionNumber(), 4).c_str() << std::endl;
                }
                std::cout << "Manufacturer   " << LMemoryDevice->ManufacturerStr().c_str() << std::endl;
                std::cout << "Serial Number  " << LMemoryDevice->SerialNumberStr().c_str() << std::endl;
                std::cout << "Asset Tag      " << LMemoryDevice->AssetTagStr().c_str() << std::endl;
                std::cout << "Part Number    " << LMemoryDevice->PartNumberStr().c_str() << std::endl;
                std::cout << std::endl;

                if (LMemoryDevice->PhysicalMemoryArray != NULL)
                    WritePhysicalMemoryArray(LMemoryDevice->PhysicalMemoryArray);
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Memory Device Info was found" << std::endl;
    }
    __finally
    {
        delete SMBios;
    }
}

//---------------------------------------------------------------------------

int main()
{
    try
    {
        GetMemoryDeviceInfo();
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
