#include "Header.h"

// constructor implenteren:

Circle::Circle(int R) {
	
	// hier wat checks om te kijken of R negatief is, etc... 


	radius = R;
	surface = R * R * 3.14159265;


}

Circle::~Circle() {
	cout << "destructor van circle aangeroepen!" << endl;
	// variabele deleten die met new zijn aangemaakt. Anders zou een variabele gemaakt met new niet verwijderd worden buiten de scope... (pas bij afsluiten van programma)
}