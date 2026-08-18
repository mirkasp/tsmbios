//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void GetCacheInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Cache Information" << std::endl;
        std::cout << "-----------------" << std::endl;
        if (SMBios->HasCacheInfo)
        {
            for (int Index = 0; Index < SMBios->CacheInfo.Length; ++Index)
            {
                TCacheInformation* LCache = SMBios->CacheInfo[Index];

                std::cout << "Socket Designation     " << LCache->SocketDesignationStr().c_str() << std::endl;
                std::cout << "Maximum Cache Size     " << LCache->GetMaximumCacheSize() << " KB" << std::endl;
                std::cout << "Installed Cache Size   " << LCache->GetInstalledCacheSize() << " KB" << std::endl;
                std::cout << "Cache Speed            " << static_cast<int>(LCache->RAWCacheInformation->CacheSpeed) << " ns" << std::endl;
                std::cout << "Error Correction Type  " << static_cast<int>(LCache->GetErrorCorrectionType()) << std::endl;
                std::cout << "System Cache Type      " << static_cast<int>(LCache->GetSystemCacheType()) << std::endl;
                std::cout << "Associativity          " << LCache->AssociativityStr().c_str() << std::endl;
                std::cout << std::endl;
            }
        }
        else
            std::cout << "No Cache Information was found" << std::endl;
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
        GetCacheInfo();
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
