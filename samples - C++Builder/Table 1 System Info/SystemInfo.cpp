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

static void GetSystemInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        TSystemInformation* LSystem = SMBios->SysInfo;

        std::cout << "System Information" << std::endl;
        WriteLine("Manufacter    ", LSystem->ManufacturerStr());
        WriteLine("Product Name  ", LSystem->ProductNameStr());
        WriteLine("Version       ", LSystem->VersionStr());
        WriteLine("Serial Number ", LSystem->SerialNumberStr());

        if (LSystem->HasUUID())
            WriteLine("UUID          ", LSystem->UUIDStr());

        if (LSystem->HasWakeUpType())
            WriteLine("Wake-up Type  ", LSystem->WakeUpTypeStr());

        if (SMBiosAtLeast(SMBios, 2, 4))
        {
            if (LSystem->HasSKUNumber())
                WriteLine("SKU Number    ", LSystem->SKUNumberStr());
            if (LSystem->HasFamily())
                WriteLine("Family        ", LSystem->FamilyStr());
        }

        std::cout << std::endl;
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
        GetSystemInfo();
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
