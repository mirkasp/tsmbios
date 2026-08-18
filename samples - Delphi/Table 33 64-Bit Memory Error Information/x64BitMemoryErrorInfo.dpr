program x64BitMemoryErrorInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure Getx64BitMemoryErrorInfo;
var
  SMBios: TSMBios;
  Lx64BitMemoryErrorInfo: Tx64BitMemoryErrorInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('64-Bit Memory Error Information');
    WriteLn('-------------------------------');
    if SMBiosAtLeast(SMBios, 2, 3) and SMBios.Hasx64BitMemoryErrorInfo then
      for Lx64BitMemoryErrorInfo in SMBios.x64BitMemoryErrorInfo do
      begin
        WriteLn(Format('Error Type                  %s', [Lx64BitMemoryErrorInfo.GetErrorTypeStr]));
        WriteLn(Format('Error Granularity           %s', [Lx64BitMemoryErrorInfo.GetErrorGranularityStr]));
        WriteLn(Format('Error Operation             %s', [Lx64BitMemoryErrorInfo.GetErrorOperationStr]));
        WriteLn(Format('Vendor Syndrome             %.8x', [Lx64BitMemoryErrorInfo.RAWx64BitMemoryErrorInfo.VendorSyndrome]));
        WriteLn(Format('Memory Array Error Address  %.16x', [Lx64BitMemoryErrorInfo.RAWx64BitMemoryErrorInfo.MemoryArrayErrorAddress]));
        WriteLn(Format('Device Error Address        %.16x', [Lx64BitMemoryErrorInfo.RAWx64BitMemoryErrorInfo.DeviceErrorAddress]));
        WriteLn(Format('Error Resolution            %.8x', [Lx64BitMemoryErrorInfo.RAWx64BitMemoryErrorInfo.ErrorResolution]));
        WriteLn;
      end
    else
      WriteLn('No 64-Bit Memory Error Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    Getx64BitMemoryErrorInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
