#pragma once
#include "Spezialfahrzeug.h"
class Landfahrzeug : public /*virtual*/ Spezialfahrzeug //virtual stops diamand of death!
{
public:
	int maxKmh = 100;
	Landfahrzeug();
	~Landfahrzeug();
};

