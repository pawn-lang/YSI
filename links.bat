rem Create a Windows soft link.  Parameters are in reverse to Linux.
cd scriptfiles
mkdir DANGEROUS_SERVER_ROOT
cd DANGEROUS_SERVER_ROOT
mklink /J gamemodes ..\..\gamemodes
mklink /J filterscripts ..\..\filterscripts
mklink /J npcmodes ..\..\npcmodes
mklink /H server.cfg ..\..\server.cfg
cd ..\..

