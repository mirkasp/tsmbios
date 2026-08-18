// CodeGear C++Builder
// Copyright (c) 1995, 2025 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'uSMBIOS.pas' rev: 37.00 (Windows)

#ifndef uSMBIOSHPP
#define uSMBIOSHPP

#pragma delphiheader begin
#pragma option push
#if defined(__BORLANDC__) && !defined(__clang__)
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#endif
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.SysUtils.hpp>
#include <System.Generics.Collections.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Usmbios
{
//-- forward type declarations -----------------------------------------------
struct TRawSMBIOSData;
struct TSmBiosTableHeader;
struct TBiosInfo;
class DELPHICLASS TBiosInformation;
struct TSysInfo;
class DELPHICLASS TSystemInformation;
struct TBaseBoardInfo;
class DELPHICLASS TBaseBoardInformation;
struct TEnclosureInfo;
class DELPHICLASS TEnclosureInformation;
struct TMemoryControllerInfo;
class DELPHICLASS TMemoryControllerInformation;
struct TMemoryModuleInfo;
class DELPHICLASS TMemoryModuleInformation;
struct TCacheInfo;
class DELPHICLASS TCacheInformation;
struct TProcessorInfo;
class DELPHICLASS TProcessorInformation;
struct TPortConnectorInfo;
class DELPHICLASS TPortConnectorInformation;
struct TSystemSlotInfo;
class DELPHICLASS TSystemSlotInformation;
struct TOnBoardSystemInfo;
class DELPHICLASS TOnBoardSystemInformation;
struct TOEMStringsInfo;
struct TGroupAssociationsInfo;
class DELPHICLASS TGroupAssociationsInformation;
class DELPHICLASS TOEMStringsInformation;
struct TSystemConfInfo;
class DELPHICLASS TSystemConfInformation;
struct TBIOSLanguageInfo;
class DELPHICLASS TBIOSLanguageInformation;
struct TSystemEventLogInfo;
class DELPHICLASS TSystemEventLogInformation;
struct TPhysicalMemoryArrayInfo;
class DELPHICLASS TPhysicalMemoryArrayInformation;
struct TMemoryErrorInfo;
class DELPHICLASS TMemoryErrorInformation;
struct TMemoryArrayMappedAddress;
class DELPHICLASS TMemoryArrayMappedAddressInformation;
struct TMemoryDeviceMappedAddress;
class DELPHICLASS TMemoryDeviceMappedAddressInformation;
struct TMemoryDeviceInfo;
class DELPHICLASS TMemoryDeviceInformation;
struct TBuiltInPointingDevice;
class DELPHICLASS TBuiltInPointingDeviceInformation;
struct TBatteryInfo;
class DELPHICLASS TBatteryInformation;
struct TSystemResetInfo;
class DELPHICLASS TSystemResetInformation;
struct THardwareSecurityInfo;
class DELPHICLASS THardwareSecurityInformation;
struct TSystemPowerControlsInfo;
class DELPHICLASS TSystemPowerControlsInformation;
struct TVoltageProbeInfo;
class DELPHICLASS TVoltageProbeInformation;
struct TCoolingDeviceInfo;
class DELPHICLASS TCoolingDeviceInformation;
struct TTemperatureProbeInfo;
class DELPHICLASS TTemperatureProbeInformation;
struct TElectricalCurrentProbeInfo;
class DELPHICLASS TElectricalCurrentProbeInformation;
struct TOutOfBandRemoteAccessInfo;
class DELPHICLASS TOutOfBandRemoteAccessInformation;
struct TBootIntegrityServicesEntryPointInfo;
class DELPHICLASS TBootIntegrityServicesEntryPointInformation;
struct TSystemBootInfo;
class DELPHICLASS TSystemBootInformation;
struct Tx64BitMemoryErrorInfo;
class DELPHICLASS Tx64BitMemoryErrorInformation;
struct TManagementDeviceInfo;
class DELPHICLASS TManagementDeviceInformation;
struct TManagementDeviceComponentInfo;
class DELPHICLASS TManagementDeviceComponentInformation;
struct TManagementDeviceThresholdDataInfo;
class DELPHICLASS TManagementDeviceThresholdDataInformation;
struct TMemoryChannelInfo;
class DELPHICLASS TMemoryChannelInformation;
struct TIPMIDeviceInfo;
class DELPHICLASS TIPMIDeviceInformation;
struct TSystemPowerSupplyInfo;
class DELPHICLASS TSystemPowerSupplyInformation;
struct TAdditionalInformationInfo;
class DELPHICLASS TAdditionalInformationInformation;
struct TOnboardDevicesExtendedInfo;
class DELPHICLASS TOnboardDevicesExtendedInformation;
struct TManagementControllerHostInterfaceInfo;
class DELPHICLASS TManagementControllerHostInterfaceInformation;
struct TTPMDeviceInfo;
struct TStringPropertyInfo;
class DELPHICLASS TStringPropertyInformation;
class DELPHICLASS TTPMDeviceInformation;
struct TProcessorAdditionalInfo;
class DELPHICLASS TProcessorAdditionalInformation;
struct TFirmwareInventoryInfo;
class DELPHICLASS TFirmwareInventoryInformation;
struct TSMBiosTableEntry;
class DELPHICLASS TSMBios;
//-- type declarations -------------------------------------------------------
typedef unsigned DWORD;

typedef unsigned *PDWORD;

typedef TRawSMBIOSData *PRawSMBIOSData;

struct DECLSPEC_DRECORD TRawSMBIOSData
{
public:
	System::Byte Used20CallingMethod;
	System::Byte SMBIOSMajorVersion;
	System::Byte SMBIOSMinorVersion;
	System::Byte DmiRevision;
	DWORD Length;
	System::Sysutils::PByteArray SMBIOSTableData;
};


enum DECLSPEC_DENUM TSMBiosTablesTypes : unsigned char { BIOSInformation, SystemInformation, BaseBoardInformation, EnclosureInformation, ProcessorInformation, MemoryControllerInformation, MemoryModuleInformation, CacheInformation, PortConnectorInformation, SystemSlotsInformation, OnBoardDevicesInformation, OEMStrings, SystemConfigurationOptions, BIOSLanguageInformation, GroupAssociations, SystemEventLog, PhysicalMemoryArray, MemoryDevice, MemoryErrorInformation, MemoryArrayMappedAddress, MemoryDeviceMappedAddress, BuiltinPointingDevice, PortableBattery, SystemReset, HardwareSecurity, SystemPowerControls, VoltageProbe, CoolingDevice, TemperatureProbe, ElectricalCurrentProbe, OutofBandRemoteAccess, BootIntegrityServicesEntryPoint, SystemBootInformation, 
	x64BitMemoryErrorInformation, ManagementDevice, ManagementDeviceComponent, ManagementDeviceThresholdData, MemoryChannel, IPMIDeviceInformation, SystemPowerSupply, AdditionalInformation, OnboardDevicesExtendedInformation, ManagementControllerHostInterface, TPMDevice, ProcessorAdditionalInformation, FirmwareInventoryInformation, StringProperty, SMBIOSTable47, SMBIOSTable48, SMBIOSTable49, SMBIOSTable50, SMBIOSTable51, SMBIOSTable52, SMBIOSTable53, SMBIOSTable54, SMBIOSTable55, SMBIOSTable56, SMBIOSTable57, SMBIOSTable58, SMBIOSTable59, SMBIOSTable60, SMBIOSTable61, SMBIOSTable62, SMBIOSTable63, SMBIOSTable64, SMBIOSTable65, SMBIOSTable66, SMBIOSTable67, SMBIOSTable68, SMBIOSTable69, SMBIOSTable70, SMBIOSTable71, SMBIOSTable72, SMBIOSTable73, SMBIOSTable74, 
	SMBIOSTable75, SMBIOSTable76, SMBIOSTable77, SMBIOSTable78, SMBIOSTable79, SMBIOSTable80, SMBIOSTable81, SMBIOSTable82, SMBIOSTable83, SMBIOSTable84, SMBIOSTable85, SMBIOSTable86, SMBIOSTable87, SMBIOSTable88, SMBIOSTable89, SMBIOSTable90, SMBIOSTable91, SMBIOSTable92, SMBIOSTable93, SMBIOSTable94, SMBIOSTable95, SMBIOSTable96, SMBIOSTable97, SMBIOSTable98, SMBIOSTable99, SMBIOSTable100, SMBIOSTable101, SMBIOSTable102, SMBIOSTable103, SMBIOSTable104, SMBIOSTable105, SMBIOSTable106, SMBIOSTable107, SMBIOSTable108, SMBIOSTable109, SMBIOSTable110, SMBIOSTable111, SMBIOSTable112, SMBIOSTable113, SMBIOSTable114, SMBIOSTable115, SMBIOSTable116, SMBIOSTable117, SMBIOSTable118, SMBIOSTable119, SMBIOSTable120, SMBIOSTable121, SMBIOSTable122, SMBIOSTable123, 
	SMBIOSTable124, SMBIOSTable125, Inactive, EndofTable };

typedef System::StaticArray<System::AnsiString, 256> Usmbios__1;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSmBiosTableHeader
{
public:
	System::Byte TableType;
	System::Byte Length;
	System::Word Handle;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TBiosInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Vendor;
	System::Byte Version;
	System::Word StartingSegment;
	System::Byte ReleaseDate;
	System::Byte BiosRomSize;
	__int64 Characteristics;
	System::StaticArray<System::Byte, 2> ExtensionBytes;
	System::Byte SystemBIOSMajorRelease;
	System::Byte SystemBIOSMinorRelease;
	System::Byte EmbeddedControllerFirmwareMajorRelease;
	System::Byte EmbeddedControllerFirmwareMinorRelease;
	System::Word ExtendedBiosRomSize;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TBiosInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TBiosInfo *RAWBiosInformation;
	System::AnsiString __fastcall VendorStr();
	System::AnsiString __fastcall VersionStr();
	System::AnsiString __fastcall ReleaseDateStr();
	bool __fastcall HasExtendedBiosRomSize();
	System::Word __fastcall GetExtendedBiosRomSize();
public:
	/* TObject.Create */ inline __fastcall TBiosInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBiosInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSysInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Manufacturer;
	System::Byte ProductName;
	System::Byte Version;
	System::Byte SerialNumber;
	System::StaticArray<System::Byte, 16> UUID;
	System::Byte WakeUpType;
	System::Byte SKUNumber;
	System::Byte Family;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSystemInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TSysInfo *RAWSystemInformation;
	System::AnsiString __fastcall ManufacturerStr();
	System::AnsiString __fastcall ProductNameStr();
	System::AnsiString __fastcall VersionStr();
	System::AnsiString __fastcall SerialNumberStr();
	bool __fastcall HasUUID();
	System::AnsiString __fastcall UUIDStr();
	bool __fastcall HasWakeUpType();
	System::AnsiString __fastcall WakeUpTypeStr();
	System::AnsiString __fastcall SKUNumberStr();
	bool __fastcall HasSKUNumber();
	System::AnsiString __fastcall FamilyStr();
	bool __fastcall HasFamily();
public:
	/* TObject.Create */ inline __fastcall TSystemInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TSystemInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TBaseBoardInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Manufacturer;
	System::Byte Product;
	System::Byte Version;
	System::Byte SerialNumber;
	System::Byte AssetTag;
	System::Byte FeatureFlags;
	System::Byte LocationinChassis;
	System::Word ChassisHandle;
	System::Byte BoardType;
	System::Byte NumberofContainedObjectHandles;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TBaseBoardInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TBaseBoardInfo *RAWBaseBoardInformation;
	System::AnsiString __fastcall BoardTypeStr();
	System::AnsiString __fastcall ManufacturerStr();
	System::AnsiString __fastcall ProductStr();
	System::AnsiString __fastcall VersionStr();
	System::AnsiString __fastcall SerialNumberStr();
	System::AnsiString __fastcall AssetTagStr();
	System::AnsiString __fastcall LocationinChassisStr();
public:
	/* TObject.Create */ inline __fastcall TBaseBoardInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBaseBoardInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TEnclosureInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Manufacturer;
	System::Byte _Type;
	System::Byte Version;
	System::Byte SerialNumber;
	System::Byte AssetTagNumber;
	System::Byte BootUpState;
	System::Byte PowerSupplyState;
	System::Byte ThermalState;
	System::Byte SecurityStatus;
	DWORD OEM_Defined;
	System::Byte Height;
	System::Byte NumberofPowerCords;
	System::Byte ContainedElementCount;
	System::Byte ContainedElementRecordLength;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TEnclosureInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TEnclosureInfo *RAWEnclosureInformation;
	System::AnsiString __fastcall ManufacturerStr();
	System::AnsiString __fastcall VersionStr();
	System::AnsiString __fastcall SerialNumberStr();
	System::AnsiString __fastcall AssetTagNumberStr();
	System::AnsiString __fastcall TypeStr();
	System::AnsiString __fastcall BootUpStateStr();
	System::AnsiString __fastcall PowerSupplyStateStr();
public:
	/* TObject.Create */ inline __fastcall TEnclosureInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TEnclosureInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TMemoryControllerInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte ErrorDetectingMethod;
	System::Byte ErrorCorrectingCapability;
	System::Byte SupportedInterleave;
	System::Byte CurrentInterleave;
	System::Byte MaximumMemoryModuleSize;
	System::Word SupportedSpeeds;
	System::Word SupportedMemoryTypes;
	System::Byte MemoryModuleVoltage;
	System::Byte NumberofAssociatedMemorySlots;
	System::Word MemoryModuleConfigurationHandles;
	System::Byte EnabledErrorCorrectingCapabilities;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TMemoryControllerInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TMemoryControllerInfo *RAWMemoryControllerInformation;
	System::UnicodeString __fastcall GetErrorDetectingMethodDescr();
	System::UnicodeString __fastcall GetSupportedInterleaveDescr();
	System::UnicodeString __fastcall GetCurrentInterleaveDescr();
public:
	/* TObject.Create */ inline __fastcall TMemoryControllerInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TMemoryControllerInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TMemoryModuleInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte SocketDesignation;
	System::Byte BankConnections;
	System::Byte CurrentSpeed;
	System::Word CurrentMemoryType;
	System::Byte InstalledSize;
	System::Byte EnabledSize;
	System::Byte ErrorStatus;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TMemoryModuleInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TMemoryModuleInfo *RAWMemoryModuleInformation;
	System::AnsiString __fastcall GetSocketDesignationDescr();
public:
	/* TObject.Create */ inline __fastcall TMemoryModuleInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TMemoryModuleInformation() { }
	
};

#pragma pack(pop)

enum DECLSPEC_DENUM TCacheSRAMType : unsigned char { SROther, SRUnknown, SRNon_Burst, SRBurst, SRPipelineBurst, SRSynchronous, SRAsynchronous };

typedef System::Set<TCacheSRAMType, TCacheSRAMType::SROther, TCacheSRAMType::SRAsynchronous> TCacheSRAMTypes;

enum DECLSPEC_DENUM TErrorCorrectionType : unsigned char { ECFiller, ECOther, ECUnknown, ECNone, ECParity, ECSingle_bitECC, ECMulti_bitECC };

typedef System::StaticArray<System::UnicodeString, 7> Usmbios__8;

enum DECLSPEC_DENUM TSystemCacheType : unsigned char { SCFiller, SCOther, SCUnknown, SCInstruction, SCData, SCUnified };

typedef System::StaticArray<System::UnicodeString, 6> Usmbios__9;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TCacheInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte SocketDesignation;
	System::Word CacheConfiguration;
	System::Word MaximumCacheSize;
	System::Word InstalledSize;
	System::Word SupportedSRAMType;
	System::Word CurrentSRAMType;
	System::Byte CacheSpeed;
	System::Byte ErrorCorrectionType;
	System::Byte SystemCacheType;
	System::Byte Associativity;
	DWORD MaximumCacheSize2;
	DWORD InstalledSize2;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TCacheInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TCacheInfo *RAWCacheInformation;
	System::AnsiString __fastcall SocketDesignationStr();
	int __fastcall GetMaximumCacheSize();
	bool __fastcall HasMaximumCacheSize2();
	int __fastcall GetInstalledCacheSize();
	bool __fastcall HasInstalledCacheSize2();
	TCacheSRAMTypes __fastcall GetSupportedSRAMType();
	TCacheSRAMTypes __fastcall GetCurrentSRAMType();
	TErrorCorrectionType __fastcall GetErrorCorrectionType();
	TSystemCacheType __fastcall GetSystemCacheType();
	System::AnsiString __fastcall AssociativityStr();
public:
	/* TObject.Create */ inline __fastcall TCacheInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TCacheInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TProcessorInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte SocketDesignation;
	System::Byte ProcessorType;
	System::Byte ProcessorFamily;
	System::Byte ProcessorManufacturer;
	__int64 ProcessorID;
	System::Byte ProcessorVersion;
	System::Byte Voltaje;
	System::Word ExternalClock;
	System::Word MaxSpeed;
	System::Word CurrentSpeed;
	System::Byte Status;
	System::Byte ProcessorUpgrade;
	System::Word L1CacheHandle;
	System::Word L2CacheHandle;
	System::Word L3CacheHandle;
	System::Byte SerialNumber;
	System::Byte AssetTag;
	System::Byte PartNumber;
	System::Byte CoreCount;
	System::Byte CoreEnabled;
	System::Byte ThreadCount;
	System::Word ProcessorCharacteristics;
	System::Word ProcessorFamily2;
	System::Word CoreCount2;
	System::Word CoreEnabled2;
	System::Word ThreadCount2;
	System::Word ThreadEnabled;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TProcessorInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TProcessorInfo *RAWProcessorInformation;
	TCacheInformation* L1Chache;
	TCacheInformation* L2Chache;
	TCacheInformation* L3Chache;
	System::AnsiString __fastcall ProcessorManufacturerStr();
	System::AnsiString __fastcall SocketDesignationStr();
	System::AnsiString __fastcall ProcessorTypeStr();
	System::AnsiString __fastcall ProcessorFamilyStr();
	bool __fastcall HasCoreCount2();
	System::Word __fastcall GetCoreCount();
	bool __fastcall HasCoreEnabled2();
	System::Word __fastcall GetCoreEnabled();
	bool __fastcall HasThreadCount2();
	System::Word __fastcall GetThreadCount();
	bool __fastcall HasThreadEnabled();
	System::Word __fastcall GetThreadEnabled();
	System::AnsiString __fastcall ProcessorVersionStr();
	double __fastcall GetProcessorVoltaje();
	System::AnsiString __fastcall ProcessorUpgradeStr();
	System::AnsiString __fastcall SerialNumberStr();
	System::AnsiString __fastcall AssetTagStr();
	System::AnsiString __fastcall PartNumberStr();
public:
	/* TObject.Create */ inline __fastcall TProcessorInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TProcessorInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TPortConnectorInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte InternalReferenceDesignator;
	System::Byte InternalConnectorType;
	System::Byte ExternalReferenceDesignator;
	System::Byte ExternalConnectorType;
	System::Byte PortType;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TPortConnectorInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TPortConnectorInfo *RAWPortConnectorInformation;
	System::AnsiString __fastcall InternalReferenceDesignatorStr();
	System::AnsiString __fastcall GetConnectorType(System::Byte Connector);
	System::AnsiString __fastcall ExternalReferenceDesignatorStr();
	System::AnsiString __fastcall PortTypeStr();
public:
	/* TObject.Create */ inline __fastcall TPortConnectorInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TPortConnectorInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSystemSlotInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte SlotDesignation;
	System::Byte SlotType;
	System::Byte SlotDataBusWidth;
	System::Byte CurrentUsage;
	System::Byte SlotLength;
	System::Word SlotID;
	System::Byte SlotCharacteristics1;
	System::Byte SlotCharacteristics2;
	System::Word SegmentGroupNumber;
	System::Byte BusNumber;
	System::Byte DeviceFunctionNumber;
	System::Byte DataBusWidth;
	System::Byte PeerGroupingCount;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSystemSlotInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TSystemSlotInfo *RAWSystemSlotInformation;
	System::AnsiString __fastcall SlotDesignationStr();
	System::AnsiString __fastcall GetSlotType();
	System::AnsiString __fastcall GetSlotDataBusWidth();
	System::AnsiString __fastcall GetCurrentUsage();
	System::AnsiString __fastcall GetSlotLength();
	bool __fastcall HasDataBusWidth();
	System::Byte __fastcall GetDataBusWidth();
	bool __fastcall HasPeerGroupingCount();
	System::Byte __fastcall GetPeerGroupingCount();
public:
	/* TObject.Create */ inline __fastcall TSystemSlotInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TSystemSlotInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TOnBoardSystemInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte DeviceType;
	System::Byte DescriptionString;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TOnBoardSystemInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TOnBoardSystemInfo *RAWOnBoardSystemInfo;
	System::AnsiString __fastcall GetDescription();
	bool __fastcall Enabled();
	System::AnsiString __fastcall GetTypeDescription();
public:
	/* TObject.Create */ inline __fastcall TOnBoardSystemInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TOnBoardSystemInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TOEMStringsInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Count;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TGroupAssociationsInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte GroupName;
	System::Byte ItemType;
	System::Word ItemHandle;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TGroupAssociationsInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TGroupAssociationsInfo *RAWGroupAssociationsInformation;
	System::AnsiString __fastcall GetGroupName();
public:
	/* TObject.Create */ inline __fastcall TGroupAssociationsInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TGroupAssociationsInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TOEMStringsInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TOEMStringsInfo *RAWOEMStringsInformation;
	System::AnsiString __fastcall GetOEMString(int index);
public:
	/* TObject.Create */ inline __fastcall TOEMStringsInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TOEMStringsInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSystemConfInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Count;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSystemConfInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TSystemConfInfo *RAWSystemConfInformation;
	System::AnsiString __fastcall GetConfString(int index);
public:
	/* TObject.Create */ inline __fastcall TSystemConfInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TSystemConfInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TBIOSLanguageInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte InstallableLanguages;
	System::Byte Flags;
	System::StaticArray<System::Byte, 15> Reserved;
	System::Byte CurrentLanguage;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TBIOSLanguageInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TBIOSLanguageInfo *RAWBIOSLanguageInformation;
	System::AnsiString __fastcall GetLanguageString(int index);
	System::AnsiString __fastcall GetCurrentLanguageStr();
public:
	/* TObject.Create */ inline __fastcall TBIOSLanguageInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBIOSLanguageInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSystemEventLogInfo
{
public:
	TSmBiosTableHeader Header;
	System::Word LogAreaLength;
	System::Word LogHeaderStartOffset;
	System::Word LogDataStartOffset;
	System::Byte AccessMethod;
	System::Byte LogStatus;
	DWORD LogChangeToken;
	DWORD AccessMethodAddress;
	System::Byte LogHeaderFormat;
	System::Byte NumberOfSupportedLogTypeDescriptors;
	System::Byte LengthOfEachLogTypeDescriptor;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSystemEventLogInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TSystemEventLogInfo *RAWSystemEventLogInfo;
	System::AnsiString __fastcall GetAccessMethodStr();
	bool __fastcall LogAreaIsValid();
	bool __fastcall LogAreaIsFull();
	bool __fastcall HasLogHeaderDescriptorFields();
	System::AnsiString __fastcall GetLogHeaderFormatStr();
	System::Word __fastcall GetAccessMethodIndexAddress();
	System::Word __fastcall GetAccessMethodDataAddress();
	System::Word __fastcall GetAccessMethodGPNVHandle();
	bool __fastcall HasSupportedLogTypeDescriptor(int Index);
	System::Byte __fastcall GetSupportedLogType(int Index);
	System::AnsiString __fastcall GetSupportedLogTypeStr(int Index);
	System::Byte __fastcall GetSupportedVariableDataFormatType(int Index);
	System::AnsiString __fastcall GetSupportedVariableDataFormatTypeStr(int Index);
public:
	/* TObject.Create */ inline __fastcall TSystemEventLogInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TSystemEventLogInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TPhysicalMemoryArrayInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Location;
	System::Byte Use;
	System::Byte MemoryErrorCorrection;
	DWORD MaximumCapacity;
	System::Word MemoryErrorInformationHandle;
	System::Word NumberofMemoryDevices;
	__int64 ExtendedMaximumCapacity;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TPhysicalMemoryArrayInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TPhysicalMemoryArrayInfo *RAWPhysicalMemoryArrayInformation;
	System::AnsiString __fastcall GetLocationStr();
	System::AnsiString __fastcall GetUseStr();
	System::AnsiString __fastcall GetErrorCorrectionStr();
	bool __fastcall HasExtendedMaximumCapacity();
	__int64 __fastcall GetExtendedMaximumCapacity();
public:
	/* TObject.Create */ inline __fastcall TPhysicalMemoryArrayInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TPhysicalMemoryArrayInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TMemoryErrorInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte ErrorType;
	System::Byte ErrorGranularity;
	System::Byte ErrorOperation;
	DWORD VendorSyndrome;
	DWORD MemoryArrayErrorAddress;
	DWORD DeviceErrorAddress;
	DWORD ErrorResolution;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TMemoryErrorInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TMemoryErrorInfo *RAWMemoryErrorInfo;
	System::AnsiString __fastcall GetErrorTypeStr();
	System::AnsiString __fastcall GetErrorGranularityStr();
	System::AnsiString __fastcall GetErrorOperationStr();
	bool __fastcall MemoryArrayErrorAddressIsUnknown();
	bool __fastcall DeviceErrorAddressIsUnknown();
	bool __fastcall ErrorResolutionIsUnknown();
public:
	/* TObject.Create */ inline __fastcall TMemoryErrorInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TMemoryErrorInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TMemoryArrayMappedAddress
{
public:
	TSmBiosTableHeader Header;
	DWORD StartingAddress;
	DWORD EndingAddress;
	System::Word MemoryArrayHandle;
	System::Byte PartitionWidth;
	__int64 ExtendedStartingAddress;
	__int64 ExtendedEndingAddress;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TMemoryArrayMappedAddressInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TMemoryArrayMappedAddress *RAWMemoryArrayMappedAddressInfo;
	bool __fastcall HasExtendedAddresses();
	__int64 __fastcall GetExtendedStartingAddress();
	__int64 __fastcall GetExtendedEndingAddress();
public:
	/* TObject.Create */ inline __fastcall TMemoryArrayMappedAddressInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TMemoryArrayMappedAddressInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TMemoryDeviceMappedAddress
{
public:
	TSmBiosTableHeader Header;
	DWORD StartingAddress;
	DWORD EndingAddress;
	System::Word MemoryDeviceHandle;
	System::Word MemoryArrayMappedAddressHandle;
	System::Byte PartitionRowPosition;
	System::Byte InterleavePosition;
	System::Byte InterleavedDataDepth;
	__int64 ExtendedStartingAddress;
	__int64 ExtendedEndingAddress;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TMemoryDeviceMappedAddressInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TMemoryDeviceMappedAddress *RAWMemoryDeviceMappedAddressInfo;
	bool __fastcall HasExtendedAddresses();
	__int64 __fastcall GetExtendedStartingAddress();
	__int64 __fastcall GetExtendedEndingAddress();
public:
	/* TObject.Create */ inline __fastcall TMemoryDeviceMappedAddressInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TMemoryDeviceMappedAddressInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TMemoryDeviceInfo
{
public:
	TSmBiosTableHeader Header;
	System::Word PhysicalMemoryArrayHandle;
	System::Word MemoryErrorInformationHandle;
	System::Word TotalWidth;
	System::Word DataWidth;
	System::Word Size;
	System::Byte FormFactor;
	System::Byte DeviceSet;
	System::Byte DeviceLocator;
	System::Byte BankLocator;
	System::Byte MemoryType;
	System::Word TypeDetail;
	System::Word Speed;
	System::Byte Manufacturer;
	System::Byte SerialNumber;
	System::Byte AssetTag;
	System::Byte PartNumber;
	System::Byte Attributes;
	DWORD ExtendedSize;
	System::Word ConfiguredMemoryClockSpeed;
	System::Word MinimumVoltage;
	System::Word MaximumVoltage;
	System::Word ConfiguredVoltage;
	System::Byte MemoryTechnology;
	System::Word MemoryOperatingModeCapability;
	System::Byte FirmwareVersion;
	System::Word ModuleManufacturerID;
	System::Word ModuleProductID;
	System::Word MemorySubsystemControllerManufacturerID;
	System::Word MemorySubsystemControllerProductID;
	__int64 NonVolatileSize;
	__int64 VolatileSize;
	__int64 CacheSize;
	__int64 LogicalSize;
	DWORD ExtendedSpeed;
	DWORD ExtendedConfiguredMemorySpeed;
	System::Word PMIC0ManufacturerID;
	System::Word PMIC0RevisionNumber;
	System::Word RCDManufacturerID;
	System::Word RCDRevisionNumber;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TMemoryDeviceInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TMemoryDeviceInfo *RAWMemoryDeviceInfo;
	TPhysicalMemoryArrayInformation* PhysicalMemoryArray;
	DWORD __fastcall GetSize();
	System::AnsiString __fastcall GetFormFactor();
	System::AnsiString __fastcall GetDeviceLocatorStr();
	System::AnsiString __fastcall GetBankLocatorStr();
	System::AnsiString __fastcall GetMemoryTypeStr();
	bool __fastcall HasMemoryTechnology();
	System::AnsiString __fastcall GetMemoryTechnologyStr();
	bool __fastcall HasFirmwareVersion();
	System::AnsiString __fastcall FirmwareVersionStr();
	bool __fastcall HasExtendedSpeed();
	DWORD __fastcall GetSpeed();
	bool __fastcall HasConfiguredMemorySpeed();
	bool __fastcall HasExtendedConfiguredMemorySpeed();
	DWORD __fastcall GetConfiguredMemorySpeed();
	bool __fastcall HasNonVolatileSize();
	__int64 __fastcall GetNonVolatileSize();
	bool __fastcall HasVolatileSize();
	__int64 __fastcall GetVolatileSize();
	bool __fastcall HasCacheSize();
	__int64 __fastcall GetCacheSize();
	bool __fastcall HasLogicalSize();
	__int64 __fastcall GetLogicalSize();
	bool __fastcall HasPMIC0();
	System::Word __fastcall GetPMIC0ManufacturerID();
	System::Word __fastcall GetPMIC0RevisionNumber();
	bool __fastcall HasRCD();
	System::Word __fastcall GetRCDManufacturerID();
	System::Word __fastcall GetRCDRevisionNumber();
	System::AnsiString __fastcall ManufacturerStr();
	System::AnsiString __fastcall SerialNumberStr();
	System::AnsiString __fastcall AssetTagStr();
	System::AnsiString __fastcall PartNumberStr();
public:
	/* TObject.Create */ inline __fastcall TMemoryDeviceInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TMemoryDeviceInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TBuiltInPointingDevice
{
public:
	TSmBiosTableHeader Header;
	System::Byte _Type;
	System::Byte _Interface;
	System::Byte NumberofButtons;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TBuiltInPointingDeviceInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TBuiltInPointingDevice *RAWBuiltInPointingDeviceInfo;
	System::UnicodeString __fastcall GetType();
	HIDESBASE System::UnicodeString __fastcall GetInterface();
public:
	/* TObject.Create */ inline __fastcall TBuiltInPointingDeviceInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBuiltInPointingDeviceInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TBatteryInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Location;
	System::Byte Manufacturer;
	System::Byte ManufacturerDate;
	System::Byte SerialNumber;
	System::Byte DeviceName;
	System::Byte DeviceChemistry;
	System::Word DesignCapacity;
	System::Word DesignVoltage;
	System::Byte SBDSVersionNumber;
	System::Byte MaximumErrorInBatteryData;
	System::Word SBDSSerialNumber;
	System::Word SBDSManufacturerDate;
	System::Byte SBDSDeviceChemistry;
	System::Byte DesignCapacityMultiplier;
	DWORD OEM_Specific;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TBatteryInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TBatteryInfo *RAWBatteryInfo;
	System::AnsiString __fastcall GetLocationStr();
	System::AnsiString __fastcall GetManufacturerStr();
	System::AnsiString __fastcall GetManufacturerDateStr();
	System::AnsiString __fastcall GetSerialNumberStr();
	System::AnsiString __fastcall GetDeviceNameStr();
	System::AnsiString __fastcall GetDeviceChemistry();
	System::AnsiString __fastcall GetSBDSVersionNumberStr();
	System::TDateTime __fastcall GetSBDSManufacturerDate();
	System::AnsiString __fastcall GetSBDSDeviceChemistryStr();
public:
	/* TObject.Create */ inline __fastcall TBatteryInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBatteryInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSystemResetInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Capabilities;
	System::Word ResetCount;
	System::Word ResetLimit;
	System::Word TimerInterval;
	System::Word Timeout;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSystemResetInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TSystemResetInfo *RAWSystemResetInfo;
	bool __fastcall ResetEnabledByUser();
	System::AnsiString __fastcall GetBootOptionStr();
	System::AnsiString __fastcall GetBootOptionOnLimitStr();
	bool __fastcall ContainsWatchdogTimer();
	System::AnsiString __fastcall GetResetCountStr();
	System::AnsiString __fastcall GetResetLimitStr();
	System::AnsiString __fastcall GetTimerIntervalStr();
	System::AnsiString __fastcall GetTimeoutStr();
public:
	/* TObject.Create */ inline __fastcall TSystemResetInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TSystemResetInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD THardwareSecurityInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte HardwareSecuritySettings;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION THardwareSecurityInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	THardwareSecurityInfo *RAWHardwareSecurityInfo;
	System::AnsiString __fastcall GetFrontPanelResetStatusStr();
	System::AnsiString __fastcall GetAdministratorPasswordStatusStr();
	System::AnsiString __fastcall GetKeyboardPasswordStatusStr();
	System::AnsiString __fastcall GetPowerOnPasswordStatusStr();
public:
	/* TObject.Create */ inline __fastcall THardwareSecurityInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~THardwareSecurityInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSystemPowerControlsInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte NextScheduledPowerOnMonth;
	System::Byte NextScheduledPowerOnDayOfMonth;
	System::Byte NextScheduledPowerOnHour;
	System::Byte NextScheduledPowerOnMinute;
	System::Byte NextScheduledPowerOnSecond;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSystemPowerControlsInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TSystemPowerControlsInfo *RAWSystemPowerControlsInfo;
	bool __fastcall HasValidScheduledPowerOnTime();
	System::Byte __fastcall GetNextScheduledPowerOnMonth();
	System::Byte __fastcall GetNextScheduledPowerOnDayOfMonth();
	System::Byte __fastcall GetNextScheduledPowerOnHour();
	System::Byte __fastcall GetNextScheduledPowerOnMinute();
	System::Byte __fastcall GetNextScheduledPowerOnSecond();
public:
	/* TObject.Create */ inline __fastcall TSystemPowerControlsInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TSystemPowerControlsInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TVoltageProbeInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Description;
	System::Byte LocationandStatus;
	System::Word MaximumValue;
	System::Word MinimumValue;
	System::Word Resolution;
	System::Word Tolerance;
	System::Word Accuracy;
	DWORD OEMdefined;
	System::Word NominalValue;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TVoltageProbeInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TVoltageProbeInfo *RAWVoltageProbeInfo;
	System::AnsiString __fastcall GetDescriptionStr();
	System::AnsiString __fastcall GetLocation();
	System::AnsiString __fastcall GetStatus();
	bool __fastcall HasNominalValue();
	System::Word __fastcall GetNominalValue();
public:
	/* TObject.Create */ inline __fastcall TVoltageProbeInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TVoltageProbeInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TCoolingDeviceInfo
{
public:
	TSmBiosTableHeader Header;
	System::Word TemperatureProbeHandle;
	System::Byte DeviceTypeandStatus;
	System::Byte CoolingUnitGroup;
	DWORD OEMdefined;
	System::Word NominalSpeed;
	System::Byte Description;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TCoolingDeviceInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TCoolingDeviceInfo *RAWCoolingDeviceInfo;
	System::AnsiString __fastcall GetDescriptionStr();
	bool __fastcall HasDescription();
	System::AnsiString __fastcall GetDeviceType();
	System::AnsiString __fastcall GetStatus();
public:
	/* TObject.Create */ inline __fastcall TCoolingDeviceInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TCoolingDeviceInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TTemperatureProbeInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Description;
	System::Byte LocationandStatus;
	System::Word MaximumValue;
	System::Word MinimumValue;
	System::Word Resolution;
	System::Word Tolerance;
	System::Word Accuracy;
	DWORD OEMdefined;
	System::Word NominalValue;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TTemperatureProbeInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TTemperatureProbeInfo *RAWTemperatureProbeInfo;
	System::AnsiString __fastcall GetDescriptionStr();
	System::AnsiString __fastcall GetLocation();
	System::AnsiString __fastcall GetStatus();
	bool __fastcall HasNominalValue();
	System::Word __fastcall GetNominalValue();
public:
	/* TObject.Create */ inline __fastcall TTemperatureProbeInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TTemperatureProbeInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TElectricalCurrentProbeInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Description;
	System::Byte LocationandStatus;
	System::Word MaximumValue;
	System::Word MinimumValue;
	System::Word Resolution;
	System::Word Tolerance;
	System::Word Accuracy;
	DWORD OEMdefined;
	System::Word NominalValue;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TElectricalCurrentProbeInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TElectricalCurrentProbeInfo *RAWElectricalCurrentProbeInfo;
	System::AnsiString __fastcall GetDescriptionStr();
	System::AnsiString __fastcall GetLocation();
	System::AnsiString __fastcall GetStatus();
	bool __fastcall HasNominalValue();
	System::Word __fastcall GetNominalValue();
public:
	/* TObject.Create */ inline __fastcall TElectricalCurrentProbeInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TElectricalCurrentProbeInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TOutOfBandRemoteAccessInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte ManufacturerName;
	System::Byte Connections;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TOutOfBandRemoteAccessInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TOutOfBandRemoteAccessInfo *RAWOutOfBandRemoteAccessInfo;
	System::AnsiString __fastcall GetManufacturerNameStr();
	bool __fastcall InboundConnectionEnabled();
	bool __fastcall OutboundConnectionEnabled();
public:
	/* TObject.Create */ inline __fastcall TOutOfBandRemoteAccessInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TOutOfBandRemoteAccessInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TBootIntegrityServicesEntryPointInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Checksum;
	System::Byte Reserved1;
	System::Word Reserved2;
	System::LongWord EntryPoint16;
	System::LongWord EntryPoint32;
	System::StaticArray<System::Byte, 12> Reserved3;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TBootIntegrityServicesEntryPointInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TBootIntegrityServicesEntryPointInfo *RAWBootIntegrityServicesEntryPointInfo;
	bool __fastcall IsStructureLengthValid();
	bool __fastcall ChecksumIsValid();
	System::Word __fastcall GetEntryPoint16Segment();
	System::Word __fastcall GetEntryPoint16Offset();
	bool __fastcall EntryPoint16IsValid();
	bool __fastcall EntryPoint32IsValid();
public:
	/* TObject.Create */ inline __fastcall TBootIntegrityServicesEntryPointInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TBootIntegrityServicesEntryPointInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSystemBootInfo
{
public:
	TSmBiosTableHeader Header;
	System::StaticArray<System::Byte, 6> Reserved;
	System::Byte BootStatus;
	System::StaticArray<System::Byte, 9> BootStatusAdditionalData;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSystemBootInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TSystemBootInfo *RAWSystemBootInfo;
	System::AnsiString __fastcall GetBootStatusStr();
	System::Byte __fastcall GetBootStatusAdditionalDataByte(const int Index);
public:
	/* TObject.Create */ inline __fastcall TSystemBootInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TSystemBootInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD Tx64BitMemoryErrorInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte ErrorType;
	System::Byte ErrorGranularity;
	System::Byte ErrorOperation;
	DWORD VendorSyndrome;
	__int64 MemoryArrayErrorAddress;
	__int64 DeviceErrorAddress;
	DWORD ErrorResolution;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION Tx64BitMemoryErrorInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Tx64BitMemoryErrorInfo *RAWx64BitMemoryErrorInfo;
	System::AnsiString __fastcall GetErrorTypeStr();
	System::AnsiString __fastcall GetErrorGranularityStr();
	System::AnsiString __fastcall GetErrorOperationStr();
public:
	/* TObject.Create */ inline __fastcall Tx64BitMemoryErrorInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~Tx64BitMemoryErrorInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TManagementDeviceInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Description;
	System::Byte DeviceType;
	DWORD Address;
	System::Byte AddressType;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TManagementDeviceInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TManagementDeviceInfo *RAWManagementDeviceInfo;
	System::AnsiString __fastcall GetDescriptionStr();
	System::AnsiString __fastcall GetDeviceTypeStr();
	System::AnsiString __fastcall GetAddressTypeStr();
public:
	/* TObject.Create */ inline __fastcall TManagementDeviceInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TManagementDeviceInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TManagementDeviceComponentInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte Description;
	System::Word ManagementDeviceHandle;
	System::Word ComponentHandle;
	System::Word ThresholdHandle;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TManagementDeviceComponentInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TManagementDeviceComponentInfo *RAWManagementDeviceComponentInfo;
	System::AnsiString __fastcall GetDescriptionStr();
public:
	/* TObject.Create */ inline __fastcall TManagementDeviceComponentInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TManagementDeviceComponentInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TManagementDeviceThresholdDataInfo
{
public:
	TSmBiosTableHeader Header;
	System::Word LowerThresholdNonCritical;
	System::Word UpperThresholdNonCritical;
	System::Word LowerThresholdCritical;
	System::Word UpperThresholdCritical;
	System::Word LowerThresholdNonRecoverable;
	System::Word UpperThresholdNonRecoverable;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TManagementDeviceThresholdDataInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TManagementDeviceThresholdDataInfo *RAWManagementDeviceThresholdDataInfo;
public:
	/* TObject.Create */ inline __fastcall TManagementDeviceThresholdDataInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TManagementDeviceThresholdDataInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TMemoryChannelInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte ChannelType;
	System::Byte MaximumChannelLoad;
	System::Byte MemoryDeviceCount;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TMemoryChannelInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TMemoryChannelInfo *RAWMemoryChannelInfo;
	System::AnsiString __fastcall GetChannelTypeStr();
	bool __fastcall HasMemoryDeviceEntry(int Index);
	System::Byte __fastcall GetMemoryDeviceLoad(int Index);
	System::Word __fastcall GetMemoryDeviceHandle(int Index);
public:
	/* TObject.Create */ inline __fastcall TMemoryChannelInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TMemoryChannelInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TIPMIDeviceInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte InterfaceType;
	System::Byte IPMISpecificationRevision;
	System::Byte I2CSlaveAddress;
	System::Byte NVStorageDeviceAddress;
	__int64 BaseAddress;
	System::Byte BaseAddressModifierInterruptInfo;
	System::Byte InterruptNumber;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TIPMIDeviceInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TIPMIDeviceInfo *RAWIPMIDeviceInfo;
	System::AnsiString __fastcall GetInterfaceTypeStr();
	System::AnsiString __fastcall GetSpecificationVersionStr();
public:
	/* TObject.Create */ inline __fastcall TIPMIDeviceInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TIPMIDeviceInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TSystemPowerSupplyInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte PowerUnitGroup;
	System::Byte Location;
	System::Byte DeviceName;
	System::Byte Manufacturer;
	System::Byte SerialNumber;
	System::Byte AssetTagNumber;
	System::Byte ModelPartNumber;
	System::Byte RevisionLevel;
	System::Word MaxPowerCapacity;
	System::Word PowerSupplyCharacteristics;
	System::Word InputVoltageProbeHandle;
	System::Word CoolingDeviceHandle;
	System::Word InputCurrentProbeHandle;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSystemPowerSupplyInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TSystemPowerSupplyInfo *RAWSystemPowerSupplyInfo;
	System::AnsiString __fastcall LocationStr();
	System::AnsiString __fastcall DeviceNameStr();
	System::AnsiString __fastcall ManufacturerStr();
	System::AnsiString __fastcall SerialNumberStr();
	System::AnsiString __fastcall AssetTagNumberStr();
	System::AnsiString __fastcall ModelPartNumberStr();
	System::AnsiString __fastcall RevisionLevelStr();
	bool __fastcall MaxPowerCapacityIsUnknown();
	bool __fastcall IsHotReplaceable();
	bool __fastcall IsPresent();
	bool __fastcall IsUnplugged();
	System::Byte __fastcall GetInputVoltageRangeSwitching();
	System::AnsiString __fastcall GetInputVoltageRangeSwitchingStr();
	System::Byte __fastcall GetStatus();
	System::AnsiString __fastcall GetStatusStr();
	System::Byte __fastcall GetPowerSupplyType();
	System::AnsiString __fastcall GetPowerSupplyTypeStr();
public:
	/* TObject.Create */ inline __fastcall TSystemPowerSupplyInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TSystemPowerSupplyInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TAdditionalInformationInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte NumberOfAdditionalInformationEntries;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TAdditionalInformationInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TAdditionalInformationInfo *RAWAdditionalInformationInfo;
	bool __fastcall HasAdditionalInformationEntry(int Index);
	System::Byte __fastcall GetAdditionalInformationEntryLength(int Index);
	System::Word __fastcall GetReferencedHandle(int Index);
	System::Byte __fastcall GetReferencedOffset(int Index);
	System::AnsiString __fastcall GetEntryStringStr(int Index);
	System::Byte __fastcall GetEntryValueSize(int Index);
	System::Byte __fastcall GetEntryValueByte(int Index, int ValueIndex);
public:
	/* TObject.Create */ inline __fastcall TAdditionalInformationInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TAdditionalInformationInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TOnboardDevicesExtendedInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte ReferenceDesignation;
	System::Byte DeviceType;
	System::Byte DeviceTypeInstance;
	System::Word SegmentGroupNumber;
	System::Byte BusNumber;
	System::Byte DeviceFunctionNumber;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TOnboardDevicesExtendedInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TOnboardDevicesExtendedInfo *RAWOnboardDevicesExtendedInfo;
	System::AnsiString __fastcall ReferenceDesignationStr();
	bool __fastcall Enabled();
	System::AnsiString __fastcall GetDeviceTypeStr();
	System::Byte __fastcall GetDeviceNumber();
	System::Byte __fastcall GetFunctionNumber();
public:
	/* TObject.Create */ inline __fastcall TOnboardDevicesExtendedInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TOnboardDevicesExtendedInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TManagementControllerHostInterfaceInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte InterfaceType;
	System::Byte InterfaceTypeSpecificDataLength;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TManagementControllerHostInterfaceInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TManagementControllerHostInterfaceInfo *RAWManagementControllerHostInterfaceInfo;
	System::AnsiString __fastcall GetInterfaceTypeStr();
	bool __fastcall HasInterfaceTypeSpecificData();
	System::Byte __fastcall GetInterfaceTypeSpecificDataByte(int Index);
	System::Byte __fastcall GetProtocolRecordCount();
	bool __fastcall HasProtocolRecord(int Index);
	System::Byte __fastcall GetProtocolType(int Index);
	System::AnsiString __fastcall GetProtocolTypeStr(int Index);
	System::Byte __fastcall GetProtocolTypeSpecificDataLength(int Index);
	System::Byte __fastcall GetProtocolTypeSpecificDataByte(int Index, int DataIndex);
public:
	/* TObject.Create */ inline __fastcall TManagementControllerHostInterfaceInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TManagementControllerHostInterfaceInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TTPMDeviceInfo
{
public:
	TSmBiosTableHeader Header;
	System::StaticArray<char, 4> VendorID;
	System::Byte MajorSpecVersion;
	System::Byte MinorSpecVersion;
	DWORD FirmwareVersion1;
	DWORD FirmwareVersion2;
	System::Byte Description;
	__int64 Characteristics;
	DWORD OEMDefined;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TStringPropertyInfo
{
public:
	TSmBiosTableHeader Header;
	System::Word StringPropertyID;
	System::Byte StringPropertyValue;
	System::Word ParentHandle;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TStringPropertyInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TStringPropertyInfo *RAWStringPropertyInfo;
	System::AnsiString __fastcall GetStringPropertyIDStr();
	System::AnsiString __fastcall StringPropertyValueStr();
public:
	/* TObject.Create */ inline __fastcall TStringPropertyInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TStringPropertyInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TTPMDeviceInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TTPMDeviceInfo *RAWTPMDeviceInfo;
	System::AnsiString __fastcall VendorIDStr();
	System::AnsiString __fastcall GetSpecificationVersionStr();
	System::AnsiString __fastcall DescriptionStr();
public:
	/* TObject.Create */ inline __fastcall TTPMDeviceInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TTPMDeviceInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TProcessorAdditionalInfo
{
public:
	TSmBiosTableHeader Header;
	System::Word ReferencedHandle;
	System::Byte ProcessorSpecificBlockLength;
	System::Byte ProcessorType;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TProcessorAdditionalInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TProcessorAdditionalInfo *RAWProcessorAdditionalInfo;
	System::AnsiString __fastcall GetProcessorTypeStr();
	System::Byte __fastcall GetProcessorSpecificDataSize();
public:
	/* TObject.Create */ inline __fastcall TProcessorAdditionalInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TProcessorAdditionalInformation() { }
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TFirmwareInventoryInfo
{
public:
	TSmBiosTableHeader Header;
	System::Byte FirmwareComponentName;
	System::Byte FirmwareVersion;
	System::Byte FirmwareVersionFormat;
	System::Byte FirmwareID;
	System::Byte FirmwareIDFormat;
	System::Byte ReleaseDate;
	System::Byte Manufacturer;
	System::Byte LowestSupportedFirmwareVersion;
	__int64 ImageSize;
	System::Word Characteristics;
	System::Byte State;
	System::Byte AssociatedComponentCount;
};
#pragma pack(pop)


#pragma pack(push,4)
class PASCALIMPLEMENTATION TFirmwareInventoryInformation : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TFirmwareInventoryInfo *RAWFirmwareInventoryInfo;
	System::AnsiString __fastcall FirmwareComponentNameStr();
	System::AnsiString __fastcall FirmwareVersionStr();
	System::AnsiString __fastcall FirmwareIDStr();
	System::AnsiString __fastcall ReleaseDateStr();
	System::AnsiString __fastcall ManufacturerStr();
	System::AnsiString __fastcall LowestSupportedFirmwareVersionStr();
	System::AnsiString __fastcall GetStateStr();
	System::Word __fastcall GetAssociatedComponentHandle(System::Byte Index);
public:
	/* TObject.Create */ inline __fastcall TFirmwareInventoryInformation() : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TFirmwareInventoryInformation() { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TSMBiosTableEntry
{
public:
	TSmBiosTableHeader Header;
	int index;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TSMBios : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TRawSMBIOSData FRawSMBIOSData;
	System::AnsiString FDataString;
	TBiosInformation* FBiosInfo;
	TSystemInformation* FSysInfo;
	System::DynamicArray<TBaseBoardInformation*> FBaseBoardInfo;
	System::DynamicArray<TEnclosureInformation*> FEnclosureInfo;
	System::DynamicArray<TProcessorInformation*> FProcessorInfo;
	System::DynamicArray<TCacheInformation*> FCacheInfo;
	System::DynamicArray<TPortConnectorInformation*> FPortConnectorInfo;
	System::DynamicArray<TSystemSlotInformation*> FSystemSlotInfo;
	System::DynamicArray<TSMBiosTableEntry> FSMBiosTablesList;
	System::DynamicArray<TOEMStringsInformation*> FOEMStringsInfo;
	System::DynamicArray<TBIOSLanguageInformation*> FBIOSLanguageInfo;
	System::DynamicArray<TSystemConfInformation*> FSystemConfInfo;
	System::DynamicArray<TPhysicalMemoryArrayInformation*> FPhysicalMemoryArrayInfo;
	System::DynamicArray<TMemoryDeviceInformation*> FMemoryDeviceInfo;
	System::DynamicArray<TBatteryInformation*> FBatteryInformation;
	System::DynamicArray<TSystemResetInformation*> FSystemResetInformation;
	System::DynamicArray<THardwareSecurityInformation*> FHardwareSecurityInformation;
	System::DynamicArray<TSystemPowerControlsInformation*> FSystemPowerControlsInformation;
	System::DynamicArray<TMemoryErrorInformation*> FMemoryErrorInformation;
	System::DynamicArray<TMemoryArrayMappedAddressInformation*> FMemoryArrayMappedAddressInformation;
	System::DynamicArray<TMemoryDeviceMappedAddressInformation*> FMemoryDeviceMappedAddressInformation;
	System::DynamicArray<TBuiltInPointingDeviceInformation*> FBuiltInPointingDeviceInformation;
	System::DynamicArray<TVoltageProbeInformation*> FVoltageProbeInformation;
	System::DynamicArray<TCoolingDeviceInformation*> FCoolingDeviceInformation;
	System::DynamicArray<TTemperatureProbeInformation*> FTemperatureProbeInformation;
	System::DynamicArray<TElectricalCurrentProbeInformation*> FElectricalCurrentProbeInformation;
	System::DynamicArray<TOutOfBandRemoteAccessInformation*> FOutOfBandRemoteAccessInformation;
	System::DynamicArray<TBootIntegrityServicesEntryPointInformation*> FBootIntegrityServicesEntryPointInformation;
	System::DynamicArray<TSystemBootInformation*> FSystemBootInformation;
	System::DynamicArray<Tx64BitMemoryErrorInformation*> Fx64BitMemoryErrorInformation;
	System::DynamicArray<TOnBoardSystemInformation*> FOnBoardSystemInfo;
	System::DynamicArray<TMemoryControllerInformation*> FMemoryControllerInfo;
	System::DynamicArray<TMemoryModuleInformation*> FMemoryModuleInfo;
	System::DynamicArray<TGroupAssociationsInformation*> FGroupAssociationsInformation;
	System::DynamicArray<TSystemEventLogInformation*> FSystemEventLogInfo;
	System::DynamicArray<TManagementDeviceInformation*> FManagementDeviceInfo;
	System::DynamicArray<TManagementDeviceComponentInformation*> FManagementDeviceComponentInfo;
	System::DynamicArray<TManagementDeviceThresholdDataInformation*> FManagementDeviceThresholdDataInfo;
	System::DynamicArray<TMemoryChannelInformation*> FMemoryChannelInfo;
	System::DynamicArray<TIPMIDeviceInformation*> FIPMIDeviceInfo;
	System::DynamicArray<TSystemPowerSupplyInformation*> FSystemPowerSupplyInfo;
	System::DynamicArray<TAdditionalInformationInformation*> FAdditionalInformationInfo;
	System::DynamicArray<TOnboardDevicesExtendedInformation*> FOnboardDevicesExtendedInfo;
	System::DynamicArray<TManagementControllerHostInterfaceInformation*> FManagementControllerHostInterfaceInfo;
	System::DynamicArray<TTPMDeviceInformation*> FTPMDeviceInfo;
	System::DynamicArray<TProcessorAdditionalInformation*> FProcessorAdditionalInfo;
	System::DynamicArray<TFirmwareInventoryInformation*> FFirmwareInventoryInfo;
	System::DynamicArray<TStringPropertyInformation*> FStringPropertyInfo;
	void __fastcall LoadSMBIOSWinAPI();
	void __fastcall ClearSMBiosTables();
	void __fastcall ReadSMBiosTables();
	void __fastcall Init();
	System::DynamicArray<TSMBiosTableEntry> __fastcall GetSMBiosTablesList();
	int __fastcall GetSMBiosTablesCount();
	bool __fastcall GetHasBaseBoardInfo();
	bool __fastcall GetHasEnclosureInfo();
	bool __fastcall GetHasProcessorInfo();
	bool __fastcall GetHasCacheInfo();
	bool __fastcall GetHasPortConnectorInfo();
	bool __fastcall GetHasSystemSlotInfo();
	System::UnicodeString __fastcall GetSmbiosVersion();
	bool __fastcall GetHasOEMStringsInfo();
	bool __fastcall GetHasBIOSLanguageInfo();
	bool __fastcall GetHasSystemConfInfo();
	bool __fastcall GetHasPhysicalMemoryArrayInfo();
	bool __fastcall GetHasMemoryDeviceInfo();
	bool __fastcall GetHasMemoryErrorInfo();
	bool __fastcall GetHasBatteryInfo();
	bool __fastcall GetHasSystemResetInfo();
	bool __fastcall GetHasHardwareSecurityInfo();
	bool __fastcall GetHasSystemPowerControlsInfo();
	bool __fastcall GetHasMemoryArrayMappedAddressInfo();
	bool __fastcall GetHasMemoryDeviceMappedAddressInfo();
	bool __fastcall GetHasBuiltInPointingDeviceInfo();
	bool __fastcall GetHasVoltageProbeInfo();
	bool __fastcall GetHasCoolingDeviceInfo();
	bool __fastcall GetHasTemperatureProbeInfo();
	bool __fastcall GetHasElectricalCurrentProbeInfo();
	bool __fastcall GetHasOutOfBandRemoteAccessInfo();
	bool __fastcall GetHasBootIntegrityServicesEntryPointInfo();
	bool __fastcall GetHasSystemBootInfo();
	bool __fastcall GetHasx64BitMemoryErrorInfo();
	bool __fastcall GetHasOnBoardSystemInfo();
	bool __fastcall GetHasMemoryControllerInfo();
	bool __fastcall GetHasMemoryModuleInfo();
	bool __fastcall GetHasGroupAssociationsInfo();
	bool __fastcall GetHasSystemEventLogInfo();
	bool __fastcall GetHasManagementDeviceInfo();
	bool __fastcall GetHasManagementDeviceComponentInfo();
	bool __fastcall GetHasManagementDeviceThresholdDataInfo();
	bool __fastcall GetHasMemoryChannelInfo();
	bool __fastcall GetHasIPMIDeviceInfo();
	bool __fastcall GetHasSystemPowerSupplyInfo();
	bool __fastcall GetHasAdditionalInformationInfo();
	bool __fastcall GetHasOnboardDevicesExtendedInfo();
	bool __fastcall GetHasManagementControllerHostInterfaceInfo();
	bool __fastcall GetHasTPMDeviceInfo();
	bool __fastcall GetHasProcessorAdditionalInfo();
	bool __fastcall GetHasFirmwareInventoryInfo();
	bool __fastcall GetHasStringPropertyInfo();
	
public:
	__fastcall TSMBios(bool LoadBiosData)/* overload */;
	__fastcall TSMBios(const System::UnicodeString FileName)/* overload */;
	__fastcall virtual ~TSMBios();
	int __fastcall SearchSMBiosTable(TSMBiosTablesTypes TableType);
	int __fastcall GetSMBiosTableNextIndex(TSMBiosTablesTypes TableType, int Offset = 0x0);
	int __fastcall GetSMBiosTableEntries(TSMBiosTablesTypes TableType);
	System::AnsiString __fastcall GetSMBiosString(int Entry, int index);
	void __fastcall SaveToFile(const System::UnicodeString FileName);
	void __fastcall LoadFromFile(const System::UnicodeString FileName, bool LoadSMBIOSTables = false);
	void __fastcall LoadFromStream(System::Classes::TStream* const Stream, bool LoadSMBIOSTables = false);
	void __fastcall FindAndLoadFromFile(const System::UnicodeString FileName);
	void __fastcall FindAndLoadFromStream(System::Classes::TStream* const Stream);
	__property System::AnsiString DataString = {read=FDataString};
	__property TRawSMBIOSData RawSMBIOSData = {read=FRawSMBIOSData};
	__property System::UnicodeString SmbiosVersion = {read=GetSmbiosVersion};
	__property System::DynamicArray<TSMBiosTableEntry> SMBiosTablesList = {read=FSMBiosTablesList};
	__property TBiosInformation* BiosInfo = {read=FBiosInfo};
	__property TSystemInformation* SysInfo = {read=FSysInfo};
	__property System::DynamicArray<TBaseBoardInformation*> BaseBoardInfo = {read=FBaseBoardInfo};
	__property bool HasBaseBoardInfo = {read=GetHasBaseBoardInfo, nodefault};
	__property System::DynamicArray<TEnclosureInformation*> EnclosureInfo = {read=FEnclosureInfo};
	__property bool HasEnclosureInfo = {read=GetHasEnclosureInfo, nodefault};
	__property System::DynamicArray<TCacheInformation*> CacheInfo = {read=FCacheInfo};
	__property bool HasCacheInfo = {read=GetHasCacheInfo, nodefault};
	__property System::DynamicArray<TProcessorInformation*> ProcessorInfo = {read=FProcessorInfo};
	__property bool HasProcessorInfo = {read=GetHasProcessorInfo, nodefault};
	__property System::DynamicArray<TMemoryControllerInformation*> MemoryControllerInfo = {read=FMemoryControllerInfo};
	__property bool HasMemoryControllerInfo = {read=GetHasMemoryControllerInfo, nodefault};
	__property System::DynamicArray<TPortConnectorInformation*> PortConnectorInfo = {read=FPortConnectorInfo};
	__property bool HasPortConnectorInfo = {read=GetHasPortConnectorInfo, nodefault};
	__property System::DynamicArray<TSystemSlotInformation*> SystemSlotInfo = {read=FSystemSlotInfo};
	__property bool HasSystemSlotInfo = {read=GetHasSystemSlotInfo, nodefault};
	__property System::DynamicArray<TOnBoardSystemInformation*> OnBoardSystemInfo = {read=FOnBoardSystemInfo};
	__property bool HasOnBoardSystemInfo = {read=GetHasOnBoardSystemInfo, nodefault};
	__property System::DynamicArray<TOEMStringsInformation*> OEMStringsInfo = {read=FOEMStringsInfo};
	__property bool HasOEMStringsInfo = {read=GetHasOEMStringsInfo, nodefault};
	__property System::DynamicArray<TBIOSLanguageInformation*> BIOSLanguageInfo = {read=FBIOSLanguageInfo};
	__property bool HasBIOSLanguageInfo = {read=GetHasBIOSLanguageInfo, nodefault};
	__property System::DynamicArray<TSystemConfInformation*> SystemConfInfo = {read=FSystemConfInfo};
	__property bool HasSystemConfInfo = {read=GetHasSystemConfInfo, nodefault};
	__property System::DynamicArray<TPhysicalMemoryArrayInformation*> PhysicalMemoryArrayInfo = {read=FPhysicalMemoryArrayInfo};
	__property bool HasPhysicalMemoryArrayInfo = {read=GetHasPhysicalMemoryArrayInfo, nodefault};
	__property System::DynamicArray<TMemoryDeviceInformation*> MemoryDeviceInfo = {read=FMemoryDeviceInfo};
	__property bool HasMemoryDeviceInfo = {read=GetHasMemoryDeviceInfo, nodefault};
	__property System::DynamicArray<TMemoryModuleInformation*> MemoryModuleInfo = {read=FMemoryModuleInfo};
	__property bool HasMemoryModuleInfo = {read=GetHasMemoryModuleInfo, nodefault};
	__property System::DynamicArray<TBatteryInformation*> BatteryInformation = {read=FBatteryInformation};
	__property bool HasBatteryInfo = {read=GetHasBatteryInfo, nodefault};
	__property System::DynamicArray<TSystemResetInformation*> SystemResetInformation = {read=FSystemResetInformation};
	__property bool HasSystemResetInfo = {read=GetHasSystemResetInfo, nodefault};
	__property System::DynamicArray<THardwareSecurityInformation*> HardwareSecurityInformation = {read=FHardwareSecurityInformation};
	__property bool HasHardwareSecurityInfo = {read=GetHasHardwareSecurityInfo, nodefault};
	__property System::DynamicArray<TSystemPowerControlsInformation*> SystemPowerControlsInformation = {read=FSystemPowerControlsInformation};
	__property bool HasSystemPowerControlsInfo = {read=GetHasSystemPowerControlsInfo, nodefault};
	__property System::DynamicArray<TMemoryArrayMappedAddressInformation*> MemoryArrayMappedAddressInformation = {read=FMemoryArrayMappedAddressInformation};
	__property bool HasMemoryArrayMappedAddressInfo = {read=GetHasMemoryArrayMappedAddressInfo, nodefault};
	__property System::DynamicArray<TMemoryErrorInformation*> MemoryErrorInfo = {read=FMemoryErrorInformation};
	__property bool HasMemoryErrorInfo = {read=GetHasMemoryErrorInfo, nodefault};
	__property System::DynamicArray<TMemoryDeviceMappedAddressInformation*> MemoryDeviceMappedAddressInformation = {read=FMemoryDeviceMappedAddressInformation};
	__property bool HasMemoryDeviceMappedAddressInfo = {read=GetHasMemoryDeviceMappedAddressInfo, nodefault};
	__property System::DynamicArray<TBuiltInPointingDeviceInformation*> BuiltInPointingDeviceInformation = {read=FBuiltInPointingDeviceInformation};
	__property bool HasBuiltInPointingDeviceInfo = {read=GetHasBuiltInPointingDeviceInfo, nodefault};
	__property System::DynamicArray<TVoltageProbeInformation*> VoltageProbeInformation = {read=FVoltageProbeInformation};
	__property bool HasVoltageProbeInfo = {read=GetHasVoltageProbeInfo, nodefault};
	__property System::DynamicArray<TCoolingDeviceInformation*> CoolingDeviceInformation = {read=FCoolingDeviceInformation};
	__property bool HasCoolingDeviceInfo = {read=GetHasCoolingDeviceInfo, nodefault};
	__property System::DynamicArray<TTemperatureProbeInformation*> TemperatureProbeInformation = {read=FTemperatureProbeInformation};
	__property bool HasTemperatureProbeInfo = {read=GetHasTemperatureProbeInfo, nodefault};
	__property System::DynamicArray<TElectricalCurrentProbeInformation*> ElectricalCurrentProbeInformation = {read=FElectricalCurrentProbeInformation};
	__property bool HasElectricalCurrentProbeInfo = {read=GetHasElectricalCurrentProbeInfo, nodefault};
	__property System::DynamicArray<TOutOfBandRemoteAccessInformation*> OutOfBandRemoteAccessInformation = {read=FOutOfBandRemoteAccessInformation};
	__property bool HasOutOfBandRemoteAccessInfo = {read=GetHasOutOfBandRemoteAccessInfo, nodefault};
	__property System::DynamicArray<TBootIntegrityServicesEntryPointInformation*> BootIntegrityServicesEntryPointInformation = {read=FBootIntegrityServicesEntryPointInformation};
	__property bool HasBootIntegrityServicesEntryPointInfo = {read=GetHasBootIntegrityServicesEntryPointInfo, nodefault};
	__property System::DynamicArray<TSystemBootInformation*> SystemBootInfo = {read=FSystemBootInformation};
	__property bool HasSystemBootInfo = {read=GetHasSystemBootInfo, nodefault};
	__property System::DynamicArray<Tx64BitMemoryErrorInformation*> x64BitMemoryErrorInfo = {read=Fx64BitMemoryErrorInformation};
	__property bool Hasx64BitMemoryErrorInfo = {read=GetHasx64BitMemoryErrorInfo, nodefault};
	__property System::DynamicArray<TManagementDeviceInformation*> ManagementDeviceInfo = {read=FManagementDeviceInfo};
	__property bool HasManagementDeviceInfo = {read=GetHasManagementDeviceInfo, nodefault};
	__property System::DynamicArray<TManagementDeviceComponentInformation*> ManagementDeviceComponentInfo = {read=FManagementDeviceComponentInfo};
	__property bool HasManagementDeviceComponentInfo = {read=GetHasManagementDeviceComponentInfo, nodefault};
	__property System::DynamicArray<TManagementDeviceThresholdDataInformation*> ManagementDeviceThresholdDataInfo = {read=FManagementDeviceThresholdDataInfo};
	__property bool HasManagementDeviceThresholdDataInfo = {read=GetHasManagementDeviceThresholdDataInfo, nodefault};
	__property System::DynamicArray<TMemoryChannelInformation*> MemoryChannelInfo = {read=FMemoryChannelInfo};
	__property bool HasMemoryChannelInfo = {read=GetHasMemoryChannelInfo, nodefault};
	__property System::DynamicArray<TIPMIDeviceInformation*> IPMIDeviceInfo = {read=FIPMIDeviceInfo};
	__property bool HasIPMIDeviceInfo = {read=GetHasIPMIDeviceInfo, nodefault};
	__property System::DynamicArray<TSystemPowerSupplyInformation*> SystemPowerSupplyInfo = {read=FSystemPowerSupplyInfo};
	__property bool HasSystemPowerSupplyInfo = {read=GetHasSystemPowerSupplyInfo, nodefault};
	__property System::DynamicArray<TAdditionalInformationInformation*> AdditionalInformationInfo = {read=FAdditionalInformationInfo};
	__property bool HasAdditionalInformationInfo = {read=GetHasAdditionalInformationInfo, nodefault};
	__property System::DynamicArray<TOnboardDevicesExtendedInformation*> OnboardDevicesExtendedInfo = {read=FOnboardDevicesExtendedInfo};
	__property bool HasOnboardDevicesExtendedInfo = {read=GetHasOnboardDevicesExtendedInfo, nodefault};
	__property System::DynamicArray<TManagementControllerHostInterfaceInformation*> ManagementControllerHostInterfaceInfo = {read=FManagementControllerHostInterfaceInfo};
	__property bool HasManagementControllerHostInterfaceInfo = {read=GetHasManagementControllerHostInterfaceInfo, nodefault};
	__property System::DynamicArray<TTPMDeviceInformation*> TPMDeviceInfo = {read=FTPMDeviceInfo};
	__property bool HasTPMDeviceInfo = {read=GetHasTPMDeviceInfo, nodefault};
	__property System::DynamicArray<TProcessorAdditionalInformation*> ProcessorAdditionalInfo = {read=FProcessorAdditionalInfo};
	__property bool HasProcessorAdditionalInfo = {read=GetHasProcessorAdditionalInfo, nodefault};
	__property System::DynamicArray<TFirmwareInventoryInformation*> FirmwareInventoryInfo = {read=FFirmwareInventoryInfo};
	__property bool HasFirmwareInventoryInfo = {read=GetHasFirmwareInventoryInfo, nodefault};
	__property System::DynamicArray<TStringPropertyInformation*> StringPropertyInfo = {read=FStringPropertyInfo};
	__property bool HasStringPropertyInfo = {read=GetHasStringPropertyInfo, nodefault};
	__property System::DynamicArray<TGroupAssociationsInformation*> GroupAssociationsInformation = {read=FGroupAssociationsInformation};
	__property bool HasGroupAssociationsInfo = {read=GetHasGroupAssociationsInfo, nodefault};
	__property System::DynamicArray<TSystemEventLogInformation*> SystemEventLogInfo = {read=FSystemEventLogInfo};
	__property bool HasSystemEventLogInfo = {read=GetHasSystemEventLogInfo, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE Usmbios__1 SMBiosTablesDescr;
extern DELPHI_PACKAGE Usmbios__8 ErrorCorrectionTypeStr;
extern DELPHI_PACKAGE Usmbios__9 SystemCacheTypeStr;
extern DELPHI_PACKAGE bool __fastcall SMBiosAtLeast(TSMBios* const ASMBios, int Major, int Minor);
}	/* namespace Usmbios */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_USMBIOS)
using namespace Usmbios;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// uSMBIOSHPP
