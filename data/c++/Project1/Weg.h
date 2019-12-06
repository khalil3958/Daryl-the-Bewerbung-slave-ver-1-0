#pragma once
//#include "Fahrzeug.h"
#include <iostream> 
#include "aktivesVO.h"
#include <list>
#include"FzgVerhalten.h"
#include"LazyListe.h"
#include"LazyAktion.h"

using namespace std ;
extern double dGlobaleZeit;

class Fahrzeug;
class Kreuzung;

class Weg : public aktivesVO

{
public:
	enum Begrenzung { Innerort=50, Landstrasse=100, Autobahn  };
	Weg();
	~Weg();
	Weg(const std::string a, const double b, const  Begrenzung  begrenzung = Autobahn , const bool verbot = true); 
	virtual ostream& ostreamAusgabe(ostream& out) const;

	//void vAbfertigung() ; 

	Begrenzung limit();
	double lange();
	//virtual void in(Weg, Fahrzeug*);
	//bool compare ( Weg , Weg ) ;
	virtual void vAnnahme(Fahrzeug *);
	virtual void vAnnahme(Fahrzeug *, double)  ; 
	void vAbfertigung()  ;
	virtual double relativestrecke(Fahrzeug*);
	double getreallimit(); 
	void vZeichen();
	void set_gegen(Weg* );
	void Abgabe(Fahrzeug*);
	double getminkm(double);
	double getlange();
	void setlange(double); 
	double GetVerbot(Fahrzeug*);
	Kreuzung* getrondpoint() ;
	Weg* get_gegen();
	void setZielkreuzung(Kreuzung* pZielkreuzung);
	
protected:



private:
	double 	p_dLange;
	Weg*   gegenstrecke ;
	LazyListe <Fahrzeug*>  p_pFahrzeug;
	Begrenzung  iMax_speed;
	bool Verbot; 
	Kreuzung* rondpoint;
};

