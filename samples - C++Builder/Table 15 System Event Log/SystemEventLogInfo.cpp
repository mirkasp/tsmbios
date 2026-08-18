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

static void GetSystemEventLogInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "System Event Log" << std::endl;
        std::cout << "----------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 0) && SMBios->HasSystemEventLogInfo)
        {
            for (int TableIndex = 0; TableIndex < SMBios->SystemEventLogInfo.Length; ++TableIndex)
            {
                TSystemEventLogInformation* LInfo = SMBios->SystemEventLogInfo[TableIndex];

                std::cout << "Log Area Length      " << LInfo->RAWSystemEventLogInfo->LogAreaLength << std::endl;
                std::cout << "Header Start Offset  "
                          << IntToHex(LInfo->RAWSystemEventLogInfo->LogHeaderStartOffset, 4).c_str() << std::endl;
                std::cout << "Data Start Offset    "
                          << IntToHex(LInfo->RAWSystemEventLogInfo->LogDataStartOffset, 4).c_str() << std::endl;
                std::cout << "Access Method        "
                          << IntToHex(LInfo->RAWSystemEventLogInfo->AccessMethod, 2).c_str() << " - "
                          << LInfo->GetAccessMethodStr().c_str() << std::endl;
                std::cout << "Log Area Valid       " << BoolText(LInfo->LogAreaIsValid()) << std::endl;
                std::cout << "Log Area Full        " << BoolText(LInfo->LogAreaIsFull()) << std::endl;
                std::cout << "Log Change Token     "
                          << IntToHex(static_cast<int>(LInfo->RAWSystemEventLogInfo->LogChangeToken), 8).c_str() << std::endl;
                std::cout << "Access Address       "
                          << IntToHex(static_cast<int>(LInfo->RAWSystemEventLogInfo->AccessMethodAddress), 8).c_str() << std::endl;

                if (LInfo->HasLogHeaderDescriptorFields())
                {
                    std::cout << "Header Format        "
                              << IntToHex(LInfo->RAWSystemEventLogInfo->LogHeaderFormat, 2).c_str() << " - "
                              << LInfo->GetLogHeaderFormatStr().c_str() << std::endl;
                    std::cout << "Descriptor Count     "
                              << static_cast<int>(LInfo->RAWSystemEventLogInfo->NumberOfSupportedLogTypeDescriptors)
                              << std::endl;
                    std::cout << "Descriptor Length    "
                              << static_cast<int>(LInfo->RAWSystemEventLogInfo->LengthOfEachLogTypeDescriptor)
                              << std::endl;
                    for (int Index = 0; Index < LInfo->RAWSystemEventLogInfo->NumberOfSupportedLogTypeDescriptors; ++Index)
                    {
                        if (LInfo->HasSupportedLogTypeDescriptor(Index))
                        {
                            std::cout << "Descriptor " << Index << "         "
                                      << IntToHex(LInfo->GetSupportedLogType(Index), 2).c_str() << " "
                                      << LInfo->GetSupportedLogTypeStr(Index).c_str() << " / "
                                      << IntToHex(LInfo->GetSupportedVariableDataFormatType(Index), 2).c_str() << " "
                                      << LInfo->GetSupportedVariableDataFormatTypeStr(Index).c_str() << std::endl;
                        }
                    }
                }
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No System Event Log Info was found" << std::endl;
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
        GetSystemEventLogInfo();
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
