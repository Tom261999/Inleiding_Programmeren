#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

double root2(double S, double x0, double epsilon)
{
	if ((S < 0) || (x0 <= 0) || (epsilon <= 0))
	{
		cout << "Invalid input: some or all values are negative." << endl;
		return 0;
	}
	double xa = 0;
	double xb = x0;
	do
	{
		xa = xb;
		xb = 0.5*(xa + S / xa);
	} while (abs(xb - xa) > epsilon);
	return xb;
}

double root2alt(double S, double x0, double epsilon)
{
	int iter = 1;
	double xa = 0;
	double xb = x0;
	cout << "startwaarde: " << x0 << endl;
	cout << "iteratie - output" << endl;
	do
	{
		xa = xb;
		xb = 0.5*(xa + S / xa);
		cout << iter << " , " << xb << " ; " << endl;
		iter++;
	} while (abs(xb - xa) > epsilon);
	cout << "(Opmerking: deze data is zo geformatteerd opdat deze makkelijk in MatLab ingelezen kon worden met de structuur van een matrix.)" << endl;
	return xb;
}

double rootn(double S, double x0, double epsilon, int n)
{
	if ((((S < 0) || (x0 <= 0)) && (n % 2 == 0)) || (epsilon <= 0) || (n <= 0) || (x0 == 0))
	{
		cout << "Invalid input: one (or more) of the entered values cannot be negative." << endl;
		return 0;
	}

	double xa = 0;
	double xb = x0;
	do
	{
		xa = xb;
		xb = xa - (pow(xa, n) - S) / (n*pow(xa, n - 1));
	} while (abs(xb - xa) > epsilon);
	return xb;
}