#include <string>

#include "Fahrzeug.h"



Fahrzeug::Fahrzeug()
{
	//  geschwindigkeit = 0.0f;
	geschwindigkeit = 0.3f;
	position = 0.2f;
}


Fahrzeug::~Fahrzeug()
{
}


void Fahrzeug::fahre(float line)
{
	// TODO: F�gen Sie hier Ihren Implementierungscode ein..
}


std::string Fahrzeug::getType()
{
	// TODO: F�gen Sie hier Ihren Implementierungscode ein..
	return "Fahrzeug";
}
