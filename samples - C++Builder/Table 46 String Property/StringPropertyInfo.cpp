//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetStringPropertyInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "String Property" << std::endl;
        std::cout << "---------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 3, 5) && SMBios->HasStringPropertyInfo)
        {
            for (int Index = 0; Index < SMBios->StringPropertyInfo.Length; ++Index)
            {
                TStringPropertyInformation* Info = SMBios->StringPropertyInfo[Index];
                std::cout << "Property ID   " << IntToHex(Info->RAWStringPropertyInfo->StringPropertyID, 4).c_str()
                          << " " << Info->GetStringPropertyIDStr().c_str() << std::endl;
                std::cout << "Value         " << Info->StringPropertyValueStr().c_str() << std::endl;
                std::cout << "Parent Handle " << IntToHex(Info->RAWStringPropertyInfo->ParentHandle, 4).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No String Property Info was found" << std::endl;
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
        GetStringPropertyInfo();
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
