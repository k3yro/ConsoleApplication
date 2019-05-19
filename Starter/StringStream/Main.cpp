#include <iostream>
#include <sstream>

// SS - Verkettung Strings mit Int, Float usw. 
int main()
{
	{
		//Beispiel 01
		std::stringstream ss(27.5);
		float number = 0.0f;
		//ss >> number;
		ss << "String: " << 27 << " = " << 5;
		std::cout << ss.str() << std::endl;
		//Ausgabe: String: 27 = 5
	}

	{
		//Beispiel 02
		std::stringstream ss;
		ss << "23.3";
		float number = 0.0f;
		ss >> number;
		std::cout << typeid(number).name() << ": " << number << std::endl;
		//Ausgabe: float: 23.3
	}
	return 0;
}
