/*
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Inlevering op: 10-03-2019
 */

#include "pch.h"
#include <iostream>
#include "Diamond_TomStoops.h"
#include <string>

int main()
{
	// Demonstratie voor normale zijde
	std::cout << " --Eerst een demonstratie van de werking (zijde 6)-- " << std::endl;
	Diamond Diamond(4);
	Diamond.getSide();
	Diamond.getSurface();
	Diamond.getCircumference();
	Diamond.drawScreen();
	Diamond.drawFile("Diamantbestand");

	// Demonstratie voor negatieve zijde
	std::cout << " --Dan voor een negatieve zijde (-5)--" << std::endl;
	Diamond.setSide(-5);
	Diamond.getSide();
	Diamond.getSurface();
	Diamond.getCircumference();
	Diamond.drawScreen();
	Diamond.drawFile("Diamantbestand_negatief");

	// Demonstratie voor nul zijde
	std::cout << " --Dan voor een nul zijde (0)--" << std::endl;
	Diamond.setSide(0);
	Diamond.getSide();
	Diamond.getSurface();
	Diamond.getCircumference();
	Diamond.drawScreen();
	Diamond.drawFile("Diamantbestand_nul");

	/* Laatste opmerking: het is mogelijk nodig om te scrollen in het pop-up venster, de output is namelijk vrij lang.*/
}

