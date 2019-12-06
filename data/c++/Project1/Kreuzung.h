#pragma once
#include "aktivesVO.h"
#include"LazyListe.h"
#include "Weg.h"
#include<list>
class Weg;
class PKW;
class Fahrzeug;

class Kreuzung :
	public aktivesVO
{
public:
	Kreuzung();
	~Kreuzung();
		
	Kreuzung(std::string);
	Kreuzung(std::string, double T);
	void V_verbinde(std::string, std::string, double, Kreuzung*, Weg::Begrenzung, bool);
	void dTanken(Fahrzeug*);
	void vAnnahme(Fahrzeug*, double);
	void vAbfertigung();
	virtual ostream& ostreamAusgabe(ostream& out) const;
	void vZeichnen();
	Weg* Randomize(Weg*);
	double gettankstelle();
	virtual istream& istreamEingabe(istream& in);



private:
		double dTankstelle;
		list<Weg*>  p_Weg;

	};


