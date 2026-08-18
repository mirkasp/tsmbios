//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void WriteValueBytes(TAdditionalInformationInformation* Info, int EntryIndex)
{
    std::cout << "Value             ";
    for (int Index = 0; Index < Info->GetEntryValueSize(EntryIndex); ++Index)
        std::cout << IntToHex(Info->GetEntryValueByte(EntryIndex, Index), 2).c_str() << " ";
    std::cout << std::endl;
}

static void GetAdditionalInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Additional Information" << std::endl;
        std::cout << "----------------------" << std::endl;
        if (SMBiosAtLeast(SMBios, 2, 3) && SMBios->HasAdditionalInformationInfo)
        {
            for (int TableIndex = 0; TableIndex < SMBios->AdditionalInformationInfo.Length; ++TableIndex)
            {
                TAdditionalInformationInformation* Info = SMBios->AdditionalInformationInfo[TableIndex];
                for (int Index = 0; Index < Info->RAWAdditionalInformationInfo->NumberOfAdditionalInformationEntries; ++Index)
                {
                    if (Info->HasAdditionalInformationEntry(Index))
                    {
                        std::cout << "Entry             " << Index << std::endl;
                        std::cout << "Length            " << static_cast<int>(Info->GetAdditionalInformationEntryLength(Index)) << std::endl;
                        std::cout << "Referenced Handle " << IntToHex(Info->GetReferencedHandle(Index), 4).c_str() << std::endl;
                        std::cout << "Referenced Offset " << IntToHex(Info->GetReferencedOffset(Index), 2).c_str() << std::endl;
                        std::cout << "String            " << Info->GetEntryStringStr(Index).c_str() << std::endl;
                        WriteValueBytes(Info, Index);
                        std::cout << std::endl;
                    }
                }
            }
        }
        else
            std::cout << "No Additional Information Info was found" << std::endl;
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
        GetAdditionalInfo();
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
