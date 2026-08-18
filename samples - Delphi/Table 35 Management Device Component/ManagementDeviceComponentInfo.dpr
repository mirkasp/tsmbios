program ManagementDeviceComponentInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetManagementDeviceComponentInfo;
var
  SMBios: TSMBios;
  LManagementDeviceComponentInfo: TManagementDeviceComponentInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Management Device Component');
    WriteLn('---------------------------');
    if SMBiosAtLeast(SMBios, 2, 3) and SMBios.HasManagementDeviceComponentInfo then
      for LManagementDeviceComponentInfo in SMBios.ManagementDeviceComponentInfo do
      begin
        WriteLn(Format('Description               %s', [LManagementDeviceComponentInfo.GetDescriptionStr]));
        WriteLn(Format('Management Device Handle  %.4x', [LManagementDeviceComponentInfo.RAWManagementDeviceComponentInfo.ManagementDeviceHandle]));
        WriteLn(Format('Component Handle          %.4x', [LManagementDeviceComponentInfo.RAWManagementDeviceComponentInfo.ComponentHandle]));
        WriteLn(Format('Threshold Handle          %.4x', [LManagementDeviceComponentInfo.RAWManagementDeviceComponentInfo.ThresholdHandle]));
        WriteLn;
      end
    else
      WriteLn('No Management Device Component Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetManagementDeviceComponentInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
