/*
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 24-03-2019
 */

#pragma once
#include <vector>

class Dice {
public:

	// Constructor & Destructor
	Dice(int, int);
	~Dice();

	// Essentiële functies
	void Throw(int);
	void Reset();
	void makeFrequency();

	// SET functies
	void setDistribution(std::vector<int>);

	// GET functies
	int getNDice() const;
	int getNFaces() const;
	int getNThrows() const;
	std::vector<int> getDistribution() const;
	std::vector<double> getFrequency() const;

	// DISPLAY functies
	void displayNThrows() const;
	void displayDistribution() const;
	void displayFrequency() const;

private:
	const int NDice;
	const int NFaces;
	int NThrows;
	std::vector<int> Distribution;
	std::vector<double> Frequency;

	// Private SET functies
	int setNDice(int);
	int setNFaces(int);
	void setNThrows(); // Private zodat dit enkel aangeroepen wordt door setDistribution, het aantal worpen wordt hier bepaald door de som van de elementen van Distribution. Als een gebruiker dit aan zou kunnen roepen zou dit serieuze gevolgen kunnen hebben voor de gegenereerde frequenties.

};