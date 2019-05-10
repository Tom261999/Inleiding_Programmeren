/*
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 08-04-2019
 */

#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

class Bar {
public:
	// Constructor & destructor
	Bar(float L, float K, float rho, float C);
	~Bar();

	// 'Heat' functie met overladen variant
	std::vector<float> Heat(int t,float dx, float dt, std::string outputName);							// Neumann randvoorwaarden
	std::vector<float> Heat(int t,float dx, float dt, float LB, float RB, std::string outputName);		// Dirichlet randvoorwaarden

private:
	// Constante (gegeven) variabelen
	const float L;
	const float K;
	const float rho;
	const float C;

	// Overige nodige functies, enkel aan te roepen door functies van deze klasse
	float set(float) const;
	float checkHeat(float);
	void displayVector(std::vector<float>) const;
	void writeOutput(std::string,std::vector<float>) const;
};