
#include "pch.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include "DiceACovaci.h"
using namespace std;

int main()
{
	int numberofDice1 = 2;
	int numberofFaces1 = 6;
	int aantalWorpen1 = 1000;
	Dice set1(numberofDice1, numberofFaces1);
	set1.Throw(aantalWorpen1);
	vector <int> distributie1 = set1.getDistribution("2_maal_6_zijden_distr");
	vector <float> frequentie1 = set1.getFrequency("2_maal_6_zijden_freq");

	int numberofDice2 = 7;
	int numberofFaces2 = 12;
	Dice set2(numberofDice2, numberofFaces2);
	set2.Throw(aantalWorpen1);
	vector <int> distributie2 = set2.getDistribution("7_maal_12_zijden_distr");
	vector <float> frequentie2 = set2.getFrequency("7_maal_12_zijden_freq");

/*
	int numberofDice3 = 2;
	int numberofFaces3 = 4;
	int previousThrow = 10;
	vector <int> previousdistr{ 1,0,2,3,0,0,4 };
	Dice set3(numberofDice3, numberofFaces3);
	set3.setThrow(previousThrow);
	set3.setDistribution( previousdistr ) ;
	set3.Reset();
		
	set3.Throw(aantalWorpen1);
	vector <int> distributie = set2.getDistribution("2_maal_4_zijden_distr");
	vector <float> frequentie = set2.getFrequency("2_maal_4_zijden_freq");
	*/
	return 0;
}

