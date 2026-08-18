@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "ORGPATH=%PATH%"
set "BUILD_STATUS=0"

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

pushd "%~dp0"
if errorlevel 1 goto DONE_FAIL

set "SAMPLES_ROOT=..\samples - Delphi"
if not exist "%SAMPLES_ROOT%" (
  echo Delphi samples folder was not found: %SAMPLES_ROOT%
  popd
  goto DONE_FAIL
)

set "PROJECT_COUNT=0"
for /R "%SAMPLES_ROOT%" %%P in (*.dproj) do (
  set /A PROJECT_COUNT+=1
  echo.
  echo [!PROJECT_COUNT!] Building %%P
  msbuild.exe "%%P" /target:Clean;Build /p:Platform=Win32 /p:config=debug /nologo /verbosity:minimal
  set "BUILD_STATUS=!ERRORLEVEL!"
  if not "!BUILD_STATUS!"=="0" (
    echo Build failed: %%P
    popd
    goto DONE_FAIL
  )
)

popd
echo.
echo Built !PROJECT_COUNT! Delphi sample projects.
goto DONE

:USAGE
echo Usage: Demo_Build.bat ^<RAD Studio major version^>
echo Example: Demo_Build.bat 37
goto DONE_FAIL

:DONE_FAIL
set "PATH=%ORGPATH%"
endlocal & exit /b 1

:DONE
set "PATH=%ORGPATH%"
endlocal & exit /b 0
