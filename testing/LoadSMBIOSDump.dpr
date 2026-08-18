program LoadSMBIOSDump;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  System.NetEncoding,
  uSMBIOS in '..\source\uSMBIOS.pas';

{ ================================================================ }
{  SMBIOS Dump                                                     }
{ ================================================================ }
{  Source        : Official DMTF SMBIOS Specification Sample       }
{  SMBIOS Version: 3.2.0                                           }
{  Entry Point   : SMBIOS 3.x (64-bit) - _SM3_                     }
{  Total Size    : ~1874 bytes (after Base64 decoding)             }
{  Tables included:                                                }
{    - Type 0   (BIOS Information)                                 }
{    - Type 1   (System Information)                               }
{    - Type 2   (Baseboard Information)                            }
{    - Type 3   (Chassis Information)                              }
{    - Type 4   (Processor Information) x2                         }
{    - Type 7   (Cache Information) x3                             }
{    - Type 9   (System Slots) x5                                  }
{    - Type 16  (Physical Memory Array)                            }
{    - Type 17  (Memory Device) x4                                 }
{    - Type 19  (Memory Array Mapped Address)                      }
{    - Type 32  (System Boot Information)                          }
{    - Type 127 (End of Table)                                     }
{ ================================================================ }

const
  SMBIOS_Sample_3_2_Base64: string =
    'X1NNM1/cGAMCAAEAVAkAABgAAAAAAAAAABgAAAECAPADD4CYi38BAAAAMwcID///U2FtcGxlIEJp' +
    'b3MgVmVuZG9yAFExLjA5Lnh5egAwOS8wMS8yMDIwAAABGwEAAQIDBAACAAMABAAFAAYABwAIAAkG' +
    'BQZTYW1wbGUgU3lzdGVtIE1hbnVmYWN0dXJlcgBTYW1wbGUgU3lzdGVtIE1vZGVsAFNhbXBsZSBT' +
    'eXN0ZW0gUmV2aXNpb24AU2FtcGxlIFN5c3RlbSBTZXJpYWwgTnVtYmVyAFRvIEJlIEZpbGxlZCBC' +
    'eSBPLkUuTS4AVG8gQmUgRmlsbGVkIEJ5IE8uRS5NLgAAAg8CAAECAwQFCQYDAAoAU2FtcGxlIEJh' +
    'c2Vib2FyZCBNYW51ZmFjdHVyZXIAU2FtcGxlIEJhc2Vib2FyZCBNb2RlbABTYW1wbGUgQmFzZWJv' +
    'YXJkIFJldmlzaW9uAFNhbXBsZSBCYXNlYm9hcmQgU2VyaWFsIE51bWJlcgBUbyBCZSBGaWxsZWQg' +
    'QnkgTy5FLk0uAFRvIEJlIEZpbGxlZCBCeSBPLkUuTS4AAAMVAwABAwIDBAMDAwMAAAAAAAEAAFNh' +
    'bXBsZSBDaGFzc2lzIE1hbnVmYWN0dXJlcgBTYW1wbGUgQ2hhc3NpcyBSZXZpc2lvbgBTYW1wbGUg' +
    'Q2hhc3NpcyBTZXJpYWwgTnVtYmVyAFRvIEJlIEZpbGxlZCBCeSBPLkUuTS4AAAQoBAABA8YCpQYB' +
    'AP/7678DAIUAagpABkEBBQAGAAcABAUGBAQIBABDUFVTb2NrZXQAU2FtcGxlIFByb2Nlc3NvciBN' +
    'YW51ZmFjdHVyZXIAU2FtcGxlIFByb2Nlc3NvciBSZXZpc2lvbgBTYW1wbGUgUHJvY2Vzc29yIFNl' +
    'cmlhbCBOdW1iZXIAVG8gQmUgRmlsbGVkIEJ5IE8uRS5NLgBUbyBCZSBGaWxsZWQgQnkgTy5FLk0u' +
    'AAAEKAQAAQPvAqUGAQD/++u/AwCFAGoKQAZBBgUABgAHAAQFBgQECAQAQ1BVU29ja2V0AFNhbXBs' +
    'ZSBDUFUgTWFudWZhY3R1cmVyAFNhbXBsZSBDUFUgUmV2aXNpb24AU2FtcGxlIENQVSBTZXJpYWwg' +
    'TnVtYmVyAFRvIEJlIEZpbGxlZCBCeSBPLkUuTS4AVG8gQmUgRmlsbGVkIEJ5IE8uRS5NLgAABxMF' +
    'AAGAAAABAAEBAAEAAAQDBUwxLUNhY2hlAAAHEwYAAYEAAAQABAEAAQAABQUHTDItQ2FjaGUAAAcT' +
    'BwABggEAIAAgAQABAAAFBQhMMy1DYWNoZQAACQ0IAAEGBQMDAQAMAVBDSTEAAAkNCQABBgUDAwIA' +
    'DAFQQ0kyAAAJDQoAAaUIBAMRAAwBUENJRTEAAAkNCwABpQ0DAxIADAFQQ0lFMgAACQ0MAAGlCAMD' +
    'EwAMAVBDSUUzAAAJDQ0AAaUNBAMUAAwBUENJRTQAAAkNDgABpQoDAxUADAFQQ0lFNQAAEA8PAAMD' +
    'BgAAAAz+/wYAAAATDxAAAAAAAP//vwAPAAQAABFUEQAPAP7/SABAAAAICQABAhgCADUFAwQFBgAA' +
    'AAAAAAAAAAAAAAABAAAHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAERJ' +
    'TU0wAEJBTkswAFNhbXBsZSBSQU0gTWFudWZhY3R1cmVyAFNhbXBsZSBSQU0gU2VyaWFsIE51bWJl' +
    'ciAxAEFzc2V0VGFnTnVtMABTYW1wbGUgUkFNIE1vZGVsAFNhbXBsZSBSQU0gUmV2aXNpb24AABQT' +
    'EgAAAAAA//8fABEAEAABAAEAABFUEwAPAP7/SABAAAAICQABAhgCADUFAwQFAAAAAAAAAAAAAAAA' +
    'AAABAAAHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAERJTU0xAEJBTmsx' +
    'AFNhbXBsZSBSQU0gTWFudWZhY3R1cmVyAFNhbXBsZSBSQU0gU2VyaWFsIE51bWJlciAyAEFzc2V0' +
    'VGFnTnVtMQBTYW1wbGUgUkFNIE1vZGVsAFNhbXBsZSBSQU0gUmV2aXNpb24AABQTFAAAACAA//8/' +
    'ABMAEAABAAEAABFUFQAPAP7/SABAAAAICQABAhgCADUFAwQFBgAAAAAAAAAAAAAAAAABAAAHAAAA' +
    'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAERJTU0yAEJBTmsyAFNhbXBsZSBS' +
    'QU0gTWFudWZhY3R1cmVyAFNhbXBsZSBSQU0gU2VyaWFsIE51bWJlciAzAEFzc2V0VGFnTnVtMgBT' +
    'YW1wbGUgUkFNIE1vZGVsAFNhbXBsZSBSQU0gUmV2aXNpb24AABQTFgAAAEAA//9fABUAEAABAAEA' +
    'ABFUFwAPAP7/SABAAAAICQABAhgCADUFAwQFBgAAAAAAAAAAAAAAAAABAAAHAAAAAAAAAAAAAAAA' +
    'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAERJTU0zAEJBTkszAFNhbXBsZSBSQU0gTWFudWZh' +
    'Y3R1cmVyAFNhbXBsZSBSQU0gU2VyaWFsIE51bWJlciA0AEFzc2V0VGFnTnVtMwBTYW1wbGUgUkFN' +
    'IE1vZGVsAFNhbXBsZSBSQU0gUmV2aXNpb24AABQTGAAAAGAA//9/ABcAEAABAAEAACAUHQAAAAAA' +
    'AAAAAAAAAAAAAAAAAnFiEAAAECAwQFBgeAABIJ////////U2FtcGxlIFBvd2VyIFN1cHBseSBM' +
    'b2NhdGlvbgBTYW1wbGUgUG93ZXIgU3VwcGx5IERldmljZSBOYW1lAFNhbXBsZSBQb3dlciBTdXBw' +
    'bHkgTWFudWZhY3R1cmVyAFNhbXBsZSBQb3dlciBTdXBwbHkgU2VyaWFsIE51bWJlcgBTYW1wbGUg' +
    'UG93ZXIgU3VwcGx5IEFzc2V0IFRhZyBOdW1iZXIAU2FtcGxlIFBvd2VyIFN1cHBseSBNb2RlbCBQ' +
    'YXJ0IE51bWJlcgBTYW1wbGUgUG93ZXIgU3VwcGx5IFJldmlzaW9uIExldmVsAAArHyMAQUJDAAIA' +
    'AQIDBAUGBwgBBAAAAAAAAAAAAAAAU2FtcGxlIFRQTSBEZXNjcmlwdGlvbgAAfwQlAAAA';


{ ================================================================ }
{  SMBIOS Dump                                                     }
{ ================================================================ }
{  Source        : Synthetic minimal SMBIOS sample based on the     }
{                  original dump format                            }
{  SMBIOS Version: 3.5.0                                           }
{  Entry Point   : SMBIOS 3.x (64-bit) - _SM3_                     }
{  Total Size    : 730 bytes after Base64 decoding                 }
{  Tables included:                                                }
{    - Type 0   (BIOS Information)                                 }
{    - Type 1   (System Information)                               }
{    - Type 2   (Baseboard Information)                            }
{    - Type 3   (Chassis Information)                              }
{    - Type 4   (Processor Information)                            }
{    - Type 38  (IPMI Device Information)                          }
{    - Type 43  (TPM Device)                                       }
{    - Type 44  (Processor Additional Information)                 }
{    - Type 45  (Firmware Inventory Information)                   }
{    - Type 127 (End of Table)                                     }
{ ================================================================ }

const
  SMBIOS_Sample_Minimal_3_5_Base64: string =
    'X1NNM1+KGAMFAAEAwgIAAAAAAAAAAAAAABgAAAECAAAD/wgAAAAAAAAAAwEDBf//U2FtcGxlIEJJ' +
    'T1MgVmVuZG9yAFEzLjA1Lm1pbgAwNi8wMi8yMDI2AAABGwEAAQIDBDMiEQBVRHdmiJmqu8zd7v8G' +
    'BQZTYW1wbGUgU3lzdGVtIE1hbnVmYWN0dXJlcgBNaW5pbWFsIFNNQklPUyBTYW1wbGUAMS4wAFNZ' +
    'Uy1NSU4tMDAwMQBTTUItVEVTVABTYW1wbGUgRmFtaWx5AAACDwIAAQIDBAUJBgMACgBTYW1wbGUg' +
    'QmFzZWJvYXJkIE1hbnVmYWN0dXJlcgBTYW1wbGUgQmFzZWJvYXJkADEuMABCQi1NSU4tMDAwMQBC' +
    'Qi1BU1NFVABNYWluIENoYXNzaXMAAAMVAwABAwIDBAMDAwMAAAAAAAEAAFNhbXBsZSBDaGFzc2lz' +
    'IE1hbnVmYWN0dXJlcgAxLjAAQ0gtTUlOLTAwMDEAQ0gtQVNTRVQAAAQwBAABA7MCv+v7/wAJBuoD' +
    'oWQAEA4oCkEF////////BAUGCAQC/AAAAAgABAACAENQVSBTb2NrZXQAU2FtcGxlIENQVSBNYW51' +
    'ZmFjdHVyZXIAU2FtcGxlIHg2NCBQcm9jZXNzb3IAQ1BVLVNOLTAwMDEAQ1BVLUFTU0VUAENQVS1Q' +
    'QVJULTAwMDEAACYSJgACICD/ogwAAAAAAAAAAAAAKx8rAElGWAACAFUABwABAAAAAQ8AAAAAAAAA' +
    'AAAAAFNhbXBsZSBUUE0gMi4wIERldmljZQAALAwsAAQABAIBAAAAAAAtHC0AAQIBAwEEBQYAAAAB' +
    'AAAAAAEAAwIrACYAVUVGSSBTeXN0ZW0gRmlybXdhcmUAMS4yLjMAVUVGSS0yMDI2LVNBTVBMRQAw' +
    'Ni8wMi8yMDI2AFNhbXBsZSBGaXJtd2FyZSBWZW5kb3IAMS4wLjAAAH8EfwAAAA==';


{ ================================================================ }
{  SMBIOS Dump                                                     }
{ ================================================================ }
{  Source        : Synthetic minimal SMBIOS sample based on the     }
{                  original dump format                            }
{  SMBIOS Version: 3.5.0                                           }
{  Entry Point   : SMBIOS 3.x (64-bit) - _SM3_                     }
{  Total Size    : 703 bytes after Base64 decoding                 }
{  Table Size    : 679 bytes                                       }
{  Tables included:                                                }
{    - Type 0   (BIOS Information)                                 }
{    - Type 1   (System Information)                               }
{    - Type 2   (Baseboard Information)                            }
{    - Type 3   (Chassis Information)                              }
{    - Type 22  (Portable Battery)                                 }
{    - Type 23  (System Reset)                                     }
{    - Type 26  (Voltage Probe)                                    }
{    - Type 27  (Cooling Device)                                   }
{    - Type 28  (Temperature Probe)                                }
{    - Type 29  (Electrical Current Probe)                         }
{    - Type 127 (End of Table)                                     }
{ ================================================================ }

const
  SMBIOS_Sample_Minimal_3_5_Type22_23_26_27_28_29_Base64: string =
    'X1NNM1+lGAMFAAEApwIAAAAAAAAAAAAAABgAAAECAOAD/wgAAAAAAAAAAwADBf//U2FtcGxlIEJJ' +
    'T1MgVmVuZG9yAFEzLjA1Lm1pbgAwNi8wMi8yMDI2AAABGwABAQIDBDMiEQBVRHdmiJmqu8zd7v8G' +
    'BQZTYW1wbGUgU3lzdGVtIE1hbnVmYWN0dXJlcgBNaW5pbWFsIFNNQklPUyBTYW1wbGUAMS4wAFNZ' +
    'Uy1NSU4tMDAwMQBTTUItVEVTVABTYW1wbGUgRmFtaWx5AAACDwACAQIDBAUJBgMACgBTYW1wbGUg' +
    'QmFzZWJvYXJkIE1hbnVmYWN0dXJlcgBTYW1wbGUgQmFzZWJvYXJkADEuMABCQi1NSU4tMDAwMQBC' +
    'Qi1BU1NFVABNYWluIENoYXNzaXMAAAMVAAMBAwIDBAMDAwMAAAAAAAEAAFNhbXBsZSBDaGFzc2lz' +
    'IE1hbnVmYWN0dXJlcgAxLjAAQ0gtTUlOLTAwMDEAQ0gtQVNTRVQAAAYaABYBAgMEBQLguCxGBlUE' +
    'NJohBwEAAAAASW50ZXJuYWwgQmF0dGVyeSBCYXkAU2FtcGxlIEJhdHRlcnkgTWFudWZhY3R1cmVy' +
    'ADA2LzAyLzIwMjYAQkFULVNOLTAwMDEAU2FtcGxlIExpLUlvbiBCYXR0ZXJ5AFNCRFMgMS4xAExp' +
    'T04AABcNABcGAAADAAoAPAAAGhYAGgFj4C4AAAoAZAD0AQAAAAiTExWwAUwEAAAAU2FtcGxlIENv' +
    'b2xpbmcgRmFuAAAcFgAcAWPoAwAAAQAFAGQAAAAAXgEdFgAdAWMgTgAACgBkAPQBAAAAALAEQ1BV' +
    'Q29yZSBDdXJyZW50AAB/BAB/AA==';

function AddBase64Padding(const AValue: string): string;
begin
  Result := AValue;
  while (Length(Result) mod 4) <> 0 do
    Result := Result + '=';
end;

function CreateSMBIOSFromBase64Dump(const ABase64Dump: string): TSMBios;
var
  DecodedDump: TBytes;
  Stream: TMemoryStream;
begin
  DecodedDump := TNetEncoding.Base64.DecodeStringToBytes(AddBase64Padding(ABase64Dump));
  Stream := TMemoryStream.Create;
  try
    Stream.WriteBuffer(DecodedDump[0], Length(DecodedDump));
    Stream.Position := 0;
    Result := TSMBios.Create(false);
    try
      Result.FindAndLoadFromStream(Stream);
    except
      Result.Free;
      raise;
    end;
  finally
    Stream.Free;
  end;
end;

procedure GetBIOSInfo(const SMBIOSDump: string);
var
  SMBios: TSMBios;
  LBIOS: TBiosInformation;
  OEMStr: TOEMStringsInformation;
  i: Integer;

  procedure WriteNameValueTableHeader(const ATitle: string);
  begin
    WriteLn(ATitle);
    WriteLn('+---------------------------------------------+------------------------------------------+');
    WriteLn('| Property                                    | Value                                    |');
    WriteLn('+---------------------------------------------+------------------------------------------+');
  end;

  procedure WriteNameValueRow(const AName, AValue: string);
  begin
    WriteLn(Format('| %-43s | %-40s |', [AName, AValue]));
  end;

  procedure WriteNameValueTableFooter;
  begin
    WriteLn('+---------------------------------------------+------------------------------------------+');
  end;

begin
  SMBios := CreateSMBIOSFromBase64Dump(SMBIOSDump);
  try
    LBIOS := SMBios.BIOSInfo;

    WriteNameValueTableHeader('BIOS Information');

    WriteNameValueRow('Vendor', LBIOS.VendorStr);
    WriteNameValueRow('Version', LBIOS.VersionStr);
    WriteNameValueRow('Start Segment', IntToHex(LBIOS.RAWBiosInformation.StartingSegment, 4));
    WriteNameValueRow('Release Date', LBIOS.ReleaseDateStr);

    if SMBiosAtLeast(SMBios, 3, 1) and
       (LBIOS.RAWBiosInformation.BiosRomSize = $FF) and
       LBIOS.HasExtendedBiosRomSize then
      WriteNameValueRow('BIOS ROM Size', Format('%d', [LBIOS.GetExtendedBiosRomSize]))
    else
      WriteNameValueRow('BIOS ROM Size', Format('%d KB', [64 * (LBIOS.RAWBiosInformation.BiosRomSize + 1)]));

    if LBIOS.RAWBiosInformation.SystemBIOSMajorRelease <> $FF then
      WriteNameValueRow('System BIOS Major Release',
        Format('%d', [LBIOS.RAWBiosInformation.SystemBIOSMajorRelease]));

    if LBIOS.RAWBiosInformation.SystemBIOSMinorRelease <> $FF then
      WriteNameValueRow('System BIOS Minor Release',
        Format('%d', [LBIOS.RAWBiosInformation.SystemBIOSMinorRelease]));

    if LBIOS.RAWBiosInformation.EmbeddedControllerFirmwareMajorRelease <> $FF then
      WriteNameValueRow('Embedded Controller Firmware Major Release',
        Format('%d', [LBIOS.RAWBiosInformation.EmbeddedControllerFirmwareMajorRelease]));

    if LBIOS.RAWBiosInformation.EmbeddedControllerFirmwareMinorRelease <> $FF then
      WriteNameValueRow('Embedded Controller Firmware Minor Release',
        Format('%d', [LBIOS.RAWBiosInformation.EmbeddedControllerFirmwareMinorRelease]));

    WriteNameValueTableFooter;
    WriteLn;

    if SMBios.HasOEMStringsInfo then
    begin
      WriteLn('OEM Strings');
      WriteLn('+-------+--------------------------------------------------------------+');
      WriteLn('| Index | Value                                                        |');
      WriteLn('+-------+--------------------------------------------------------------+');

      for OEMStr in SMBios.OEMStringsInfo do
        for i := 1 to OEMStr.RAWOEMStringsInformation.Count do
          WriteLn(Format('| %5d | %-60s |', [i, OEMStr.GetOEMString(i)]));

      WriteLn('+-------+--------------------------------------------------------------+');
      WriteLn;
    end;

    WriteLn(Format('%d SMBIOS tables found', [Length(SMBios.SMBiosTablesList)]));
    WriteLn('+------+----------+--------+--------+----------------------------------------------------+');
    WriteLn('| Type | Handle   | Length | Index  | Description                                        |');
    WriteLn('+------+----------+--------+--------+----------------------------------------------------+');

    for var Entry in SMBios.SMBiosTablesList do
    begin
      WriteLn(Format(
        '| %4d | %8.4X | %6d | %6d | %-50s |',
        [Entry.Header.TableType,
         Entry.Header.Handle,
         Entry.Header.Length,
         Entry.Index,
         SMBiosTablesDescr[Entry.Header.TableType]]));
    end;

    WriteLn('+------+----------+--------+--------+----------------------------------------------------+');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    //GetBIOSInfo(SMBIOS_Sample_3_2_Base64);
    GetBIOSInfo(SMBIOS_Sample_Minimal_3_5_Type22_23_26_27_28_29_Base64);
  except
    on E: Exception do
      WriteLn(E.Classname, ':', E.Message);
  end;
  WriteLn;
  WriteLn('Press Enter to exit');
  Readln;

end.
