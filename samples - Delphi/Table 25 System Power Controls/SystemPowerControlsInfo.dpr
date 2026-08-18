program SystemPowerControlsInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetSystemPowerControlsInfo;
var
  SMBios: TSMBios;
  LSystemPowerControlsInfo: TSystemPowerControlsInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('System Power Controls');
    WriteLn('---------------------');
    if SMBiosAtLeast(SMBios, 2, 2) and SMBios.HasSystemPowerControlsInfo then
      for LSystemPowerControlsInfo in SMBios.SystemPowerControlsInformation do
      begin
        WriteLn(Format('Raw Scheduled Power-on  %.2x %.2x %.2x %.2x %.2x',
          [LSystemPowerControlsInfo.RAWSystemPowerControlsInfo.NextScheduledPowerOnMonth,
           LSystemPowerControlsInfo.RAWSystemPowerControlsInfo.NextScheduledPowerOnDayOfMonth,
           LSystemPowerControlsInfo.RAWSystemPowerControlsInfo.NextScheduledPowerOnHour,
           LSystemPowerControlsInfo.RAWSystemPowerControlsInfo.NextScheduledPowerOnMinute,
           LSystemPowerControlsInfo.RAWSystemPowerControlsInfo.NextScheduledPowerOnSecond]));
        if LSystemPowerControlsInfo.HasValidScheduledPowerOnTime then
        begin
          WriteLn(Format('Month                   %d', [LSystemPowerControlsInfo.GetNextScheduledPowerOnMonth]));
          WriteLn(Format('Day Of Month            %d', [LSystemPowerControlsInfo.GetNextScheduledPowerOnDayOfMonth]));
          WriteLn(Format('Hour                    %d', [LSystemPowerControlsInfo.GetNextScheduledPowerOnHour]));
          WriteLn(Format('Minute                  %d', [LSystemPowerControlsInfo.GetNextScheduledPowerOnMinute]));
          WriteLn(Format('Second                  %d', [LSystemPowerControlsInfo.GetNextScheduledPowerOnSecond]));
        end
        else
          WriteLn('Scheduled Power-on      Invalid BCD value');
        WriteLn;
      end
    else
      WriteLn('No System Power Controls Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetSystemPowerControlsInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
