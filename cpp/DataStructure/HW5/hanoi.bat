set PjName=hanoi
:loop
%PjName%Data.exe
%PjName%.exe < %PjName%.in > %PjName%1.out
%PjName%2.exe < %PjName%.in > %PjName%2.out
fc %PjName%1.out %PjName%2.out
if errorlevel==1 pause
goto loop
