#include "pch.h"
#include "Dobbelsteen.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
Dice::Dice(int dobbelstenen, int zijden) : NDice(setNDices(dobbelstenen)), NFace(setNFaces(zijden))
{

	vector <int> Distribution(2 * NFace, 0); // vector met op al de NFace plaatsen een 0 om de distribution juist te zetten. We nemen ook 2*Nface omdat je de som gaat moeten nemen en die is max 2*Nface
	vector <double> Frequentie(2 * NFace, 0);
	setNDices(dobbelstenen);
	setNFaces(zijden);
	std::cout << "Aandacht: De constructor is net aangeroepen." << std::endl;
	Reset();
}

int Dice::setNDices(int dobbelstenen)
{
	if (dobbelstenen <= 0)
	{
		if (dobbelstenen < 0)

		{
			cout << "Error: Je moet met minstens 1 dobbelsteen gooien" << endl;
			aantalstenen = abs(dobbelstenen);
			cout << "Het aantal dobbelstenen is " << aantalstenen << endl;
		}

		else
		{
			cout << "Error: Je moet met minstens 1 dobbelsteen gooien" << endl;
			aantalstenen = 1;
			cout << "Het aantal dobbelstenen is " << aantalstenen << endl;

		}
	}
	else
	{
		aantalstenen = dobbelstenen;
		cout << "Het aantal dobbelstenen is " << aantalstenen << endl;

	}
	Reset();
	return aantalstenen;
}

int Dice::setNFaces(int zijden)
{

	if (zijden != 4 && zijden != 6 && zijden != 8 && zijden != 12 && zijden != 20)
	{
		cout << "Error: Je aantal zijden moeten 4,6,8,12 of 20 zijn, Deze wordt nu op 6 gezet" << endl;
		aantalzijden = 6;

	}
	else
	{
		aantalzijden = zijden;
	}
	cout << "Het aantal zijden is " << aantalzijden << endl;
	Reset();
	return aantalzijden;
}

int Dice::NThrows(int worpen)
{
	int aantalworpen = 0;
	for (int k = 0; k < worpen; k++) // Voor elke worp moet je de soms van de waarde in de vector zetten
	{
		int som = 0;
		for (int i = 0; i < NDice; i++) //Je moet per dobbelsteen de waarden in 
		{
			som += (rand() % NFace) + 1; // Hier wordt er per dobbelsteen een randomgetal genomen dat 1 van de zijden is. Deze wordt bij som opgeteld. De plus 1 is zodat het getal tussen 1 en NFace ligt.
		}
		Distribution.at(som - 1)++; // Op de plaats van som wordt er 1 bijgeteld om zo te kunnen zien hoeveel keren dat getal gegooid is. Er moet nog 1 bij opgeteld worden, omdat de vector bij 0 begint. 
		aantalworpen += 1;
	}

	getFrequentie();
	return aantalworpen;
}


void Dice::Reset()
{
	Distribution.resize(2*NFace, 0);
	Frequentie.resize(2*NFace, 0); //De vectoren worden terug op 0 gezet. 

}

void Dice::getDistribution()
{
	string myName = "Resultaten distribution";
	myName += ".csv";
	ofstream Distribution_output(myName, ios::out);

	for (int i = 0; i < aantalstenen * aantalzijden; i++)
	{
		cout << Distribution[i] << endl;
		Distribution_output << Distribution[i] << endl;

	}
	if (!Distribution_output)
	{
		cerr << " Error: Bestand niet gevonden. " << std::endl;
		exit(1);

	}
	Distribution_output.close();
	exit(1);
	//return Distribution;

}


vector<double> Dice::getFrequentie()
{
	for (int i = 0; i < Distribution.size(); i++)
	{
		Frequentie.at(i) = (double)Distribution[i] / aantalworpen; //Geeft de frequentie van waar hoeveel worpen waren. 
	}

	string myName = "Resultaten frequentie";
	myName += ".csv";
	ofstream Frequentie_output(myName, ios::out);

	for (int i = 0; i < 2 * aantalzijden; i++)
	{
		cout << Frequentie[i] << endl;
		Frequentie_output << Frequentie[i] << endl;

	}
	if (!Frequentie_output)
	{
		cerr << " Error: Bestand niet gevonden. " << std::endl;
		exit(1);

	}
	Frequentie_output.close();

	return Frequentie;
}


Dice::~Dice()
{
	std::cout << "Object wordt gedeleteted" << std::endl; // De deconstructor die uiteindelijk
}