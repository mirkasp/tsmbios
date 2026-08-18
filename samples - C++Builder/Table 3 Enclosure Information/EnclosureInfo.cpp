//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void WriteLine(const char* Caption, const AnsiString& Value)
{
    std::cout << Caption << Value.c_str() << std::endl;
}

//---------------------------------------------------------------------------

static void GetEnclosureInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Enclosure Information" << std::endl;
        if (SMBios->HasEnclosureInfo)
        {
            for (int Index = 0; Index < SMBios->EnclosureInfo.Length; ++Index)
            {
                TEnclosureInformation* LEnclosure = SMBios->EnclosureInfo[Index];

                WriteLine("Manufacter         ", LEnclosure->ManufacturerStr());
                WriteLine("Version            ", LEnclosure->VersionStr());
                WriteLine("Serial Number      ", LEnclosure->SerialNumberStr());
                WriteLine("Asset Tag Number   ", LEnclosure->AssetTagNumberStr());
                WriteLine("Type               ", LEnclosure->TypeStr());
                WriteLine("Power Supply State ", LEnclosure->PowerSupplyStateStr());
                WriteLine("BootUp State       ", LEnclosure->BootUpStateStr());
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Enclosure Info was found" << std::endl;
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
        GetEnclosureInfo();
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
