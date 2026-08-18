//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetSystemConfInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        if (SMBios->HasSystemConfInfo)
        {
            std::cout << "System Config Strings" << std::endl;
            std::cout << "---------------------" << std::endl;
            for (int TableIndex = 0; TableIndex < SMBios->SystemConfInfo.Length; ++TableIndex)
            {
                TSystemConfInformation* LSystemConf = SMBios->SystemConfInfo[TableIndex];
                for (int Index = 1; Index <= LSystemConf->RAWSystemConfInformation->Count; ++Index)
                    std::cout << LSystemConf->GetConfString(Index).c_str() << std::endl;
            }
        }
        else
            std::cout << "No System Config Strings were found" << std::endl;
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
        GetSystemConfInfo();
    }
    catch (Exception& E)
    {
        std::cout << AnsiString(E.ClassName()).c_str() << ": " << AnsiString(E.Message).c_str() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Press Enter to exit" << std::endl;
    std::cin.get();
    return 0;
}

//---------------------------------------------------------------------------
