program HardwareSecurityInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetHardwareSecurityInfo;
var
  SMBios: TSMBios;
  LHardwareSecurityInfo: THardwareSecurityInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Hardware Security');
    WriteLn('-----------------');
    if SMBiosAtLeast(SMBios, 2, 2) and SMBios.HasHardwareSecurityInfo then
      for LHardwareSecurityInfo in SMBios.HardwareSecurityInformation do
      begin
        WriteLn(Format('Hardware Security Settings   %.2x', [LHardwareSecurityInfo.RAWHardwareSecurityInfo.HardwareSecuritySettings]));
        WriteLn(Format('Front Panel Reset Status     %s', [LHardwareSecurityInfo.GetFrontPanelResetStatusStr]));
        WriteLn(Format('Administrator Password       %s', [LHardwareSecurityInfo.GetAdministratorPasswordStatusStr]));
        WriteLn(Format('Keyboard Password            %s', [LHardwareSecurityInfo.GetKeyboardPasswordStatusStr]));
        WriteLn(Format('Power-on Password            %s', [LHardwareSecurityInfo.GetPowerOnPasswordStatusStr]));
        WriteLn;
      end
    else
      WriteLn('No Hardware Security Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetHardwareSecurityInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
