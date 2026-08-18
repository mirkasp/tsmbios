program CacheInformation;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetCacheInfo;
var
  SMBios: TSMBios;
  LCache: TCacheInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Cache Information');
    WriteLn('-----------------');
    if SMBios.HasCacheInfo then
      for LCache in SMBios.CacheInfo do
      begin
        WriteLn(Format('Socket Designation     %s', [LCache.SocketDesignationStr]));
        WriteLn(Format('Maximum Cache Size     %d KB', [LCache.GetMaximumCacheSize]));
        WriteLn(Format('Installed Cache Size   %d KB', [LCache.GetInstalledCacheSize]));
        WriteLn(Format('Cache Speed            %d ns', [LCache.RAWCacheInformation.CacheSpeed]));
        WriteLn(Format('Error Correction Type  %d', [Ord(LCache.GetErrorCorrectionType)]));
        WriteLn(Format('System Cache Type      %d', [Ord(LCache.GetSystemCacheType)]));
        WriteLn(Format('Associativity          %s', [LCache.AssociativityStr]));
        WriteLn;
      end
    else
      WriteLn('No Cache Information was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetCacheInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
