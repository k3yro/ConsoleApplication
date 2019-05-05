#include "Segel.h"

Segel::Segel()
{
	std::cout << "Konstruktor Segel" << std::endl;
	this->mast = new Mast(SDM);
	this->name = "";
	this->hersteller = "";
	groesse = 0;
}

Segel::~Segel()
{
	std::cout << "Destruktor Segel" << std::endl;

	//Kommentar entfernen, um Memory Leak zu beseitigen:
	//delete this->mast;
	//this->mast = nullptr;
}