/* Tom Stoops, 2BFYS, s0173659 */

#include "pch.h"
#include <iostream>

using namespace std;

// root2 gebruikt het Babylonische algoritme
double root2(double S, double x0, double epsilon) {
	// check validity of input
	if ((S < 0) || (x0 <= 0) || (epsilon <= 0)) {
		cout << "Invalid input: some or all values are negative." << endl;
		return nan(""); // returns NaN for invalid input
	}

	// initial conditions
	double xa = 0;
	double xb = x0;

	// main loop, "do while" will loop at least once, then continue until the tolerance is reached
	do {
		xa = xb;
		xb = 0.5*(xa + S / xa);
	} while (abs(xb - xa) > epsilon);
	return xb;
}

// root2alt is volledig analoog aan root2, maar print ook de tussenstappen in de console
double root2alt(double S, double x0, double epsilon) { // Geen input controle hier toegevoegd omdat dit alleen gebruikt zal worden voor sqrt(100)
	// initial conditions
	int iter = 1;
	double xa = 0; 
	double xb = x0;
	cout << "startwaarde: " << x0 << endl;
	cout << "iteratie - output" << endl;

	// main loop, "do while" will loop at least once, then continue until the tolerance is reached
	do { 
		xa = xb;
		xb = 0.5*(xa + S / xa);
		cout << iter << " , " << xb << " ; " << endl; // purely for easy copy-paste for the plots in MatLab
		iter++;
	} while (abs(xb - xa) > epsilon);

	cout << "(Opmerking: deze data is zo geformatteerd opdat deze makkelijk in MatLab ingelezen kon worden met de structuur van een matrix.)" << endl;
	return xb;
}

// rootn gebruikt de methode van Newton
double rootn(double S, double x0, double epsilon, int n) {
	// check validity of input
	if ((((S < 0) || (x0 < 0)) && (n % 2 == 0)) || (epsilon <= 0) || (n <= 0) || (x0 == 0)) { // merk op, hier kan negatieve x0 als we een oneven macht nemen anders niet!
		cout << "Invalid input: one (or more) of the entered values cannot be negative." << endl;
		return nan(""); // returns NaN for invalid input
	}
	
	// initial conditions
	double xa = 0;
	double xb = x0;

	// main loop, "do while" will loop at least once, then continue until the tolerance is reached
	do {
		xa = xb;
		xb = xa - (pow(xa, n) - S) / (n*pow(xa, n - 1));
	} while (abs(xb - xa) > epsilon);
	return xb;
}