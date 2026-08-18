//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetProcessorAdditionalInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Processor Additional Information" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 3, 3) && SMBios->HasProcessorAdditionalInfo)
        {
            for (int Index = 0; Index < SMBios->ProcessorAdditionalInfo.Length; ++Index)
            {
                TProcessorAdditionalInformation* Info = SMBios->ProcessorAdditionalInfo[Index];
                std::cout << "Processor Handle " << IntToHex(Info->RAWProcessorAdditionalInfo->ReferencedHandle, 4).c_str() << std::endl;
                std::cout << "Architecture     " << Info->GetProcessorTypeStr().c_str() << std::endl;
                std::cout << "Specific Bytes   " << static_cast<int>(Info->GetProcessorSpecificDataSize()) << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Processor Additional Info was found" << std::endl;
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
        GetProcessorAdditionalInfo();
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
