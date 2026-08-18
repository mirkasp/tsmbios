//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetHardwareSecurityInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Hardware Security" << std::endl;
        std::cout << "-----------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 2) && SMBios->HasHardwareSecurityInfo)
        {
            for (int Index = 0; Index < SMBios->HardwareSecurityInformation.Length; ++Index)
            {
                THardwareSecurityInformation* Info = SMBios->HardwareSecurityInformation[Index];

                std::cout << "Hardware Security Settings   "
                          << IntToHex(Info->RAWHardwareSecurityInfo->HardwareSecuritySettings, 2).c_str() << std::endl;
                std::cout << "Front Panel Reset Status     " << Info->GetFrontPanelResetStatusStr().c_str() << std::endl;
                std::cout << "Administrator Password       " << Info->GetAdministratorPasswordStatusStr().c_str() << std::endl;
                std::cout << "Keyboard Password            " << Info->GetKeyboardPasswordStatusStr().c_str() << std::endl;
                std::cout << "Power-on Password            " << Info->GetPowerOnPasswordStatusStr().c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Hardware Security Info was found" << std::endl;
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
        GetHardwareSecurityInfo();
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
