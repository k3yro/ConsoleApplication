#include "Mast.h"

Mast::Mast(Durchmesser d) : d(d)
{
	std::cout << "Konstruktor Mast" << std::endl;
	this->name = "";
	this->hersteller = "";
	this->laenge = 0;
	this->gewicht = 0;
	this->carbon = 0;
	this->haerte = 0;
}

Mast::~Mast()
{
	std::cout << "Destruktor Mast" << std::endl;
}


