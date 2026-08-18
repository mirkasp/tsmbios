//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetPointingDeviceInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Built-in Pointing Device Information" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        if (SMBios->HasBuiltInPointingDeviceInfo)
        {
            for (int Index = 0; Index < SMBios->BuiltInPointingDeviceInformation.Length; ++Index)
            {
                TBuiltInPointingDeviceInformation* Info = SMBios->BuiltInPointingDeviceInformation[Index];

                std::cout << "Type              " << AnsiString(Info->GetType()).c_str() << std::endl;
                std::cout << "Interface         " << AnsiString(Info->GetInterface()).c_str() << std::endl;
                std::cout << "Number of Buttons " << static_cast<int>(Info->RAWBuiltInPointingDeviceInfo->NumberofButtons) << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Built-in Pointing Device Info was found" << std::endl;
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
        GetPointingDeviceInfo();
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
