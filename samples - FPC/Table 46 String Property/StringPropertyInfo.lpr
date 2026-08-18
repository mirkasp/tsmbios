program StringPropertyInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetStringPropertyInfo;
var
  SMBios: TSMBios;
  LInfo: TStringPropertyInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('String Property');
    WriteLn('---------------');
    if SMBiosAtLeast(SMBios, 3, 5) and SMBios.HasStringPropertyInfo then
      for LInfo in SMBios.StringPropertyInfo do
      begin
        WriteLn(Format('Property ID   %.4x %s', [LInfo.RAWStringPropertyInfo^.StringPropertyID, LInfo.GetStringPropertyIDStr]));
        WriteLn(Format('Value         %s', [LInfo.StringPropertyValueStr]));
        WriteLn(Format('Parent Handle %.4x', [LInfo.RAWStringPropertyInfo^.ParentHandle]));
        WriteLn;
      end
    else
      WriteLn('No String Property Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetStringPropertyInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
