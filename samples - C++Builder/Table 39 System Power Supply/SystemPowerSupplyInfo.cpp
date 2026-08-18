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

static void GetSystemPowerSupplyInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "System Power Supply" << std::endl;
        std::cout << "-------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 3) && SMBios->HasSystemPowerSupplyInfo)
        {
            for (int Index = 0; Index < SMBios->SystemPowerSupplyInfo.Length; ++Index)
            {
                TSystemPowerSupplyInformation* Info = SMBios->SystemPowerSupplyInfo[Index];
                std::cout << "Power Unit Group  " << static_cast<int>(Info->RAWSystemPowerSupplyInfo->PowerUnitGroup) << std::endl;
                std::cout << "Location          " << Info->LocationStr().c_str() << std::endl;
                std::cout << "Device Name       " << Info->DeviceNameStr().c_str() << std::endl;
                std::cout << "Manufacturer      " << Info->ManufacturerStr().c_str() << std::endl;
                std::cout << "Serial Number     " << Info->SerialNumberStr().c_str() << std::endl;
                std::cout << "Asset Tag         " << Info->AssetTagNumberStr().c_str() << std::endl;
                std::cout << "Model Part Number " << Info->ModelPartNumberStr().c_str() << std::endl;
                std::cout << "Revision Level    " << Info->RevisionLevelStr().c_str() << std::endl;
                if (Info->MaxPowerCapacityIsUnknown())
                    std::cout << "Max Power         Unknown" << std::endl;
                else
                    std::cout << "Max Power         " << Info->RAWSystemPowerSupplyInfo->MaxPowerCapacity << " W" << std::endl;
                std::cout << "Type              " << Info->GetPowerSupplyTypeStr().c_str() << std::endl;
                std::cout << "Status            " << Info->GetStatusStr().c_str() << std::endl;
                std::cout << "Voltage Switching " << Info->GetInputVoltageRangeSwitchingStr().c_str() << std::endl;
                std::cout << "Hot Replaceable   " << BoolText(Info->IsHotReplaceable()) << std::endl;
                std::cout << "Present           " << BoolText(Info->IsPresent()) << std::endl;
                std::cout << "Unplugged         " << BoolText(Info->IsUnplugged()) << std::endl;
                std::cout << "Voltage Probe     " << IntToHex(Info->RAWSystemPowerSupplyInfo->InputVoltageProbeHandle, 4).c_str() << std::endl;
                std::cout << "Cooling Device    " << IntToHex(Info->RAWSystemPowerSupplyInfo->CoolingDeviceHandle, 4).c_str() << std::endl;
                std::cout << "Current Probe     " << IntToHex(Info->RAWSystemPowerSupplyInfo->InputCurrentProbeHandle, 4).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No System Power Supply Info was found" << std::endl;
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
        GetSystemPowerSupplyInfo();
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
