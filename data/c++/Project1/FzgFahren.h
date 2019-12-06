#pragma once
#include "FzgVerhalten.h"
class FzgVerhalten;
class FzgFahren : public FzgVerhalten
{
public:
	virtual ~FzgFahren();
	FzgFahren(Weg*);
	virtual double dStrecke(Fahrzeug*, double) ;

protected:

};


