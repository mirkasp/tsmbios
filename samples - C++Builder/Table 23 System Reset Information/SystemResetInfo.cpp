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

//---------------------------------------------------------------------------

static void GetSystemResetInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "System Reset Information" << std::endl;
        std::cout << "------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 2) && SMBios->HasSystemResetInfo)
        {
            for (int Index = 0; Index < SMBios->SystemResetInformation.Length; ++Index)
            {
                TSystemResetInformation* Info = SMBios->SystemResetInformation[Index];

                std::cout << "Capabilities           " << IntToHex(Info->RAWSystemResetInfo->Capabilities, 2).c_str() << std::endl;
                std::cout << "Reset Enabled By User  " << BoolText(Info->ResetEnabledByUser()) << std::endl;
                std::cout << "Boot Option            " << Info->GetBootOptionStr().c_str() << std::endl;
                std::cout << "Boot Option On Limit   " << Info->GetBootOptionOnLimitStr().c_str() << std::endl;
                std::cout << "Watchdog Timer         " << BoolText(Info->ContainsWatchdogTimer()) << std::endl;
                std::cout << "Reset Count            " << Info->GetResetCountStr().c_str() << std::endl;
                std::cout << "Reset Limit            " << Info->GetResetLimitStr().c_str() << std::endl;
                std::cout << "Timer Interval         " << Info->GetTimerIntervalStr().c_str() << std::endl;
                std::cout << "Timeout                " << Info->GetTimeoutStr().c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No System Reset Info was found" << std::endl;
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
        GetSystemResetInfo();
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
