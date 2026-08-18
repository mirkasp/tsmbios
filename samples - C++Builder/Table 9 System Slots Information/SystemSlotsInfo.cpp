//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <bitset>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static AnsiString ByteToBinStr(System::Byte Value)
{
    return AnsiString(std::bitset<8>(Value).to_string().c_str());
}

//---------------------------------------------------------------------------

static void GetSystemSlotInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "System Slot Information" << std::endl;
        std::cout << "--------------------------" << std::endl;
        if (SMBios->HasSystemSlotInfo)
        {
            for (int Index = 0; Index < SMBios->SystemSlotInfo.Length; ++Index)
            {
                TSystemSlotInformation* LSlot = SMBios->SystemSlotInfo[Index];

                std::cout << "Slot Designation    " << LSlot->SlotDesignationStr().c_str() << std::endl;
                std::cout << "Slot Type           " << LSlot->GetSlotType().c_str() << std::endl;
                std::cout << "Slot Data Bus Width " << LSlot->GetSlotDataBusWidth().c_str() << std::endl;
                std::cout << "Current Usage       " << LSlot->GetCurrentUsage().c_str() << std::endl;
                std::cout << "Slot Length         " << LSlot->GetSlotLength().c_str() << std::endl;
                std::cout << "Slot ID             " << IntToHex(LSlot->RAWSystemSlotInformation->SlotID, 4).c_str() << std::endl;
                std::cout << "Characteristics 1   "
                          << ByteToBinStr(LSlot->RAWSystemSlotInformation->SlotCharacteristics1).c_str() << std::endl;
                std::cout << "Characteristics 2   "
                          << ByteToBinStr(LSlot->RAWSystemSlotInformation->SlotCharacteristics2).c_str() << std::endl;

                if (SMBiosAtLeast(SMBios, 2, 6))
                {
                    std::cout << "Segment Group Number "
                              << IntToHex(LSlot->RAWSystemSlotInformation->SegmentGroupNumber, 4).c_str() << std::endl;
                    std::cout << "Bus Number           "
                              << static_cast<int>(LSlot->RAWSystemSlotInformation->BusNumber) << std::endl;
                }

                if (SMBiosAtLeast(SMBios, 3, 2) && LSlot->HasDataBusWidth() && LSlot->HasPeerGroupingCount())
                {
                    std::cout << "Data Bus Width       " << static_cast<int>(LSlot->GetDataBusWidth()) << std::endl;
                    std::cout << "Peer Grouping Count  " << static_cast<int>(LSlot->GetPeerGroupingCount()) << std::endl;
                }

                std::cout << std::endl;
            }
        }
        else
            std::cout << "No System Slot  Info was found" << std::endl;
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
        GetSystemSlotInfo();
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
