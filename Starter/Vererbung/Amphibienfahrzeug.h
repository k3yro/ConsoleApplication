#pragma once
#include "Landfahrzeug.h"
#include "Wasserfahrzeug.h"

class Amphibienfahrzeug : public Wasserfahrzeug, public Landfahrzeug
{
public:
	Amphibienfahrzeug();
	~Amphibienfahrzeug();
};

