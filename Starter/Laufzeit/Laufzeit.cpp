#include <iostream>
#include <chrono>
#include <thread>

//Laufzeit von f(n) = 2^n
long long fibonacciRecursiv(long long x) 
{
	if (x < 2)
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		//std::cout << "Kleiner 2: " << x << std::endl;
		return x;
	}
	//std::cout << "Groesser 2: " << x << std::endl;
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return fibonacciRecursiv(x - 1) + fibonacciRecursiv(x - 2);
}

//Lineare Laufzeit f(n) = n
//Todo: std::vector
long long fibonacciItertativ(long long x)
{
	if (x < 2)
	{
		std::cout << "Kleiner 2" << std::endl;
		return x;
	}
	long long* numbers = new long long[x];
	numbers[0] = numbers[1] = 1;
	for (size_t i = 2; i < x; i++)
	{
		numbers[i] = numbers[i - 1] + numbers[i - 2];
	}
	return numbers[x - 1];
}

int main() 
{
	std::cout << fibonacciItertativ(50) << std::endl;
}