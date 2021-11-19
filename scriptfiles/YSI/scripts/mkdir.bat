set arg1=scriptfiles\%~1
set arg1=%arg1:..=%
set arg1=%arg1:\\=\%
mkdir "%arg1%"
type nul > scriptfiles\YSI\.donescript
