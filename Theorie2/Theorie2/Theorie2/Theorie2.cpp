#include "pch.h"
#include <iostream>
#include "AccessByPointer.h"

#include <vector>

using namespace std;

int main()
{
	int x;
	x = 5;
	
	// Adres-van operator (&)
	cout << "waarde van x is " << x << endl;
	cout << "adres van x is " << &x << endl;

	// && bitsgewijze en-operator

	// Dereference-operator (*)
	cout << "de waarde op het adres van x is " << *&x << endl;

	// Alternatief is * ook gewoon een vermenigvuldiging (dan heeft * 2 argumenten (links en rechts))


	// Pointers
	int *Ptr; // Declaratie v/e pointer, int want pointer wijst naar een integer, Ptr is de naam van de pointer
	int* Ptr2;
	int * Ptr3; // locatie van * is niet zo belangrijk
	// kan natuurlijk ook naar andere types wijzen, niet enkel int (duh-uh)

	double* b;

	// Initialisatie van pointer
	Ptr = &x;

	// Samengevat
	int y = 6;
	int* PtrY = &y;

	cout << "y heeft een waarde van " << y << " en een adres " << &y << endl;
	cout << "PtrY wijst naar adres " << PtrY << endl;
	cout << "waar de waarde " << *PtrY << " is opgeslagen." << endl;

	// FOUT int *PtrToY = 5;
	cout << "We passen mbv een pointer de waarde van y aan:" << endl;

	*PtrY = 8;
	cout << "y heeft een waarde van " << y << " en een adres " << &y << endl;
	cout << "PtrY wijst naar adres " << PtrY << endl;
	cout << "waar de waarde " << *PtrY << " is opgeslagen." << endl;


	// Gebruik van pointers
	// (1) Pointer als functieparameter
	int d = 9;
	AccessByPtr(&d);
	cout << "de waarde van d is " << d << endl;
	AccessByPtr(&d);
	cout << "de waarde van d is " << d << endl;
	AccessByPtr(&d);
	cout << "de waarde van d is " << d << endl;
	AccessByPtr(&d);
	cout << "de waarde van d is " << d << endl;

	// (2) Dynamisch geheugengebruik
	int* dynInt = new int;
	*dynInt = 7;

	// of in 1 keer:

	double* dynDouble = new double(8.5);

	cout << "pointer zijn adres is " <<  dynInt << " en waarde " << *dynInt << endl;

	/*

	Opmerking:

	int k = 3;
	int l(3); // deze methode doet eigelijk hetzelfde, maar gebruikt de constructor om l te maken

	*/

	// VOOR IEDERE NEW MOET ER OOK EEN DELETE GEIPLEMENTEERD ZIJN!!!!

	delete dynInt;
	delete dynDouble;
	// Opmerking: de adresseb zijn verwijderd, maar de pointers bestaan nog!

	/*
	cout << "dan eens een testje:" << endl;
	cout << "de pointer zijn adres is nu (na delete) " << dynInt << "en de waarde is " << *dynInt << endl;
	*/

	// Dan kunnen we die pointers recyclen door ze opnieuw toe te wijzen
	dynDouble = new double(9.8);

	cout << dynDouble << endl;

	// Pointer naar een vector

	vector<int> MyVec = { 1,2,3 };
	vector<int>* MyVectorPtr = &MyVec;

	cout << "de lengte van mijn vector is " << MyVec.size() << endl;
	cout << "de lengte van mijn vector is " << MyVectorPtr->size() << endl;

	// vector<int>* MyVecPtr = new vector<int>(5,0);

	// EINDE POINTERS

	//---------------------------------------------------------------------------------------

	// REFERENCES

	int h = 9;

	int& refH = h; // opm, voor references moet je initialiseren en declareren op zelfde moment!

	cout << "waarde van h is " << h << " en van refH " << refH << endl;
	cout << "adres van h is " << &h << " en van refH " << &refH << endl;

	refH += 7;
	cout << "waarde van h is " << h << " en van refH " << refH << endl;
	cout << "adres van h is " << &h << " en van refH " << &refH << endl;

	h /= 2;
	cout << "waarde van h is " << h << " en van refH " << refH << endl;
	cout << "adres van h is " << &h << " en van refH " << &refH << endl;

	// parameter voor functie

	int t = 26;
	cout << "de waarde van t is " << t << endl;
	AccessByRef(t);
	cout << "de waarde van t is " << t << endl; // Als we neit met reference hadden gewerkt, had a alleen binnen de scope van de functie bestaan en zou t niet aangepast zijn!!

}
