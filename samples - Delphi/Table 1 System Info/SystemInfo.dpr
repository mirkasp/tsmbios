program SystemInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetSystemInfo;
var
  SMBios: TSMBios;
  LSystem: TSystemInformation;
begin
  SMBios := TSMBios.Create;
  try
    //SMBios.LoadFromFile('/home/rruz/PAServer/scratch-dir/RRUZ-Linux Ubuntu/SMBiosTables/SMBIOS.dat', true);
    LSystem := SMBios.SysInfo;
    WriteLn('System Information');
    WriteLn('Manufacter    ' + LSystem.ManufacturerStr);
    WriteLn('Product Name  ' + LSystem.ProductNameStr);
    WriteLn('Version       ' + LSystem.VersionStr);
    WriteLn('Serial Number ' + LSystem.SerialNumberStr);
    if LSystem.HasUUID then
      WriteLn('UUID          ' + LSystem.UUIDStr);
    if LSystem.HasWakeUpType then
      WriteLn('Wake-up Type  ' + LSystem.WakeUpTypeStr);
    if SMBiosAtLeast(SMBios, 2, 4)
    then
    begin
      if LSystem.HasSKUNumber then
        WriteLn('SKU Number    ' + LSystem.SKUNumberStr);
      if LSystem.HasFamily then
        WriteLn('Family        ' + LSystem.FamilyStr);
    end;
    WriteLn;
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetSystemInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ':', E.Message);
  end;
  WriteLn('Press Enter to exit');
  Readln;

end.
