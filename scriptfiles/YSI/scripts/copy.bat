set arg1=scriptfiles\%~1
set arg1=%arg1:..=%
set arg1=%arg1:\\=\%
set arg2=scriptfiles\%~2
set arg2=%arg2:..=%
set arg2=%arg2:\\=\%
copy "%arg1%" "%arg2%"
type nul > scriptfiles\YSI\.donescript
