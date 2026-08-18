@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "ORGPATH=%PATH%"
set "BUILD_STATUS=0"
set "SCRIPT_DIR=%~dp0"
set "BUILD_CONFIG=debug"
set "BUILD_PLATFORM=Win32"
set "TSMBIOS_CBUILDER_SDK_INCLUDE="

if "%~1"=="" goto USAGE

if %1 LEQ 13 goto RADSTUDIO
goto STUDIO

:RADSTUDIO
set "RSVARS=c:\Program Files (x86)\Embarcadero\RAD Studio\%1.0\bin\rsvars.bat"
if exist "%RSVARS%" goto INIT
echo ...\Embarcadero\RAD Studio\%1.0\bin\rsvars.bat was not found.
goto DONE_FAIL

:STUDIO
set "RSVARS=c:\Program Files (x86)\Embarcadero\Studio\%1.0\bin\rsvars.bat"
if exist "%RSVARS%" goto INIT
echo ...\Embarcadero\Studio\%1.0\bin\rsvars.bat was not found.
goto DONE_FAIL

:INIT
call "%RSVARS%"
if errorlevel 1 goto DONE_FAIL

call :FIND_CBUILDER_SDK "%~1"
if "%TSMBIOS_CBUILDER_SDK_INCLUDE%"=="" goto SKIP_SDK_MESSAGE
echo Using C++Builder SDK include: %TSMBIOS_CBUILDER_SDK_INCLUDE%

:SKIP_SDK_MESSAGE

pushd "%SCRIPT_DIR%"
if errorlevel 1 goto DONE_FAIL

set "SAMPLES_ROOT=%SCRIPT_DIR%..\samples - C++Builder"
if not exist "%SAMPLES_ROOT%" (
  echo C++Builder samples folder was not found: %SAMPLES_ROOT%
  popd
  goto DONE_FAIL
)

set "PROJECT_COUNT=0"
for /R "%SAMPLES_ROOT%" %%P in (*.cbproj) do (
  set /A PROJECT_COUNT+=1
  echo.
  echo [!PROJECT_COUNT!] Building %%P
  pushd "%%~dpP"
  if exist ".\%BUILD_PLATFORM%\%BUILD_CONFIG%" (
    del /q /f ".\%BUILD_PLATFORM%\%BUILD_CONFIG%\%%~nP.il*" >nul 2>nul
    del /q /f ".\%BUILD_PLATFORM%\%BUILD_CONFIG%\%%~nP.tds" >nul 2>nul
  )
  msbuild.exe "%%~nxP" /target:Clean;Build /p:Platform=%BUILD_PLATFORM% /p:config=%BUILD_CONFIG% /p:TSMBIOS_CBUILDER_SDK_INCLUDE="%TSMBIOS_CBUILDER_SDK_INCLUDE%" /nologo /verbosity:minimal
  set "BUILD_STATUS=!ERRORLEVEL!"
  popd
  if not "!BUILD_STATUS!"=="0" (
    echo Build failed: %%P
    popd
    goto DONE_FAIL
  )
)

if "!PROJECT_COUNT!"=="0" (
  echo No C++Builder sample projects were found under: %SAMPLES_ROOT%
  popd
  goto DONE_FAIL
)

popd
echo.
echo Built !PROJECT_COUNT! C++Builder sample projects.
goto DONE

:USAGE
echo Usage: CBuilder_Build.bat ^<RAD Studio major version^>
echo Example: CBuilder_Build.bat 37
goto DONE_FAIL

:FIND_CBUILDER_SDK
set "TSMBIOS_CBUILDER_SDK_INCLUDE="
set "REQUESTED_VERSION=%~1"

if %REQUESTED_VERSION% LEQ 13 goto FIND_RADSTUDIO_SDK
set "REQUESTED_SDK=c:\Program Files (x86)\Embarcadero\Studio\%REQUESTED_VERSION%.0\include\windows\sdk"
goto CHECK_REQUESTED_SDK

:FIND_RADSTUDIO_SDK
set "REQUESTED_SDK=c:\Program Files (x86)\Embarcadero\RAD Studio\%REQUESTED_VERSION%.0\include\windows\sdk"

:CHECK_REQUESTED_SDK
if not exist "%REQUESTED_SDK%\windows.h" goto FIND_INSTALLED_SDK
set "TSMBIOS_CBUILDER_SDK_INCLUDE=%REQUESTED_SDK%"
goto :EOF

:FIND_INSTALLED_SDK
for /F "usebackq delims=" %%D in (`powershell -NoProfile -ExecutionPolicy Bypass -Command "$roots = @('C:\Program Files (x86)\Embarcadero\Studio','C:\Program Files (x86)\Embarcadero\RAD Studio'); $candidates = foreach ($root in $roots) { if (Test-Path $root) { Get-ChildItem -LiteralPath $root -Directory | ForEach-Object { $sdk = Join-Path $_.FullName 'include\windows\sdk'; if (Test-Path (Join-Path $sdk 'windows.h')) { [pscustomobject]@{ Version = [double]($_.Name -replace '[^0-9.]',''); Path = $sdk } } } } }; $candidates | Sort-Object Version -Descending | Select-Object -First 1 -ExpandProperty Path"`) do (
  set "TSMBIOS_CBUILDER_SDK_INCLUDE=%%D"
)
goto :EOF

:DONE_FAIL
set "PATH=%ORGPATH%"
endlocal & exit /b 1

:DONE
set "PATH=%ORGPATH%"
endlocal & exit /b 0
