#pragma once
#include"Weg.h"
class Weg; 
class Fahrzeug; 
class aktivesVO;
class FzgVerhalten 
{
public:
	FzgVerhalten();
	virtual ~FzgVerhalten();
	FzgVerhalten(Weg*);
	virtual double dStrecke(Fahrzeug*, double)   =0;
	
protected : 
	 
	Weg* pweg; 
};

