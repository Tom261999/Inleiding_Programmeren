/*	Opdracht1: Dice.h
	Bert Jorissen (s0150821)
	bert.jorissen@student.uantwerpen.be
	datum inlevering: vrijdag 24 maart 2017

	Header file voor class Dice*/

#ifndef DICE_H
#define DICE_H

#include <string>
#include <vector>

using namespace std;

class Dice
{
public:
	Dice(int, int);
	~Dice();
	void setNDice(int);
	void setNfaces(int);
	void Throw();
	void Reset();
	void csvWrite(string&);
	vector<int> getFrequency();
	vector<int> setFrequency(vector<int>,int,int);
	int frequencyMax();

private:
	int nDice;
	int nFaces;
	vector<int> frequency;
};

#endif