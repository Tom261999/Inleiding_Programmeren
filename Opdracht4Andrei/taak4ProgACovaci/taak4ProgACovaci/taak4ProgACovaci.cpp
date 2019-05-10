// Andrei Coavci, 2BaFys
// andrei.covaci@student.uantwerpen.be
// in te leveren tegen 12/04/2019

#include "pch.h"
#include <iostream>
#include "BarACovaci.h"

int main()
{
	// we gebruiken voor elke opdracht telkens de volgende tijden::
	// t =1s 10s 25s 60s 1000s 10000s

	// de laatste inputvariabele bij de heat functie bepaald de rand-en beging voorwaarden van het probleem zijnde:
	// als 1 wordt ingevuld dan zijn het de voorwaarden voor taak 1 en 2 
	// als 2 wordt ingevuld dan zijn het de voorwaarden voor taak 3
	// een ander getal zal ervoor zorgen dat het programma stopt met werken

	// oplossingen voor taak 1
	Bar Bartaak1(1.0, 450, 7874, 80.4);

	cout << " op t= 1s " << endl;
	Bartaak1.Heat(0.01, 1.0, 1.0, "taak1 ", 1);

	cout << " op t= 10s " << endl;
	Bartaak1.Heat(0.01, 1.0, 10.0, "taak1 ", 1);

	cout << " op t= 25s " << endl;
	Bartaak1.Heat(0.01, 1.0, 25.0, "taak1 ", 1);

	cout << " op t= 60s " << endl;
	Bartaak1.Heat(0.01, 1.0, 60.0, "taak1 ", 1);

	cout << " op t= 1000s " << endl;
	Bartaak1.Heat(0.01, 1.0, 1000.0, "taak1 ", 1);

	cout << " op t= 10000s " << endl;
	Bartaak1.Heat(0.01, 1.0, 10000.0, "taak1 ", 1);





	// oplossingen voor taak 2

	cout << "oplossingen voor taak 2" << endl;
	cout << "\n" << endl;
	Bar Bartaak2(1.0, 450, 7874, 80.4);

	cout << " op t= 1s " << endl;
	Bartaak1.Heat(0.005, 1.0, 1.0, "taak2 ", 1);

	cout << " op t= 10s " << endl;
	Bartaak1.Heat(0.005, 1.0, 10.0, "taak2 ", 1);

	cout << " op t= 25s " << endl;
	Bartaak1.Heat(0.005, 1.0, 25.0, "taak2 ", 1);

	cout << " op t= 60s " << endl;
	Bartaak1.Heat(0.005, 1.0, 60.0, "taak2 ", 1);

	cout << " op t= 1000s " << endl;
	Bartaak1.Heat(0.005, 1.0, 1000.0, "taak2 ", 1);

	cout << " op t= 10000s " << endl;
	Bartaak1.Heat(0.005, 1.0, 10000.0, "taak2 ", 1);






	// oplossingen voor taak 3

	cout << "oplossingen voor taak 3" << endl;
	cout << "\n" << endl;
	Bar Bartaak3(1.0, 450, 7874, 80.4);

	cout << " op t= 1s " << endl;
	Bartaak3.Heat(0.01, 1.0, 1.0, "taak3 ", 2);

	cout << " op t= 10s " << endl;
	Bartaak3.Heat(0.01, 1.0, 10.0, "taak3 ", 2);

	cout << " op t= 25s " << endl;
	Bartaak1.Heat(0.01, 1.0, 25.0, "taak3 ", 2);

	cout << " op t= 60s " << endl;
	Bartaak1.Heat(0.01, 1.0, 60.0, "taak3 ", 2);

	cout << " op t= 1000s " << endl;
	Bartaak1.Heat(0.01, 1.0, 1000.0, "taak3 ", 2);

	cout << " op t= 10000s " << endl;
	Bartaak1.Heat(0.01, 1.0, 10000.0, "taak3 ", 2);





	return 0;
}

