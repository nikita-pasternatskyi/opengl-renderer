@echo off

pushd ..
Vendor\Binaries\Premake\Windows\premake5.exe --file=Build.lua vs2022
popd

IF "%~1"=="--nopause" EXIT /B
pause