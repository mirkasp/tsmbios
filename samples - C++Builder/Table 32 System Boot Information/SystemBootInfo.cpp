//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetSystemBootInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "System Boot Information" << std::endl;
        std::cout << "-----------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 3) && SMBios->HasSystemBootInfo)
        {
            for (int TableIndex = 0; TableIndex < SMBios->SystemBootInfo.Length; ++TableIndex)
            {
                TSystemBootInformation* Info = SMBios->SystemBootInfo[TableIndex];
                std::cout << "Boot Status                  " << IntToHex(Info->RAWSystemBootInfo->BootStatus, 2).c_str()
                          << " - " << Info->GetBootStatusStr().c_str() << std::endl;
                for (int Index = 0; Index < 9; ++Index)
                    std::cout << "Boot Status Additional Data " << Index << "  "
                              << IntToHex(Info->GetBootStatusAdditionalDataByte(Index), 2).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No System Boot Info was found" << std::endl;
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
        GetSystemBootInfo();
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
