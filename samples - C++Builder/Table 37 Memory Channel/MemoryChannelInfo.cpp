//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetMemoryChannelInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Memory Channel" << std::endl;
        std::cout << "--------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 3) && SMBios->HasMemoryChannelInfo)
        {
            for (int TableIndex = 0; TableIndex < SMBios->MemoryChannelInfo.Length; ++TableIndex)
            {
                TMemoryChannelInformation* Info = SMBios->MemoryChannelInfo[TableIndex];
                std::cout << "Channel Type          " << IntToHex(Info->RAWMemoryChannelInfo->ChannelType, 2).c_str()
                          << " - " << Info->GetChannelTypeStr().c_str() << std::endl;
                std::cout << "Maximum Channel Load  " << static_cast<int>(Info->RAWMemoryChannelInfo->MaximumChannelLoad) << std::endl;
                std::cout << "Memory Device Count   " << static_cast<int>(Info->RAWMemoryChannelInfo->MemoryDeviceCount) << std::endl;
                for (int Index = 0; Index < Info->RAWMemoryChannelInfo->MemoryDeviceCount; ++Index)
                    if (Info->HasMemoryDeviceEntry(Index))
                        std::cout << "Device " << Index << " Load/Handle  "
                                  << static_cast<int>(Info->GetMemoryDeviceLoad(Index)) << " / "
                                  << IntToHex(Info->GetMemoryDeviceHandle(Index), 4).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Memory Channel Info was found" << std::endl;
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
        GetMemoryChannelInfo();
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
