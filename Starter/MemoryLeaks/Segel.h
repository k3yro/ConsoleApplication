#pragma once
#include <iostream>

#include "Mast.h"


class Segel
{
public:
	Segel();
	~Segel();

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

	int setGroesse(float groesse)
	{
		this->groesse = groesse;
		return 0;
	}

	int setMast(Mast* mast)
	{
		this->mast = mast;
		return 0;
	}

	std::string getName()
	{
		return this->name;
	}

	std::string getHersteller()
	{
		return this->hersteller;
	}

	float getGroesse()
	{
		return this->groesse;
	}

	Mast* getMast()
	{
		return this->mast;
	}

private:
	std::string name;
	std::string hersteller;
	float groesse;
	Mast *mast = nullptr;
};

