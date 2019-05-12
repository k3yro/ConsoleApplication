#include <iostream>

#include "DynamischerVektor.h"

//Auslagerung nur in .h Dateien
template<class T> //"class" oder "typename"
T GetMax(T x, T y)
{
	return x > y ? x : y;
}

template<typename X, class O>
X Cast(O o)
{
	return (X)o;
}

int main()
{
	//Template Funktionen
	int iMax = GetMax<int>(1, 2);
	float fMax = GetMax<float>(2.4f, 1.3f);

	int iValue = Cast<int, float>(fMax);
	std::cout << "Capacity: " << iValue << std::endl;

	//Template Klasse
	DynamischerVektor<int> dVektor;
	for (size_t i = 0; i < 27; i++)
	{
		dVektor.push_back(i);
	}

	std::cout << "Capacity: " << dVektor.getCapacity() << std::endl;

	for (size_t i = 0; i < dVektor.getSize(); i++)
	{
		std::cout << dVektor[i] << std::endl;
	}

	for (size_t i = 0; i < 27; i++)
	{
		dVektor.pop_back();
	}

	std::cout << "Capacity: " << dVektor.getCapacity() << std::endl;
}