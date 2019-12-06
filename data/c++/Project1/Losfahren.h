#pragma once
#include"FahrAusnahme.h"
#include "FzgFahren.h"
#include "FzgParken.h"
class Losfahren : public FahrAusnahme 
{
public:
	Losfahren();
	~Losfahren();
	Losfahren(Fahrzeug*, Weg*); 
	virtual void vBearbeiten();
};

