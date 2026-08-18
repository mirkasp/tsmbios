program MemArrayMappedInfo;

{$APPTYPE CONSOLE}

uses
  Classes,
  SysUtils,
  uSMBIOS in '..\..\source\uSMBIOS.pas';

procedure GetMemArrayMappedInfo;
var
  SMBios: TSMBios;
  LMemArrMappedAddress: TMemoryArrayMappedAddressInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Memory Array Mapped Address Information');
    WriteLn('---------------------------------------');
    if SMBios.HasMemoryArrayMappedAddressInfo
    then
      for LMemArrMappedAddress in SMBios.MemoryArrayMappedAddressInformation do
      begin
        WriteLn(Format('Starting Address    %.8x ',
          [LMemArrMappedAddress.RAWMemoryArrayMappedAddressInfo.StartingAddress]));
        WriteLn(Format('Ending   Address    %.8x ',
          [LMemArrMappedAddress.RAWMemoryArrayMappedAddressInfo.EndingAddress]));
        WriteLn(Format('Memory Array Handle %.4x ',
          [LMemArrMappedAddress.RAWMemoryArrayMappedAddressInfo.MemoryArrayHandle]));
        WriteLn(Format('Partition Width     %d ',
          [LMemArrMappedAddress.RAWMemoryArrayMappedAddressInfo.PartitionWidth]));
        if SMBiosAtLeast(SMBios, 2, 7) and LMemArrMappedAddress.HasExtendedAddresses
        then
        begin
          WriteLn(Format('Extended Starting Address  %x',
            [LMemArrMappedAddress.GetExtendedStartingAddress]));
          WriteLn(Format('Extended Ending   Address  %x',
            [LMemArrMappedAddress.GetExtendedEndingAddress]));
        end;

        WriteLn;
      end
    else

      WriteLn('No Memory Array Mapped Address Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetMemArrayMappedInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ':', E.Message);
  end;
  WriteLn('Press Enter to exit');
  Readln;

end.
