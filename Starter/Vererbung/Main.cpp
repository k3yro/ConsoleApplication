#include <iostream>
#include "Fahrzeug.h"
#include "Auto.h"
#include "Bus.h"

int main()
{
	Fahrzeug* fzg = new Fahrzeug();
	Bus* bus1 = new Bus;

	bus1->setPosition(2.4f);
	bus1->setGeschwindigkeit(3.9f);
	bus1->fahre(12);

	std::cout << bus1->getPosition() << std::endl;

	return 0;
}