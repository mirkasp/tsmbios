program TPMDeviceInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetTPMDeviceInfo;
var
  SMBios: TSMBios;
  LInfo: TTPMDeviceInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('TPM Device Information');
    WriteLn('----------------------');
    if SMBiosAtLeast(SMBios, 3, 1) and SMBios.HasTPMDeviceInfo then
      for LInfo in SMBios.TPMDeviceInfo do
      begin
        WriteLn(Format('Vendor ID       %s', [LInfo.VendorIDStr]));
        WriteLn(Format('TPM Version     %s', [LInfo.GetSpecificationVersionStr]));
        WriteLn(Format('Firmware 1      %.8x', [LInfo.RAWTPMDeviceInfo^.FirmwareVersion1]));
        WriteLn(Format('Firmware 2      %.8x', [LInfo.RAWTPMDeviceInfo^.FirmwareVersion2]));
        WriteLn(Format('Description     %s', [LInfo.DescriptionStr]));
        WriteLn(Format('OEM Defined     %.8x', [LInfo.RAWTPMDeviceInfo^.OEMDefined]));
        WriteLn;
      end
    else
      WriteLn('No TPM Device Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetTPMDeviceInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
