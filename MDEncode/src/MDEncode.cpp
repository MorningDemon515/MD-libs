#include "MDEncode.h"

BLITZ3D(const char*) UTF8ToANSI(const char* str)
{
	return utf8_to_ansi(str).c_str();
}

BLITZ3D(const char*) ANSIToUTF8(const char* str)
{

	return ansi_to_utf8(str).c_str();
}