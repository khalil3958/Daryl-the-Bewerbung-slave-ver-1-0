
#include "Fahrzeug.h"
#include <iostream >
#include <iomanip>
#include "PKW.h"
#include "Fahrrad.h"
int Fahrzeug::p_iMaxID = 0; // initialisation te3ha 


Fahrzeug::Fahrzeug()
{	
	
	vInitialisierung();
	p_sName = "";
	//p_iMaxID++;
	//p_iID = p_iMaxID;
} 

Fahrzeug::Fahrzeug(std::string a)
{
	vInitialisierung();
	//p_iMaxID++;
	//p_iID = p_iMaxID;
	p_sName = a; 
	

}

Fahrzeug::Fahrzeug(const Fahrzeug& fahrzeug) // tab3an ta3 el karhba 
{
	vInitialisierung(); 
	 
	p_sName = fahrzeug.p_sName +"'";
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
	
	
}

Fahrzeug::Fahrzeug(std::string b, double c )
{	
	vInitialisierung(); 
	p_sName = b; 
	p_dMaxGeschwindigkeit = c;
	p_iMaxID++;
	p_iID = p_iMaxID;
};


void Fahrzeug ::  vInitialisierung  ()
{
	p_dMaxGeschwindigkeit = 0; 
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0; 
	p_dZeit = 0; 
	p_sName = ""; 
	 p_iMaxID++;
	p_iID = p_iMaxID;
}
 
 void Fahrzeug::vAusgabe()
{
	std::cout << std::endl;
	std::cout <<  setprecision(2) << setiosflags(ios::fixed) <<  setiosflags(ios::left)
		<< setw(10) <<p_iID  << resetiosflags(ios::right) << setiosflags(ios::left)
		<< setw(10) << p_sName.data() << setw(3)<<":" << resetiosflags(ios::right)<< setiosflags(ios::left)
		<<setw(10)<< p_dMaxGeschwindigkeit << " "
		<< setw(10) << p_dGesamtStrecke << std::endl
		<<"die aktuelle Geschwidigkeit ist :"<<dGeschwindigkeit() ;
		
	

}

 ostream& Fahrzeug::ostreamAusgabe(ostream& out) const 
 {
	 
		out << std::endl;
		out << setprecision(2) << setiosflags(ios::fixed) << setiosflags(ios::left)
		 << setw(10) << p_iID << resetiosflags(ios::right) << setiosflags(ios::left)
		 << setw(10) << p_sName.data() << setw(3) << ":" << resetiosflags(ios::right) << setiosflags(ios::left)
		 << setw(10) << p_dMaxGeschwindigkeit << " "
		 << setw(10) << p_dGesamtStrecke << std::endl
		 << "die aktuelle Geschwidigkeit ist :" << dGeschwindigkeit();
	 return out;
 }
 

void  Fahrzeug::vAbfertigung()
{

	if ((dGlobaleZeit - p_dZeit) > 0)
	{
		
		//p_dGesamtStrecke += (dGlobaleZeit - p_dZeit)*p_dMaxGeschwindigkeit;
		p_dGesamtStrecke += (dGlobaleZeit - p_dZeit)*dGeschwindigkeit(); 
		p_dZeit = dGlobaleZeit;
		p_dGesamtZeit += (dGlobaleZeit - p_dZeit);
	}

}
double Fahrzeug:: dTanken (double dMenge ) 
{
	std::cout << "Fahrzeug und Fahrraeder koennen  nicht getankt werden "<< std::endl ;
	return 0.0; 
	}
	
double Fahrzeug ::dGeschwindigkeit() const 
{
	return p_dMaxGeschwindigkeit; 
}

Fahrzeug::~Fahrzeug()
{
	//std::cout << "Deleted Fahrzeug :" << std::endl << "id=" << p_iID << std::endl << "name= ";
	//std::cout << p_sName.data()<<std::endl;
}
ostream& operator << (ostream& out, const Fahrzeug& fahrzeug)
{
	return fahrzeug.ostreamAusgabe(out);
}

bool Fahrzeug::operator < (const Fahrzeug& fahrzeug) const
{
 bool y = this->p_dGesamtStrecke < fahrzeug .p_dGesamtStrecke;
 return y; 
}

Fahrzeug&  Fahrzeug :: operator = (const Fahrzeug& fahrzeug)
{
	vInitialisierung();
	p_sName = fahrzeug.p_sName +"''";	
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
	return *this;

}