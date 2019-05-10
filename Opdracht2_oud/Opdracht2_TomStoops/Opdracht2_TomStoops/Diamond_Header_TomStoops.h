/* Tom Stoops, 2BFYS, s0173659 */

#pragma once
#include <string>
#include "Diamond_Header_TomStoops.cpp"

class Diamond {
public:
	Diamond(int); // constructor
	~Diamond(); // destructor

	void setSide(int);
	int getSide();
	int getSurface();
	int getCircumferences();
	void DrawScreen();
	void DrawFile(string);

private:
	int diamondSide;
/*	string Drawstring();
	string DrawRow(int);
*/ // Artefact van Bert
};