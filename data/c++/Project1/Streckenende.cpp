#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"

Streckenende::Streckenende()
{
}


Streckenende::~Streckenende()
{
}
 
Streckenende::Streckenende(Fahrzeug * a, Weg* b)
{
	ausw = b;
	ausf = a; 
}

void Streckenende::vBearbeiten()
	
{
	/*Weg* w = ausw->getrondpoint()->Randomize(ausw);
	ausf->setthespeed(0.0); 
	//ausf->VneueStrecke(ausw, 100);
	w->Abgabe(ausf);*/
	Kreuzung* pKreuzung = ausw->getrondpoint();
	ausw->Abgabe(ausf);

	if (pKreuzung != nullptr)
	{
		Weg* randomWeg = pKreuzung->Randomize(ausw);
		pKreuzung->dTanken(ausf);
		randomWeg->vAnnahme(ausf);
		ausf->VneueStrecke(randomWeg);
		cout << "ZEIT     : " << dGlobaleZeit << endl
			<< "KREUZUNG : " << pKreuzung->getname().data() << " " << pKreuzung->gettankstelle() << endl
			<< "WECHSEL  : " << ausw->getname().data() << " => " << randomWeg->getname().data() << endl
			<< "FAHRZEUG : " << *ausf << endl;
	}
	else
	{
		cout << "Streckenende ohne Zielkreuzung erreicht! Fahrzeug wird nicht umgesetzt." << endl;
	}

	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

 
}