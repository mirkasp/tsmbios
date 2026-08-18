program ProcessorAdditionalInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetProcessorAdditionalInfo;
var
  SMBios: TSMBios;
  LInfo: TProcessorAdditionalInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Processor Additional Information');
    WriteLn('--------------------------------');
    if SMBiosAtLeast(SMBios, 3, 3) and SMBios.HasProcessorAdditionalInfo then
      for LInfo in SMBios.ProcessorAdditionalInfo do
      begin
        WriteLn(Format('Processor Handle %.4x', [LInfo.RAWProcessorAdditionalInfo.ReferencedHandle]));
        WriteLn(Format('Architecture     %s', [LInfo.GetProcessorTypeStr]));
        WriteLn(Format('Specific Bytes   %d', [LInfo.GetProcessorSpecificDataSize]));
        WriteLn;
      end
    else
      WriteLn('No Processor Additional Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetProcessorAdditionalInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
