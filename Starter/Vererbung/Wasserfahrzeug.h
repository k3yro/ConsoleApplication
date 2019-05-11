#pragma once
#include "Spezialfahrzeug.h"
class Wasserfahrzeug : public /*virtual*/ Spezialfahrzeug //virtual stops diamand of death!
{
public:
	int maxKmh = 15;
	Wasserfahrzeug();
	~Wasserfahrzeug();
};

