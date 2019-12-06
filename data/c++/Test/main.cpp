#pragma once 
#include <iostream>
#include "Fahrzeug.h"
#include <iomanip>
#include"PKW.h"
#include "Fahrrad.h"
#include <vector>
#include<math.h>
#include <string>
#include<stdlib.h>
#include "aktivesVO.h" 
int  start(  )
{
	int a; 
	cout << "Wahlen Sie die Aufgabe : " << endl << endl << "1- Aufgabe 1 " << endl << endl << "2- Aufgabe 1 deb " << endl << endl << "3- Aufgabe 2 "
		<< endl << endl << "4- Aufgabe 3 " << endl<<endl;
	cin >> a;
	return a; 
}
 
void vaufgabe_5()
{
	Fahrzeug a("terma ", 150)	;
	a.vAusgabe(); 
	


}



int main ()
{

	return 0;
 }

