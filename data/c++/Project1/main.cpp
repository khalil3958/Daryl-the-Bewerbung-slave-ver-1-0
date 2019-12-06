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
#include "Weg.h"
#include"FzgVerhalten.h"
#include "SimuClient.h"
#include"LazyAktion.h"
#include"LazyListe.h"
#include "Kreuzung.h"
#include <fstream>
#include<istream>
#include"Welt.h"
class Kreuzung;



int  start(  )
{
	int a; 
	cout << endl; 
		cout << "Wahlen Sie die Aufgabe : " << endl << endl << "1- Aufgabe 1 " << endl << endl << "2- Aufgabe 1 deb " << endl << endl << "3- Aufgabe 2 "
		<< endl << endl << "4- Aufgabe 3 " << endl << endl << "5- Aufgabe 4" << endl << endl << "6- Aufgabe 5" << endl <<endl<< "7- Aufgabe 6"
		<< endl<<endl << "8- Aufgabe 6a"<<endl<<endl<<"9- Aufgabe 7 "<<endl<<endl<< "10- Aufgabe 8 "<<endl<<endl<<" 11- Aufgabe9 part 1"<<endl<<endl <<"12- Aufgabe 9 part 2 "<<endl<<endl ;
	cin >> a;
	return a; 
}

	double dGlobaleZeit=0.0 ;


	void vAufgabe_1()
	{
		double x = 0;
		PKW Roua("hamila ", 50, 10);
		Fahrrad khalil("jlif ", 30);
		Fahrzeug aj;
		Fahrzeug e("Mercedes ", 90.00); // object crÈÈ statiquement yetfassakh automatiquement bel des
		Fahrzeug* j = new Fahrzeug("Audi", 50.00); // object crÈÈ dynamiquement fel memoire heap tfasskhou ken bel delete sinon yo93‡d fel RAM 
		unsigned int i;
		std::cout.width(10); std::cout << std::left << "ID";
		cout.width(10);
		std::cout << "Name";
		cout.width(3);
		std::cout << ":";
		cout.width(11);
		std::cout << "MaxKmh";
		cout.width(10);
		std::cout << "GesamtStrecke" << std::endl;
		for (i = 0; i < 48; i++)

		{
			std::cout << "+";

		}

		j->vAusgabe();
		e.vAusgabe();
		while (dGlobaleZeit < 6)
		{
			khalil.vAbfertigung();
			khalil.vAusgabe();
			Roua.vAbfertigung();
			Roua.vAusgabe();
			dGlobaleZeit = dGlobaleZeit + 1;
			e.vAbfertigung();
			e.vAusgabe();
			j->vAbfertigung();
			j->vAusgabe();

		}

		delete j;
		Roua.dTanken();
		e.dTanken();
	}
	

	void vAufgabe_1_deb()
	{
		Fahrzeug abc("a", 20);
		Fahrzeug bcd("b", 30);
		Fahrzeug cde("c", 40);
		Fahrzeug def("d", 50);
		Fahrzeug* Feld[5];
		Fahrzeug* p;
		Fahrzeug* q;
		Fahrzeug* r;
		Fahrzeug* s;
		p = &abc;
		q = &bcd;
		r = &cde;
		s = &def;


		Feld[0] = p;
		Feld[1] = q;
		Feld[2] = r;
		Feld[3] = s;

		for (int i = 0; i < 4; i++)
		{
			Feld[i]->vAusgabe();
		}



	}

	void vAufgabe_2()
	{
		int PKWanzahl = 0;
		int Fahrradanzahl = 0;

		std::cout << endl;
		cout << "how many  pkws ? ";
		cin >> PKWanzahl;
		cout << "how many bicycles  ";
		cin >> Fahrradanzahl;

		vector<Fahrzeug*> unsereFahrzeuge;

		for (int i = 1; i <= PKWanzahl; i++)
		{
			PKW *p = new PKW("AUTO " + to_string(i), 120, 10);
			unsereFahrzeuge.push_back(p);
		}

		for (int i = 1; i <= Fahrradanzahl; i++)
		{
			Fahrrad *s = new Fahrrad("FAHRRAD " + to_string(i), 12);
			unsereFahrzeuge.push_back(s);
		}

		double dZeitabfrage = 0.0;
		cout << "type the used time lap : ";
		cin >> dZeitabfrage;
		cout << endl;


		bool bK = fabs(dGlobaleZeit - 3.0) < 1e-6;
		bool bY = false;

		for (dGlobaleZeit = 0; dGlobaleZeit < 7; dGlobaleZeit = dGlobaleZeit + dZeitabfrage)
		{

			for (auto it = unsereFahrzeuge.begin(); it != unsereFahrzeuge.end(); it++)
			{
				if (dGlobaleZeit > 3.0) //nach 3 stunden keine tanken mehr 
				{
					bY = true;
				}
				if (bK || dGlobaleZeit > 2.0 && !bY)
				{
					(*it)->dTanken();

				}

				(*it)->vAbfertigung();
				(*it)->vAusgabe();
				cout << endl;
			}

		}


		for (auto it = unsereFahrzeuge.begin(); it != unsereFahrzeuge.end(); it++)
		{
			delete *it;
		}

	}

	void vAufgabe_3()
	{
		Fahrrad a("Not so fast ", 23);
		PKW b(" fast and furious ", 30, 10);
		Fahrrad c = a;// copy constructor
		Fahrrad d;
		d = a; // operateur 
		cout << endl;
		cout.width(10); std::cout << left << "ID";
		cout.width(10);
		cout << "Name";
		cout.width(3);
		cout << ":";
		cout.width(11);
		cout << "MaxKmh";
		cout.width(10);
		cout << "GesamtStrecke" << std::endl;

		cout << endl;

		cout << a << endl << b << endl << c << std::endl << d << endl;



		for (dGlobaleZeit = 1; dGlobaleZeit < 10; dGlobaleZeit++)
		{
			a.vAbfertigung();
			b.vAbfertigung();
			cout << endl;
			bool t = a < b;
			std::string s = "wins";
			if (t == true)
			{
				cout << endl << b << endl << s << endl;
			}
			else if (t == false)
			{
				cout << endl << a << " " << s << endl;
			}
			else break;
		}

	}


//////////////////////////////////////////////////AUFGABEBLOCK 2 //////////////////////////////////////////////////////



void vaufgabe_4()
{
	Weg mallesine("mallesine ",200 , Weg::Autobahn);
	Fahrzeug* a =new Fahrzeug("khalil1",150) 	;
	Fahrzeug* b = new Fahrzeug ("Khalil2", 80);
	//a.vAusgabe(); 
	 //cout << mallesine; 
	//a.vAbfertigung(); 
	//cout << a; 
	mallesine.vAnnahme(a);
	mallesine.vAnnahme(b,3);
	//mallesine.vAnnahme(c); 
	//mallesine.vAnnahme(d);
	for (dGlobaleZeit = 0; dGlobaleZeit <8; dGlobaleZeit=dGlobaleZeit+1)
	{
		 
		mallesine.vAbfertigung();
		cout << endl<<endl<<endl  << "*******" << endl << dGlobaleZeit << endl << "*******" << endl;
		cout << mallesine;
		cout << *a << *b;
	
		
	}
	delete a;
	delete b; 
	
}
void vaufgabe_5()
{
	bInitialisiereGrafik(1000, 1000);
	Weg*  machy = new Weg("mallesine", 1000, Weg::Innerort);
	Weg* jayyen = new Weg("agba", 1000, Weg::Innerort);
	PKW* dildol1 = new PKW("dildol1", 120, 0);
	PKW* dildol2 = new PKW("dildol2", 160, 0);
	Fahrrad* silsol1 = new Fahrrad("silsol1", 80);
	Fahrrad* silsol2 = new Fahrrad("silsol2", 90);
	machy->vAnnahme(dildol1);
	jayyen->vAnnahme(silsol1, 1.4);
	machy->vAnnahme(dildol2, 1.2);
	jayyen->vAnnahme(silsol2);
	machy->set_gegen(jayyen);
	machy->vZeichen();
	for (dGlobaleZeit = 0; dGlobaleZeit < 60; dGlobaleZeit = dGlobaleZeit + 1)
	{
		machy->vAbfertigung();
		jayyen->vAbfertigung();
		vSetzeZeit(dGlobaleZeit);
		dildol1->bZeichen(machy);
		dildol2->bZeichen(machy);
		silsol1->bZeichen(jayyen);
		silsol2->bZeichen(jayyen);


	}

	delete machy;
	delete jayyen;
	delete dildol1;
	delete silsol1;
	delete dildol2;
	delete silsol2;

}

void vaufgabe_6()
{
	//bInitialisiereGrafik(1000, 1000);
	Weg*  machy = new Weg("mallesine", 700, Weg::Innerort);
	Weg* jayyen = new Weg("terma", 700, Weg::Innerort);
	PKW* dildol1 = new PKW("dildol1", 90, 0);
	PKW* dildol2 = new PKW("dildol2", 160, 0);
	Fahrrad* silsol1 = new Fahrrad("silsol1", 80);
	Fahrrad* silsol2 = new Fahrrad("silsol2", 90);
	machy->vAnnahme(dildol1);
	machy->vAnnahme(silsol1, 2);
	machy->vAnnahme(dildol2, 3);
	machy->vAnnahme(silsol2);
	machy->set_gegen(jayyen);
	//machy->vZeichen();
	cout << *machy ;
	for (dGlobaleZeit = 0; dGlobaleZeit < 100; dGlobaleZeit = dGlobaleZeit + 1)
	{
		
		cout << endl << endl << endl << "*******" << endl << dGlobaleZeit << endl << "*******" << endl;
		
		//jayyen->vAbfertigung();
		cout << *dildol1 << *dildol2 ;
		machy->vAbfertigung();
		cout << *machy; 
		//vSetzeZeit(dGlobaleZeit);
		//dildol1->bZeichen(machy);
		//dildol2->bZeichen(machy);
		//silsol1->bZeichen(jayyen);
		//silsol2->bZeichen(jayyen);


	}

	vBeendeGrafik();
}
void vAufgabe6_a()
{
	 LazyListe<int>   a; 
	 
	 for (int i = 0; i <10; i++)
	 {
		 int b = rand() % 10 + 1; 
		 a.push_front(b);
	 }
	 
	 a.vAktualisieren();

	 for (auto it = a.begin(); it != a.end(); it++)
	 {
		 cout << *it <<"  " ;
	 }
	 cout << endl; 
	 for (auto it = a.begin(); it != a.end(); it++)
	 {
		 if ((*it) > 5)
		 {
			 cout << *it << " erased" << endl; 
			 a.erase(it);
		 }
		 
	 }
	 
	 a.vAktualisieren();
	 cout << endl;
	 for (auto it = a.begin(); it != a.end(); it++)
	 {
		 cout << *it <<" "  ;
	 }
	 
	 a.push_back(4);
	 a.push_back(1);
	 a.vAktualisieren();
	 cout << endl; 
	 
	 for (auto it = a.begin(); it != a.end(); it++)
	 {
		 cout << *it << " " ;
	 }

}

void vAufgabe7()
{
	bInitialisiereGrafik(1000, 1000);
	bool y = true ; 
	double a; 
	Weg*  machy = new Weg("mallesine", 700, Weg::Autobahn);
	Weg* jayyen = new Weg("terma", 700, Weg::Autobahn  );
	PKW* dildol1 = new PKW("dildol1", 30,50 );
	Fahrrad* silsol1 = new Fahrrad("silsol1", 1);
	PKW* dildol2 = new PKW("dildol2",200 ,0 );
	PKW* dildol3 = new PKW("superdildo", 120,0 );
	machy->vAnnahme(dildol1 );
	machy->vAnnahme(silsol1 );
	cout << "w‰hlen Sie die maximale Zeit : " << endl; 
	cin >> a;
	cout <<endl; 
	machy->set_gegen(jayyen);
	machy->vZeichen();
	for (dGlobaleZeit = 0; dGlobaleZeit < a; dGlobaleZeit++)
	{
		vSetzeZeit(dGlobaleZeit); 
		if ((dGlobaleZeit >= a / 2) && y)
		{
			machy->vAnnahme(dildol2, 2);
			machy->vAnnahme(dildol3, 3);
			cout << dildol2->getname() << " wurde in " << machy->getname() << " Angenommen" << endl<<endl;
			cout<< dildol3->getname()<<" wurde in "<< machy->getname() << " Angenommen" << endl<<endl;
			y = false;
		}

		cout << "****" << endl << dGlobaleZeit <<endl << "****" << endl; 
		machy->vAbfertigung(); 
		cout << *machy << *dildol1<< *silsol1 << *dildol2<<*dildol3; 
		silsol1->bZeichen(machy); 
		dildol1->bZeichen(machy);
		dildol2->bZeichen(machy);
		dildol3->bZeichen(machy); 

		
	}

}

void vAufgabe_8()
{
	Kreuzung Rp1("rondpoint1", 10000);
	Kreuzung Rp2("rondpoint2", 1000);
	Kreuzung Rp3("rondpoint3");
	Kreuzung Rp4("rondpoint4");

	PKW dildol1("dildol1", 120, 10);
	PKW dildol2("dildol2", 140, 20);
	Fahrrad silsol1("silsol1", 26);
	Fahrrad silsol2("silsol", 24);

	Rp1.V_verbinde( "W12", "W21", 40, &Rp2, Weg::Innerort, true);		// Straﬂe 1
	Rp2.V_verbinde( "W23a", "W32a", 115, &Rp3, Weg::Autobahn, true);		// Straﬂe 2
	Rp2.V_verbinde( "W23b", "W32b", 40, &Rp3, Weg::Innerort, true);		// Straﬂe 3
	Rp2.V_verbinde( "W24", "W42", 55, &Rp4, Weg::Innerort, true);		// Straﬂe 4
	Rp3.V_verbinde( "W34", "W43", 85, &Rp4, Weg::Autobahn, true);		// Straﬂe 5
	Rp4.V_verbinde("W44a", "W44b", 130, &Rp4, Weg::Landstrasse, true);	// Straﬂe 6

	Rp1.vAnnahme(&dildol1, 1.2);
	Rp1.vAnnahme(&dildol2, 2.6);
	Rp1.vAnnahme(&silsol1, 0.4);
	Rp1.vAnnahme(&silsol2, 1.8);
	
	if (!bInitialisiereGrafik(1200, 800))
	{
		cerr << "Fehler beim Starten des Simulationsservers." << endl;
	}
	int iCoords1[] = { 680,  40, 680, 300 };
	int iCoords2[] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
	int iCoords3[] = { 680, 300, 680, 570 };
	int iCoords4[] = { 680, 300, 320, 300 };
	int iCoords5[] = { 680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	int iCoords6[] = { 320, 300, 320, 150, 200,  60,  80,  90,  70, 250, 170, 300, 320, 300 };
	
	bZeichneStrasse("W12", "W21", 40, 2, iCoords1);
	bZeichneStrasse("W23a", "W32a", 115, 6, iCoords2);
	bZeichneStrasse("W23b", "W32b", 40, 2, iCoords3);
	bZeichneStrasse("W24", "W42", 55, 2, iCoords4);
	bZeichneStrasse("W34", "W43", 85, 5, iCoords5);
	bZeichneStrasse("W44a", "W44b", 130, 7, iCoords6);
	
	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300);
	
	
	for (dGlobaleZeit = 0; dGlobaleZeit < 100; dGlobaleZeit =dGlobaleZeit+0.1)
	{
		vSetzeZeit(dGlobaleZeit);
		cout << "*******" << endl << dGlobaleZeit << endl << "*********" << endl; 
		Rp1.vAbfertigung();
		Rp2.vAbfertigung();
		Rp3.vAbfertigung();
		Rp4.vAbfertigung();

		Rp1.vZeichnen();
		Rp2.vZeichnen();
		Rp3.vZeichnen();
		Rp4.vZeichnen();
		
		cout << dildol1 << endl << dildol2 << endl << silsol1 << endl << silsol2 << endl << Rp1 << endl << Rp2 << endl << Rp3 << endl << Rp4 << endl;
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	vSleep(100);
	}

	//vBeendeGrafik();
}
void v_Aufgabe9()
{
	ifstream a("VO.dat");
	//ifstream c("SimuDisplay.dat");
	ifstream b("Simu.dat");

	if (!a)
	{
		cout << "ERROR : Vo.dat can't be opened";
		return;
	}

	PKW dildol;
	Fahrrad silsol;
	Kreuzung Rondpoint;
	Welt denya;
	a >> dildol >> silsol >> Rondpoint;
	a.close();
	cout << dildol << endl << silsol << endl << Rondpoint << endl;
	try
	{
		string sName = "";

		cout << "Please type the name of the object you're looking for : " << endl;
		cin >> sName;
		aktivesVO* a = aktivesVO::ptObjekt(sName);
		cout << "Pointer: " << a << endl << *a << endl;

		cout << "Please type the name of the object you're creating : " << endl;
		cin >> sName;
		Fahrrad silsol(sName, 12);
		cout << silsol << endl;


	}
	catch (string &exception)
	{
		cerr << exception << endl;
	}

	/*cout << endl << "++++++++++++++++++++++ Aufgabe 9.5 ++++++++++++++++++++++++++++" << endl;

	try
	{
		denya.vEinlesen(b);
	}

	catch (string &a)
	{
		cerr << a << endl;
	}

	denya.vSimulation();
	cout << denya << endl;
	b.close();
	*/
}
void vAufgabe9()
{
	ifstream c("SimuDisplay.dat");
	Welt denya; 
 		cout << endl << "+++++++++++++++++++++++++ Aufgabe 9.6 ++++++++++++++++++++++++++++" << endl;
		if (!bInitialisiereGrafik(1200, 1000))
		{
			cerr << "Der Simulationsserver konnte nicht gestartet werden." << endl;
			exit(2);
		}
		try
		{
			denya.vEinlesenMitGrafik(c);
		}
		catch (string &a)
		{
			cerr << a << endl;
		}
		c.close();

		for (dGlobaleZeit = 0; dGlobaleZeit < 100; dGlobaleZeit += 0.1)
		{
			vSetzeZeit(dGlobaleZeit);
			denya.vSimulation();
			denya.vZeichnen();
			vSleep(10);
		}

		vBeendeGrafik();
	}









int main ()
{	
	
	cout << endl;
	int a = 1;
	while (a < 13)

	{
		int b = start();
		a = b;
		switch (b)
		{
		case 1:system("CLS");
			vAufgabe_1();
			cout << endl;
			break;
		case 2:system("CLS");
			vAufgabe_1_deb();
			cout << endl;
			break;
		case 3:system("CLS");
			vAufgabe_2();
			cout << endl;
			break;
		case 4:system("CLS");
			vAufgabe_3();
			cout << endl;
			break;
		case 5:system("CLS");
			vaufgabe_4();
			cout << endl;
			break;
		case 6:system("CLS");
			vaufgabe_5();
			cout << endl;
			break;
		case 7:system("CLS");
			vaufgabe_6();
			cout << endl;
			break;
		case 8:system("CLS");
			vAufgabe6_a();
			cout << endl;
			break;
		case 9: system("CLS");
			vAufgabe7();
			cout << endl;
			break; 
		case 10: system("CLS");
			vAufgabe_8();
			cout << endl;
			break;
		case 11: system("CLS");
			v_Aufgabe9();
			cout << endl;
			break; 
		case 12: system("CLS");
			vAufgabe9();
			cout << endl;
			break; 

		}
	}
	return 0;
}
	
	
	

