@echo off 
set basepath=%~dp0aveng
reg add "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v ZSDK_BASES /t REG_SZ /d "%basepath%" /f
