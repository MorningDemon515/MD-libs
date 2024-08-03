# MD-libs
Provide some libs for Blitz3D/BlitzPlus

Current libs:

MDEncode: Can be used for converting UTF8 encoded and ANSI encoded characters

MDReaderWriter: Used for reading and writing ini and json files

# How To Build

1. git clone this repository
2. Open the cmd of the repository
3. Input:
- mkdir build
- cd build
- cmake -G "Visual Studio 16 2019" -A Win32 ..
- cmake --build . --config Release
4. Find DLL in build\Release