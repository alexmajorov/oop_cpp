@echo off

call "D:\Programs\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
cl -Zi main.cpp
devenv main.exe