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

static void GetBIOSInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        TBiosInformation* LBIOS = SMBios->BiosInfo;

        std::cout << "Bios Information" << std::endl;
        WriteLine("Vendor        ", LBIOS->VendorStr());
        WriteLine("Version       ", LBIOS->VersionStr());
        std::cout << "Start Segment " << IntToHex(LBIOS->RAWBiosInformation->StartingSegment, 4).c_str() << std::endl;
        WriteLine("ReleaseDate   ", LBIOS->ReleaseDateStr());

        if (SMBiosAtLeast(SMBios, 3, 1) &&
            (LBIOS->RAWBiosInformation->BiosRomSize == 0xFF) &&
            LBIOS->HasExtendedBiosRomSize())
            std::cout << "Bios Rom Size " << LBIOS->GetExtendedBiosRomSize() << std::endl;
        else
            std::cout << "Bios Rom Size " << (64 * (LBIOS->RAWBiosInformation->BiosRomSize + 1)) << " k" << std::endl;

        if (LBIOS->RAWBiosInformation->SystemBIOSMajorRelease != 0xFF)
            std::cout << "System BIOS Major Release " << static_cast<int>(LBIOS->RAWBiosInformation->SystemBIOSMajorRelease) << std::endl;
        if (LBIOS->RAWBiosInformation->SystemBIOSMinorRelease != 0xFF)
            std::cout << "System BIOS Minor Release " << static_cast<int>(LBIOS->RAWBiosInformation->SystemBIOSMinorRelease) << std::endl;

        if (LBIOS->RAWBiosInformation->EmbeddedControllerFirmwareMajorRelease != 0xFF)
            std::cout << "Embedded Controller Firmware Major Release "
                      << static_cast<int>(LBIOS->RAWBiosInformation->EmbeddedControllerFirmwareMajorRelease) << std::endl;
        if (LBIOS->RAWBiosInformation->EmbeddedControllerFirmwareMinorRelease != 0xFF)
            std::cout << "Embedded Controller Firmware Minor Release "
                      << static_cast<int>(LBIOS->RAWBiosInformation->EmbeddedControllerFirmwareMinorRelease) << std::endl;

        std::cout << std::endl;

        if (SMBios->HasOEMStringsInfo)
        {
            std::cout << "OEM Strings" << std::endl;
            std::cout << "-----------" << std::endl;
            for (int TableIndex = 0; TableIndex < SMBios->OEMStringsInfo.Length; ++TableIndex)
            {
                TOEMStringsInformation* OEMStr = SMBios->OEMStringsInfo[TableIndex];
                for (int Index = 1; Index <= OEMStr->RAWOEMStringsInformation->Count; ++Index)
                    std::cout << OEMStr->GetOEMString(Index).c_str() << std::endl;
            }
        }
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
        GetBIOSInfo();
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
