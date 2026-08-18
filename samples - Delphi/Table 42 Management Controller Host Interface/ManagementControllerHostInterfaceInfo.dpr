program ManagementControllerHostInterfaceInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure WriteBytes(const Caption: string; const LInfo: TManagementControllerHostInterfaceInformation);
var
  i: Integer;
begin
  Write(Caption);
  for i := 0 to LInfo.RAWManagementControllerHostInterfaceInfo.InterfaceTypeSpecificDataLength - 1 do
    Write(Format('%.2x ', [LInfo.GetInterfaceTypeSpecificDataByte(i)]));
  WriteLn;
end;

procedure WriteProtocolData(const LInfo: TManagementControllerHostInterfaceInformation; RecordIndex: Integer);
var
  i: Integer;
begin
  Write('Protocol Data     ');
  for i := 0 to LInfo.GetProtocolTypeSpecificDataLength(RecordIndex) - 1 do
    Write(Format('%.2x ', [LInfo.GetProtocolTypeSpecificDataByte(RecordIndex, i)]));
  WriteLn;
end;

procedure GetManagementControllerHostInterfaceInfo;
var
  SMBios: TSMBios;
  LInfo: TManagementControllerHostInterfaceInformation;
  i: Integer;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Management Controller Host Interface');
    WriteLn('------------------------------------');
    if SMBiosAtLeast(SMBios, 2, 6) and SMBios.HasManagementControllerHostInterfaceInfo then
      for LInfo in SMBios.ManagementControllerHostInterfaceInfo do
      begin
        WriteLn(Format('Interface Type    %s', [LInfo.GetInterfaceTypeStr]));
        WriteLn(Format('Interface Length  %d', [LInfo.RAWManagementControllerHostInterfaceInfo.InterfaceTypeSpecificDataLength]));
        if LInfo.HasInterfaceTypeSpecificData then
          WriteBytes('Interface Data    ', LInfo);
        WriteLn(Format('Protocol Records  %d', [LInfo.GetProtocolRecordCount]));
        for i := 0 to LInfo.GetProtocolRecordCount - 1 do
          if LInfo.HasProtocolRecord(i) then
          begin
            WriteLn(Format('Protocol Type     %s', [LInfo.GetProtocolTypeStr(i)]));
            WriteLn(Format('Protocol Length   %d', [LInfo.GetProtocolTypeSpecificDataLength(i)]));
            WriteProtocolData(LInfo, i);
          end;
        WriteLn;
      end
    else
      WriteLn('No Management Controller Host Interface Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetManagementControllerHostInterfaceInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
