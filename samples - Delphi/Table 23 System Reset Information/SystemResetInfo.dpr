program SystemResetInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetSystemResetInfo;
var
  SMBios: TSMBios;
  LSystemResetInfo: TSystemResetInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('System Reset Information');
    WriteLn('------------------------');
    if SMBiosAtLeast(SMBios, 2, 2) and SMBios.HasSystemResetInfo then
      for LSystemResetInfo in SMBios.SystemResetInformation do
      begin
        WriteLn(Format('Capabilities           %.2x', [LSystemResetInfo.RAWSystemResetInfo.Capabilities]));
        WriteLn(Format('Reset Enabled By User  %s', [BoolToStr(LSystemResetInfo.ResetEnabledByUser, True)]));
        WriteLn(Format('Boot Option            %s', [LSystemResetInfo.GetBootOptionStr]));
        WriteLn(Format('Boot Option On Limit   %s', [LSystemResetInfo.GetBootOptionOnLimitStr]));
        WriteLn(Format('Watchdog Timer         %s', [BoolToStr(LSystemResetInfo.ContainsWatchdogTimer, True)]));
        WriteLn(Format('Reset Count            %s', [LSystemResetInfo.GetResetCountStr]));
        WriteLn(Format('Reset Limit            %s', [LSystemResetInfo.GetResetLimitStr]));
        WriteLn(Format('Timer Interval         %s', [LSystemResetInfo.GetTimerIntervalStr]));
        WriteLn(Format('Timeout                %s', [LSystemResetInfo.GetTimeoutStr]));
        WriteLn;
      end
    else
      WriteLn('No System Reset Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetSystemResetInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
