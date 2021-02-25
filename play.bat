g++ code.cpp --std=c++17 -o finalCode.exe
@echo OFF
FOR %%x IN (c d) DO (
ECHO %%x 
finalCode.exe <%%x.in> %%x.out
)
PAUSE
