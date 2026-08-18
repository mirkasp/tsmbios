//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetSystemPowerControlsInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "System Power Controls" << std::endl;
        std::cout << "---------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 2) && SMBios->HasSystemPowerControlsInfo)
        {
            for (int Index = 0; Index < SMBios->SystemPowerControlsInformation.Length; ++Index)
            {
                TSystemPowerControlsInformation* Info = SMBios->SystemPowerControlsInformation[Index];

                std::cout << "Raw Scheduled Power-on  "
                          << IntToHex(Info->RAWSystemPowerControlsInfo->NextScheduledPowerOnMonth, 2).c_str() << " "
                          << IntToHex(Info->RAWSystemPowerControlsInfo->NextScheduledPowerOnDayOfMonth, 2).c_str() << " "
                          << IntToHex(Info->RAWSystemPowerControlsInfo->NextScheduledPowerOnHour, 2).c_str() << " "
                          << IntToHex(Info->RAWSystemPowerControlsInfo->NextScheduledPowerOnMinute, 2).c_str() << " "
                          << IntToHex(Info->RAWSystemPowerControlsInfo->NextScheduledPowerOnSecond, 2).c_str() << std::endl;
                if (Info->HasValidScheduledPowerOnTime())
                {
                    std::cout << "Month                   " << static_cast<int>(Info->GetNextScheduledPowerOnMonth()) << std::endl;
                    std::cout << "Day Of Month            " << static_cast<int>(Info->GetNextScheduledPowerOnDayOfMonth()) << std::endl;
                    std::cout << "Hour                    " << static_cast<int>(Info->GetNextScheduledPowerOnHour()) << std::endl;
                    std::cout << "Minute                  " << static_cast<int>(Info->GetNextScheduledPowerOnMinute()) << std::endl;
                    std::cout << "Second                  " << static_cast<int>(Info->GetNextScheduledPowerOnSecond()) << std::endl;
                }
                else
                    std::cout << "Scheduled Power-on      Invalid BCD value" << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No System Power Controls Info was found" << std::endl;
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
        GetSystemPowerControlsInfo();
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
