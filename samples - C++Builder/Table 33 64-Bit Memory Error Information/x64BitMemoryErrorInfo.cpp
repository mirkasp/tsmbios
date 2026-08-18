//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void Getx64BitMemoryErrorInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "64-Bit Memory Error Information" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 3) && SMBios->Hasx64BitMemoryErrorInfo)
        {
            for (int Index = 0; Index < SMBios->x64BitMemoryErrorInfo.Length; ++Index)
            {
                Tx64BitMemoryErrorInformation* Info = SMBios->x64BitMemoryErrorInfo[Index];
                std::cout << "Error Type                  " << Info->GetErrorTypeStr().c_str() << std::endl;
                std::cout << "Error Granularity           " << Info->GetErrorGranularityStr().c_str() << std::endl;
                std::cout << "Error Operation             " << Info->GetErrorOperationStr().c_str() << std::endl;
                std::cout << "Vendor Syndrome             " << IntToHex(static_cast<int>(Info->RAWx64BitMemoryErrorInfo->VendorSyndrome), 8).c_str() << std::endl;
                std::cout << "Memory Array Error Address  " << IntToHex(Info->RAWx64BitMemoryErrorInfo->MemoryArrayErrorAddress, 16).c_str() << std::endl;
                std::cout << "Device Error Address        " << IntToHex(Info->RAWx64BitMemoryErrorInfo->DeviceErrorAddress, 16).c_str() << std::endl;
                std::cout << "Error Resolution            " << IntToHex(static_cast<int>(Info->RAWx64BitMemoryErrorInfo->ErrorResolution), 8).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No 64-Bit Memory Error Info was found" << std::endl;
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
        Getx64BitMemoryErrorInfo();
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
