/*
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 24-03-2019
 */

#include "pch.h"
#include "Dice_TomStoops.h"
#include <iostream>


int main() {
	/*
	Dice test(2, 2);
	test.Throw(10);
	test.displayDistribution();
	std::vector<int> temp = { 1,-1,1,1 };
	test.setDistribution(temp);
	*/


	{  // Opdracht 1
		std::cout << "-- Opdracht 1: 2 Hexaeders --" << std::endl;
		Dice Hexa2(2, 6);
		Hexa2.Throw(1000000);
		Hexa2.displayNThrows();
		Hexa2.displayDistribution();
		Hexa2.displayFrequency();
	}
	std::cout << "\n" << std::endl; // Gewoon wat extra lege ruimte tussen de blokken.

	{ // Opdracht 2
		std::cout << "-- Opdracht 2: 7 Dodecaeders --" << std::endl;
		Dice Dodeca7(7, 12);
		Dodeca7.Throw(1000000);
		Dodeca7.displayNThrows();
		Dodeca7.displayDistribution();
		Dodeca7.displayFrequency();
	}
	std::cout << "\n" << std::endl;

	{ // Extra Demonstratie
		std::cout << "-- Extra Demonstratie -- " << std::endl; // De code is geschreven dus waarom niet gebruiken?
		Dice demo(3, 5); // Niet platonische lichamen
		demo.Throw(150);
		demo.displayNThrows();
		demo.displayDistribution();
		demo.displayFrequency();
		std::cout << "\n" << std::endl;

		std::cout << "We passen de distributie aan met een compatibele vector:" << std::endl;
		demo.setDistribution(std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
		demo.displayNThrows();
		demo.displayDistribution();
		demo.displayFrequency();
		std::cout << "\n" << std::endl;

		std::cout << "We passen de distributie aan met een compatibele vector maar met negatieve waarden:" << std::endl;
		demo.setDistribution(std::vector<int> {1, -2, 3, 4, 5, -6, 7, 8, 9, 10, 11, -12, 13, -14, 15});
		std::cout << "\n" << std::endl;
		
		
		/* // Uitvoeren van dit stuk van de demo kan, maar zal 'exit(1)' aanroepen en dus het vervolg van de 'main()' niet meer uitvoeren.
		std::cout << "We passen de distributie aan met een incompatibele vector:" << std::endl;
		demo.setDistribution(std::vector<int> {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}); // Werkt (logischerwijze) niet
		*/
	}

	
	return 0;
}