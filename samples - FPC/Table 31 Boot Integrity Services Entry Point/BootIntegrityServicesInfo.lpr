program BootIntegrityServicesInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetBootIntegrityServicesInfo;
var
  SMBios: TSMBios;
  LBISInfo: TBootIntegrityServicesEntryPointInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Boot Integrity Services Entry Point');
    WriteLn('-----------------------------------');
    if SMBiosAtLeast(SMBios, 2, 3) and SMBios.HasBootIntegrityServicesEntryPointInfo then
      for LBISInfo in SMBios.BootIntegrityServicesEntryPointInformation do
      begin
        WriteLn(Format('Handle                  %.4x', [LBISInfo.RAWBootIntegrityServicesEntryPointInfo^.Header.Handle]));
        WriteLn(Format('Length                  %d', [LBISInfo.RAWBootIntegrityServicesEntryPointInfo^.Header.Length]));
        WriteLn(Format('Checksum                %.2x', [LBISInfo.RAWBootIntegrityServicesEntryPointInfo^.Checksum]));
        WriteLn(Format('Structure Length Valid  %s', [BoolToStr(LBISInfo.IsStructureLengthValid, True)]));
        WriteLn(Format('Checksum Valid          %s', [BoolToStr(LBISInfo.ChecksumIsValid, True)]));
        WriteLn(Format('16-bit Entry Point      %.4x:%.4x',
          [LBISInfo.GetEntryPoint16Segment, LBISInfo.GetEntryPoint16Offset]));
        WriteLn(Format('16-bit Entry Valid      %s', [BoolToStr(LBISInfo.EntryPoint16IsValid, True)]));
        WriteLn(Format('32-bit Entry Point      %.8x', [LBISInfo.RAWBootIntegrityServicesEntryPointInfo^.EntryPoint32]));
        WriteLn(Format('32-bit Entry Valid      %s', [BoolToStr(LBISInfo.EntryPoint32IsValid, True)]));
        WriteLn;
      end
    else
      WriteLn('No Boot Integrity Services Entry Point Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetBootIntegrityServicesInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
