program SystemPowerSupplyInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetSystemPowerSupplyInfo;
var
  SMBios: TSMBios;
  LInfo: TSystemPowerSupplyInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('System Power Supply');
    WriteLn('-------------------');
    if SMBiosAtLeast(SMBios, 2, 3) and SMBios.HasSystemPowerSupplyInfo then
      for LInfo in SMBios.SystemPowerSupplyInfo do
      begin
        WriteLn(Format('Power Unit Group  %d', [LInfo.RAWSystemPowerSupplyInfo^.PowerUnitGroup]));
        WriteLn(Format('Location          %s', [LInfo.LocationStr]));
        WriteLn(Format('Device Name       %s', [LInfo.DeviceNameStr]));
        WriteLn(Format('Manufacturer      %s', [LInfo.ManufacturerStr]));
        WriteLn(Format('Serial Number     %s', [LInfo.SerialNumberStr]));
        WriteLn(Format('Asset Tag         %s', [LInfo.AssetTagNumberStr]));
        WriteLn(Format('Model Part Number %s', [LInfo.ModelPartNumberStr]));
        WriteLn(Format('Revision Level    %s', [LInfo.RevisionLevelStr]));
        if LInfo.MaxPowerCapacityIsUnknown then
          WriteLn('Max Power         Unknown')
        else
          WriteLn(Format('Max Power         %d W', [LInfo.RAWSystemPowerSupplyInfo^.MaxPowerCapacity]));
        WriteLn(Format('Type              %s', [LInfo.GetPowerSupplyTypeStr]));
        WriteLn(Format('Status            %s', [LInfo.GetStatusStr]));
        WriteLn(Format('Voltage Switching %s', [LInfo.GetInputVoltageRangeSwitchingStr]));
        WriteLn(Format('Hot Replaceable   %s', [BoolToStr(LInfo.IsHotReplaceable, True)]));
        WriteLn(Format('Present           %s', [BoolToStr(LInfo.IsPresent, True)]));
        WriteLn(Format('Unplugged         %s', [BoolToStr(LInfo.IsUnplugged, True)]));
        WriteLn(Format('Voltage Probe     %.4x', [LInfo.RAWSystemPowerSupplyInfo^.InputVoltageProbeHandle]));
        WriteLn(Format('Cooling Device    %.4x', [LInfo.RAWSystemPowerSupplyInfo^.CoolingDeviceHandle]));
        WriteLn(Format('Current Probe     %.4x', [LInfo.RAWSystemPowerSupplyInfo^.InputCurrentProbeHandle]));
        WriteLn;
      end
    else
      WriteLn('No System Power Supply Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetSystemPowerSupplyInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
