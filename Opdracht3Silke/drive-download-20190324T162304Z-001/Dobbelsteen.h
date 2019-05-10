//Silke Kennis 
// silke.kennis@student.uantwerpen.be
//25 maart 2019 
#pragma once
#include <vector>
using namespace std;
class Dice
{

public:
	Dice(int, int); //constructor 
	~Dice(); //deconstructor 
	void setDistribution(int);
	int setNDices(int);
	int setNFaces(int);
	int setNThrows(int);
	int NThrows(int);
	void Reset();
	void getDistribution();
	vector <double> getFrequentie();
private:
	const int NDice;
	const int NFace;
	vector <int> Distribution; // een container dus het moet een vector zijn. 
	vector <double> Frequentie;
	int aantalstenen;
	int aantalzijden;
	int aantalworpen;
	int size;

};