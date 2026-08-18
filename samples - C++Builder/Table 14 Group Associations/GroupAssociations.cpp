//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetGroupAssociationsInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Group Associations Information" << std::endl;
        std::cout << "------------------------------" << std::endl;
        if (SMBios->HasGroupAssociationsInfo)
        {
            for (int Index = 0; Index < SMBios->GroupAssociationsInformation.Length; ++Index)
            {
                TGroupAssociationsInformation* LGroup = SMBios->GroupAssociationsInformation[Index];

                std::cout << "Group Name    " << LGroup->GetGroupName().c_str() << std::endl;
                std::cout << "Item Type     "
                          << static_cast<int>(LGroup->RAWGroupAssociationsInformation->ItemType) << std::endl;
                std::cout << "Item Handle   " << LGroup->RAWGroupAssociationsInformation->ItemHandle << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Group Associations Info was found" << std::endl;
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
        GetGroupAssociationsInfo();
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
