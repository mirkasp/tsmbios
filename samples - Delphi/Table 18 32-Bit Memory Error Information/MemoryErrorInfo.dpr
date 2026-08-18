program MemoryErrorInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetMemoryErrorInfo;
var
  SMBios: TSMBios;
  LInfo: TMemoryErrorInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('32-Bit Memory Error Information');
    WriteLn('-------------------------------');
    if SMBiosAtLeast(SMBios, 2, 1) and SMBios.HasMemoryErrorInfo then
      for LInfo in SMBios.MemoryErrorInfo do
      begin
        WriteLn(Format('Error Type           %.2x - %s', [LInfo.RAWMemoryErrorInfo.ErrorType, LInfo.GetErrorTypeStr]));
        WriteLn(Format('Error Granularity    %.2x - %s', [LInfo.RAWMemoryErrorInfo.ErrorGranularity, LInfo.GetErrorGranularityStr]));
        WriteLn(Format('Error Operation      %.2x - %s', [LInfo.RAWMemoryErrorInfo.ErrorOperation, LInfo.GetErrorOperationStr]));
        WriteLn(Format('Vendor Syndrome      %.8x', [LInfo.RAWMemoryErrorInfo.VendorSyndrome]));
        if LInfo.MemoryArrayErrorAddressIsUnknown then
          WriteLn('Array Error Address  Unknown')
        else
          WriteLn(Format('Array Error Address  %.8x', [LInfo.RAWMemoryErrorInfo.MemoryArrayErrorAddress]));
        if LInfo.DeviceErrorAddressIsUnknown then
          WriteLn('Device Error Address Unknown')
        else
          WriteLn(Format('Device Error Address %.8x', [LInfo.RAWMemoryErrorInfo.DeviceErrorAddress]));
        if LInfo.ErrorResolutionIsUnknown then
          WriteLn('Error Resolution     Unknown')
        else
          WriteLn(Format('Error Resolution     %.8x', [LInfo.RAWMemoryErrorInfo.ErrorResolution]));
        WriteLn;
      end
    else
      WriteLn('No 32-Bit Memory Error Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetMemoryErrorInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
