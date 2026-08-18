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

static void GetBIOSLanguageInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "BIOS Language Information" << std::endl;
        if (SMBios->HasBIOSLanguageInfo)
        {
            for (int TableIndex = 0; TableIndex < SMBios->BIOSLanguageInfo.Length; ++TableIndex)
            {
                TBIOSLanguageInformation* LBIOSLng = SMBios->BIOSLanguageInfo[TableIndex];

                std::cout << "Installable Languages  "
                          << static_cast<int>(LBIOSLng->RAWBIOSLanguageInformation->InstallableLanguages) << std::endl;
                std::cout << "Flags                  "
                          << ByteToBinStr(LBIOSLng->RAWBIOSLanguageInformation->Flags).c_str() << std::endl;
                std::cout << "Current Language       " << LBIOSLng->GetCurrentLanguageStr().c_str() << std::endl;

                if (LBIOSLng->RAWBIOSLanguageInformation->InstallableLanguages > 1)
                {
                    std::cout << "BIOS Languages" << std::endl;
                    std::cout << "--------------" << std::endl;
                    for (int Index = 1; Index <= LBIOSLng->RAWBIOSLanguageInformation->InstallableLanguages; ++Index)
                        std::cout << "  " << LBIOSLng->GetLanguageString(Index).c_str() << std::endl;
                }

                std::cout << std::endl;
            }
        }
        else
            std::cout << "No BIOS Language Info was found" << std::endl;
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
        GetBIOSLanguageInfo();
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
