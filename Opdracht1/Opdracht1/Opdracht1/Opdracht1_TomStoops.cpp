/* Tom Stoops, 2BFYS, s0173659 */

#include "pch.h"
#include <iostream>
#include "roots_TomStoops.h"

using namespace std;

int main() {
	cout.precision(10); // Precisie van de output wat hoger zetten

	// Vraag 2: sanity check
	double out = root2(100, 50, 0.1);
	cout << "Gevonden wortel van 100 is: " << out << endl;
	cout << "Iteraties en resultaten: " << endl;
	root2alt(100, 50, 0.001);
	root2alt(100, 1, 0.001);

	// Vraag 3: Babylonische techniek voor wortels
	cout << " " << endl;
	cout << "Babylonische techniek voor vierkantswortels." << endl;
	cout << "de wortel van 0 is " << root2(0, 1, 0.001) << endl;
	cout << "de wortel van -100 is " << root2((-100), 1, 0.001) << endl;
	cout << "de wortel van 100 (met epsilon = -0.01)" << root2(100, 1, -0.01) << endl;
	cout << "de wortel van 100 (met x0 = -15)" << root2(100, (-15), 0.001) << endl;
	cout << "de wortel van 676 is " << root2(676, 1, 0.001) << endl;
	cout << "de wortel van 999 is " << root2(999, 1, 0.001) << endl;

	// Vraag 4: Newton's methode
	cout << " " << endl;
	cout << "Newton's methode voor n-de machtswortels." << endl;
	cout << "de 2de wortel van 0 is " << rootn(0, 1, 0.001, 2) << endl;
	cout << "de 3de wortel van 27 is " << rootn(27, 1, 0.001, 3) << endl;
	cout << "de -3de wortel van 16 is " << rootn(16, 1, 0.001, (-3)) << endl;
	cout << "de 3de wortel van -16 is " << rootn((-16), 1, 0.001, 3) << endl;
	cout << "de 0de wortel van 100 is " << rootn(100, 1, 0.001, 0) << endl;
	cout << "de 8ste wortel van 390625 is " << rootn(280625, 1, 0.001, 8) << endl;
	cout << "de 6de wortel van 999 is " << rootn(99, 1, 0.001, 6) << endl;

	return 0;
}