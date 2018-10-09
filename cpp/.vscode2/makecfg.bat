:chagedir
@echo off
set tmppath=%1
%tmppath:~0,2%
cd %tmppath%
make