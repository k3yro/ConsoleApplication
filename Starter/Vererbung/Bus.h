#pragma once
#include "Fahrzeug.h"
class Bus :
	public Fahrzeug
{
public:
	Bus();
	~Bus();
	std::string getType();
};

