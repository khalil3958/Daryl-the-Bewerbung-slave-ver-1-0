#pragma once 
#include <iostream>
#include "Fahrrad.h"
#include"Fahrzeug.h"
#include"SimuClient.h"



Fahrrad::Fahrrad()
	: Fahrzeug()
{
}

Fahrrad::~Fahrrad()
{
}


Fahrrad::Fahrrad (const string sName, const double dMaxGeschwindigkeit)
: Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

double Fahrrad::dGeschwindigkeit() const 
{
	double a = p_dMaxGeschwindigkeit;
	int i;
	int b = (int)(p_dGesamtStrecke/20); 
	for (i = 0; i < b; i++)
	{
		a = a - (a / 10);

	}
	if (a < 12)
	{
		a = 12;
	}
		

	return a ;
	
}

bool Fahrrad::bZeichen(Weg* w)
{
		return	(bZeichneFahrrad( p_sName,  w->getname(), w->relativestrecke(this), thespeed));
}


	/*double a = p_dMaxGeschwindigkeit;
	while ((a > 12))
	{
		if (p_dGesamtStrecke == 0)
		{
			return p_dMaxGeschwindigkeit;
		}
		if (p_dGesamtStrecke >= 20)
		{
			p_dGesamtStrecke = p_dGesamtStrecke - 20;
			p_dMaxGeschwindigkeit = p_dMaxGeschwindigkeit - (p_dMaxGeschwindigkeit / 10);
			if (p_dMaxGeschwindigkeit < 12)
			{
				p_dMaxGeschwindigkeit = 12;
			//}
	*/