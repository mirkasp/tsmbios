//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetMemoryErrorInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "32-Bit Memory Error Information" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 1) && SMBios->HasMemoryErrorInfo)
        {
            for (int Index = 0; Index < SMBios->MemoryErrorInfo.Length; ++Index)
            {
                TMemoryErrorInformation* LInfo = SMBios->MemoryErrorInfo[Index];

                std::cout << "Error Type           " << IntToHex(LInfo->RAWMemoryErrorInfo->ErrorType, 2).c_str()
                          << " - " << LInfo->GetErrorTypeStr().c_str() << std::endl;
                std::cout << "Error Granularity    " << IntToHex(LInfo->RAWMemoryErrorInfo->ErrorGranularity, 2).c_str()
                          << " - " << LInfo->GetErrorGranularityStr().c_str() << std::endl;
                std::cout << "Error Operation      " << IntToHex(LInfo->RAWMemoryErrorInfo->ErrorOperation, 2).c_str()
                          << " - " << LInfo->GetErrorOperationStr().c_str() << std::endl;
                std::cout << "Vendor Syndrome      " << IntToHex(static_cast<int>(LInfo->RAWMemoryErrorInfo->VendorSyndrome), 8).c_str() << std::endl;
                if (LInfo->MemoryArrayErrorAddressIsUnknown())
                    std::cout << "Array Error Address  Unknown" << std::endl;
                else
                    std::cout << "Array Error Address  "
                              << IntToHex(static_cast<int>(LInfo->RAWMemoryErrorInfo->MemoryArrayErrorAddress), 8).c_str() << std::endl;
                if (LInfo->DeviceErrorAddressIsUnknown())
                    std::cout << "Device Error Address Unknown" << std::endl;
                else
                    std::cout << "Device Error Address "
                              << IntToHex(static_cast<int>(LInfo->RAWMemoryErrorInfo->DeviceErrorAddress), 8).c_str() << std::endl;
                if (LInfo->ErrorResolutionIsUnknown())
                    std::cout << "Error Resolution     Unknown" << std::endl;
                else
                    std::cout << "Error Resolution     "
                              << IntToHex(static_cast<int>(LInfo->RAWMemoryErrorInfo->ErrorResolution), 8).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No 32-Bit Memory Error Info was found" << std::endl;
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
        GetMemoryErrorInfo();
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
