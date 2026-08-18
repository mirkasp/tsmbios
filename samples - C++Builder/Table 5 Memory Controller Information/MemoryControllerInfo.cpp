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

static void GetMemoryControllerInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Memory Controller Information" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        if (SMBios->HasMemoryControllerInfo)
        {
            for (int Index = 0; Index < SMBios->MemoryControllerInfo.Length; ++Index)
            {
                TMemoryControllerInformation* LMemoryController = SMBios->MemoryControllerInfo[Index];

                std::cout << "Error Detecting Method "
                          << static_cast<int>(LMemoryController->RAWMemoryControllerInformation->ErrorDetectingMethod)
                          << " - " << AnsiString(LMemoryController->GetErrorDetectingMethodDescr()).c_str() << std::endl;
                std::cout << "Error Correcting Capability "
                          << ByteToBinStr(LMemoryController->RAWMemoryControllerInformation->ErrorCorrectingCapability).c_str()
                          << std::endl;
                std::cout << "Supported Interleave   "
                          << static_cast<int>(LMemoryController->RAWMemoryControllerInformation->SupportedInterleave)
                          << " - " << AnsiString(LMemoryController->GetSupportedInterleaveDescr()).c_str() << std::endl;
                std::cout << "Current Interleave     "
                          << static_cast<int>(LMemoryController->RAWMemoryControllerInformation->CurrentInterleave)
                          << " - " << AnsiString(LMemoryController->GetCurrentInterleaveDescr()).c_str() << std::endl;
                std::cout << "Maximum Memory Module Size  "
                          << static_cast<int>(LMemoryController->RAWMemoryControllerInformation->MaximumMemoryModuleSize)
                          << std::endl;
                std::cout << "Supported Speeds       "
                          << WordToBinStr(LMemoryController->RAWMemoryControllerInformation->SupportedSpeeds).c_str()
                          << std::endl;
                std::cout << "Supported Memory Types "
                          << WordToBinStr(LMemoryController->RAWMemoryControllerInformation->SupportedMemoryTypes).c_str()
                          << std::endl;
                std::cout << "Memory Module Voltage  "
                          << ByteToBinStr(LMemoryController->RAWMemoryControllerInformation->MemoryModuleVoltage).c_str()
                          << std::endl;
                std::cout << "Number of Associated Memory Slots    "
                          << static_cast<int>(LMemoryController->RAWMemoryControllerInformation->NumberofAssociatedMemorySlots)
                          << std::endl;
                std::cout << "Memory Module Configuration Handles  "
                          << LMemoryController->RAWMemoryControllerInformation->MemoryModuleConfigurationHandles
                          << std::endl;
                std::cout << "Enabled Error Correcting Capabilities "
                          << ByteToBinStr(LMemoryController->RAWMemoryControllerInformation->EnabledErrorCorrectingCapabilities).c_str()
                          << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Memory Controller Information was found" << std::endl;
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
        GetMemoryControllerInfo();
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
