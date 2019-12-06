
#include "Fahrzeug.h"
#include <iostream >
#include <iomanip>
#include "PKW.h"
#include "Fahrrad.h"
#include "FzgFahren.h"
#include"FzgParken.h"
class FzgFahren;
//int Fahrzeug::p_iMaxID = 0; // initialisation te3ha 
//class FzgFahren; 

Fahrzeug::Fahrzeug():aktivesVO()
{	
	
	//vInitialisierung();
	//p_sName = "";
	//p_iMaxID++;
	//p_iID = p_iMaxID;
} 

/*Fahrzeug::Fahrzeug(std::string a)
{
	//vInitialisierung();
	//p_iMaxID++;
	//p_iID = p_iMaxID;
	p_sName = a; 
	

}*/

Fahrzeug::Fahrzeug(const Fahrzeug& fahrzeug) : aktivesVO(p_sName) // tab3an ta3 el karhba 
{
	//vInitialisierung(); 
	 
	p_sName = fahrzeug.p_sName +"'";
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
	
	
}

Fahrzeug::Fahrzeug(std::string b, double c ) : aktivesVO(b)
{	
	//vInitialisierung();
	p_sName = b;
	p_dMaxGeschwindigkeit = c;
	p_dGesamtStrecke = 0; 
	//p_iMaxID++;
	//p_iID = p_iMaxID;
	p_pVerhalten = nullptr;
	thespeed = 0.0;
};


/*void Fahrzeug ::  vInitialisierung  ()
{
	p_dMaxGeschwindigkeit = 0; 
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0; 
	p_dZeit = 0; 
	p_sName = ""; 
	 p_iMaxID++;
	p_iID = p_iMaxID;
}*/
 
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
			<< setw(10) << setprecision(2) << p_dGesamtStrecke << std::endl
			<< "die aktuelle Geschwidigkeit ist :" << this->dGeschwindigkeit() << endl << "======================================================================="
			<< endl << endl << endl;
		return out;
 }
 

void  Fahrzeug::vAbfertigung() 
{
	
	if ((dGlobaleZeit - dZeit) > 0)
	{
		//p_dGesamtStrecke += (dGlobaleZeit - p_dZeit)*p_dMaxGeschwindigkeit;
		
		double abschnittzeit = dGlobaleZeit - dZeit;
		double takt_strecke =( p_pVerhalten->dStrecke(this, abschnittzeit));
		p_dGesamtZeit = p_dGesamtZeit + (abschnittzeit);
	
		p_dAbschnittStrecke += takt_strecke;

		p_dGesamtStrecke += takt_strecke;
		dZeit = dGlobaleZeit; 

	}

}
bool Fahrzeug::bZeichen(Weg* p )
{
	return true; 
}




double Fahrzeug:: dTanken (double dMenge ) 
{
	std::cout << "Fahrzeug und Fahrraeder koennen  nicht getankt werden "<< std::endl ;
	return 0.0; 
	}
	
double Fahrzeug ::dGeschwindigkeit()  const  
{
	
	return thespeed; 
}

Fahrzeug::~Fahrzeug()
{
	delete p_pVerhalten;
	//std::cout << "Deleted Fahrzeug :" << std::endl << "id=" << p_iID << std::endl << "name= ";
	//std::cout << p_sName.data()<<std::endl;
}
/*ostream& operator << (ostream& out, const Fahrzeug& fahrzeug)
{
	return fahrzeug.ostreamAusgabe(out);
}*/

bool Fahrzeug::operator < (const Fahrzeug& fahrzeug) const
{
 bool y = this->p_dGesamtStrecke < fahrzeug .p_dGesamtStrecke;
 return y; 
}

Fahrzeug&  Fahrzeug :: operator = (const Fahrzeug& fahrzeug)
{
	//vInitialisierung();
	p_sName = fahrzeug.p_sName +"''";	
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
	return *this;

}

double Fahrzeug::route()
{
	return p_dAbschnittStrecke; 
}

void Fahrzeug::set_route(double d)
{
	p_dAbschnittStrecke = d;
}

void Fahrzeug::VneueStrecke(Weg* p)
{	
	delete p_pVerhalten; 
	this->setdzeit(dGlobaleZeit);
	p_pVerhalten = new FzgFahren(p); 
	p_dAbschnittStrecke = 0; 
	
	
}
void Fahrzeug::VneueStrecke(Weg* p, double d)
{
	delete p_pVerhalten;
	p_pVerhalten = new FzgParken(p, d);
	p_dAbschnittStrecke = 0;
}


std::string Fahrzeug::getname()
{
	return p_sName;
}


double Fahrzeug::limitregulation(Weg* p) // 3awed edhen 
{
	bool a = this->p_dMaxGeschwindigkeit > p->getreallimit(); 
	
	if (a && p->limit() != Weg::Autobahn  )
	{
		thespeed = p->getreallimit();
		 

	}
	else if(p->limit()== Weg::Autobahn)
	{
		thespeed = p_dMaxGeschwindigkeit;
	}

	/*p->getminkm(this);
	if*/

	return thespeed; 
}
/*double Fahrzeug::dStrecke(Fahrzeug* p, double Zeitraum)
{

	for (Zeitraum = 1.0; pweg->lange() == p->route() && p->dGeschwindigkeit() <= pweg->limit(); Zeitraum++)
	{
		p->set_route(p->route() + (p->dGeschwindigkeit() * dGlobaleZeit));
	}
	return p->route();
}*/

double Fahrzeug::getgesamtstrecke()
{
	return p_dGesamtStrecke; 
}

void Fahrzeug::setmaxgeschwindigkeit(double s)
{
	p_dMaxGeschwindigkeit = s;
}

void Fahrzeug::setgesamtstrecke(double s)
{
	this->p_dGesamtStrecke = s; 
}

void Fahrzeug::setthespeed(double a)
{
	thespeed = a; 
}


double Fahrzeug::getdzeit()
{
	return dZeit; 
}

istream& Fahrzeug::istreamEingabe(istream& in)
{
	aktivesVO::istreamEingabe(in) >> p_dMaxGeschwindigkeit;
	return in;
}