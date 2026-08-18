//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <bitset>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static AnsiString ByteToBinStr(System::Byte Value)
{
    return AnsiString(std::bitset<8>(Value).to_string().c_str());
}

//---------------------------------------------------------------------------

static AnsiString WordToBinStr(System::Word Value)
{
    return AnsiString(std::bitset<16>(Value).to_string().c_str());
}

//---------------------------------------------------------------------------

static void GetMemoryModuleInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Memory Module Information" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        if (SMBios->HasMemoryModuleInfo)
        {
            for (int Index = 0; Index < SMBios->MemoryModuleInfo.Length; ++Index)
            {
                TMemoryModuleInformation* LMemoryModule = SMBios->MemoryModuleInfo[Index];

                std::cout << "Socket Designation  " << LMemoryModule->GetSocketDesignationDescr().c_str() << std::endl;
                std::cout << "Bank Connections    "
                          << ByteToBinStr(LMemoryModule->RAWMemoryModuleInformation->BankConnections).c_str() << std::endl;
                std::cout << "CurrentSpeed        "
                          << static_cast<int>(LMemoryModule->RAWMemoryModuleInformation->CurrentSpeed) << " ns" << std::endl;
                std::cout << "Current Memory Type "
                          << WordToBinStr(LMemoryModule->RAWMemoryModuleInformation->CurrentMemoryType).c_str() << std::endl;
                std::cout << "Installed Size      "
                          << ByteToBinStr(LMemoryModule->RAWMemoryModuleInformation->InstalledSize).c_str() << std::endl;
                std::cout << "Enabled Size        "
                          << ByteToBinStr(LMemoryModule->RAWMemoryModuleInformation->EnabledSize).c_str() << std::endl;
                std::cout << "Error Status        "
                          << ByteToBinStr(LMemoryModule->RAWMemoryModuleInformation->ErrorStatus).c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Memory Module Information was found" << std::endl;
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
        GetMemoryModuleInfo();
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
