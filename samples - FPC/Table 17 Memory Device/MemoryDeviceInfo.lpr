program MemoryDeviceInfo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes,
  SysUtils,
  uSMBIOS;

procedure GetMemoryDeviceInfo;
Var
  SMBios: TSMBios;
  LMemoryDevice: TMemoryDeviceInformation;
begin
  SMBios := TSMBios.Create;
  try
    WriteLn('Memory Device Information');
    WriteLn('-------------------------');

    if SMBios.HasMemoryDeviceInfo
    then
      for LMemoryDevice in SMBios.MemoryDeviceInfo do
      begin
        WriteLn(Format('Total Width    %d bits', [LMemoryDevice.RAWMemoryDeviceInfo^.TotalWidth]));
        WriteLn(Format('Data Width     %d bits', [LMemoryDevice.RAWMemoryDeviceInfo^.DataWidth]));
        WriteLn(Format('Size           %d Mbytes', [LMemoryDevice.GetSize]));
        WriteLn(Format('Form Factor    %s', [LMemoryDevice.GetFormFactor]));
        WriteLn(Format('Device Locator %s', [LMemoryDevice.GetDeviceLocatorStr]));
        WriteLn(Format('Bank Locator   %s', [LMemoryDevice.GetBankLocatorStr]));
        WriteLn(Format('Memory Type    %s', [LMemoryDevice.GetMemoryTypeStr]));
        WriteLn(Format('Speed          %d MT/s', [LMemoryDevice.GetSpeed]));
        if SMBiosAtLeast(SMBios, 2, 7) and LMemoryDevice.HasConfiguredMemorySpeed then
          WriteLn(Format('Configured Speed %d MT/s', [LMemoryDevice.GetConfiguredMemorySpeed]));
        if SMBiosAtLeast(SMBios, 3, 2) then
        begin
          if LMemoryDevice.HasMemoryTechnology then
            WriteLn(Format('Technology     %s', [LMemoryDevice.GetMemoryTechnologyStr]));
          if LMemoryDevice.HasFirmwareVersion then
            WriteLn(Format('Firmware       %s', [LMemoryDevice.FirmwareVersionStr]));
          if LMemoryDevice.HasNonVolatileSize then
            WriteLn(Format('Non-Volatile   %d bytes', [LMemoryDevice.GetNonVolatileSize]));
          if LMemoryDevice.HasVolatileSize then
            WriteLn(Format('Volatile       %d bytes', [LMemoryDevice.GetVolatileSize]));
          if LMemoryDevice.HasCacheSize then
            WriteLn(Format('Cache          %d bytes', [LMemoryDevice.GetCacheSize]));
          if LMemoryDevice.HasLogicalSize then
            WriteLn(Format('Logical        %d bytes', [LMemoryDevice.GetLogicalSize]));
        end;
        if SMBiosAtLeast(SMBios, 3, 7) and LMemoryDevice.HasPMIC0 then
        begin
          WriteLn(Format('PMIC0 Manufacturer ID %.4x', [LMemoryDevice.GetPMIC0ManufacturerID]));
          WriteLn(Format('PMIC0 Revision Number %.4x', [LMemoryDevice.GetPMIC0RevisionNumber]));
        end;
        if SMBiosAtLeast(SMBios, 3, 7) and LMemoryDevice.HasRCD then
        begin
          WriteLn(Format('RCD Manufacturer ID   %.4x', [LMemoryDevice.GetRCDManufacturerID]));
          WriteLn(Format('RCD Revision Number   %.4x', [LMemoryDevice.GetRCDRevisionNumber]));
        end;
        WriteLn(Format('Manufacturer   %s', [LMemoryDevice.ManufacturerStr]));
        WriteLn(Format('Serial Number  %s', [LMemoryDevice.SerialNumberStr]));
        WriteLn(Format('Asset Tag      %s', [LMemoryDevice.AssetTagStr]));
        WriteLn(Format('Part Number    %s', [LMemoryDevice.PartNumberStr]));

        WriteLn;

        if Assigned(LMemoryDevice.PhysicalMemoryArray)
        then
        begin
          WriteLn('  Physical Memory Array');
          WriteLn('  ---------------------');
          WriteLn('  Location         ' + LMemoryDevice.PhysicalMemoryArray.GetLocationStr);
          WriteLn('  Use              ' + LMemoryDevice.PhysicalMemoryArray.GetUseStr);
          WriteLn('  Error Correction ' + LMemoryDevice.PhysicalMemoryArray.GetErrorCorrectionStr);
          if LMemoryDevice.PhysicalMemoryArray.RAWPhysicalMemoryArrayInformation^.MaximumCapacity <> $80000000
          then
            WriteLn(Format('  Maximum Capacity %d Kb',
              [LMemoryDevice.PhysicalMemoryArray.RAWPhysicalMemoryArrayInformation^.MaximumCapacity]))
          else if LMemoryDevice.PhysicalMemoryArray.HasExtendedMaximumCapacity
          then
            WriteLn(Format('  Maximum Capacity %d bytes',
              [LMemoryDevice.PhysicalMemoryArray.GetExtendedMaximumCapacity]))
          else
            WriteLn('  Maximum Capacity Unknown');

          WriteLn(Format('  Memory devices   %d',
            [LMemoryDevice.PhysicalMemoryArray.RAWPhysicalMemoryArrayInformation^.NumberofMemoryDevices]));
        end;
        WriteLn;
      end
    else
      WriteLn('No Memory Device Info was found');
  finally
    SMBios.Free;
  end;
end;

begin
  try
    GetMemoryDeviceInfo;
  except
    on E: Exception do
      WriteLn(E.Classname, ':', E.Message);
  end;
  WriteLn('Press Enter to exit');
  Readln;

end.
