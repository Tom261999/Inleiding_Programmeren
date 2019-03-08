/* Tom Stoops, 2BFYS, s0173659 */

#include "pch.h"
#include "Diamond_TomStoops.h"
#include <iostream>
#include <string>
#include <fstream>


Diamond::Diamond(int n)
{
	std::cout << " Constructor aangeroepen. \n (Opmerking: We nemen de aftsand tussen de sterren als eenheid voor lengte; \n als input voor de constructor wordt er echter het aantal sterren aan 1 kant genomen.)" << std::endl;
	if (n < 0) {
		std::cout << " Waarde voor de zijde kan niet negatief zijn! \n Minteken verwijderd, we gebruiken de absolute waarde." << std::endl;
		diamondSide = abs(n);
}
	else if (n >= 1) {
		diamondSide = n;
	}
	else {
		std::cout << " Error: Onverwachte waarde! Probeer opnieuw met een andere waarde voor de zijde." << std::endl;
		diamondSide = 0; // Stel de diamantzijde is 0; want NaN kan niet toegewezen worden aan een integer-type.
	}
}

Diamond::~Diamond()
{
	std::cout << " Destructor aangeroepen." << std::endl;
}

void Diamond::setSide(int n) {
	diamondSide = n;
};

int Diamond::getSide() {
	std::cout << " De zijde van de diamant is: " << diamondSide << std::endl;
	return diamondSide;
}

int Diamond::getSurface() {
	int surface = (diamondSide-1) * (diamondSide-1);
	std::cout << " De oppervlakte van de diamant is: " << surface << std::endl;
	return surface;
};

int Diamond::getCircumference() {
	int circumference = 4 * (diamondSide-1);
	std::cout << " De omtrek van de diamant is: " << circumference << std::endl;
	return circumference;
};

std::string Diamond::diamondString() {

	std::string a;

	for (int i = diamondSide; i > 1; i--)
	{
		for (int k = 1; k <= 2 * diamondSide - 1; k++)
		{
			if (k == i || k == 2 * diamondSide - i)
			{
				a += "* ";
			}
			else
			{
				a += "  ";
			}

		}
		a += "\n";

	}

	std::string b;

	for (int i = 1; i <= diamondSide; i++)
	{
		for (int k = 1; k <= 2 * diamondSide - 1; k++)
		{
			if (k == i || k == 2 * diamondSide - i)
			{
				b += "* ";
			}
			else
			{
				b += "  ";
			}
		}
		b += "\n";
	}

	std::string c = a + b;

	return c;
};

void Diamond::drawScreen() {
	std::cout << diamondString() << std::endl;
};


void Diamond::drawFile(std::string name) {

	name += ".txt";
	std::ofstream outputBestand(name, std::ios::out);

	if (!outputBestand) {
		std::cout << "Error: bestand niet gevonden." << std::endl;
	}

	outputBestand << diamondString() << std::endl;
};