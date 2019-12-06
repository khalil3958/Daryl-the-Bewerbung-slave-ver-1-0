#include "FzgVerhalten.h"



FzgVerhalten::FzgVerhalten()
{
}


FzgVerhalten::~FzgVerhalten()
{
}





FzgVerhalten::FzgVerhalten(Weg* p)
{
	pweg = p ; 
 }


/*double FzgVerhalten::dStrecke(Fahrzeug* p, double Zeitraum)
{
	bool bY = true;
	bool bK = pweg->lange() - p->getgesamtstrecke() > 0.0;

	if (p->route() + p->getgesamtstrecke() > pweg->lange())
	{
		bY = false;
	}

	if ((bY == false) && (bK == true))
	{
		p->set_route(pweg->lange() - p->getgesamtstrecke());
	}



	else if (bK == true && bY == true)
	{

		p->set_route(p->limitregulation(pweg) * Zeitraum);



	}

	else { p->set_route(0.0); }

	if (pweg->lange() < p->route() + p->getgesamtstrecke() && bK == true)
	{
		p->setgesamtstrecke(pweg->lange() - p->route());
	}

	return p->route();
}*/











