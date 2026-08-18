program ManagementDeviceInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetManagementDeviceInfo;
var
  SMBios: TSMBios;
  LManagementDeviceInfo: TManagementDeviceInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Management Device');
    WriteLn('-----------------');
    if SMBiosAtLeast(SMBios, 2, 3) and SMBios.HasManagementDeviceInfo then
      for LManagementDeviceInfo in SMBios.ManagementDeviceInfo do
      begin
        WriteLn(Format('Description   %s', [LManagementDeviceInfo.GetDescriptionStr]));
        WriteLn(Format('Device Type   %.2x - %s', [LManagementDeviceInfo.RAWManagementDeviceInfo.DeviceType, LManagementDeviceInfo.GetDeviceTypeStr]));
        WriteLn(Format('Address       %.8x', [LManagementDeviceInfo.RAWManagementDeviceInfo.Address]));
        WriteLn(Format('Address Type  %.2x - %s', [LManagementDeviceInfo.RAWManagementDeviceInfo.AddressType, LManagementDeviceInfo.GetAddressTypeStr]));
        WriteLn;
      end
    else
      WriteLn('No Management Device Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetManagementDeviceInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
