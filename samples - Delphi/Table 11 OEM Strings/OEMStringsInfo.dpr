program OEMStringsInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetOEMStringsInfo;
var
  SMBios: TSMBios;
  LOEMStrings: TOEMStringsInformation;
  i: Integer;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('OEM Strings Information');
    WriteLn('-----------------------');
    if SMBios.HasOEMStringsInfo then
      for LOEMStrings in SMBios.OEMStringsInfo do
      begin
        for i := 1 to LOEMStrings.RAWOEMStringsInformation.Count do
          if LOEMStrings.GetOEMString(i) <> '' then
            WriteLn(Format('OEM String %d  %s', [i, LOEMStrings.GetOEMString(i)]));
        WriteLn;
      end
    else
      WriteLn('No OEM Strings Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetOEMStringsInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.

