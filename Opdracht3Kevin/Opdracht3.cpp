// Opdracht3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Dice.h"

int main()
{
	Dice MyDice(6, 3);
	MyDice.Throw(100);
	vector<int> D = MyDice.GetDist();
	MyDice.PrintDist();
	/*MyDice.SetDist({ 10,10,10,10,10,10 });
	MyDice.PrintDist();
	MyDice.SetNThrows(60);*/
	vector<float> Freq = MyDice.GetFrequency();
	MyDice.Reset();
	MyDice.PrintDist();
}
