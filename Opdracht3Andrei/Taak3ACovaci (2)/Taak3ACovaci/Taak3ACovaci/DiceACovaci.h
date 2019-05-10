#pragma once


#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Dice {
public:

	Dice(int Ndice, int Nfaces);
	~Dice();

	int setDice(int) const;
	int setFaces(int) const;
	void setThrow(int&);
	void Throw(int);		
	vector <int> getDistribution(string);
	vector <float> getFrequency(string);
	void setDistribution(vector <int>);
	void Reset();
	   
private:
	const int Ndice;
	const int Nfaces;
	int Nthrows;
	vector<float> Frequency;
	vector<int> Distribution;
	const int SizeVect;
};
