@echo off
IF not exist build ( 
	mkdir build 
	)
clang++.exe  Main.cpp Validate.cpp Util.cpp NetworkWin.cpp -lws2_32 -o build\Transfer.exe -std=c++11 -pedantic -Wall
