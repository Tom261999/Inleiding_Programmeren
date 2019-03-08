/* Tom Stoops, 2BFYS, s0173659 */

#include "pch.h"
#include <iostream>
#include "Diamond_TomStoops.h"
#include <string>

int main()
{
	Diamond Diamond(3);

	Diamond.getSide();

	Diamond.getSurface();

	Diamond.getCircumference();

	Diamond.drawScreen();

	Diamond.drawFile("Diamantbestand");

}

