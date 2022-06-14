@echo off

set MODE=%~1
set TARGET=%~2
set FLAGS=%~3

set NAME=%MODE%%TARGET%

call :setup
call :build
call :run
echo.
goto :eof

:build
	rem Can't pass string defines on the command-line
	echo #define COMPILE_FLAGS "%FLAGS%" > %NAME%\pawno\include\compile_flags.inc
	echo pawno\pawncc.exe "gamemodes\%MODE%.pwn" -v0 -i"pawno\include" -i"%NAME%\pawno\include" -;+ -(+ %FLAGS% _DEBUG=0 TEST_AUTO_EXIT=true -o"%NAME%\gamemodes\mode.amx"
	pawno\pawncc.exe "gamemodes\%MODE%.pwn" -v0 -i"pawno\include" -i"%NAME%\pawno\include" -;+ -(+ %FLAGS% _DEBUG=0 TEST_AUTO_EXIT=true -o"%NAME%\gamemodes\mode.amx" > nul
	goto :eof

:setup
	rem Remove old versions
	del logs\%NAME%.txt 2> nul
	rem Create subdirectories
	rmdir /S /Q %NAME% 2> nul
	mkdir %NAME%\pawno\include
	cd %NAME%
	mkdir gamemodes
	mklink samp-server.exe ..\samp-server.exe > nul
	mklink samp-npc.exe ..\samp-npc.exe > nul
	mklink /D plugins ..\plugins > nul
	mklink /D scriptfiles ..\scriptfiles > nul
	mklink /D modules ..\modules > nul
	rem copy the important files
	rem Write the current test to the config file
	copy /A /Y ..\server.cfg.ysi server.cfg > nul
	cd ..
	goto :eof

:run
	rem Run the server with the custom server.cfg - it closes itself after
	cd %NAME%
	echo samp-server.exe
	samp-server.exe
	rem Copy server-log.txt somewhere
	if exist "server_log.txt" (
		move /Y server_log.txt ..\logs\%NAME%.txt > nul
	)
	cd ..
	rmdir /S /Q %NAME%
	goto :eof

