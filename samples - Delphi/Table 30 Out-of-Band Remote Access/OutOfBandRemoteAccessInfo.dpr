program OutOfBandRemoteAccessInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetOutOfBandRemoteAccessInfo;
var
  SMBios: TSMBios;
  LOutOfBandRemoteAccessInfo: TOutOfBandRemoteAccessInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Out-of-Band Remote Access Information');
    WriteLn('-------------------------------------');
    if SMBiosAtLeast(SMBios, 2, 2) and SMBios.HasOutOfBandRemoteAccessInfo then
      for LOutOfBandRemoteAccessInfo in SMBios.OutOfBandRemoteAccessInformation do
      begin
        WriteLn(Format('Manufacturer Name            %s', [LOutOfBandRemoteAccessInfo.GetManufacturerNameStr]));
        WriteLn(Format('Connections                  %.2x', [LOutOfBandRemoteAccessInfo.RAWOutOfBandRemoteAccessInfo.Connections]));
        WriteLn(Format('Inbound Connection Enabled   %s', [BoolToStr(LOutOfBandRemoteAccessInfo.InboundConnectionEnabled, True)]));
        WriteLn(Format('Outbound Connection Enabled  %s', [BoolToStr(LOutOfBandRemoteAccessInfo.OutboundConnectionEnabled, True)]));
        WriteLn;
      end
    else
      WriteLn('No Out-of-Band Remote Access Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetOutOfBandRemoteAccessInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
