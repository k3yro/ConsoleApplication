#include <iostream>
#include "OwnLibary.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReasonForCall, LPVOID lpReserved) 
{
	//Optional:
	switch (dwReasonForCall)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}

Test::Test()
{
}

Test::~Test()
{
}

void Test::printHello() 
{
	std::cout << "Hello from OwnLibary.dll!" << std::endl;
}

void Test::printNumber()
{
	std::cout << 42 << std::endl;
}

void OWNLIBARY_API doNothing() {}