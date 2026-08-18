program IPMIDeviceInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetIPMIDeviceInfo;
var
  SMBios: TSMBios;
  LInfo: TIPMIDeviceInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('IPMI Device Information');
    WriteLn('-----------------------');
    if SMBiosAtLeast(SMBios, 2, 3) and SMBios.HasIPMIDeviceInfo then
      for LInfo in SMBios.IPMIDeviceInfo do
      begin
        WriteLn(Format('Interface Type  %s', [LInfo.GetInterfaceTypeStr]));
        WriteLn(Format('IPMI Version    %s', [LInfo.GetSpecificationVersionStr]));
        WriteLn(Format('I2C Address     %.2x', [LInfo.RAWIPMIDeviceInfo^.I2CSlaveAddress]));
        WriteLn(Format('NV Address      %.2x', [LInfo.RAWIPMIDeviceInfo^.NVStorageDeviceAddress]));
        WriteLn(Format('Base Address    %.16x', [LInfo.RAWIPMIDeviceInfo^.BaseAddress]));
        WriteLn(Format('Interrupt       %d', [LInfo.RAWIPMIDeviceInfo^.InterruptNumber]));
        WriteLn;
      end
    else
      WriteLn('No IPMI Device Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetIPMIDeviceInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
