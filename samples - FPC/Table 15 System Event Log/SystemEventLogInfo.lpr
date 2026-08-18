program SystemEventLogInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetSystemEventLogInfo;
var
  SMBios: TSMBios;
  LInfo: TSystemEventLogInformation;
  i: Integer;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('System Event Log');
    WriteLn('----------------');
    if SMBiosAtLeast(SMBios, 2, 0) and SMBios.HasSystemEventLogInfo then
      for LInfo in SMBios.SystemEventLogInfo do
      begin
        WriteLn(Format('Log Area Length      %d', [LInfo.RAWSystemEventLogInfo^.LogAreaLength]));
        WriteLn(Format('Header Start Offset  %.4x', [LInfo.RAWSystemEventLogInfo^.LogHeaderStartOffset]));
        WriteLn(Format('Data Start Offset    %.4x', [LInfo.RAWSystemEventLogInfo^.LogDataStartOffset]));
        WriteLn(Format('Access Method        %.2x - %s', [LInfo.RAWSystemEventLogInfo^.AccessMethod, LInfo.GetAccessMethodStr]));
        WriteLn(Format('Log Area Valid       %s', [BoolToStr(LInfo.LogAreaIsValid, True)]));
        WriteLn(Format('Log Area Full        %s', [BoolToStr(LInfo.LogAreaIsFull, True)]));
        WriteLn(Format('Log Change Token     %.8x', [LInfo.RAWSystemEventLogInfo^.LogChangeToken]));
        WriteLn(Format('Access Address       %.8x', [LInfo.RAWSystemEventLogInfo^.AccessMethodAddress]));
        if LInfo.HasLogHeaderDescriptorFields then
        begin
          WriteLn(Format('Header Format        %.2x - %s', [LInfo.RAWSystemEventLogInfo^.LogHeaderFormat, LInfo.GetLogHeaderFormatStr]));
          WriteLn(Format('Descriptor Count     %d', [LInfo.RAWSystemEventLogInfo^.NumberOfSupportedLogTypeDescriptors]));
          WriteLn(Format('Descriptor Length    %d', [LInfo.RAWSystemEventLogInfo^.LengthOfEachLogTypeDescriptor]));
          for i := 0 to LInfo.RAWSystemEventLogInfo^.NumberOfSupportedLogTypeDescriptors - 1 do
            if LInfo.HasSupportedLogTypeDescriptor(i) then
              WriteLn(Format('Descriptor %d         %.2x %s / %.2x %s', [i, LInfo.GetSupportedLogType(i),
                LInfo.GetSupportedLogTypeStr(i), LInfo.GetSupportedVariableDataFormatType(i),
                LInfo.GetSupportedVariableDataFormatTypeStr(i)]));
        end;
        WriteLn;
      end
    else
      WriteLn('No System Event Log Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetSystemEventLogInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
