#pragma once
#include <string>

#include "Fahrzeug.h"
#include "Bus.h"

class Auto :
	public Fahrzeug
{
private:
	Bus* bus;
public:
	Auto();
	~Auto();
	void bremse();
	bool istInBewegung();
	void beschleunige(float neueGeschwindigkeit);
	std::string getType() override;
};

