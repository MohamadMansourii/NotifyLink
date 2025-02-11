REM ----HELP----
REM == REM is Comment mark in Batch file (so you can use :: for comment instead of REM)
REM ------------

@echo off
REM echo MESSAGE1: %1
echo MESSAGE2: %2
echo MESSAGE3: %3
echo MESSAGE4: %4
REM echo MESSAGE5: %5

REM set MESSAGE1=%1
set MESSAGE2=%2
set MESSAGE3=%3
set MESSAGE4=%4

set Message=%MESSAGE2% %MESSAGE3% %MESSAGE4%
REM set Message="slm"
set IP1=192.168.1.1
set IP2=192.168.1.2
set IP3=192.168.1.3
set IP=%IP1% %IP2% %IP3%
C:\Users\Administrator\Desktop\ConsoleApplication2.exe %Message% %IP%
REM -------------------------Play Alarm--------------------------------
powershell -c (New-Object Media.SoundPlayer "C:\WINDOWS\Media\YourAlert.wav").PlaySync()
REM -------------------------------------------------------------------
echo %Message% > c:\log1.txt

pause

::echo %IP%
::echo %Message%
::C:\Users\Administrator\Desktop\ConsoleApplication2.exe %Message% %IP%