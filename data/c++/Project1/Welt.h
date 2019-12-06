#pragma once
#include <list>
#include "Kreuzung.h"
class Welt
{
public:
	Welt();
	virtual ~Welt();
	void vEinlesen(istream& in);
	void vSimulation();
	ostream& ostreamAusgabe(ostream& out) const;
	void vZeichnen();
	void vEinlesenMitGrafik(istream& in);
private:
	list<Kreuzung*> p_pKreuzungen;
};

ostream& operator << (ostream& out, const Welt& w);