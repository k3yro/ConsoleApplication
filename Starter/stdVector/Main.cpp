#include <vector>
#include <iostream>


int main() 
{
	std::vector<int> numbers(10);

	for (size_t i = 0; i < numbers.size(); i++)
	{
		numbers[i] = i+1;
	}
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	numbers.push_back(11);
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	numbers.pop_back();
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	numbers.shrink_to_fit();
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	numbers.reserve(17);
	std::cout << "Capacity: " << numbers.capacity() << std::endl;
	
	//numbers.resize(20, 1);
	std::cout << "Capacity: " << numbers.capacity() << std::endl;

	for (size_t i = 0; i < numbers.size(); i++)
	{
	//	std::cout << numbers[i] << std::endl;
	}

	for (auto i = numbers.cbegin(); i < numbers.cend(); i++)
	{
		std::cout << *i << std::endl;
		//*i = 42;
	}

	for (auto i = numbers.crbegin(); i < numbers.crend(); i++)
	{
		std::cout << *i << std::endl;
	}
}