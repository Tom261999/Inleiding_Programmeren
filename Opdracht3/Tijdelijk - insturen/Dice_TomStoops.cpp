/*
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 24-03-2019
 */

#include "pch.h"
#include "Dice_TomStoops.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>


// Constructor & Destructor

Dice::Dice(int n,int m) : NDice(setNDice(n)), NFaces(setNFaces(m)) { // n = #dobbelstenen, m = #zijvlakken per dobbelsteen
	std::cout << "<<Dice constructor aangeroepen.>>" << std::endl;
	std::cout << "We hebben " << n << " dobbelstenen, iedere dobbelsteen heeft " << m << " zijden." << std::endl;
	Distribution.resize(NDice * NFaces, 0); // Initialisatie van distributie en frequentie
	Frequency.resize(NDice * NFaces, 0);
	srand(time(0)); // Nodig om de seed van pseudo-random getallen generator te veranderen voor iedere run (anders wordt er eentje gekozen op compilatie en nadien blijft die constant!!)
};

Dice::~Dice() {
	std::cout << "<<Dice destructor aangeroepen.>>" << std::endl;
};


// Essenstiële functies

void Dice::Throw(int t) { // We zullen 't' keer de dobbelstenen rollen --> 'for'-loop
	for (int i = 1; i <= t; i++) { 
		int som = 0;
		for (int j = 1; j <= NDice; j++) { // Genereer pseudo-random getallen zoals voorgeschreven in de opdracht en tel deze bij elkaar op.
			som += (rand() % NFaces) + 1;
		}
		Distribution.at(som - 1)++; // Op de plaats met waarde van de som (-1 omdat C++ telt vanaf 0) 1 bijtellen.
		NThrows++;
	}
	makeFrequency(); // Uit de distributie en aantal worpen ook de frequentie bepalen.
};

void Dice::Reset() { // Voor reset vullen we gewoon alle waarden van de vectoren 'Distribution' en 'Frequency' gewoon in met 0 op iedere positie. Hiervoor kon een loop gebruikt worden maar 'resize' was compacter.
	Distribution.resize(NDice * NFaces, 0);
	Frequency.resize(NDice * NFaces, 0);
	std::cout << "Distributie reset voltooid." << std::endl;
};

void Dice::makeFrequency() { // Gebruik van een pointer opdat we de vector 'Frequency' direct aanpassen i.p.v. een lokale kopie. 
	std::vector<double>* FrequencyPtr = &Frequency;
	for (int i = 0; i < Distribution.size(); i++) {
		FrequencyPtr->at(i) = (double)100.0 * (double)Distribution[i] / (double)NThrows; // De '(double)' moet er bij staan opdat c++ de getallen interpreteert als 'double' en ze dan kan delen om een 'double' te krijgen i.p.v. 'int'.
	}
};


// SET functies

int Dice::setNDice(int n) { // Inputcontrole voor aantal dobbelstenen.
	if (n <= 0) {
		std::cout << "<Error>: Aantal dobbelstenen moet een strikt positief getal zijn." << std::endl;
		exit(1);
	}
	else {
		return n;
	}
};

int Dice::setNFaces(int m) { // Input controle voor aantal zijvlakken.
	if (m <= 0) {
		std::cout << "<Error>: Aantal zijden moet een strikt positief getal zijn." << std::endl;
		exit(1);
	}
	else if (m != 20 && m != 12 && m != 8 && m != 6 && m != 4) { // Controle of het een platonic solid is. Echter is dit niet essentiëel voor het programma dus worden niet-platonische lichamen toegelaten als input (met waarschuwing).
		std::cout << "<Warning>: Ingegeven dobbesteen is geen platonic solid." << std::endl;
		return m;
	}
	else {
		return m;
	}
};

void Dice::setDistribution(std::vector<int> vect) { // Mogelijkheid om zelf een distributie in te stellen (met input controle).
	if (vect.size() != NDice * NFaces) { // Voor foute lengte van vector wordt de input verworpen.
		std::cout << "<Error>: Lengte van de sitributie is incompatibel met de dobbelstenen." << std::endl;
		exit(1);
	}
	else {
		for (int i = 0; i < vect.size(); i++) { // Voor negatieve inputwaarden nemen we de absolute waarde (met waarschuwing).
			if (vect.at(i) < 0) {
				std::cout << "<Warning>: Getal op plaats " << i << " in de distributie is negatief, we vervangen deze door zijn absolute waarde." << std::endl;
				vect.at(i) = abs(vect.at(i));
			}
		}
		Distribution = vect;
		setNThrows(); // Aantal worpen 'NThrows' moet ook geupdated worden voor de nieuwe distributie.
		std::cout << "De distributie is ingesteld als: " << std::endl;
		displayDistribution();
		makeFrequency(); // De vector 'Frequency' moet ook geupdated worden voor de nieuwe distributie.
	}

};

void Dice::setNThrows() { // Telt het aantal worpen gegeven door een (ingegeven) distributie en stelt zo 'NThrows' in.
	int N = 0;
	for (int i = 0; i < Distribution.size(); i++) { // Loop over alle elementen en tel ze op:
		N += Distribution.at(i);
	}
	NThrows = N;
	std::cout << "Het aantal worpen in ingesteld als: " << NThrows << std::endl;
};


// GET functies

int Dice::getNDice() const { // Deze functies kunnen allemaal 'const' gelabeld worden en returnen slechts de private variabelen.
	return NDice;
};

int Dice::getNFaces() const {
	return NFaces;
};

int Dice::getNThrows() const {
	return NThrows;
};

std::vector<int> Dice::getDistribution() const {
	return Distribution;
};

std::vector<double> Dice::getFrequency() const {
	return Frequency;
};


// DISPLAY functies

void Dice::displayNThrows() const { // Deze functies tonen enkel de variabelen op de console en worden als 'const' gelabeld.
	std::cout << "Er werden " << NThrows << " worpen gemaakt." << std::endl;
};

void Dice::displayDistribution() const {
	for (int i = 0; i < Distribution.size(); i++) {
		std::cout << Distribution.at(i) << "  ";
	}
	std::cout << "\n" << std::endl;
};

void Dice::displayFrequency() const {
	for (int i = 0; i < Frequency.size(); i++) {
		std::cout << Frequency.at(i) << "%  ";
	}
	std::cout << "\n" << std::endl;
};