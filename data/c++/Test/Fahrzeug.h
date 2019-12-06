#pragma once 
#include <iostream>
#include <iomanip>


using namespace std;
extern double dGlobaleZeit; 

class Fahrzeug
{
public:
	Fahrzeug();
	Fahrzeug(std::string );
	Fahrzeug(std::string, double);
	virtual ~Fahrzeug(); 
	virtual void vAusgabe();
	virtual void vAbfertigung();   
	virtual double dGeschwindigkeit() const;
	virtual double dTanken(double dMenge = 0);
	virtual ostream& ostreamAusgabe(ostream& out) const  ;
	bool  operator < (const Fahrzeug& fahrzeug) const; 
	Fahrzeug(const Fahrzeug& fahrzeug);
	Fahrzeug& operator = (const Fahrzeug& fahrzeug);

protected : 
	int p_iID;
	static int p_iMaxID;  // page 35 objet statique variable commune entre les tout objets de cette classe ki tbaddal wahda yetbaddlou lkoll  // 	
	std::string p_sName;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke; 
	double p_dGesamtZeit;
	double p_dZeit; 
	
private:
	void vInitialisierung(); 

	
};

ostream& operator << (ostream& out, const Fahrzeug& fahrzeug)  ;