#include <iostream>
#include "Fahrzeug.h"
#include "Auto.h"
#include "Bus.h"

int main()
{
	//Vererbung
	std::cout << "Vererbung" << std::endl; 
	std::cout << "=========" << std::endl;
	Fahrzeug* fzg = new Fahrzeug();
	Bus* bus1 = new Bus;

	bus1->setPosition(2.4f);
	bus1->setGeschwindigkeit(3.9f);
	bus1->fahre(12);

	Auto* c1 = new Auto();

	std::cout << c1->position << std::endl; //<- public
	//std::cout << c1->geschwindigkeit << std::endl; //<- protected
	std::cout << bus1->getPosition() << std::endl << std::endl;

	delete fzg, bus1, c1;
	fzg = nullptr;
	bus1 = nullptr;
	c1 = nullptr;

	//Polymorphismus und pure virtuelle Methoden
	std::cout << "Polymorphismus" << std::endl;
	std::cout << "==============" << std::endl;

	while (true)/*Memory Leak: Destructor von Fahrzeuge sollte virtual sein!*/
	{
		Fahrzeug* fahrzeuge[3];
		fahrzeuge[0] = new Bus();
		fahrzeuge[1] = new Auto();
		fahrzeuge[2] = new Fahrzeug();

		for (size_t i = 0; i < 3; i++)
		{
			if (nullptr != fahrzeuge[i])
			{
				std::cout << fahrzeuge[i]->getType() << std::endl;
				delete fahrzeuge[i];
				fahrzeuge[i] = nullptr;

			}
		}
	}
	return 0;
}