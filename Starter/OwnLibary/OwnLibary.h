#pragma once
#include <Windows.h>

#ifdef OWNLIBARY_EXPORTS
#define OWNLIBARY_API __declspec(dllexport)
#else
#define OWNLIBARY_API __declspec(dllexport)
#endif // OWNLIBARY_EXPORTS

//Main Funktion fuer DLLs
BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReasonForCall, LPVOID lpReserved);

class OWNLIBARY_API Test
{
public:
	Test();
	~Test();
	static void printHello();
	static void printNumber();
	
private:
	
};

void OWNLIBARY_API doNothing();