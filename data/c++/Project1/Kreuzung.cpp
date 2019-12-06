#include "Kreuzung.h"
#include"Weg.h"
#include "Fahrzeug.h" 
#include"PKW.h"
class Weg;
class PKW;


Kreuzung::Kreuzung()
{
}


Kreuzung::~Kreuzung()
{
}

Kreuzung::Kreuzung(std::string a):aktivesVO(a)
{
	p_sName = a;
}

Kreuzung::Kreuzung(const std::string a, double d) :
	aktivesVO(a), dTankstelle(d)
{

}

void Kreuzung::V_verbinde(std::string Namehin, std::string nameruck, double limit, Kreuzung* p, Weg::Begrenzung begrenzung, bool uberhol)
{
	Weg* machy = new Weg(Namehin, limit, begrenzung, uberhol);
	Weg* jayyen = new Weg(nameruck, limit, begrenzung, uberhol);
	machy->set_gegen(jayyen);
	jayyen->set_gegen(machy);
	machy->setZielkreuzung(p);
	jayyen->setZielkreuzung(this);

	p_Weg.push_back(machy);
	p->p_Weg.push_back(jayyen);

}



void Kreuzung::vAnnahme(Fahrzeug* f, double b)
{
	dTanken(f);

	p_Weg.front()->vAnnahme(f, b);


}

void Kreuzung::vAbfertigung()
{
	for (auto it = p_Weg.begin(); it != p_Weg.end(); ++it)
	{
		(*it)->vAbfertigung();

	}
}

void Kreuzung::dTanken(Fahrzeug* p)
{
	if (dTankstelle > 0)
	{
		dTankstelle = dTankstelle - p->dTanken();

	}
	else if (dTankstelle < 0)
	{
		dTankstelle = 0.0;
	}
	else
		return;

}


ostream& Kreuzung::ostreamAusgabe(ostream& out) const
{

	out << std::endl;
	out << setprecision(2) << setiosflags(ios::fixed) << setiosflags(ios::left)
		<< setw(10) << p_iID << resetiosflags(ios::right) << setiosflags(ios::left)
		<< setw(10) << p_sName.data() << setw(3) << ":" << resetiosflags(ios::right) << setiosflags(ios::left)
		<< setw(10) << " Gazoline" << dTankstelle << " ";

	cout << "(";

	for (auto it = p_Weg.begin(); it != p_Weg.end(); ++it)
	{
		out << (*it)->getname().data() << " ";


	}
	out << ")" << endl << "=======================================================================" << endl;

	return out;

}



void Kreuzung::vZeichnen()
{
	for (auto it = p_Weg.begin(); it != p_Weg.end(); ++it)
	{
		(*it)->vZeichen();
	}
}


Weg* Kreuzung::Randomize(Weg* p)
{
	Weg* randomWeg = nullptr;

	if (p_Weg.size() == 1)
	{
		return p_Weg.front();
	}
	do
	
	{
		int Random = rand() % p_Weg.size();
		int i = 0;

		for (auto it = p_Weg.begin(); it != p_Weg.end(); ++it)
		{
			if (i++ >= Random)
			{
				randomWeg = *it;
				break;
			}
		}
		/*auto it = p_Weg.begin();

		std::advance(it, Random);*/

	} while (randomWeg == p->get_gegen() && randomWeg != nullptr);
	
	return randomWeg;
}

double Kreuzung::gettankstelle()
{
	return dTankstelle;
}

istream& Kreuzung::istreamEingabe(istream& in)
{
	aktivesVO::istreamEingabe(in) >> dTankstelle;
	return in;
}
