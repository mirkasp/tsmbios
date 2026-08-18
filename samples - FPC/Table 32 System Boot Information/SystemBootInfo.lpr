program SystemBootInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetSystemBootInfo;
var
  SMBios: TSMBios;
  LSystemBootInfo: TSystemBootInformation;
  i: Integer;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('System Boot Information');
    WriteLn('-----------------------');
    if SMBiosAtLeast(SMBios, 2, 3) and SMBios.HasSystemBootInfo then
      for LSystemBootInfo in SMBios.SystemBootInfo do
      begin
        WriteLn(Format('Boot Status                  %.2x - %s', [LSystemBootInfo.RAWSystemBootInfo^.BootStatus, LSystemBootInfo.GetBootStatusStr]));
        for i := Low(LSystemBootInfo.RAWSystemBootInfo^.BootStatusAdditionalData) to High(LSystemBootInfo.RAWSystemBootInfo^.BootStatusAdditionalData) do
          WriteLn(Format('Boot Status Additional Data %d  %.2x', [i, LSystemBootInfo.GetBootStatusAdditionalDataByte(i)]));
        WriteLn;
      end
    else
      WriteLn('No System Boot Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetSystemBootInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
