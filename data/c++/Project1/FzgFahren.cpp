#include "FzgFahren.h"
#include"Fahrzeug.h"
#include"Streckenende.h"



FzgFahren::~FzgFahren()
{
}

FzgFahren::FzgFahren(Weg* pWeg)
	: FzgVerhalten(pWeg)
{
}

double i = 0;
bool gegenVerbot = false;


double FzgFahren::dStrecke(Fahrzeug* p, double Zeitraum) //zu korrigieren: ist bei PKW auch so wenn tankinhalt leer ist ? 
														// es muss doch parken ?? Idee:: polymorphie von dstrecke 
{

	if (fabs(p->route() - pweg->lange()) < 1e-06) {
		throw Streckenende(p, pweg);
	}
	p->setthespeed(p->limitregulation(pweg)); 
	double takt_strecke = (p->dGeschwindigkeit() * Zeitraum);
	bool bY = true;
	double a = p->route();
	bool bK = ((pweg->GetVerbot(p)-a) - takt_strecke) > 0;
	//p->setdzeit(dGlobaleZeit);

	if (bK == false && bY == true)
	{
		takt_strecke = (pweg->GetVerbot(p) - a );
	}



/*if (pweg->GetVerbot() == true)
{
	pweg->getminkm(p);
}*/


//if (takt_strecke + p->route() > pweg->lange()) // wenn   das fahrzeug uberschreitet aber trzdem die gesamtstrecke < lenge 
//	{
//		bY = false;
//	 }
//
//if ((bY == false) && (bK == true)) // was ubriges von der entfernung berechnen 
//	{
//		p->setthespeed(0.0);
//		return (pweg->lange() - p->route());
//	} 
//
//
//else if (pweg->lange() < (pweg->GetVerbot(p) + takt_strecke))
//	{
//		throw Streckenende(p, pweg);
//
//	}



	 /*if (pweg->lange() < ((p->route() )))
		{
		

		}*/

	
	
	//i++; 
	
	

	return takt_strecke;
}

