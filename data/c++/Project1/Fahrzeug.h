#pragma once
#include <iostream>
#include "aktivesVO.h" 
#include "FzgVerhalten.h"
#include "Weg.h"


extern double dGlobaleZeit; 
class FzgParken;
//class Weg;
class FzgFahren; 
class Fahrzeug: public aktivesVO
{
public:
	Fahrzeug();
//	Fahrzeug(std::string );
	Fahrzeug(std::string, double);
	virtual ~Fahrzeug(); 
	virtual void vAusgabe();
	virtual void vAbfertigung() ;   
	virtual double dGeschwindigkeit()  const ;
	virtual double dTanken(double dMenge = 0);
	virtual ostream& ostreamAusgabe(ostream& out) const  ;
	bool  operator < (const Fahrzeug& fahrzeug) const; 
	Fahrzeug(const Fahrzeug& fahrzeug);
	Fahrzeug& operator = (const Fahrzeug& fahrzeug);
	double route();
	void set_route(double);
	virtual void VneueStrecke(Weg*);
	std::string getname();
	//double dStrecke(Fahrzeug* p, double Zeitraum);
	double getgesamtstrecke(); 
	double limitregulation (Weg*);
	void setmaxgeschwindigkeit(double);
	void setgesamtstrecke(double);
	virtual void VneueStrecke(Weg*, double); 
	virtual void setthespeed(double);
	virtual double getdzeit(); 
	virtual bool bZeichen(Weg*);
	virtual istream& istreamEingabe(istream& in);
	

protected : 
	//int p_iID;
	//static int p_iMaxID;  // page 35 objet statique variable commune entre les tout objets de cette classe ki tbaddal wahda yetbaddlou lkoll  // 	
	//std::string p_sName;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke; 
	double p_dGesamtZeit;
	double p_dZeit; 
	double p_dAbschnittStrecke;
	double thespeed; 
	FzgVerhalten * p_pVerhalten;

	
private:


	//void vInitialisierung(); 

};

//ostream& operator << (ostream& out, const Fahrzeug& fahrzeug)  ;