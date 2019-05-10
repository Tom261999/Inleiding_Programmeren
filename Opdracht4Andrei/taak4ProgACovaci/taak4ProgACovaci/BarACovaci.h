// Andrei Coavci, 2BaFys
// andrei.covaci@student.uantwerpen.be
// in te leveren tegen 12/04/2019
#pragma once

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Bar
{
public:
	Bar(double  Length, double HeatCap, double Density, double DifusionCst);
	~Bar();
	double SetFunc(double) const;
	vector<double> Heat(double dx, double dt, double T, string OutputName, int situatie);
	void OutPutMaker( vector<double> TePrintVect, string name);
private:
	const double Length;
	const double HeatCap;
	const double Density;
	const double DifusionCst;	
};
