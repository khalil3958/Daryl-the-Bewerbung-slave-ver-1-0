#include "FzgParken.h"
#include "Losfahren.h"


FzgParken::FzgParken()
{
}


FzgParken::~FzgParken()
{
}

FzgParken::FzgParken(Weg* p, double a)
{
	pweg = p; 
	dStartZeit = a; 
}
double FzgParken::dStrecke(Fahrzeug* a, double b )  // dstartzeit
{
	//b = a->getdzeit() + this->dStartZeit; 
	bool	c = (fabs(a->getdzeit()-dGlobaleZeit )< 1e-6) ;
	if ( c  ||   fabs(dGlobaleZeit-a->getdzeit())>1e-6) // c=dStartzeit von der globalzeit beginnend  _ dGlobalezeit>b 
	{
		//a->setdzeit(this->dStartZeit);
		throw Losfahren(a,pweg );
		
	}
	else
	{
		a->setthespeed(0);
		return 0.0;
	}
 }
