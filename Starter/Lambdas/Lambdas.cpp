#include <iostream>
#include <functional> //Funktionalle Programmierung

int main() 
{
	int x = 0;

	//Lambda = Funktion als Variable
	auto lambda = [&x]() -> void/*rueckgabe typ*/
	{
		std::cout << "Hallo aus der Lambda Funktion. x = " << x << std::endl;
	};

	x = 10;

	auto verdoppleWert = [](auto x/*Parameter*/) -> auto
	{
		return x + x;
	};

	std::function<int(int)> leereWert = [](int x) -> int { return 0; };

	lambda();
	x = verdoppleWert(x);
	lambda();
	x = leereWert(x);
	lambda();

	return 0;
}