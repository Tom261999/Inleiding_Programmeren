/*
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 08-04-2019
 */

#include "pch.h"
#include "Bar_TomStoops.h"

int main() {
	// We zullen de 'Heat' functie aanroepen voor meerdere tijdstippen (in seconden): { 10, 20, 30, 60, 600, 10 000 } opdat we duidelijk de diffusie van de temperatuur zullen waarnemen in de data (en bijhorende verwerking).

	{	// Taak 1
		std::cout << "-- Taak 1 --" << std::endl;
		Bar taak1(100, 80.4 / 100, 7.874, 0.45); // 80.4/100 wegens eenheden

		std::cout << "Voor t = 10s" << std::endl;
		taak1.Heat(10, 1, 1, 0, 100, "Taak 1");

		std::cout << "Voor t = 20s" << std::endl;
		taak1.Heat(20, 1, 1, 0, 100, "Taak 1");

		std::cout << "Voor t = 30s" << std::endl;
		taak1.Heat(30, 1, 1, 0, 100, "Taak 1");

		std::cout << "Voor t = 60s" << std::endl;
		taak1.Heat(60, 1, 1, 0, 100, "Taak 1");

		std::cout << "Voor t = 600s" << std::endl;
		taak1.Heat(600, 1, 1, 0, 100, "Taak 1");

		std::cout << "Voor t = 10 000s" << std::endl;
		taak1.Heat(10000, 1, 1, 0, 100, "Taak 1");
	}
	{	// Taak 2
		std::cout << "\n\n-- Taak 2 --" << std::endl;
		Bar taak2(100, 80.4 / 100, 7.874, 0.45);

		std::cout << "Voor t = 10s" << std::endl;
		taak2.Heat(10, 0.5, 0.75, 0, 100, "Taak 2");

		std::cout << "Voor t = 20s" << std::endl;
		taak2.Heat(20, 0.5, 0.75, 0, 100, "Taak 2");

		std::cout << "Voor t = 30s" << std::endl;
		taak2.Heat(30, 0.5, 0.75, 0, 100, "Taak 2");

		std::cout << "Voor t = 60s" << std::endl;
		taak2.Heat(60, 0.5, 0.75, 0, 100, "Taak 2");

		std::cout << "Voor t = 600s" << std::endl;
		taak2.Heat(600, 0.5, 0.75, 0, 100, "Taak 2");

		/* // Deze nemen we niet meer mee omdat voor 't = 600 s' de output al '-nan(ind)' teruggaf.
		std::cout << "Voor t = 10 000s" << std::endl;
		taak2.Heat(10000, 0.5, 0.75, 0, 100);
		*/
	}
	{	// Taak 3
		std::cout << "\n\n-- Taak 3 -- " << std::endl;
		Bar taak3(100, 80.4 / 100, 7.874, 0.45);

		std::cout << "Voor t = 10s" << std::endl;
		taak3.Heat(10, 1, 1, "Taak 3");

		std::cout << "Voor t = 20s" << std::endl;
		taak3.Heat(20, 1, 1, "Taak 3");

		std::cout << "Voor t = 30s" << std::endl;
		taak3.Heat(30, 1, 1, "Taak 3");

		std::cout << "Voor t = 60s" << std::endl;
		taak3.Heat(60, 1, 1, "Taak 3");

		std::cout << "Voor t = 600s" << std::endl;
		taak3.Heat(600, 1, 1, "Taak 3");

		std::cout << "Voor t = 10 000s" << std::endl;
		taak3.Heat(10000, 1, 1, "Taak 3");
	}

	return 0;
}

// Nota: ik gebruik ' { ... } ' rond de taken zelf zodat de output iets overzichtelijker is. Dit is echter niet essentieel voor de werking van het programma.