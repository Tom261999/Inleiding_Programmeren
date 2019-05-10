#include "pch.h"
#include "DiceACovaci.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

Dice::Dice(const int NumberOfdice, const int NumberOfFaces) : Ndice(setDice(NumberOfdice)), Nfaces(setFaces(NumberOfFaces)), SizeVect(NumberOfdice*NumberOfFaces)
{
	cout << " de constructor werd hier aangeroepen" << endl;
	
	vector<float> nulFrequency (SizeVect, 0.0);
	Frequency = nulFrequency;
	vector<int> nulDistribution (SizeVect, 0);
	Distribution = nulDistribution;
	Nthrows = 0;
	}

int Dice::setDice(int NumberOfdice) const
{
	while (NumberOfdice < 1) {
		cerr << "It is not logical to have 0 or a negative amount of dices. Input a logical amount" << endl;
		std::cin >> NumberOfdice;
	}
	return NumberOfdice;
}

int Dice::setFaces(int NumberOfFaces) const
{
	while (NumberOfFaces != 4 && NumberOfFaces != 6 && NumberOfFaces != 8 && NumberOfFaces != 12 && NumberOfFaces != 20) {
		cerr << "a dice with this amount of sides doesn't exist." << endl;
		std::cin >> NumberOfFaces;
	}
	return NumberOfFaces;
}
void Dice::setThrow(int& NumberOfthrows)
{
	int som = 0;
	for (int i=0; i < SizeVect ; i++)
	{
		som += Distribution[i];
	}
	if (NumberOfthrows == som)
	{
		Nthrows = NumberOfthrows;
	}
	else
	{
		cerr << "the amount of previous throwns doesn't correspond with the summation of the ellements from Distribution" << endl;

	}
}


void Dice::setDistribution(vector<int> inputDistr) 
{
	
	
	if (SizeVect == inputDistr.size())
	{
		Distribution = inputDistr;
	}
	else
	{
		cerr << "The input vector doesn't have the same size as the distribution vector." << endl;
		cerr << "De distributie wordt aan de nuldistributie geljk gesteld" << endl;
		vector <int> nuldistr(SizeVect, 0);
		Distribution = nuldistr;
		
	}
}

void Dice::Throw(int newThrow)
{
	if (newThrow <= 0)
	{
		cerr << " the amount of throws has to be positive and greater than zero, it is now set to 1 throw" << endl;
		newThrow = 1;
	}
	Nthrows += newThrow;
	int lengte = SizeVect;

	for (int j = 0; j < newThrow; j++)
	{

		int somOgen = 0;
		for (int i = 0; i < Ndice; i++)
		{
			somOgen += (rand() % Nfaces) + 1;
			
		}
		Distribution.at(somOgen - 1)++;
	}

	/*
	int j = 0;
	while (j < newThrow){
		somOgen = (rand() % lengte) + 1;
		Distribution[somOgen-1] += 1;
		j++;
	}
	*/
}



vector <int> Dice::getDistribution(string filenaam) 
{
	filenaam += ".txt";
	ofstream outputDist(filenaam, ios::out);

	cout << " number of faces: " << Nfaces << endl;
	cout << " number of Dice: " << Ndice << endl;
	cout << " amount of times that the dice has been thrown: " << Nthrows << endl;
	for (int i = 0; i < SizeVect; i++)
	{
		cout << " the amount of times " << i + 1 << " has been thrown, is: " << Distribution[i] << endl;
		outputDist << Distribution[i] << endl;
	}
	if (!outputDist)
	{
		cerr << "file not found" << endl;
		exit(1);
	}
	outputDist.close();
	return Distribution;
}

vector <float> Dice::getFrequency(string filenaam)
{
	filenaam += ".txt";
	ofstream outputFreq(filenaam, ios::out);
	for (int i = 0; i < SizeVect; i++)
	{
		float freqwaarde = Distribution[i] / (float)Nthrows;
		Frequency[i] = freqwaarde * 100;
		outputFreq << Frequency[i] << endl;
	}
	if (!outputFreq)
	{
	    cerr << "file not found" << endl;
	    exit(1);
	}
	outputFreq.close();

	for (int i = 0; i < SizeVect; i++)
	{
		cout << "The chance (in percentage) of throwing " << i + 1 << "is " << Frequency[i] << "%" << endl;
	}
	return Frequency;
}
void Dice::Reset()
{
	Distribution.clear();
	Frequency.clear();
	for (int i = 0; i < SizeVect; i++)
	{
		Distribution.push_back(0);
		Frequency.push_back(0);
	}
	Nthrows = 0;
		cout << "the previous distribution and frequency have been reset" << endl;
}



Dice::~Dice()
{
	cout << "de destructor is aangeroepen geweest " << endl;
}