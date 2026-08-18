//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetBatteryInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Battery Information" << std::endl;
        std::cout << "-------------------" << std::endl;
        if (SMBios->HasBatteryInfo)
        {
            for (int Index = 0; Index < SMBios->BatteryInformation.Length; ++Index)
            {
                TBatteryInformation* Info = SMBios->BatteryInformation[Index];

                std::cout << "Location           " << Info->GetLocationStr().c_str() << std::endl;
                std::cout << "Manufacturer       " << Info->GetManufacturerStr().c_str() << std::endl;
                std::cout << "Manufacturer Date  " << Info->GetManufacturerDateStr().c_str() << std::endl;
                std::cout << "Serial Number      " << Info->GetSerialNumberStr().c_str() << std::endl;
                std::cout << "Device Name        " << Info->GetDeviceNameStr().c_str() << std::endl;
                std::cout << "Device Chemistry   " << Info->GetDeviceChemistry().c_str() << std::endl;
                std::cout << "Design Capacity    "
                          << (Info->RAWBatteryInfo->DesignCapacity * Info->RAWBatteryInfo->DesignCapacityMultiplier)
                          << " mWatt/hours" << std::endl;
                std::cout << "Design Voltage     " << Info->RAWBatteryInfo->DesignVoltage << " mVolts" << std::endl;
                std::cout << "SBDS Version Number  " << Info->GetSBDSVersionNumberStr().c_str() << std::endl;
                std::cout << "Maximum Error in Battery Data "
                          << static_cast<int>(Info->RAWBatteryInfo->MaximumErrorInBatteryData) << "%" << std::endl;
                std::cout << "SBDS Serial Number            "
                          << IntToHex(Info->RAWBatteryInfo->SBDSSerialNumber, 4).c_str() << std::endl;
                std::cout << "SBDS Manufacture Date  "
                          << AnsiString(FormatDateTime("dd-mm-yyyy", Info->GetSBDSManufacturerDate())).c_str() << std::endl;
                std::cout << "SBDS Device Chemistry  " << Info->GetSBDSDeviceChemistryStr().c_str() << std::endl;
                std::cout << "OEM Specific                  "
                          << IntToHex(static_cast<int>(Info->RAWBatteryInfo->OEM_Specific), 8).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Battery Info was found" << std::endl;
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
        GetBatteryInfo();
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
