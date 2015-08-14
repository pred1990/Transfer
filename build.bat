@echo off
IF not exist build\ ( 
	mkdir build 
	)
clang++.exe  Main.cpp -o build\Transfer.exe 
