#include "FahrAusnahme.h"
class Weg;
class Fahrzeug; 


FahrAusnahme::FahrAusnahme()
{
}


FahrAusnahme::~FahrAusnahme()
{
}
FahrAusnahme::FahrAusnahme(Fahrzeug* f, Weg* w)
{
	ausf = f;
	ausw = w; 
}