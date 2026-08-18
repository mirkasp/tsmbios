@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "ORGPATH=%PATH%"
set "BUILD_STATUS=0"

if "%~1"=="" (
  set "FPC_EXE=C:\FPC\3.2.2\bin\i386-win32\fpc.exe"
) else (
  set "FPC_EXE=%~1"
)

if not exist "%FPC_EXE%" (
  echo FPC compiler was not found: %FPC_EXE%
  goto DONE_FAIL
)

pushd "%~dp0"
if errorlevel 1 goto DONE_FAIL

set "SAMPLES_ROOT=..\samples - FPC"
if not exist "%SAMPLES_ROOT%" (
  echo FPC samples folder was not found: %SAMPLES_ROOT%
  popd
  goto DONE_FAIL
)

set "PROJECT_COUNT=0"
for /R "%SAMPLES_ROOT%" %%P in (*.lpi) do (
  set "PROJECT_DIR=%%~dpP"
  set "PROJECT_NAME=%%~nP"
  set "MAIN_SOURCE=!PROJECT_DIR!!PROJECT_NAME!.lpr"

  if not exist "!MAIN_SOURCE!" (
    echo Main source was not found for %%P
    popd
    goto DONE_FAIL
  )

  set /A PROJECT_COUNT+=1
  echo.
  echo [!PROJECT_COUNT!] Building !MAIN_SOURCE!

  pushd "!PROJECT_DIR!"
  if errorlevel 1 (
    popd
    goto DONE_FAIL
  )

  if not exist "lib\i386-win32" mkdir "lib\i386-win32"
  "%FPC_EXE%" -B -Mobjfpc -Sh -Fu"..\..\source" -FU"lib\i386-win32" "!PROJECT_NAME!.lpr"
  set "BUILD_STATUS=!ERRORLEVEL!"
  popd

  if not "!BUILD_STATUS!"=="0" (
    echo Build failed: %%P
    popd
    goto DONE_FAIL
  )
)

popd
echo.
echo Built !PROJECT_COUNT! FPC sample projects.
goto DONE

:DONE_FAIL
set "PATH=%ORGPATH%"
endlocal & exit /b 1

:DONE
set "PATH=%ORGPATH%"
endlocal & exit /b 0
