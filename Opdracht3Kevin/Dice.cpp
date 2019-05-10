#include "pch.h"
#include "Dice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Dice::Dice(int F, int N) : Ndice(CheckN(N)), Nfaces(CheckF(F))
{
		cout << "constructor dice" << endl;
		cout << Ndice << " " << Nfaces << "-zijdige dobbelstenen" << endl;
		vector<int> vector(N*F, 0);
		Distribution= vector;
		srand(time(NULL));
}

Dice::~Dice()
{
	cout << "Deconstructor dice" << endl;
}

int Dice::CheckF(int F)
{
	if (F <= 0)
	{
		cerr << "Het aantal zijden mag niet negatief zijn." << endl;
		exit(1);
	}
	if (F == 4 || F == 6 || F == 8 || F == 12 || F == 20)
	{
		return F;
	}
	else
	{
		cerr << "Enkel platonische lichamen mogen gekozen worden." << endl;
		exit(1);
	}
}

int Dice::CheckN(int N)
{
	if (N <= 0)
	{
		cerr << "Het aantal dobbelstenen mag niet negatief zijn." << endl;
		exit(1);
	}
	else
	{
		return N;
	}
}

void Dice::Throw(int n)
{
	for (int j = 1; j <= n; j++)
	{
		int totaal = 0;
		for (int i = 1; i <= Ndice; i++)
		{
			int worp = (rand() % Nfaces) + 1;
			totaal = totaal + worp;
		}
		Distribution.at(totaal - 1)++;
		Nthrows++;
	}
}

void Dice::PrintDist()const
{
	cout << "Distributie waarden: " << endl;
	for (int a : Distribution)
	{
		cout << a << endl;
	}
}

vector<int> Dice::GetDist() const
{
	return Distribution;
}

void Dice::SetDist(vector<int> Dist)
{
	if (Dist.size() != Nfaces * Ndice)
	{
		cerr << "De dataset heeft de verkeerde lengte!" << endl;
		exit(1);
	}
	else
	{
		for (int b : Dist)
		{
			if (b < 0)
			{
				cerr << "De distributie mag geen negatieve waarden bevatten!" << endl;
				exit(1);
			}
		}
		Distribution = Dist;
	}
}

int Dice::CheckNThrows(int NThrow)
{
	if (NThrow < 0)
	{
		cerr << "Het aantal worpen mag niet negatief zijn!" << endl;
		exit(1);
	}
	int Nth = 0;
	for (int c : Distribution)
	{
		Nth = Nth + c;
	}
	if (Nth == NThrow)
	{
		return NThrow;
	}
	else
	{
		cerr << "Het aantal worpen komt niet overeen met de opgegeven dataset!" << endl;
		exit(1);
	}
}

void Dice::SetNThrows(int Throws)
{
	Nthrows = CheckNThrows(Throws);
	cout << "Het aantal worpen is op " << Nthrows << " gezet." << endl;
}

vector<float> Dice::GetFrequency() const
{
	int Nthrow = Nthrows;
	vector<float> Freq(Ndice*Nfaces,0);
	for (int i = 0; i < Distribution.size();i++ )
	{
		Freq.at(i) = (float)Distribution.at(i) / (float)Nthrow;
	}

		cout << "FrequentieDistributie " << endl;
		for (float a : Freq)
		{
			cout << a << endl;
		}
	return Freq;
}

void Dice::Reset()
{
	vector<int> vector(Nfaces*Ndice, 0);
	Distribution = vector;
}