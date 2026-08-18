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

static void GetCoolingDeviceInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Cooling Device Information" << std::endl;
        std::cout << "--------------------------" << std::endl;
        if (SMBios->HasCoolingDeviceInfo)
        {
            for (int Index = 0; Index < SMBios->CoolingDeviceInformation.Length; ++Index)
            {
                TCoolingDeviceInformation* Info = SMBios->CoolingDeviceInformation[Index];

                if (Info->RAWCoolingDeviceInfo->TemperatureProbeHandle != 0xFFFF)
                    std::cout << "Temperature Probe Handle "
                              << IntToHex(Info->RAWCoolingDeviceInfo->TemperatureProbeHandle, 4).c_str() << std::endl;
                std::cout << "Device Type and Status   "
                          << ByteToBinStr(Info->RAWCoolingDeviceInfo->DeviceTypeandStatus).c_str() << std::endl;
                std::cout << "Type                     " << Info->GetDeviceType().c_str() << std::endl;
                std::cout << "Status                   " << Info->GetStatus().c_str() << std::endl;
                std::cout << "Cooling Unit Group       " << static_cast<int>(Info->RAWCoolingDeviceInfo->CoolingUnitGroup) << std::endl;
                std::cout << "OEM Specific             "
                          << IntToHex(static_cast<int>(Info->RAWCoolingDeviceInfo->OEMdefined), 8).c_str() << std::endl;
                if (Info->RAWCoolingDeviceInfo->NominalSpeed == 0x8000)
                    std::cout << "Nominal Speed            Unknown" << std::endl;
                else
                    std::cout << "Nominal Speed            " << Info->RAWCoolingDeviceInfo->NominalSpeed << " rpm" << std::endl;
                if (SMBiosAtLeast(SMBios, 2, 7) && Info->HasDescription())
                    std::cout << "Description    " << Info->GetDescriptionStr().c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Cooling Device Info was found" << std::endl;
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
        GetCoolingDeviceInfo();
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
