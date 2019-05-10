/*	Opdracht1: Dice.cpp
	Bert Jorissen (s0150821)
	bert.jorissen@student.uantwerpen.be
	datum inlevering: vrijdag 24 maart 2017

	Code voor class Dice*/

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>	//max_element
#include "Dice.h"

using namespace std;

// Hier wordt even verondersteld dat het aantam zijden en aantal dobbelstenen gelijk is aan 1,
// anders moet er een functie worden geschreven die te sterk lijkt op Reset, en aangezien direct hierna
// de functies 'setNDice()' en 'setNfaces()' aangeroepen worden die altijd de waarde van 'nDice' en 'nFaces' veranderen
// (indien de invoer niet klopt (geheel, kleiner dan 1)), geven deze functies een waarde van 1 aan de variabelen.
Dice::Dice(int nFacesIn, int nDiceIn) {
	nDice = 1;
	nFaces = 1;
	setNDice(nDiceIn);
	setNfaces(nFacesIn);
}

Dice::~Dice() {}

void Dice::setNDice(int nDiceIn) {
	if (nDiceIn < 1) {
		cerr << "Error: negative / 0 Dice Number is not possible: " << nDiceIn << endl;
		cerr << "       Dice Number is now set to 1" << endl;
		nDice = 1;
	} else { nDice = nDiceIn;}
	Reset();
}
	
void Dice::setNfaces(int nFacesIn) {
	if (nFacesIn < 1) {
		cerr << "Error: negative / 0 Face Number is not possible: " << nFacesIn << endl;
		cerr << "       Face Number is now set to 1" << endl;
		nFaces = 1;
	} else { nFaces = nFacesIn; }
	Reset();
}

void Dice::Throw() {
	int som = 0;
	for (int i = 0; i < nDice; i++) som += (rand() % nFaces) + 1;
	frequency.at(som - nDice)++;
}

void Dice::Reset() {
	frequency.resize(nDice*(nFaces - 1)+1, 0);
}

// Deze functie is optioneel en gebruikt code uit de voorbeeldprogramma's van de les. Als uitvoer geeft het een 
// '.csv' bestand, dat bewerkt kan worden met excel of matlab.
void Dice::csvWrite(string& fileName)
{
	ofstream outStream(fileName, ios::out);
	if (!outStream)
	{
		cerr << "file not found" << endl;
		exit(1);
	}
	int printcount = 0;
	int i = 0;
	for (vector<int>::const_iterator iter = frequency.begin();
		iter != frequency.end(); ++iter)
	{
		printcount++;
		i++;
		outStream << nDice - 1 + i << ";" << *iter << endl;
	}
	outStream.close();
}

vector<int> Dice::getFrequency() {
	return frequency;
}

// Omdat de lengte van de vector niet vastlegt heveel stenen of zijden een dobbelsteen heeft, is het nodig
// om minstens 1 variabele te geven die de zijde/aantal stenen vastlegt. Echter is het beter om beide te 
// vragen en een controle te doen of de lengte van de verwachte vector, gezien de zijden en de stenen, overeen
// komt met de lengte van de opgegeven vector. De voorwaarde is dat de gelijkheid voldaan moet zijn:
//		nDice*(nFaces - 1)+1 == frequency.size()
// in de voorwaarde van de if-structuur wordt een omgevormde gelijkheid gebruikt, waar in het linkerlid een
// getal staat, dit toont netter.
// Als output geeft de functie de originele frequency vector terug, zodat deze misschien nog zou gebruikt kunnen worden.
vector<int> Dice::setFrequency(vector<int> frequencyIn, int nFacesIn, int nDiceIn) {
	if (nFacesIn < 1) {
		cerr << "Error: negative / 0 Face Number is not possible: " << nFacesIn << endl;
		exit(1);
	}
	if (nDiceIn < 1) {
		cerr << "Error: negative / 0 Dice Number is not possible: " << nDiceIn << endl;
		exit(1);
	}
	if (((frequencyIn.size() -1)/nDiceIn)-nFacesIn != -1){
		cerr << "Error:combination Dice and Face Number is not possible. " << frequencyIn.size() << endl;
		exit(1);
	}
	vector<int> frequencyReturn = frequency;
	frequency = frequencyIn;
	nDice = nDiceIn;
	nFaces = nFacesIn;
	return frequencyReturn;
}

// In de inleiding staat dat er getracht wordt om de meest warschijnlijke worp te vinden,
// al staat dit niet in de beschrijving van de opdracht. Hieronder een functie die opgeroepen kan worden om
// de meest waarschijnlijke worp (aantal ogen) na te gaan.
int Dice::frequencyMax()
{
	return  nDice + distance(frequency.begin(), max_element(frequency.begin(), frequency.end()));
}