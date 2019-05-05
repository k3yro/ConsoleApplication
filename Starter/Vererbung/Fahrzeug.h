#include <string>
#pragma once
class Fahrzeug
{
public:
	Fahrzeug();
	~Fahrzeug();
private:
//	float geschwindigkeit;
public:
	float geschwindigkeit;
	float position;
	void fahre(float line);
	std::string getType();
};

