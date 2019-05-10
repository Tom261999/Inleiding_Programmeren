/* Tom Stoops, 2BFYS, s0173659 */

#include "pch.h"
#include "Opdracht2_TomStoops_Header.h"
#include <iostream>
#include <string>

void DiamondClass::Diamond(int n) {
	std::cout << "Constructor aangeroepen." << std::endl;
	if (n < 0) {
		std::cout << "Waarde voor de zijde kan niet negatief zijn! \n Minteken verwijderd, we gebruiken de absolute waarde." << std::endl;
		int m = abs(n);
		n = m;
	} 
	else if (n == 0) {
		std::cout << "Waarde van de zijde kan niet nul zijn!" << std::endl;
	} 
	else if (n >= 1) {
		diamondSide = n;
	}
	else {
		std::cout << "Error: Onverwachte waarde! Probeer opnieuw met een andere waarde voor de zijde." << std::endl;
	}
};

void DiamondClass::~Diamond() {
	std::cout << "Destructor aangeroepen." << std::endl;
}

void DiamondClass::setSide(int n) {
	diamondSide = n;
};

int DiamondClass::getSide() {
	std::cout << "De zijde van de diamant is: " << diamondSide << std::endl;
	return diamondSide;
}

int DiamondClass::getSurface() {
	int surface = diamondSide * diamondSide;
	std::cout << "De oppervlakte van de diamant is: " << surface << std::endl;
	return surface;
};

int DiamondClass::getCircumferences() {
	int circumference = 4 * diamondSide;
	std::cout << "De omtrek van de diamant is: " << circumference << std::endl;
	return circumference;
};
