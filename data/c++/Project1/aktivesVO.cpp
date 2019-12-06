#include "aktivesVO.h"
#include <stdio.h>
#include <iomanip>
#include <map>
#pragma once 

int aktivesVO::p_iMaxID =0; 
map<string, aktivesVO*> aktivesVO::MyMap;

aktivesVO::aktivesVO()
{
	vInitialisierung(); 
	
}

aktivesVO::aktivesVO(std::string a)
{ 
	vInitialisierung();
	 p_sName = a;
	 fillMap();
}




aktivesVO::~aktivesVO()
{
	MyMap.erase(p_sName);

}

void aktivesVO::vInitialisierung()
{
	dZeit = 0;
	p_sName = "";
	p_iMaxID++;
	p_iID = p_iMaxID; 

}


ostream& aktivesVO::ostreamAusgabe(ostream& out)  const
{

	out << std::endl;
	out << setprecision(2) << setiosflags(ios::fixed) << setiosflags(ios::left)
		<< setw(10) << p_iID << resetiosflags(ios::right) << setiosflags(ios::left)
		<< setw(10) 
		;
	return out;
}

ostream& operator << (ostream& out, const aktivesVO& etwas)
{
	return etwas.ostreamAusgabe(out);
}

std::string aktivesVO::getname()
{
	return p_sName; 
}
void aktivesVO::setdzeit(double a)
{
	dZeit = a; 
}




istream& aktivesVO::istreamEingabe(istream& in) 
{	
	
	if (p_sName!="")
	{
		throw string("ERROR : Initialised instance can't be changed");
	}

	in>>p_sName;

	fillMap();

	return in;
}

istream& operator >> (istream& in, aktivesVO& a)
{
	return a.istreamEingabe(in);
}

void aktivesVO::fillMap()
{
	if (MyMap.find(p_sName) != MyMap.end())
	{
		throw string("ERROR :"+p_sName+"already exists");
	}
	else 	MyMap[p_sName] = this;
}



aktivesVO* aktivesVO::ptObjekt(string sName)
{
	aktivesVO* p = nullptr;

	auto it = MyMap.find(sName);

	if (it != MyMap.end())
	{
		p = it->second;
	}
	
	else
	{
		throw string("ERROR : the name you're searching for '" +sName +"' couldn't be found " );
	}

	return p;
}

