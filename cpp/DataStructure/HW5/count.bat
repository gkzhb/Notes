:loop
makedata.exe
counter.exe < count.in > count1.out
count2.exe < count.in > count2.out
fc count1.out count2.out
if errorlevel==1 pause
goto loop
