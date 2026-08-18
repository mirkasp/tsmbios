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

static void GetTempProbeInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Temperature Probe Information" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        if (SMBios->HasTemperatureProbeInfo)
        {
            for (int Index = 0; Index < SMBios->TemperatureProbeInformation.Length; ++Index)
            {
                TTemperatureProbeInformation* Info = SMBios->TemperatureProbeInformation[Index];

                std::cout << "Description    " << Info->GetDescriptionStr().c_str() << std::endl;
                std::cout << "Location and Status " << ByteToBinStr(Info->RAWTemperatureProbeInfo->LocationandStatus).c_str() << std::endl;
                std::cout << "Location       " << Info->GetLocation().c_str() << std::endl;
                std::cout << "Status         " << Info->GetStatus().c_str() << std::endl;
                if (Info->RAWTemperatureProbeInfo->MaximumValue == 0x8000)
                    std::cout << "Maximum Value  Unknown" << std::endl;
                else
                    std::cout << "Maximum Value  " << (Info->RAWTemperatureProbeInfo->MaximumValue / 10) << " C" << std::endl;
                if (Info->RAWTemperatureProbeInfo->MinimumValue == 0x8000)
                    std::cout << "Minimum Value  Unknown" << std::endl;
                else
                    std::cout << "Minimum Value  " << (Info->RAWTemperatureProbeInfo->MinimumValue / 10) << " C" << std::endl;
                if (Info->RAWTemperatureProbeInfo->Resolution == 0x8000)
                    std::cout << "Resolution     Unknown" << std::endl;
                else
                    std::cout << "Resolution     " << (Info->RAWTemperatureProbeInfo->Resolution / 1000) << " C" << std::endl;
                if (Info->RAWTemperatureProbeInfo->Tolerance == 0x8000)
                    std::cout << "Tolerance      Unknown" << std::endl;
                else
                    std::cout << "Tolerance      " << (Info->RAWTemperatureProbeInfo->Tolerance / 10.0) << " C" << std::endl;
                std::cout << "OEM Specific   "
                          << IntToHex(static_cast<int>(Info->RAWTemperatureProbeInfo->OEMdefined), 8).c_str() << std::endl;
                if (Info->HasNominalValue())
                {
                    if (Info->GetNominalValue() == 0x8000)
                        std::cout << "Nominal Value  Unknown" << std::endl;
                    else
                        std::cout << "Nominal Value  " << (Info->GetNominalValue() / 10) << " C" << std::endl;
                }
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Temperature Probe Info was found" << std::endl;
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
        GetTempProbeInfo();
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
