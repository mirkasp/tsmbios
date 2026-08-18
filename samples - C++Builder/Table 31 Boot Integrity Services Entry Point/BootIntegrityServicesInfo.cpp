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

static void GetBootIntegrityServicesInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Boot Integrity Services Entry Point" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 3) && SMBios->HasBootIntegrityServicesEntryPointInfo)
        {
            for (int Index = 0; Index < SMBios->BootIntegrityServicesEntryPointInformation.Length; ++Index)
            {
                TBootIntegrityServicesEntryPointInformation* Info = SMBios->BootIntegrityServicesEntryPointInformation[Index];
                std::cout << "Handle                  " << IntToHex(Info->RAWBootIntegrityServicesEntryPointInfo->Header.Handle, 4).c_str() << std::endl;
                std::cout << "Length                  " << static_cast<int>(Info->RAWBootIntegrityServicesEntryPointInfo->Header.Length) << std::endl;
                std::cout << "Checksum                " << IntToHex(Info->RAWBootIntegrityServicesEntryPointInfo->Checksum, 2).c_str() << std::endl;
                std::cout << "Structure Length Valid  " << BoolText(Info->IsStructureLengthValid()) << std::endl;
                std::cout << "Checksum Valid          " << BoolText(Info->ChecksumIsValid()) << std::endl;
                std::cout << "16-bit Entry Point      " << IntToHex(Info->GetEntryPoint16Segment(), 4).c_str()
                          << ":" << IntToHex(Info->GetEntryPoint16Offset(), 4).c_str() << std::endl;
                std::cout << "16-bit Entry Valid      " << BoolText(Info->EntryPoint16IsValid()) << std::endl;
                std::cout << "32-bit Entry Point      " << IntToHex(static_cast<int>(Info->RAWBootIntegrityServicesEntryPointInfo->EntryPoint32), 8).c_str() << std::endl;
                std::cout << "32-bit Entry Valid      " << BoolText(Info->EntryPoint32IsValid()) << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Boot Integrity Services Entry Point Info was found" << std::endl;
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
        GetBootIntegrityServicesInfo();
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
