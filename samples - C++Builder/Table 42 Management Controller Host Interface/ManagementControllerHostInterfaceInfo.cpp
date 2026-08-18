//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void WriteInterfaceBytes(TManagementControllerHostInterfaceInformation* Info)
{
    std::cout << "Interface Data    ";
    for (int Index = 0; Index < Info->RAWManagementControllerHostInterfaceInfo->InterfaceTypeSpecificDataLength; ++Index)
        std::cout << IntToHex(Info->GetInterfaceTypeSpecificDataByte(Index), 2).c_str() << " ";
    std::cout << std::endl;
}

static void WriteProtocolData(TManagementControllerHostInterfaceInformation* Info, int RecordIndex)
{
    std::cout << "Protocol Data     ";
    for (int Index = 0; Index < Info->GetProtocolTypeSpecificDataLength(RecordIndex); ++Index)
        std::cout << IntToHex(Info->GetProtocolTypeSpecificDataByte(RecordIndex, Index), 2).c_str() << " ";
    std::cout << std::endl;
}

static void GetManagementControllerHostInterfaceInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Management Controller Host Interface" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 6) && SMBios->HasManagementControllerHostInterfaceInfo)
        {
            for (int TableIndex = 0; TableIndex < SMBios->ManagementControllerHostInterfaceInfo.Length; ++TableIndex)
            {
                TManagementControllerHostInterfaceInformation* Info = SMBios->ManagementControllerHostInterfaceInfo[TableIndex];
                std::cout << "Interface Type    " << Info->GetInterfaceTypeStr().c_str() << std::endl;
                std::cout << "Interface Length  " << static_cast<int>(Info->RAWManagementControllerHostInterfaceInfo->InterfaceTypeSpecificDataLength) << std::endl;
                if (Info->HasInterfaceTypeSpecificData())
                    WriteInterfaceBytes(Info);
                std::cout << "Protocol Records  " << static_cast<int>(Info->GetProtocolRecordCount()) << std::endl;
                for (int Index = 0; Index < Info->GetProtocolRecordCount(); ++Index)
                {
                    if (Info->HasProtocolRecord(Index))
                    {
                        std::cout << "Protocol Type     " << Info->GetProtocolTypeStr(Index).c_str() << std::endl;
                        std::cout << "Protocol Length   " << static_cast<int>(Info->GetProtocolTypeSpecificDataLength(Index)) << std::endl;
                        WriteProtocolData(Info, Index);
                    }
                }
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Management Controller Host Interface Info was found" << std::endl;
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
        GetManagementControllerHostInterfaceInfo();
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
