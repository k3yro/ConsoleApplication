#include <string>
#pragma once
class Fahrzeug
{
protected:
	float geschwindigkeit;
private:
	
public:
	float position;
	Fahrzeug();
	~Fahrzeug();
	void fahre(float line);

	void setGeschwindigkeit(float kmh)
	{
		this->geschwindigkeit = kmh;
	}
	void setPosition(float linie)
	{
		this->position = linie;
	}

	float getGeschwindigkeit()
	{
		return this->geschwindigkeit;
	}
	float getPosition()
	{
		return this->position;
	}

	std::string getType();
};

