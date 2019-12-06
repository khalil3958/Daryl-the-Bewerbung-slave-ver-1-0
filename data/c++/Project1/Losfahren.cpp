#include "Losfahren.h"
#include"FzgParken.h"


Losfahren::Losfahren()
{
}


Losfahren::~Losfahren()
{
}

Losfahren::Losfahren(Fahrzeug* a, Weg* b)
{
	ausf = a;
	ausw = b; 
}


void Losfahren::vBearbeiten()
{
//	ausw->getminkm(ausf);

	 // getdzeit ??  

	ausw->Abgabe(ausf);
	ausw->vAnnahme(ausf);

}