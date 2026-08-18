//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetMemArrayMappedInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Memory Array Mapped Address Information" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        if (SMBios->HasMemoryArrayMappedAddressInfo)
        {
            for (int Index = 0; Index < SMBios->MemoryArrayMappedAddressInformation.Length; ++Index)
            {
                TMemoryArrayMappedAddressInformation* Info = SMBios->MemoryArrayMappedAddressInformation[Index];

                std::cout << "Starting Address    " << IntToHex(static_cast<int>(Info->RAWMemoryArrayMappedAddressInfo->StartingAddress), 8).c_str() << std::endl;
                std::cout << "Ending   Address    " << IntToHex(static_cast<int>(Info->RAWMemoryArrayMappedAddressInfo->EndingAddress), 8).c_str() << std::endl;
                std::cout << "Memory Array Handle " << IntToHex(Info->RAWMemoryArrayMappedAddressInfo->MemoryArrayHandle, 4).c_str() << std::endl;
                std::cout << "Partition Width     " << static_cast<int>(Info->RAWMemoryArrayMappedAddressInfo->PartitionWidth) << std::endl;
                if (SMBiosAtLeast(SMBios, 2, 7) && Info->HasExtendedAddresses())
                {
                    std::cout << "Extended Starting Address  " << IntToHex(Info->GetExtendedStartingAddress(), 16).c_str() << std::endl;
                    std::cout << "Extended Ending   Address  " << IntToHex(Info->GetExtendedEndingAddress(), 16).c_str() << std::endl;
                }
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Memory Array Mapped Address Info was found" << std::endl;
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
        GetMemArrayMappedInfo();
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
