//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static const char* BoolText(bool Value)
{
    return Value ? "True" : "False";
}

//---------------------------------------------------------------------------

static void GetOnBoardSystemInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "OnBoard System Information" << std::endl;
        std::cout << "--------------------------" << std::endl;
        if (SMBios->HasOnBoardSystemInfo)
        {
            for (int Index = 0; Index < SMBios->OnBoardSystemInfo.Length; ++Index)
            {
                TOnBoardSystemInformation* LOnBoardSystem = SMBios->OnBoardSystemInfo[Index];

                std::cout << "Device Type           "
                          << static_cast<int>(LOnBoardSystem->RAWOnBoardSystemInfo->DeviceType) << std::endl;
                std::cout << "Description           " << LOnBoardSystem->GetDescription().c_str() << std::endl;
                std::cout << "Enabled               " << BoolText(LOnBoardSystem->Enabled()) << std::endl;
                std::cout << "Device Type Descr.    " << LOnBoardSystem->GetTypeDescription().c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No OnBoard System Info was found" << std::endl;
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
        GetOnBoardSystemInfo();
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
