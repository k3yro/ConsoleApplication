#include "Auto.h"



Auto::Auto()
{
	geschwindigkeit = 1;

	bus = new Bus;
}


Auto::~Auto()
{
	delete bus;
	bus = nullptr;
}


void Auto::bremse()
{
	// TODO: F�gen Sie hier Ihren Implementierungscode ein..
}


bool Auto::istInBewegung()
{
	// TODO: F�gen Sie hier Ihren Implementierungscode ein..
	return false;
}


void Auto::beschleunige(float neueGeschwindigkeit)
{
	// TODO: F�gen Sie hier Ihren Implementierungscode ein..
}


std::string Auto::getType()
{
	// TODO: F�gen Sie hier Ihren Implementierungscode ein..
	return "Auto";
}
