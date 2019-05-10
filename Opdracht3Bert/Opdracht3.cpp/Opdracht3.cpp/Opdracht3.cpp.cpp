/*	Opdracht1: Dice.h
	Bert Jorissen (s0150821)
	bert.jorissen@student.uantwerpen.be
	datum inlevering: vrijdag 24 maart 2017

	Main-programma voor het testen van class Dice*/

#include "pch.h"
#include <iostream>
#include "Dice.h"
#include <string>

// Voorbeeldprogramma uit de slide's om een vector te 'printen'
void outputvector(const vector<int> & outvec)
{
	int printcount = 0;
	for (vector<int>::const_iterator iter = outvec.begin();
		iter != outvec.end(); ++iter)
	{
		printcount++;
		cout << *iter << endl;
	}
	cout << endl;
}

// In het programma wordt gevraagd om integegers in te geven om een 'Dice' te geven met opgegeven aantal zijden
// en stenen. Hierna wordt gevraagd hoeveel maal er gegooid moet worden, waarna de resultaten 'uitgeprint' worden
// in de terminal en gevraagd wordt of de resultaten weggeschreven moeten worden in een '.csv' bestand, zodat
// de resultaten makkelijk geanalyseerd kunnen worden. Dit wordt voor een tweede bobbelsteen herhaald, waarna in
// De tweede dobbelsteen de 'frequency' vector van de eerste vector ingevoerd wordt en er gevraagd wordt naar het
// aantal zijden en stenen van deze dobbel. Hierna is er een mogelijkheid om het programma te herhalen.
int main()
{
	string fileName = "lijst.csv";
	int zijden;
	int stenen;
	int herhaal;
	int tel;
	cout << "Eerste dobbel: geef aantal zijden op" << endl;
	cin >> zijden;
	cout << "Eerste dobbel: geef aantal stenen op" << endl;
	cin >> stenen;
	cout << "Eerste dobbel: Maak een 'Dice' met " << zijden << " zijden en " << stenen << " stenen." << endl;
	Dice dobbel1(zijden, stenen);
	cout << "Hoeveel herhalingen wilt u?" << endl;
	cin >> herhaal;
	for (int i = 0; i < herhaal; i++) dobbel1.Throw();
	outputvector(dobbel1.getFrequency());
	vector<int> freq1 = dobbel1.getFrequency();
	cout << "Meest waarschijnlijke worp: " << dobbel1.frequencyMax() << endl;
	tel = 0;
	cout << "Drukt op 0 om weg te schrijven." << endl;
	cin >> tel;
	if (tel == 0) dobbel1.csvWrite(fileName);


	cout << "Tweede dobbel: geef aantal zijden op" << endl;
	cin >> zijden;
	cout << "Tweede dobbel: geef aantal stenen op" << endl;
	cin >> stenen;
	cout << "Tweede dobbel: Maak een 'Dice' met " << zijden << " zijden en " << stenen << " stenen." << endl;
	Dice dobbel2(zijden, stenen);
	cout << "Hoeveel herhalingen wilt u?" << endl;
	cin >> herhaal;
	for (int i = 0; i < herhaal; i++) dobbel2.Throw();
	outputvector(dobbel2.getFrequency());
	cout << "Meest waarschijnlijke worp: " << dobbel2.frequencyMax() << endl;

	cout << "Drukt op 0 om weg te schrijven." << endl;
	cin >> tel;
	if (tel == 0) dobbel2.csvWrite(fileName);

	cout << "(invoer van vector frequency van eerste dobbel in tweede dobbel) \n Derde dobbel: geef aantal zijden op" << endl;
	cin >> zijden;
	cout << "Derde dobbel: geef aantal stenen op" << endl;
	cin >> stenen;
	dobbel2.setFrequency(freq1,zijden,stenen);
	outputvector(dobbel2.getFrequency());
	cout << "Meest waarschijnlijke worp: " << dobbel2.frequencyMax() << endl;

	cout << "Drukt op 0 om te stoppen." << endl;
	cin >> tel;
	if (tel > 0) main();
	return 0;
}