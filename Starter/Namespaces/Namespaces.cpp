#include <iostream>
#include "Version.h"

namespace first
{
	int x = 3;
}

namespace second
{
	int x = 6;
}

namespace foo
{
	namespace bar
	{
		int y = 4;
	}
}

int main()
{
	version::version();

	std::cout << first::x << std::endl << second::x << std::endl << foo::bar::y << std::endl;

	return 0;
}