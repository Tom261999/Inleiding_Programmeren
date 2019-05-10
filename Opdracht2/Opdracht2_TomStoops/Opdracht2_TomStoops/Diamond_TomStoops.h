/*
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Inlevering op: 10-03-2019
 */

#pragma once
#include <string>

class Diamond
{
public:
	Diamond(int); // constructor
	~Diamond(); // destructor

	void setSide(int);

	// Eigenschapsfuncties
	int getSide();
	int getSurface();
	int getCircumference();

	// Gemeenschappelijke functie voor de grafische functies
	std::string diamondString();

	// Declare grafische functies (tekeken & wegschrijven naar bestand)
	void drawScreen();
	void drawFile(std::string);

private:
	int diamondSide;

};

