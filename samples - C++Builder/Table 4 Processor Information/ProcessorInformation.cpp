//---------------------------------------------------------------------------

#include <System.SysUtils.hpp>
#include <iostream>
#include "uSMBIOS.hpp"

using namespace System;
using namespace System::Sysutils;
using namespace Usmbios;

//---------------------------------------------------------------------------

static void WriteLine(const char* Caption, const AnsiString& Value)
{
    std::cout << Caption << Value.c_str() << std::endl;
}

//---------------------------------------------------------------------------

static void WriteCacheInfo(const char* Caption, TCacheInformation* CacheInfo)
{
    std::cout << Caption << std::endl;
    std::cout << "--------------------" << std::endl;
    WriteLine("  Socket Designation    ", CacheInfo->SocketDesignationStr());
    std::cout << "  Cache Configuration   "
              << IntToHex(CacheInfo->RAWCacheInformation->CacheConfiguration, 4).c_str() << std::endl;
    std::cout << "  Maximum Cache Size    " << CacheInfo->GetMaximumCacheSize() << " Kb" << std::endl;
    std::cout << "  Installed Cache Size  " << CacheInfo->GetInstalledCacheSize() << " Kb" << std::endl;
    WriteLine("  Associativity         ", CacheInfo->AssociativityStr());
    std::cout << std::endl;
}

//---------------------------------------------------------------------------

static void GetProcessorInfo()
{
    TSMBios* SMBios = new TSMBios(true);
    try
    {
        std::cout << "Processor Information" << std::endl;
        if (SMBios->HasProcessorInfo)
        {
            for (int Index = 0; Index < SMBios->ProcessorInfo.Length; ++Index)
            {
                TProcessorInformation* LProcessorInfo = SMBios->ProcessorInfo[Index];

                WriteLine("Manufacter         ", LProcessorInfo->ProcessorManufacturerStr());
                WriteLine("Socket Designation ", LProcessorInfo->SocketDesignationStr());
                WriteLine("Type               ", LProcessorInfo->ProcessorTypeStr());
                WriteLine("Familiy            ", LProcessorInfo->ProcessorFamilyStr());
                WriteLine("Version            ", LProcessorInfo->ProcessorVersionStr());
                std::cout << "Processor ID       "
                          << IntToHex(static_cast<__int64>(LProcessorInfo->RAWProcessorInformation->ProcessorID), 16).c_str()
                          << std::endl;
                std::cout << "Voltaje            " << LProcessorInfo->GetProcessorVoltaje() << std::endl;
                std::cout << "External Clock     " << LProcessorInfo->RAWProcessorInformation->ExternalClock << "  Mhz" << std::endl;
                std::cout << "Maximum processor speed " << LProcessorInfo->RAWProcessorInformation->MaxSpeed << "  Mhz" << std::endl;
                std::cout << "Current processor speed " << LProcessorInfo->RAWProcessorInformation->CurrentSpeed << "  Mhz" << std::endl;
                WriteLine("Processor Upgrade  ", LProcessorInfo->ProcessorUpgradeStr());

                if (SMBiosAtLeast(SMBios, 2, 3))
                {
                    WriteLine("Serial Number      ", LProcessorInfo->SerialNumberStr());
                    WriteLine("Asset Tag          ", LProcessorInfo->AssetTagStr());
                    WriteLine("Part Number        ", LProcessorInfo->PartNumberStr());

                    if (SMBiosAtLeast(SMBios, 2, 5))
                    {
                        std::cout << "Core Count         " << LProcessorInfo->GetCoreCount() << std::endl;
                        std::cout << "Cores Enabled      " << LProcessorInfo->GetCoreEnabled() << std::endl;
                        std::cout << "Threads Count      " << LProcessorInfo->GetThreadCount() << std::endl;
                        std::cout << "Processor Characteristics "
                                  << IntToHex(LProcessorInfo->RAWProcessorInformation->ProcessorCharacteristics, 4).c_str()
                                  << std::endl;
                    }

                    if (SMBiosAtLeast(SMBios, 3, 6) && LProcessorInfo->HasThreadEnabled())
                        std::cout << "Threads Enabled    " << LProcessorInfo->GetThreadEnabled() << std::endl;
                }

                std::cout << std::endl;

                if ((LProcessorInfo->RAWProcessorInformation->L1CacheHandle > 0) && (LProcessorInfo->L1Chache != NULL))
                    WriteCacheInfo("L1 Cache Handle Info", LProcessorInfo->L1Chache);
                if ((LProcessorInfo->RAWProcessorInformation->L2CacheHandle > 0) && (LProcessorInfo->L2Chache != NULL))
                    WriteCacheInfo("L2 Cache Handle Info", LProcessorInfo->L2Chache);
                if ((LProcessorInfo->RAWProcessorInformation->L3CacheHandle > 0) && (LProcessorInfo->L3Chache != NULL))
                    WriteCacheInfo("L3 Cache Handle Info", LProcessorInfo->L3Chache);
            }
        }
        else
            std::cout << "No Processor Info was found" << std::endl;
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
        GetProcessorInfo();
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
