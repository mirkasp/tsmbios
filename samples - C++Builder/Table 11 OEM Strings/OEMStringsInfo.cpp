//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetOEMStringsInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "OEM Strings Information" << std::endl;
        std::cout << "-----------------------" << std::endl;
        if (SMBios->HasOEMStringsInfo)
        {
            for (int TableIndex = 0; TableIndex < SMBios->OEMStringsInfo.Length; ++TableIndex)
            {
                TOEMStringsInformation* LOEMStrings = SMBios->OEMStringsInfo[TableIndex];
                for (int Index = 1; Index <= LOEMStrings->RAWOEMStringsInformation->Count; ++Index)
                {
                    AnsiString Value = LOEMStrings->GetOEMString(Index);
                    if (Value != "")
                        std::cout << "OEM String " << Index << "  " << Value.c_str() << std::endl;
                }
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No OEM Strings Info was found" << std::endl;
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
        GetOEMStringsInfo();
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
