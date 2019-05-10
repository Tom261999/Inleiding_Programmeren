/* Tom Stoops, 2BFYS, s0173659 */

#include "pch.h"
#include "Opdracht2_TomStoops_Header.h"
#include <iostream>
#include <string>

//using namespace std;

int main()
{
	DiamondClass Diamond(7);
	Diamond.getSide();
	Diamond.getSurface();
	Diamond.getCircumferences()
	std::cout << "Waarde voor de zijde kan niet negatief zijn! \n Minteken verwijderd, we gebruiken de absolute waarde." << std::endl;

}