//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetMemDeviceMappedInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Memory Device Mapped Address Information" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        if (SMBios->HasMemoryDeviceMappedAddressInfo)
        {
            for (int Index = 0; Index < SMBios->MemoryDeviceMappedAddressInformation.Length; ++Index)
            {
                TMemoryDeviceMappedAddressInformation* Info = SMBios->MemoryDeviceMappedAddressInformation[Index];

                std::cout << "Starting Address      " << IntToHex(static_cast<int>(Info->RAWMemoryDeviceMappedAddressInfo->StartingAddress), 8).c_str() << std::endl;
                std::cout << "Ending   Address      " << IntToHex(static_cast<int>(Info->RAWMemoryDeviceMappedAddressInfo->EndingAddress), 8).c_str() << std::endl;
                std::cout << "Memory Device Handle  " << IntToHex(Info->RAWMemoryDeviceMappedAddressInfo->MemoryDeviceHandle, 4).c_str() << std::endl;
                std::cout << "Memory Array Mapped Address Handle "
                          << IntToHex(Info->RAWMemoryDeviceMappedAddressInfo->MemoryArrayMappedAddressHandle, 4).c_str() << std::endl;
                std::cout << "Partition Row Position  "
                          << static_cast<int>(Info->RAWMemoryDeviceMappedAddressInfo->PartitionRowPosition) << std::endl;
                std::cout << "Interleave Position     "
                          << static_cast<int>(Info->RAWMemoryDeviceMappedAddressInfo->InterleavePosition) << std::endl;
                std::cout << "Interleaved Data Depth  "
                          << static_cast<int>(Info->RAWMemoryDeviceMappedAddressInfo->InterleavedDataDepth) << std::endl;
                if (SMBiosAtLeast(SMBios, 2, 7) && Info->HasExtendedAddresses())
                {
                    std::cout << "Extended Starting Address  " << IntToHex(Info->GetExtendedStartingAddress(), 16).c_str() << std::endl;
                    std::cout << "Extended Ending   Address  " << IntToHex(Info->GetExtendedEndingAddress(), 16).c_str() << std::endl;
                }
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Memory Device Mapped Address Info was found" << std::endl;
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
        GetMemDeviceMappedInfo();
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
