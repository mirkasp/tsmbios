program MemoryChannelInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetMemoryChannelInfo;
var
  SMBios: TSMBios;
  LMemoryChannelInfo: TMemoryChannelInformation;
  i: Integer;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Memory Channel');
    WriteLn('--------------');
    if SMBiosAtLeast(SMBios, 2, 3) and SMBios.HasMemoryChannelInfo then
      for LMemoryChannelInfo in SMBios.MemoryChannelInfo do
      begin
        WriteLn(Format('Channel Type          %.2x - %s', [LMemoryChannelInfo.RAWMemoryChannelInfo^.ChannelType, LMemoryChannelInfo.GetChannelTypeStr]));
        WriteLn(Format('Maximum Channel Load  %d', [LMemoryChannelInfo.RAWMemoryChannelInfo^.MaximumChannelLoad]));
        WriteLn(Format('Memory Device Count   %d', [LMemoryChannelInfo.RAWMemoryChannelInfo^.MemoryDeviceCount]));
        for i := 0 to LMemoryChannelInfo.RAWMemoryChannelInfo^.MemoryDeviceCount - 1 do
          if LMemoryChannelInfo.HasMemoryDeviceEntry(i) then
            WriteLn(Format('Device %d Load/Handle  %d / %.4x', [i, LMemoryChannelInfo.GetMemoryDeviceLoad(i), LMemoryChannelInfo.GetMemoryDeviceHandle(i)]));
        WriteLn;
      end
    else
      WriteLn('No Memory Channel Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetMemoryChannelInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ': ', E.Message);
  end;
  WriteLn('Press Enter to exit');
  ReadLn;
end.
