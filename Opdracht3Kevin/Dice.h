#pragma once
#include <vector>

using namespace std;

class Dice
{
public:
	Dice(int F, int N);
	~Dice();
	void Throw(int n);
	void PrintDist() const;
	void SetDist(vector<int> Dist);
	vector<int> GetDist() const;
	void SetNThrows(int Throws);
	vector<float> GetFrequency()const;
	void Reset();

private:
	int CheckN(int N);
	int CheckF(int F);
	const int Ndice;
	const int Nfaces;
	vector<int> Distribution;
	int Nthrows;
	int CheckNThrows(int Throws);

};