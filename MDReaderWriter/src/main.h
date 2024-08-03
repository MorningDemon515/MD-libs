
#include <math.h>
#include <cmath>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <memory>
#include <sstream>
#include <stdexcept>

#include <json/json.h>

#include "inicpp/inicpp.hpp"

//方便使用宏!
#define BLITZ3D(x) extern "C" __declspec(dllexport) x _stdcall

BLITZ3D(const char*) ReadINIstring(const char* file,const char* section,const char* key);
BLITZ3D(int) ReadINIint(const char* file,const char* section,const char* key);
BLITZ3D(float) ReadINIfloat(const char* file,const char* section,const char* key);

BLITZ3D(void) WriteINIstring(const char* file,const char* section,const char* key,const char* value); 
BLITZ3D(void) WriteINIint(const char* file,const char* section,const char* key,int value); 
BLITZ3D(void) WriteINIfloat(const char* file,const char* section,const char* key,float value); 

BLITZ3D(const char*) ReadJSONstring(const char* file,const char* key);
BLITZ3D(int) ReadJSONint(const char* file,const char* key);
BLITZ3D(float) ReadJSONfloat(const char* file,const char* key);

BLITZ3D(void) WriteJSONstring(const char* file,const char* key,const char* value);
BLITZ3D(void) WriteJSONint(const char* file,const char* key,int value);
BLITZ3D(void) WriteJSONfloat(const char* file,const char* key,float value);
