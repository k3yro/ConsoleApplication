#pragma once
#include <iostream>
#include <string>

enum Durchmesser
{
	RDM, SDM
};

class Mast
{
public:
	Mast(Durchmesser);
	~Mast();

	std::string getName()
	{
		return this->name;
	}

	std::string getHersteller()
	{
		return this->hersteller;
	}

	std::string getModel() 
	{
		return d ? this->hersteller + " " + this->name + " SDM " + std::to_string(this->laenge) : this->hersteller + " " + this->name + " RDM " + std::to_string(this->laenge);
	}

	std::string getDurchmesser() 
	{
		return std::to_string(this->d);
	}

	int getLaenge()
	{
		return this->laenge;
	}

	float getGewicht()
	{
		return this->gewicht;
	}

	int getCarbon()
	{
		return this->carbon;
	}

	int getHaerte()
	{
		return this->haerte;
	}

	int setName(std::string name)
	{
		this->name = name;
		return 0;
	}

	int setHersteller(std::string hersteller)
	{
		this->hersteller = hersteller;
		return 0;
	}

	int setDurchmesser(Durchmesser d)
	{
		this->d = d;
		return 0;
	}

	int setLaenge(int laenge)
	{
		this->laenge = laenge;
		return 0;
	}

	int setGewicht(float gewicht)
	{
		this->gewicht = gewicht;
		return 0;
	}

	int setCarbon(int carbon)
	{
		this->carbon = carbon;
		return 0;
	}

	int setHaerte(int haerte)
	{
		this->haerte = haerte;
		return 0;
	}

private:
	Durchmesser d;
	std::string name;
	std::string hersteller;
	int laenge;
	float gewicht;
	int carbon;
	int haerte;
};

