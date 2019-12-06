#pragma once
#include "Weg.h"
#include "Fahrzeug.h"
class FahrAusnahme
{
public:
	FahrAusnahme();
	~FahrAusnahme();
	FahrAusnahme(Fahrzeug*, Weg*);
	virtual void vBearbeiten() = 0;
protected: 
	Weg* ausw; 
	Fahrzeug* ausf;
};

