program ManagementDeviceThresholdInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetManagementDeviceThresholdInfo;
var
  SMBios: TSMBios;
  LThresholdInfo: TManagementDeviceThresholdDataInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Management Device Threshold Data');
    WriteLn('--------------------------------');
    if SMBiosAtLeast(SMBios, 2, 3) and SMBios.HasManagementDeviceThresholdDataInfo then
      for LThresholdInfo in SMBios.ManagementDeviceThresholdDataInfo do
      begin
        WriteLn(Format('Lower Non-critical      %d', [LThresholdInfo.RAWManagementDeviceThresholdDataInfo.LowerThresholdNonCritical]));
        WriteLn(Format('Upper Non-critical      %d', [LThresholdInfo.RAWManagementDeviceThresholdDataInfo.UpperThresholdNonCritical]));
        WriteLn(Format('Lower Critical          %d', [LThresholdInfo.RAWManagementDeviceThresholdDataInfo.LowerThresholdCritical]));
        WriteLn(Format('Upper Critical          %d', [LThresholdInfo.RAWManagementDeviceThresholdDataInfo.UpperThresholdCritical]));
        WriteLn(Format('Lower Non-recoverable   %d', [LThresholdInfo.RAWManagementDeviceThresholdDataInfo.LowerThresholdNonRecoverable]));
        WriteLn(Format('Upper Non-recoverable   %d', [LThresholdInfo.RAWManagementDeviceThresholdDataInfo.UpperThresholdNonRecoverable]));
        WriteLn;
      end
    else
      WriteLn('No Management Device Threshold Data Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetManagementDeviceThresholdInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
