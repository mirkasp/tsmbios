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

static void GetElectricalCurrProbeInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Electrical Current Probe Information" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        if (SMBios->HasElectricalCurrentProbeInfo)
        {
            for (int Index = 0; Index < SMBios->ElectricalCurrentProbeInformation.Length; ++Index)
            {
                TElectricalCurrentProbeInformation* Info = SMBios->ElectricalCurrentProbeInformation[Index];

                std::cout << "Description    " << Info->GetDescriptionStr().c_str() << std::endl;
                std::cout << "Location and Status "
                          << ByteToBinStr(Info->RAWElectricalCurrentProbeInfo->LocationandStatus).c_str() << std::endl;
                std::cout << "Location       " << Info->GetLocation().c_str() << std::endl;
                std::cout << "Status         " << Info->GetStatus().c_str() << std::endl;
                if (Info->RAWElectricalCurrentProbeInfo->MaximumValue == 0x8000)
                    std::cout << "Maximum Value  Unknown" << std::endl;
                else
                    std::cout << "Maximum Value  " << Info->RAWElectricalCurrentProbeInfo->MaximumValue << " milliamps." << std::endl;
                if (Info->RAWElectricalCurrentProbeInfo->MinimumValue == 0x8000)
                    std::cout << "Minimum Value  Unknown" << std::endl;
                else
                    std::cout << "Minimum Value  " << Info->RAWElectricalCurrentProbeInfo->MinimumValue << " milliamps." << std::endl;
                if (Info->RAWElectricalCurrentProbeInfo->Resolution == 0x8000)
                    std::cout << "Resolution     Unknown" << std::endl;
                else
                    std::cout << "Resolution     " << (Info->RAWElectricalCurrentProbeInfo->Resolution / 10) << " milliamps." << std::endl;
                if (Info->RAWElectricalCurrentProbeInfo->Tolerance == 0x8000)
                    std::cout << "Tolerance      Unknown" << std::endl;
                else
                    std::cout << "Tolerance      " << Info->RAWElectricalCurrentProbeInfo->Tolerance << " milliamps." << std::endl;
                std::cout << "OEM Specific   "
                          << IntToHex(static_cast<int>(Info->RAWElectricalCurrentProbeInfo->OEMdefined), 8).c_str() << std::endl;
                if (Info->HasNominalValue())
                {
                    if (Info->GetNominalValue() == 0x8000)
                        std::cout << "Nominal Value  Unknown" << std::endl;
                    else
                        std::cout << "Nominal Value  " << Info->GetNominalValue() << " milliamps." << std::endl;
                }
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Electrical Current Probe Info was found" << std::endl;
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
        GetElectricalCurrProbeInfo();
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
