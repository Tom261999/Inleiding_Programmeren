/* 
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be 
	Inlevering op: 10-03-2019 
 */

#include "pch.h"
#include "Diamond_TomStoops.h"
#include <iostream>
#include <string>
#include <fstream>


Diamond::Diamond(int n) // Constructor
{
	std::cout << " <<Constructor aangeroepen.>> \n (Opmerking: We nemen de aftsand tussen de sterren als eenheid voor lengte; \n als input voor de constructor wordt er echter het aantal sterren aan 1 kant genomen.)" << std::endl;
	setSide(n);
}

Diamond::~Diamond() // Destructor
{
	std::cout << " <<Destructor aangeroepen.>>" << std::endl;
}

void Diamond::setSide(int n) { // 'setSide()' stelt de private variable 'diamondSide' gelijk aan de intput indien deze voldoet aan enkele voorwaarden.
	if (n < 0) { // Als de zijde negatief is, vervangen we het negatief getal door zijn absolute waarde.
		std::cout << " Waarde voor de zijde kan niet negatief zijn! \n Minteken verwijderd, we gebruiken de absolute waarde." << std::endl;
		diamondSide = abs(n);
	}
	else if (n >= 0) { // Als het getal groter of gelijk is aan nul werkt het gewoon door. (Nul wordt later behandeld als errors)
		diamondSide = n;
	}
	else { // Back-up indien de input onverwacht is en het programma zou kunnen breken.
		std::cout << " <Error>: Onverwachte waarde! Probeer opnieuw met een andere waarde voor de zijde." << std::endl;
		diamondSide = 0; // Stel de diamantzijde is 0; want NaN kan niet toegewezen worden aan een integer-type.
	}
};

int Diamond::getSide() { // Leest en returned de private variable 'diamondSide'
	std::cout << " De zijde van de diamant is: " << diamondSide << std::endl;
	return diamondSide;
}

int Diamond::getSurface() { // Gebruikt 'diamondSide' om de oppervlakte te bepalen. De aftsand tussen 2 sterren werd genomen als eenheidslengte.
	int surface;
	if (diamondSide == 0) { // Nulerror
		surface = 0;
		std::cout << " <Error>: Oppervlakte is 0." << std::endl;
	}
	else {
		surface = (diamondSide - 1) * (diamondSide - 1);
		std::cout << " De oppervlakte van de diamant is: " << surface << std::endl;
	}

	return surface;
};

int Diamond::getCircumference() { // Gebruikt 'diamondSide' om de omtrek te bepalen. De aftsand tussen 2 sterren werd genomen als eenheidslengte.
	int circumference;
	if (diamondSide == 0) { // Nulerror
		circumference = 0;
		std::cout << " <Error>: Omtrek is 0." << std::endl;
	}
	else {
		circumference = 4 * (diamondSide - 1);
		std::cout << " De omtrek van de diamant is: " << circumference << std::endl;
	}
	return circumference;
};

std::string Diamond::diamondString() { // De gemeenschappelijke code van 'drawScreen()' en 'drawFile(name)', maakt een string van de diamant zodat deze later eenvoudig verwerkt kan worden.
	std::string stringDiamond;
	int n = 2 * diamondSide - 1; // grid afmeting
	if (diamondSide == 0) { // Nulerror
		stringDiamond = " <Error>: Zijde 0 kan niet getekend worden. \n";
	}
	else {
		for (int i = 1; i <= n; i++) // Dit stuk (samen met volgende for-loop) maakt een grid van n x n, afhankelijk van de plaats in dit grid zullen de if-loops hier een " *" of "  " zetten (zie if-loop).
		{
			for (int j = 1; j <= n; j++) {
				if (j == i + diamondSide - 1 || j == i - diamondSide + 1 || j == diamondSide - i + 1 || j == 3 * diamondSide - i - 1) { // indien voldaan aan deze voorwaarde, zal het punt op het grid een deel uitmaken van de diamant en dus een " *" toegewezen krijgen.
					stringDiamond += " *";
				}
				else { // Indien niet voldaan aan de voorwaarden wordt dit een "  ".
					stringDiamond += "  ";
				}
			}
			stringDiamond += " \n"; // Geeft steeds de 'enter' tussen iedere lijn van sterretjes en spaties
		}
	}
	return stringDiamond;
};


void Diamond::drawScreen() {
	std::cout << diamondString() << std::endl; // Print de string gemaakt door 'diamondString()'
};


void Diamond::drawFile(std::string name) { // Schrijft de string gemaakt door 'diamondString()' weg naar een bestand met de naam "name"

	name += ".txt"; // Zorgt ervoor dat het output bestand een tekstbestand is, ongeacht wat de gebruiker probeert te typen (om currupte data en crashes te voorkomen)
	std::ofstream outputBestand(name, std::ios::out);

	outputBestand << diamondString() << std::endl;

	if (!outputBestand) {
		std::cout << " <Error>: bestand niet gevonden." << std::endl; // Error indien bestand niet gemaakt/gevonden
	}
	else {
		std::cout << " Bestand succesvol geschreven met naam: " << name << std::endl; // Bevestiging aanmaken bestand + herinnering naam voor de gebruiker
	}
}; // Nota: Ik heb dit niet in een apparte header/source gezet zoals het alternatief suggereerde omdat het mij makkelijker leek om iedere keer dit stuk code te kopieren en aan te passen naar de noden van de toepassing (e.g. bestands extensie wijzigen, ...)