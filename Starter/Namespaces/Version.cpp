#include "Version.h"

namespace version 
{
	void version()
	{
		using namespace std;
		cout << "Program version: " << VERSION_MAJOR << "." << VERSION_MINOR << endl;
	}
}