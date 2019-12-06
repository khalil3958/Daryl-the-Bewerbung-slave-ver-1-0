#pragma once
#include <iostream> 
#include <iomanip> 
#include<istream>
#include<string>
#include <map>
using namespace std;


class aktivesVO
{
public:
	aktivesVO();
	aktivesVO(std::string );
	virtual void vAbfertigung()  =0;
	virtual  ostream& ostreamAusgabe(ostream&  out) const ;
	virtual ~aktivesVO();
	//virtual void vInitialisierung(); 
	std::string getname();
	virtual void setdzeit(double); 
	virtual istream& istreamEingabe(istream& in)  ;
	static aktivesVO* ptObjekt(string sName);
	void fillMap();

protected   : 
	std::string p_sName; 
	double dZeit; 
	int p_iID;
private :  
	static map<string, aktivesVO*> MyMap;
	static int p_iMaxID; 
	void vInitialisierung(); 
	

};

ostream& operator << (ostream& out, const aktivesVO& etwas ) ;
istream& operator >> (istream& in, aktivesVO& vo) ;