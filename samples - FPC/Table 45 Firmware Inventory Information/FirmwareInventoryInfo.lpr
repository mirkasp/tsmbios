program FirmwareInventoryInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetFirmwareInventoryInfo;
var
  SMBios: TSMBios;
  LInfo: TFirmwareInventoryInformation;
  i: Integer;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Firmware Inventory Information');
    WriteLn('------------------------------');
    if SMBiosAtLeast(SMBios, 3, 5) and SMBios.HasFirmwareInventoryInfo then
      for LInfo in SMBios.FirmwareInventoryInfo do
      begin
        WriteLn(Format('Component       %s', [LInfo.FirmwareComponentNameStr]));
        WriteLn(Format('Version         %s', [LInfo.FirmwareVersionStr]));
        WriteLn(Format('Firmware ID     %s', [LInfo.FirmwareIDStr]));
        WriteLn(Format('Release Date    %s', [LInfo.ReleaseDateStr]));
        WriteLn(Format('Manufacturer    %s', [LInfo.ManufacturerStr]));
        WriteLn(Format('Lowest Version  %s', [LInfo.LowestSupportedFirmwareVersionStr]));
        WriteLn(Format('State           %s', [LInfo.GetStateStr]));
        for i := 0 to LInfo.RAWFirmwareInventoryInfo^.AssociatedComponentCount - 1 do
          WriteLn(Format('Component Handle %.4x', [LInfo.GetAssociatedComponentHandle(i)]));
        WriteLn;
      end
    else
      WriteLn('No Firmware Inventory Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetFirmwareInventoryInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
