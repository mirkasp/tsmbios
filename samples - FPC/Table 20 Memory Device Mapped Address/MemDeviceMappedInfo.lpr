program MemDeviceMappedInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetMemDeviceMappedInfo;
Var
  SMBios: TSMBios;
  LMemDevMappedAddress: TMemoryDeviceMappedAddressInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Memory Device Mapped Address Information');
    WriteLn('----------------------------------------');
    if SMBios.HasMemoryDeviceMappedAddressInfo
    then
      for LMemDevMappedAddress in SMBios.MemoryDeviceMappedAddressInformation do
      begin
        WriteLn(Format('Starting Address      %.8x',
          [LMemDevMappedAddress.RAWMemoryDeviceMappedAddressInfo^.StartingAddress]));
        WriteLn(Format('Ending   Address      %.8x',
          [LMemDevMappedAddress.RAWMemoryDeviceMappedAddressInfo^.EndingAddress]));
        WriteLn(Format('Memory Device Handle  %.4x',
          [LMemDevMappedAddress.RAWMemoryDeviceMappedAddressInfo^.MemoryDeviceHandle]));
        WriteLn(Format('Memory Array Mapped Address Handle %.4x',
          [LMemDevMappedAddress.RAWMemoryDeviceMappedAddressInfo^.MemoryArrayMappedAddressHandle]));
        WriteLn(Format('Partition Row Position  %d',
          [LMemDevMappedAddress.RAWMemoryDeviceMappedAddressInfo^.PartitionRowPosition]));
        WriteLn(Format('Interleave Position     %d',
          [LMemDevMappedAddress.RAWMemoryDeviceMappedAddressInfo^.InterleavePosition]));
        WriteLn(Format('Interleaved Data Depth  %d',
          [LMemDevMappedAddress.RAWMemoryDeviceMappedAddressInfo^.InterleavedDataDepth]));

        if SMBiosAtLeast(SMBios, 2, 7) and LMemDevMappedAddress.HasExtendedAddresses
        then
        begin
          WriteLn(Format('Extended Starting Address  %x',
            [LMemDevMappedAddress.GetExtendedStartingAddress]));
          WriteLn(Format('Extended Ending   Address  %x',
            [LMemDevMappedAddress.GetExtendedEndingAddress]));
        end;

        WriteLn;
      end
    else

      WriteLn('No Memory Device Mapped Address Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetMemDeviceMappedInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ':', E.Message);
  end;
  WriteLn('Press Enter to exit');
  Readln;

end.
