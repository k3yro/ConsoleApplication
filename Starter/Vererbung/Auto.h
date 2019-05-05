#pragma once
#include "Fahrzeug.h"
#include <string>
class Auto :
	public Fahrzeug
{
public:
	Auto();
	~Auto();
	void bremse();
	bool istInBewegung();
	void beschleunige(float neueGeschwindigkeit);
	std::string getType();
};

