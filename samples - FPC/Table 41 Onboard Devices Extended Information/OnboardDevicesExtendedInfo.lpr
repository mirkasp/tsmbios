program OnboardDevicesExtendedInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetOnboardDevicesExtendedInfo;
var
  SMBios: TSMBios;
  LInfo: TOnboardDevicesExtendedInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Onboard Devices Extended Information');
    WriteLn('------------------------------------');
    if SMBiosAtLeast(SMBios, 2, 6) and SMBios.HasOnboardDevicesExtendedInfo then
      for LInfo in SMBios.OnboardDevicesExtendedInfo do
      begin
        WriteLn(Format('Designation     %s', [LInfo.ReferenceDesignationStr]));
        WriteLn(Format('Device Type     %s', [LInfo.GetDeviceTypeStr]));
        WriteLn(Format('Enabled         %s', [BoolToStr(LInfo.Enabled, True)]));
        WriteLn(Format('Type Instance   %d', [LInfo.RAWOnboardDevicesExtendedInfo^.DeviceTypeInstance]));
        WriteLn(Format('PCI Location    %.4x:%.2x:%.2x.%d', [
          LInfo.RAWOnboardDevicesExtendedInfo^.SegmentGroupNumber,
          LInfo.RAWOnboardDevicesExtendedInfo^.BusNumber,
          LInfo.GetDeviceNumber, LInfo.GetFunctionNumber]));
        WriteLn;
      end
    else
      WriteLn('No Onboard Devices Extended Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetOnboardDevicesExtendedInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
