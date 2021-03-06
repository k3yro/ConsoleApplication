#include <string>
#pragma once
class Fahrzeug abstract /*pure virtual*/ /*Alternativ: virtual std::string getType() = 0;*/
{
protected:/*wie private, aber vererbbar!*/
	float geschwindigkeit;
private:
	
public:
	float position;
	Fahrzeug();
	virtual ~Fahrzeug();
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

	virtual std::string getType() =0/*Erbende Objekte muessen dadurch ueberschrieben werden!*/; //<- pure virtual
};

