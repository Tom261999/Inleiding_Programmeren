//Silke Kennis 
// silke.kennis@student.uantwerpen.be
//11 maart 2019 

#include "pch.h"
#include "Dobbelsteen.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int dobbelstenen = 2;
	int zijden = 12;
	int worpen = 4;
	Dice mydobbelsteen(dobbelstenen, zijden);
	cout << "De vector bestaat uit: " << endl;
	mydobbelsteen.NThrows(worpen);
	mydobbelsteen.getDistribution();
	
	return 0;
}