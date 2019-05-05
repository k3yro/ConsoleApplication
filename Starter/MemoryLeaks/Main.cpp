#include <iostream>

#include "Segel.h"
#include "Mast.h"

int main()
{
	Mast* northGold = new Mast(RDM);
	northGold->setName("Gold");
	northGold->setHersteller("North Sails");
	northGold->setLaenge(430);
	northGold->setCarbon(80);
	northGold->setGewicht(2.1f);
	northGold->setHaerte(21);

	Segel* northIdol = new Segel();
	northIdol->setName("Idol");
	northIdol->setHersteller("North Sails");
	northIdol->setGroesse(5.6f);
	northIdol->setMast(northGold);

	Mast* mref = northIdol->getMast();

	std::cout << "Model:\t\t" << mref->getModel() << std::endl;
	std::cout << "Model:\t\t" << northGold->getModel() << std::endl;
	std::cout << "Länge:\t\t" << northGold->getLaenge() << "cm" << std::endl;
	std::cout << "Carbon:\t\t" << northGold->getCarbon() << "%" << std::endl;
	std::cout << "Gewicht:\t" << northGold->getGewicht() << "kg" << std::endl;
	std::cout << "IMCS:\t\t" << northGold->getHaerte() << std::endl;

	Segel* testMemoryLeak = nullptr;
	while (true)
	{
		testMemoryLeak = new Segel;
		delete testMemoryLeak;
		testMemoryLeak = nullptr;
	}

	return 0;
}