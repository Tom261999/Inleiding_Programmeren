#include "pch.h"
#include "Bar.h"
#include <math.h> 
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>

Bar::Bar(int delen, double L, double C, double K, double rho) : N(setN(delen)), Lengte1(setLengte(L)), C1(setC(C)), K1(setK(K)), rho1(setrho(rho))
{
	cout << "De constructor wordt aangeroepen" << endl;
	setN(delen);
	setLengte(L);
	setC(C);
	setK(K);
	setrho(rho);
	T.resize(aantalopdelingen, 100);
	//vector <double> T(aantalopdelingen, 100); // De vector op 100 zetten omdat dat is als die uniform verdeeld is. 

}

int Bar::setN(int delen)
{
	if (delen <= 0)
	{
		if(delen < 0)
		{
			cout << "Error: Gelieve een positief aantal delen te geven, de absolute waarden wordt genomen." << endl; 
			 aantalopdelingen = abs(delen);
			 cout << "Het wordt in " << aantalopdelingen << " verdeeld" << endl; 
		}
		else
		{
			cout << "Error: Je opgegeven aantal delen is 0, dit kan niet en wordt veranderd naar 5" << endl; 
			aantalopdelingen = 5; 
			cout << "Het wordt in " << aantalopdelingen << " verdeeld" << endl;
		}
	}
	else
	{
		aantalopdelingen = delen;
		cout << "Het wordt in " << aantalopdelingen << " verdeeld" << endl;
	}

	return aantalopdelingen;
}
double Bar::setLengte(double L)
{
	if (L <= 0)
	{
		if (L < 0)
		{
			cout << "Error: De lengte kan niet negatief zijn, Hiervoor wordt de absolute waarde genomen." << endl;
			Lengte = abs(L); 
			cout << "De lengte is" << Lengte << endl;
		}
		else
		{
			cout << "Error: Je lengte kan niet 0 zijn, deze is nu 1" << endl; 
			Lengte = 1; 
			cout << "De lengte is" << Lengte << endl;
			
		}
	}
	else
	{
		Lengte = L;
		cout << "De lengte is " << Lengte << endl;
	}

	return Lengte;
}
double Bar::setK(double K)
{
		if (K < 0)
		{
			cout << "Error: De warmtegeleidingscoefficient kan niet negatief zijn, Hiervoor wordt de absolute waarde genomen." << endl;
			warmtegeleidingscoef = abs(K);
			cout << "Het warmtegeleidingscoëfficiënt is " << warmtegeleidingscoef << endl;
		}
	else
	{
		 warmtegeleidingscoef = K;
		 cout << "Het warmtegeleidingscoëfficiënt is " << warmtegeleidingscoef << endl;
	}
		return warmtegeleidingscoef; 
}
double Bar:: setrho(double rho)
{	if (rho <= 0)
	{
		if (rho < 0)
		{
			cout << "Error: De dichtheid kan niet negatief zijn, Hiervoor wordt de absolute waarde genomen." << endl;
		 Dichtheid = abs(rho);
		 cout << "Het dichtheid is " << Dichtheid << endl;
		}
		else
		{
			cout << "Error: De dichtheid kan niet 0 zijn, deze is nu 1" << endl;
		Dichtheid = 1;
		cout << "Het dichtheid is " << Dichtheid << endl;
		}
	}
	else
	{
		 Dichtheid = rho;
		 cout << "Het dichtheid is " << Dichtheid << endl;
	}
	return Dichtheid;
}
double Bar:: setC(double C)
{
	if (C <= 0)
	{
		if (C < 0)
		{
			cout << "Error: De warmtecapaciteit kan niet negatief zijn, Hiervoor wordt de absolute waarde genomen." << endl;
		 Warmtecapaciteit = abs(C);
		 cout << "De warmtecapaciteit is " << Warmtecapaciteit << endl;
		}
		else
		{
			cout << "Error: Je lengte kan niet 0 zijn, deze is nu 1" << endl;
		 Warmtecapaciteit = 1;
		 cout << "De warmtecapaciteit is " << Warmtecapaciteit << endl;

		}
	}
	else
	{
		 Warmtecapaciteit = C;
		 cout << "De warmtecapaciteit is " << Warmtecapaciteit << endl;
	}

	return Warmtecapaciteit;
}
double Bar::setdiscretisatie(double t)
{
	cout << "t =" << t << endl; 
	cout << aantalopdelingen << "aantalopdeingen is " << endl; 
	 delta_t = t / aantalopdelingen; 
     delta_x = Lengte / aantalopdelingen; 
	 cout << "delta t : " << delta_t << endl; 
	 cout << "delta x : " << delta_x << endl;
	return delta_t, delta_x; 
}
//double Bar::checketa()
//{
//	double  eta = (warmtegeleidingscoef*delta_t) / (Warmtecapaciteit*Dichtheid*(pow(delta_x, 2)));
//	if (eta < 1 / 2)
//	{
//		cout << "Er wordt voldaan aan de voorwaarde" << endl;
//	}
//	else
//	{
//		cout << "Gelieve de beginwaarden aan te passen zodat aan de voorwaarde wordt voldaan" << endl; 
//	}
//	return eta; 
//}
vector<double> Bar::settemperature(double t)
{
	vector<double> ::iterator it;
	it = T.begin();
	it = T.insert(it, 0);
	T.push_back(100);
	double verschuivingt = delta_t;
	double verschuivingx = delta_x; 
	eta = (warmtegeleidingscoef*verschuivingt) / (Warmtecapaciteit*Dichtheid*(pow(verschuivingx, 2)));
	
		for (double i = verschuivingt; i <= t; i = i + verschuivingt)
		{
			for (double j = verschuivingx; j <= Lengte; j = j + verschuivingx)
			{
			
				eta = (warmtegeleidingscoef*i) / (Warmtecapaciteit*Dichtheid*(pow(j, 2)));
				double T_zelfde = T.at(i);
				double T_volgende = T.at(i + 1);
				double T_vorige = T.at(i - 1); 

				Temperatuur.at(i) = T_zelfde + eta * (T_volgende + T_vorige - 2 * T_zelfde); 
				Temperatuur = T;  
			}
		}

		for (int i = 0; i < T.size(); i++) {
			std::cout << T.at(i) << "  ";
		}
		std::cout << "\n" << endl;
	
	//outputvector(T);
	string filename = "Taak 1";
	getTemperatuur(filename);

	//getTemperatuur(T);
	return  T; 
}

vector <double> Bar::getT()
{
	return T; 
}

void Bar::getTemperatuur(string& fileName)
{
	string myName = "Temperaturen frequentie"; 
	myName += ".txt"; 
	ofstream T_output(myName, ios::out);
	for (int i = 0; i < 100; i++)
	{
		T_output << T[i] << endl; 
	}
	if (!T_output)
	{
		cout << "Bestand niet gevonden" << endl; 
		exit(1); 

		for (vector <double>::const_iterator iter = T.begin();iter != T.end(); ++iter)
		{
			T_output << ";" << *iter; 
		}
		T_output << endl;
		T_output.close();
	}
	
}

//void outputvector(const vector <double> & outvec)
//{
//	int printcount = 0; 
//	for (vector<double> ::const_iterator iter = outvec.begin();
//		iter != outvec.end(); ++iter)
//	{
//		printcount++;
//		cout << setw(12) << *iter;
//		if (printcount % 4 == 0)
//			cout << endl;
//	}
//	cout << endl; 
//
//}
//vector <double> Bar::getT()
//{
//	string myName = "Temperatuur staaf"; 
//	myName += ".csv"; // Zet alles om in een excel bestand; 
//	ofstream T_output(myName, ios::out); 
//
//	for (int i = 0; i < Lengte; i= i+delta_x)
//	{
//		cout << "De staaf heeft volgende temperaturen" << endl; 
//		T_output << T[i] << endl;
//
//	}
//	if (!T_output)
//	{
//		cerr << " Error: Bestand niet gevonden. " << std::endl;
//		exit(1);
//
//	}
//	T_output.close();
//	return T;
//
//}

Bar::~Bar()
{
	cout << "Het object wordt geeleteted." << endl; 
}