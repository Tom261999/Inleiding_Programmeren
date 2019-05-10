/* Tom Stoops, 2BFYS, s0173659 */

#pragma once

//using namespace std;

class DiamondClass {
public:
	Diamond(int); // constructor
	~Diamond(); // destructor

	void setSide(int);
	int getSide();
	int getSurface();
	int getCircumferences();
//	void DrawScreen();
//	void DrawFile(string);
	
private:
	int diamondSide;

};