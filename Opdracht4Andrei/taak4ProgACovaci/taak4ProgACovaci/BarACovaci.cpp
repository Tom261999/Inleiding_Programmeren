// Andrei Coavci, 2BaFys
// andrei.covaci@student.uantwerpen.be
// in te leveren tegen 12/04/2019

#include "pch.h"
#include <iostream>
#include <vector>
#include "BarACovaci.h"
#include <string>
#include <fstream>

using namespace std;

// constructor met initialisatie van de constanten die de staaf bepalen
Bar::Bar(const double  L, const double C, const double Rho, const double K) : Length(SetFunc(L)), HeatCap(SetFunc(C)), Density(SetFunc(Rho)), DifusionCst(SetFunc(K))
{
	cout << "the Constructor has been called here" << endl;
}
// destructor
Bar::~Bar()
{
	cout << "the Destructor has been called here" << endl;
}

// functie dat checkt of de ingegeven waarden niet slecht gekozen zijn
double Bar::SetFunc(double InsertValue) const
{
	if (InsertValue < 0) {// checken voor negatieve getallen
		cerr << "The input is a negative number, this is not allowed" << endl;
		cerr << "The absolute value of the inserted number will be returned" << endl;
		cerr << "\n" << endl;
		return abs(InsertValue);// functie returned de absolute waarde van het negatief getal 
	}
	else if (InsertValue == 0) {//checken of de waarde nul is waar het niet zou mogen
		while (InsertValue <= 0) {// functie laat je een nieuwe waarde invullen om toch verder te kunnen gaan.
			cerr << "It is not possible to have a the value of this number be equal to 0" << endl;
			cerr << "please input a correct positive value" << endl;
			cerr << "\n" << endl;
			std::cin >> InsertValue;
		}
		return InsertValue;
	}
	else 
		return InsertValue;
}



void Bar::OutPutMaker(vector<double> TePrintVect, string name) {
	// gedeelte dat de filenaam aanmaakt
	string Filename = "File ";
	Filename += name;
	Filename += ".txt";
	ofstream OutPutFile(Filename, ios::out);
	// checken of de file goed gemaakt en geopend is
	if (!OutPutFile) {
		cerr << " Outputfile not found." << endl;
		exit(1);
	}
	else //vector in een kolom afdrukken in de .txt file 
	{
		for (int i=0; i < TePrintVect.size(); i++) {
			OutPutFile << TePrintVect.at(i) << endl;
		}
	}
	// afpprinten van de vector in de console 
	cout << " The Bar has the following temperatures:" << endl;
	for (int i = 0; i < TePrintVect.size(); i++) {
		cout << TePrintVect.at(i) << " ";
	}
	cout << "\n" << endl;
}


vector<double> Bar::Heat(double dx, double dt, double T, string OutputFileName, int situatie)
{
	
	// checken of de ingegeven waarden mogelijk zijn 
	dx = SetFunc(dx);
	dt = SetFunc(dt);
	T = SetFunc(T);


	double éta = (DifusionCst*dt) / (HeatCap*Density*pow(dx, 2.0));// initialiseren van éta
	if (éta >= 0.5)// checken of de von Neuman stabiliteitsvoorwaarden voldaan zijn
	{
		cerr << "Not a stable solution, because " << éta << " is bigger (or equal) than 0.5" << endl;
	}
	else
	{
		cout << "Stable solution, because " << éta << " is smaller than 0.5" << endl;
	}
	
	int lengthstep = ceil(Length / dx);// bepalen van de groote van de lengte-intervallen waarmee gewerkt zal worden
	int timestep = ceil(T / dt);// bepalen van de groote van de tijdsintervallen waarmee gewerkt zal worden

	vector<double> HeatDistr;// initialiseren van de vector die de temperaturen gaat bij houden 
	vector<double> TempDistr;// initialiseren van een dummyvector nodig voor de berekeningen


	// in deze if statement wordt bepaald welke rand en beging voorwaarden er worden gebruikt voor de staaf.
	if (situatie == 1) {
		// beging en randvoorwaarden voor taak 1 en 2

		// beging voorwaarden: temperatur = 0°C aan een kant temperatur =  100°C
		HeatDistr.resize(lengthstep, 100);
		HeatDistr.at(0) = 0;
		TempDistr = HeatDistr;

		// de algoritme voor de bepaling van de temperatuur op moment T
		for (int i = 0; i < timestep; i++) {
			TempDistr.at(0) = 0;
			TempDistr.at(lengthstep - 1) = 100;
			for (int j = 1; j < lengthstep - 1; j++) {
				TempDistr.at(j) = HeatDistr.at(j) + éta * (HeatDistr.at(j - 1) + HeatDistr.at(j + 1) - 2 * HeatDistr.at(j));
			}
			HeatDistr = TempDistr;
		}

	}

	else if (situatie == 2) {
		// beging en randvoorwaarden voor taak 3

		// begingvoorwaarde zijnde een piek in het midden van de staaf met tmperatuur =100°C
		HeatDistr.resize(lengthstep, 0);
		HeatDistr.at(ceil((double)lengthstep / 2)) = 100;
		TempDistr = HeatDistr;

		// de algoritme voor de bepaling van de temperatuur op moment T
		for (int i = 0; i < timestep; i++) {
			TempDistr.at(0) = TempDistr.at(1);
			TempDistr.at(lengthstep - 1) = TempDistr.at(lengthstep - 2);
			for (int j = 1; j < lengthstep - 1; j++) {
				TempDistr.at(j) = HeatDistr.at(j) + éta * (HeatDistr.at(j - 1) + HeatDistr.at(j + 1) - 2 * HeatDistr.at(j));
			}
			HeatDistr = TempDistr;
		}


	}
	else {
		cerr << "The choice of situation has to be either 1 or 2" << endl;
		exit(1);

	}

	
	OutputFileName += to_string(T);	//aanmaken van de naam van de files
	OutPutMaker(HeatDistr, OutputFileName); // output op de console als op de .txt files maken
	
	return HeatDistr;
}

