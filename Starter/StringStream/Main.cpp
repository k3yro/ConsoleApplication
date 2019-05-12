#include <iostream>
#include <sstream>

int main()
{
	{
		std::stringstream ss(27.5);
		float number = 0.0f;
		//ss >> number;
		ss << "String: " << 27 << " = " << 5;
		std::cout << ss.str() << std::endl;
	}

	{
		std::stringstream ss;
		ss << "23.3";
		float number = 0.0f;
		ss >> number;
		std::cout << typeid(number).name() << ": " << number << std::endl;
	}
	return 0;
}