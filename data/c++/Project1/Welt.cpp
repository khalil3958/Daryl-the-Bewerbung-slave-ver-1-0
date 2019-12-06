#include "Welt.h"
#include "PKW.h"
#include"Fahrrad.h"
#include"SimuClient.h"
#include"Kreuzung.h"


Welt::Welt()
{
}


Welt::~Welt()
{
}


void Welt::vEinlesen(istream& in)
{
	while (!in.eof()) 
	{
		string a = "";
		in >> a;

		if (a == "KREUZUNG")
		{
			Kreuzung* rondpoint = new Kreuzung();

			in >> *rondpoint;

			p_pKreuzungen.push_back(rondpoint);
		}
		else if (a == "STRASSE")
		{
			string sNameQ, sNameZ;
			string sNameW1, sNameW2;
			int dLange, maxspeed, verbot;
			Weg::Begrenzung eLimit;
			bool y;

			in >> sNameQ >> sNameZ >> sNameW1 >> sNameW2 >> dLange >> maxspeed>> verbot;

			switch (maxspeed)
			{
			case 1: eLimit = Weg::Innerort; break;
			case 2: eLimit = Weg::Landstrasse; break;
			case 3: eLimit = Weg::Autobahn; break;
			default: throw string("ERROR : The speed limit is not defined"); break;
			}

			switch (verbot)
			{
			case 0: y = false; break;
			case 1: y = true;  break;
			default: throw string("ERROR : Verbot isn't available"); break;
			}

			Kreuzung* hin = dynamic_cast<Kreuzung*> (aktivesVO::ptObjekt(sNameQ));
			Kreuzung* ruck = dynamic_cast<Kreuzung*> (aktivesVO::ptObjekt(sNameZ));

			if (hin == nullptr || ruck == nullptr)
			{
				throw string("ERROR : linking is not possible");
			}

			hin->V_verbinde(sNameW1, sNameW2, dLange, ruck, static_cast<Weg::Begrenzung>(eLimit), y);
		}
		else if (a == "PKW")
		{
			PKW* car = new PKW ();
			string sName;
			double dStartzeit;

			
			in >> *car >> sName >> dStartzeit;

			Kreuzung* first = dynamic_cast<Kreuzung*> (aktivesVO::ptObjekt(sName));

			if (first == nullptr)
			{
				throw string("ERROR : Car can't get in the traffic ");
			}

			
			first->vAnnahme(car, dStartzeit);
		}
		else if (a == "FAHRRAD")
		{
			Fahrrad* bike = new Fahrrad();
			string sName;
			double dStartzeit;

			
			in >> *bike >> sName >> dStartzeit;

			Kreuzung* pStart = dynamic_cast<Kreuzung*> (aktivesVO::ptObjekt(sName));

			if (pStart == nullptr)
			{
				throw string("ERROR : The bike can't get in the traffic");
			}
			pStart->vAnnahme(bike, dStartzeit);
		}
		else
		{
			throw string("FATAL ERROR : the type you entered isn't supported");
		}
	}
}



void Welt::vSimulation()
{
	for (auto it = p_pKreuzungen.begin(); it != p_pKreuzungen.end(); ++it)
	{
		(*it)->vAbfertigung();
	}
}


ostream& Welt::ostreamAusgabe(ostream& out) const
{
	for (auto it = p_pKreuzungen.begin(); it != p_pKreuzungen.end(); ++it)
	{
		out << **it << endl;
	}
	return out;
}

ostream& operator << (ostream& out, const Welt& w)
{
	return w.ostreamAusgabe(out);
}

void Welt::vZeichnen()
{
	for (auto it = p_pKreuzungen.begin(); it != p_pKreuzungen.end(); ++it)
	{
		(*it)->vZeichnen();
	}
}

void Welt::vEinlesenMitGrafik(istream & in)
{
	while (!in.eof())
	{
		string a = "";
		in >> a;

		if (a == "KREUZUNG")
		{
			Kreuzung* rondpoint = new Kreuzung();
			int X, Y;

		
			in >> *rondpoint >> X >> Y;

			bZeichneKreuzung(X, Y);
			p_pKreuzungen.push_back(rondpoint);
		}
		else if (a== "STRASSE")
		{
			string sNameQ, sNameZ;
			string sNameW1, sNameW2;
			int dlange, maxspeed, verbot, coordones;
			Weg::Begrenzung limit;
			bool bverbot;

			in >> sNameQ >> sNameZ >> sNameW1 >> sNameW2 >> dlange >> maxspeed >> verbot >>coordones ;

			switch (maxspeed)
			{
			case 1: limit = Weg::Innerort; break;
			case 2: limit = Weg::Landstrasse; break;
			case 3: limit = Weg::Autobahn; break;
			default: throw string("ERROR : The speed limit is not defined"); break;
			}

			switch (verbot)
			{
			case 0: bverbot = false; break;
			case 1: bverbot = true;  break;
			default: throw string("ERROR :  Ueberholverbot not defined"); break;
			}

			
			Kreuzung* hin = dynamic_cast<Kreuzung*> (aktivesVO::ptObjekt(sNameQ));
			Kreuzung* ruck = dynamic_cast<Kreuzung*> (aktivesVO::ptObjekt(sNameZ));

			if (hin == nullptr || ruck == nullptr)
			{
				throw string("Error : the centers can't be linked together");
			}

			int *iCoords = new int[2 * coordones]; 

			for (int i = 0; i < coordones; i++)
			{
				in >> iCoords[2 * i] >> iCoords[2 * i + 1];
			}

			bZeichneStrasse(sNameW1, sNameW2, dlange, coordones, iCoords);

			delete iCoords;
			hin->V_verbinde( sNameW1, sNameW2,  dlange, ruck, static_cast<Weg::Begrenzung>(limit), bverbot);
		}
		else if (a == "PKW")
		{
			PKW* car = new PKW();
			string sName;
			double dStartzeit;

			in >> *car >> sName >> dStartzeit;

		
			Kreuzung* first = dynamic_cast<Kreuzung*> (aktivesVO::ptObjekt(sName));

			if (first == nullptr)
			{
				throw string("ERROR : The car can't get in the traffic");
			}

			first->vAnnahme(car, dStartzeit);
		}
		else if (a == "FAHRRAD")
		{
			Fahrrad* bike = new Fahrrad();
			string sName;
			double dStartzeit;

			
			in >> *bike >> sName >> dStartzeit;

			Kreuzung* first = dynamic_cast<Kreuzung*> (aktivesVO::ptObjekt(sName));

			if (first == nullptr)
			{
				throw string("ERROR : The bicycle can't get in the traffic ");
			}

		
			first->vAnnahme(bike, dStartzeit);
		}
		else
		{
			throw string("FATAL ERROR :the type you entered isn't supported ");
		}
	}
}