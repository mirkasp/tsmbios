//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetPortConnectorInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Port Connector Information" << std::endl;
        std::cout << "--------------------------" << std::endl;
        if (SMBios->HasPortConnectorInfo)
        {
            for (int Index = 0; Index < SMBios->PortConnectorInfo.Length; ++Index)
            {
                TPortConnectorInformation* LPort = SMBios->PortConnectorInfo[Index];

                std::cout << "Internal Reference Designator " << LPort->InternalReferenceDesignatorStr().c_str() << std::endl;
                std::cout << "Internal Connector Type       "
                          << LPort->GetConnectorType(LPort->RAWPortConnectorInformation->InternalConnectorType).c_str() << std::endl;
                std::cout << "External Reference Designator " << LPort->ExternalReferenceDesignatorStr().c_str() << std::endl;
                std::cout << "External Connector Type       "
                          << LPort->GetConnectorType(LPort->RAWPortConnectorInformation->ExternalConnectorType).c_str() << std::endl;
                std::cout << "Port Type                     " << LPort->PortTypeStr().c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Port Connector Info was found" << std::endl;
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
        GetPortConnectorInfo();
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
