#include "PKW.h"


PKW::PKW()
{
	
	
}


PKW::~PKW()
{
}

PKW::PKW( const string sName, const double dMaxGeschwindigkeit, const   double dVerbrauch)
	: Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(55), p_dTankinhalt(55.0 / 2)
{
}

//PKW::PKW(const string sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen)
	//: Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(dTankvolumen), 
	//p_dTankinhalt(dTankvolumen / 2)
//{
// }
// initialisierungsliste 

double PKW::dTanken(double dMenge  )   //defaultparameter 
{
	if (dMenge == -0.0)
	{
		p_dTankinhalt = p_dTankvolumen;
		std::cout<<std::endl; 
		std::cout << "das PKW" << p_sName.data() <<" wurde voll getankt "<<std::endl;

	}
	else
		if ((dMenge < (p_dTankvolumen - p_dTankinhalt))&&(dMenge!=-0.0))
		{
			p_dTankinhalt = p_dTankinhalt + dMenge;
			std::cout << dMenge << "L wurden getankt "<<std::endl;
		}
		else
		{
			std::cout << dMenge << "L ist nicht möglich bitte wählen Sie weniger "<<std::endl;
		}
	std::cout <<"Die gesamte Menge ist : "<< p_dTankinhalt<<std::endl; 
	return p_dTankinhalt; 
}

double PKW::dVerbrauch()
{	
	double gesamtverbrauch = (p_dVerbrauch *(p_dGesamtStrecke / 100)); 
	return gesamtverbrauch; 
}

void  PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)
	{
		double newdGesamtstrecke = p_dGesamtStrecke;

		Fahrzeug::vAbfertigung(); 
		p_dTankinhalt = p_dTankinhalt - ( (p_dGesamtStrecke - newdGesamtstrecke) * p_dVerbrauch / 100);  // karhba 9a3da temchi donc tank
																										//mechi w youfa 

		if (p_dTankinhalt < 0) p_dTankinhalt = 0; // lezm l mazzout mahouch moin  
	}

}

void PKW::vAusgabe()
{
	double c;
	Fahrzeug::vAusgabe();
	c=dVerbrauch();
	std::cout <<std::endl<<"Gesamtverbrauch : "<< c<<std::endl; 
	std::cout <<"Tankinhalt :"<< p_dTankinhalt<<std::endl;
	
}
double PKW::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit; 
}