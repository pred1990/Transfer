@echo off
IF not exists build\ ( 
	mkdir build 
	)
clang++.exe  Main.cpp -o build\Transfer.exe 
