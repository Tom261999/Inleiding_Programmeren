/* Tom Stoops, 2BFYS, s0173659 */

#pragma once
#include <string>

class Diamond
{
public:
	Diamond(int); // constructor
	~Diamond(); // destructor

	void setSide(int);

	int getSide();
	int getSurface();
	int getCircumference();

	std::string diamondString();

	void drawScreen();
	void drawFile(std::string);

private:
	int diamondSide;

};

