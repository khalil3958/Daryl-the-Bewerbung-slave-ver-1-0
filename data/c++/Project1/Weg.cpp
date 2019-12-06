#pragma once 
#include "Weg.h"
#include <iostream>
#include "Fahrzeug.h" 
#include "aktivesVO.h"
#include <list>
#include "FahrAusnahme.h"
#include "SimuClient.h"

#include "Kreuzung.h"
#include<algorithm>
using namespace std; 
typedef list <int > ListInt;



Weg::Weg()
{
}



Weg::Weg(const std::string Name, const  double length ,  const Weg:: Begrenzung begrenzung , const bool Verbot  ) 
	: aktivesVO (Name ) ,  p_dLange (length ) ,  iMax_speed (begrenzung) , Verbot (Verbot)


{

}

Weg::~Weg()
{
}
 
double Weg::lange()
{
	return p_dLange; 
}
 
Weg::Begrenzung Weg ::limit()
{	

	return iMax_speed;
}

double Weg::getreallimit()
{
	if (iMax_speed == Weg::Innerort)
	{
		return 50;
	}
	if (iMax_speed == Weg::Landstrasse)
	{
		return 100;
	}
	else return std::numeric_limits<double>::infinity();
}


ostream& Weg::ostreamAusgabe(ostream& out) const
{

	out << std::endl;
	out << setprecision(2) << setiosflags(ios::fixed) << setiosflags(ios::left)
		<< setw(10) << p_iID << resetiosflags(ios::right) << setiosflags(ios::left)
		<< setw(10) << p_sName.data() << setw(3) << ":" << resetiosflags(ios::right) << setiosflags(ios::left)
		<< setw(10) << p_dLange << " "
		<< setw(10) << iMax_speed << " ";
		
	cout << "(";

	for (auto it = p_pFahrzeug.begin(); it != p_pFahrzeug.end(); ++it)
	{
		out << (*it)->getname().data()<< " ";
		 
		
	}
	out << ")"<<endl<<"======================================================================="<<endl ;

	return out;

}
void Weg::vAnnahme(Fahrzeug * p)
{
	// 
		
			p->VneueStrecke(this);
			p_pFahrzeug.push_front( p); 
			
	//	for (Intp = p_pFahrzeug.rbegin; Intp != p_pFahrzeug.rend; Intp++)
	//{

	}
void Weg::vAnnahme(Fahrzeug*p, double d)
{
	p->VneueStrecke(this, d);
	p->setdzeit(dGlobaleZeit + d); 
	p_pFahrzeug.push_back(p);
	p_pFahrzeug.vAktualisieren(); 
}
 
void Weg::vAbfertigung() 
{
	 
	for (auto it = p_pFahrzeug.begin(); it != p_pFahrzeug.end(); ++it)
	{	
		try {
			(*it)->vAbfertigung();
			}
		catch(FahrAusnahme& a)
		{
			a.vBearbeiten();
		}
	}
	p_pFahrzeug.vAktualisieren();

	this->dZeit = dGlobaleZeit;
}

double Weg::relativestrecke(Fahrzeug* p)
{
	double a = p->route() / this->lange();
	return a; 

}

void Weg::set_gegen(Weg* a)
{
	gegenstrecke = a;
}
void Weg::vZeichen() 
{
	for (auto it = p_pFahrzeug.begin(); it != p_pFahrzeug.end(); ++it)
	{
		(*it)->bZeichen(this);
	}
	/*int az[4] = { 700, 250, 100, 250 }; 
  return	bZeichneStrasse(p_sName, gegenstrecke->getname(), p_dLange, 2, az);
*/}

void Weg::Abgabe(Fahrzeug * p )
{	
	//Fahrzeug* a = p;
	//p_pFahrzeug.remove(p);
	//this->vAnnahme(p);
	for (auto it = p_pFahrzeug.begin(); it != p_pFahrzeug.end(); ++it)
	{
		if ((*it) == p)
		{
			p_pFahrzeug.erase(it);
		}
	}


}

double Weg::getminkm(double d)
{
	//idee : zid karhba mel teli fiha l conditions taa l constructor 
	//p->setgesamtstrecke(p->dGeschwindigkeit()*(dGlobaleZeit - p->getdzeit()));
	//double a = p->getgesamtstrecke();
	double a = p_dLange;
	for (auto it = p_pFahrzeug.begin(); it!= p_pFahrzeug.end() ;++it)
	{
		
		double b = (*it)->route();
		
		 if (b <= a && b!=0 && b>d)
		{
			a = b;
		}
		
		 
		
	}
	 
	return a;
}
 
double Weg::GetVerbot(Fahrzeug* p)
{
	if (Verbot == true)
		return this->getminkm(p->route());
	else
		return p_dLange;
}
 
double Weg::getlange()
{
	return p_dLange;
}

void Weg::setlange( double a )
{
	p_dLange = a; 
}

Kreuzung* Weg::getrondpoint() 
{
	return rondpoint;
}

void Weg::setZielkreuzung(Kreuzung* pZielkreuzung)
{
	rondpoint= pZielkreuzung;
}

/*bool Weg::bUberholverbot(Weg* a)
{
	a->Verbot = false;
	return a->Verbot;
}*/

Weg* Weg::get_gegen()
{
	return  gegenstrecke; 
}





/*void Weg::in(Weg weg, Fahrzeug* fahrzeug)//3awed edhen fel weg
{
	if ((fahrzeug->route() <= weg.lange()) && ( fahrzeug->dGeschwindigkeit() <= weg.limit()))
	{
		fahrzeug ->set_route(fahrzeug-> route() + (fahrzeug->dGeschwindigkeit() * dGlobaleZeit));
	}

}*/

/*bool Weg :: compare ( Weg weg1 , Weg weg2)
{
	if ((weg1.iMax_speed == weg2.iMax_speed) && (weg1.lange == weg2.lange) && (weg1.p_sName == weg2.p_sName))
	{
		return true; 

	}
	else return false; 
}*/