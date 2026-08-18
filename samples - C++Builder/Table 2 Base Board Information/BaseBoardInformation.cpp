//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <bitset>
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

static AnsiString ByteToBinStr(System::Byte Value)
{
    return AnsiString(std::bitset<8>(Value).to_string().c_str());
}

//---------------------------------------------------------------------------

static void GetBaseBoardInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Base Board Information" << std::endl;
        if (SMBios->HasBaseBoardInfo)
        {
            for (int Index = 0; Index < SMBios->BaseBoardInfo.Length; ++Index)
            {
                TBaseBoardInformation* LBaseBoard = SMBios->BaseBoardInfo[Index];

                WriteLine("Manufacter          ", LBaseBoard->ManufacturerStr());
                WriteLine("Product             ", LBaseBoard->ProductStr());
                WriteLine("Version             ", LBaseBoard->VersionStr());
                WriteLine("Serial Number       ", LBaseBoard->SerialNumberStr());
                WriteLine("Asset Tag           ", LBaseBoard->AssetTagStr());
                WriteLine("Feature Flags       ", ByteToBinStr(LBaseBoard->RAWBaseBoardInformation->FeatureFlags));
                WriteLine("Location in Chassis ", LBaseBoard->LocationinChassisStr());
                std::cout << "Chassis Handle      "
                          << IntToHex(LBaseBoard->RAWBaseBoardInformation->ChassisHandle, 4).c_str() << std::endl;
                std::cout << "Board Type          "
                          << IntToHex(LBaseBoard->RAWBaseBoardInformation->BoardType, 2).c_str() << " "
                          << LBaseBoard->BoardTypeStr().c_str() << std::endl;
                std::cout << "Number of Contained Object Handles "
                          << static_cast<int>(LBaseBoard->RAWBaseBoardInformation->NumberofContainedObjectHandles)
                          << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Base Board Info was found" << std::endl;
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
        GetBaseBoardInfo();
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
