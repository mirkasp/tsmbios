//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void WritePhysicalMemoryArray(TPhysicalMemoryArrayInformation* Info, const char* Prefix)
{
    std::cout << Prefix << "Location         " << Info->GetLocationStr().c_str() << std::endl;
    std::cout << Prefix << "Use              " << Info->GetUseStr().c_str() << std::endl;
    std::cout << Prefix << "Error Correction " << Info->GetErrorCorrectionStr().c_str() << std::endl;
    if (Info->RAWPhysicalMemoryArrayInformation->MaximumCapacity != 0x80000000)
        std::cout << Prefix << "Maximum Capacity " << Info->RAWPhysicalMemoryArrayInformation->MaximumCapacity << " Kb" << std::endl;
    else if (Info->HasExtendedMaximumCapacity())
        std::cout << Prefix << "Maximum Capacity " << Info->GetExtendedMaximumCapacity() << " bytes" << std::endl;
    else
        std::cout << Prefix << "Maximum Capacity Unknown" << std::endl;
    std::cout << Prefix << "Memory devices   "
              << Info->RAWPhysicalMemoryArrayInformation->NumberofMemoryDevices << std::endl;
}

//---------------------------------------------------------------------------

static void GetPhysicalMemArrayInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Physical Memory Array Information" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        if (SMBios->HasPhysicalMemoryArrayInfo)
        {
            for (int Index = 0; Index < SMBios->PhysicalMemoryArrayInfo.Length; ++Index)
            {
                WritePhysicalMemoryArray(SMBios->PhysicalMemoryArrayInfo[Index], "");
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Physical Memory Array Info was found" << std::endl;
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
        GetPhysicalMemArrayInfo();
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
