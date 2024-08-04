
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

#include <d3d.h>
#include <ddraw.h>

#define BLITZ3D(x) extern "C" __declspec(dllexport) x _stdcall 

BLITZ3D(void) TextureBumpEnvMat(const char* file,int x,int y,float envmat);
BLITZ3D(void) TextureBumpEnvScale(const char* file,float envscale);
BLITZ3D(void) TextureBumpEnvOffset(const char* file,float envoffset);




