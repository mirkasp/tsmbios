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

static void GetOutOfBandRemoteAccessInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Out-of-Band Remote Access Information" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 2) && SMBios->HasOutOfBandRemoteAccessInfo)
        {
            for (int Index = 0; Index < SMBios->OutOfBandRemoteAccessInformation.Length; ++Index)
            {
                TOutOfBandRemoteAccessInformation* Info = SMBios->OutOfBandRemoteAccessInformation[Index];

                std::cout << "Manufacturer Name            " << Info->GetManufacturerNameStr().c_str() << std::endl;
                std::cout << "Connections                  "
                          << IntToHex(Info->RAWOutOfBandRemoteAccessInfo->Connections, 2).c_str() << std::endl;
                std::cout << "Inbound Connection Enabled   " << BoolText(Info->InboundConnectionEnabled()) << std::endl;
                std::cout << "Outbound Connection Enabled  " << BoolText(Info->OutboundConnectionEnabled()) << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Out-of-Band Remote Access Info was found" << std::endl;
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
        GetOutOfBandRemoteAccessInfo();
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
