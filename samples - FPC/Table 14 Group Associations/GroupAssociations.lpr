program GroupAssociations;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetGroupAssociationsInfo;
Var
  SMBios: TSMBios;
  LGroup: TGroupAssociationsInformation;
begin
  SMBios := TSMBios.Create;
  try
    // SMBios.FindAndLoadFromFile('C:\Users\Dexter\Desktop\RAD Studio Projects\google-code\SMBIOS Delphi\Docs\DELL_system_dumps\PE2450\SMBIOS.dat');
    WriteLn('Group Associations Information');
    WriteLn('------------------------------');
    if SMBios.HasGroupAssociationsInfo
    then
      for LGroup in SMBios.GroupAssociationsInformation do
      begin
        WriteLn('Group Name    ' + LGroup.GetGroupName);
        WriteLn('Item Type     ' + IntToStr(LGroup.RAWGroupAssociationsInformation^.ItemType));
        WriteLn('Item Handle   ' + IntToStr(LGroup.RAWGroupAssociationsInformation^.ItemHandle));
        WriteLn;
      end
    else
      WriteLn('No Group Associations Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetGroupAssociationsInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ':', E.Message);
  end;
  WriteLn('Press Enter to exit');
  Readln;

end.
