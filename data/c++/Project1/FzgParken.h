#pragma once
#include "FzgVerhalten.h"
#include "PKW.h"
class FzgParken : public FzgVerhalten
{
public:
	FzgParken();
	FzgParken(Weg*, double);
	virtual ~FzgParken();
	virtual double dStrecke(Fahrzeug* , double );
	
	//virtual double dStrecke () 
protected : 
	double dStartZeit;
};

