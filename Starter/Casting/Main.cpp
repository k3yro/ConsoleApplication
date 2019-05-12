#include <iostream>
#include <typeinfo>
int main() 
{
	const char* name = "Test";
	char* otherName = const_cast<char*>(name);
	std::cout << typeid(otherName).name() << std::endl;
	std::cout << otherName << std::endl;

	int number = static_cast<int>(2.7f);
	std::cout << typeid(number).name() << std::endl;
	std::cout << number << std::endl;

	//Am besten nicht verwenden: reinterpret_cast
}