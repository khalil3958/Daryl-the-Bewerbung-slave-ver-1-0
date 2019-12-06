#pragma once
#include"FahrAusnahme.h"
#include  "FzgFahren.h"
#include"FzgParken.h"
class Streckenende : public FahrAusnahme
{
public:
	Streckenende();
	~Streckenende();
	Streckenende(Fahrzeug *, Weg*);
	virtual void vBearbeiten();
};

