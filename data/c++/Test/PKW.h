#pragma once
#include <iostream>

#include "Fahrzeug.h"
class PKW : public Fahrzeug
{
public:
	PKW();
	~PKW();
	PKW( const string sName, const double dMaxGeschwindigkeit,  const double dVerbrauch);
	//PKW(const string sName, const  double dMaxGeschwindigkeit, const  double dVerbrauch,const   double dTankvolumen);// Initialisierungsliste 
	double dVerbrauch(); 
	virtual double dTanken( double dMenge = 0 ) ;
	virtual void vAbfertigung ();
	virtual void vAusgabe(); 

	double dGeschwindigkeit();
private : 
	double p_dVerbrauch; 
	double p_dTankinhalt; 
	double p_dTankvolumen; 
	double dMenge;

	
};	

