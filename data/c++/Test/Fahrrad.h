#include <iostream>
#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug
{
public:
	Fahrrad();
	~Fahrrad();
	Fahrrad (const string sName, const double dMaxGeschwindigkeit);
	virtual double dGeschwindigkeit() const ;
};

