// Practicum2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	// ofstream MyOutput("test.txt", ios::out); // of ios:app
	
	string myName = "test";
	myName += "tje";
	int n = 5; // zo kunnen we de naam dynamisch veranderen
	myName += to_string(n);
	myName += ".txt";

	ofstream MyOutput(myName, ios::out);

	if (!MyOutput) { // the fuck doet dit?
		cerr << "file not found" << endl;
		exit(1);
	}

	MyOutput << "Waar gaat het licht heen wanneer je 's avonds het licht uit doet?" << endl; // gewoon een test string om naar file te schrijven

	MyOutput.close();


	// Nu voegen we nog wat toe:

	MyOutput.open(myName, ios::app);

	MyOutput << "Kijk dan maar eens in de koelkast!" << endl;

	MyOutput << 5 << setw(10) << 6 << setw(10) << 7 << setw(10) << endl;


	// CSV files
	ofstream MyCsvOutput("csvfile.csv", ios::out);
	MyCsvOutput << 10 << "," << 15 << "," << 20 << endl;
	MyCsvOutput << 11 << "," << 16 << "," << 21 << endl;

	MyCsvOutput.close();

	ifstream MyInput("csvfile.csv");

	return 0;
}