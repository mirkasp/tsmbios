program AdditionalInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure WriteValueBytes(const LInfo: TAdditionalInformationInformation; EntryIndex: Integer);
var
  i: Integer;
begin
  Write('Value             ');
  for i := 0 to LInfo.GetEntryValueSize(EntryIndex) - 1 do
    Write(Format('%.2x ', [LInfo.GetEntryValueByte(EntryIndex, i)]));
  WriteLn;
end;

procedure GetAdditionalInfo;
var
  SMBios: TSMBios;
  LInfo: TAdditionalInformationInformation;
  i: Integer;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Additional Information');
    WriteLn('----------------------');
    if SMBiosAtLeast(SMBios, 2, 3) and SMBios.HasAdditionalInformationInfo then
      for LInfo in SMBios.AdditionalInformationInfo do
      begin
        for i := 0 to LInfo.RAWAdditionalInformationInfo.NumberOfAdditionalInformationEntries - 1 do
          if LInfo.HasAdditionalInformationEntry(i) then
          begin
            WriteLn(Format('Entry             %d', [i]));
            WriteLn(Format('Length            %d', [LInfo.GetAdditionalInformationEntryLength(i)]));
            WriteLn(Format('Referenced Handle %.4x', [LInfo.GetReferencedHandle(i)]));
            WriteLn(Format('Referenced Offset %.2x', [LInfo.GetReferencedOffset(i)]));
            WriteLn(Format('String            %s', [LInfo.GetEntryStringStr(i)]));
            WriteValueBytes(LInfo, i);
            WriteLn;
          end;
      end
    else
      WriteLn('No Additional Information Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetAdditionalInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
