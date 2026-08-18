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

static void WriteWordOrUnknown(const char* Caption, System::Word Value, const char* Suffix)
{
    if (Value == 0x8000)
        std::cout << Caption << "Unknown" << std::endl;
    else
        std::cout << Caption << Value << Suffix << std::endl;
}

//---------------------------------------------------------------------------

static void GetVoltageProbeInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Voltage Probe Information" << std::endl;
        std::cout << "-------------------------" << std::endl;
        if (SMBios->HasVoltageProbeInfo)
        {
            for (int Index = 0; Index < SMBios->VoltageProbeInformation.Length; ++Index)
            {
                TVoltageProbeInformation* Info = SMBios->VoltageProbeInformation[Index];

                std::cout << "Description    " << Info->GetDescriptionStr().c_str() << std::endl;
                std::cout << "Location and Status " << ByteToBinStr(Info->RAWVoltageProbeInfo->LocationandStatus).c_str() << std::endl;
                std::cout << "Location       " << Info->GetLocation().c_str() << std::endl;
                std::cout << "Status         " << Info->GetStatus().c_str() << std::endl;
                WriteWordOrUnknown("Maximum Value  ", Info->RAWVoltageProbeInfo->MaximumValue, "");
                WriteWordOrUnknown("Minimum Value  ", Info->RAWVoltageProbeInfo->MinimumValue, "");
                WriteWordOrUnknown("Resolution     ", Info->RAWVoltageProbeInfo->Resolution, "");
                WriteWordOrUnknown("Tolerance      ", Info->RAWVoltageProbeInfo->Tolerance, "");
                std::cout << "OEM Specific   " << IntToHex(static_cast<int>(Info->RAWVoltageProbeInfo->OEMdefined), 8).c_str() << std::endl;
                if (Info->HasNominalValue())
                    WriteWordOrUnknown("Nominal Value  ", Info->GetNominalValue(), "");
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Voltage Probe Info was found" << std::endl;
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
        GetVoltageProbeInfo();
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
