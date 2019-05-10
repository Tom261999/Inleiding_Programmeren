/*
	Tom Stoops (s0173659)
	Tom.Stoops@student.uantwerpen.be
	Ingeleverd op: 08-04-2019
 */

#include "pch.h"
#include "Bar_TomStoops.h"

// Constructor & destructor
Bar::Bar(float L, float K, float rho, float C) : L(set(L)), K(set(K)), rho(set(rho)), C(set(C)){
	std::cout << "<<Constructor aangeroepen>>" << std::endl;
};

Bar::~Bar() {
	std::cout << "<<Destructor aangeroepen>>" << std::endl;
};

// 'set' functie, we gebruiken deze voor alle input variabelen omdat deze aan dezelfde voorwaarden moeten voldoen (strikt groter dan nul)
float Bar::set(float value) const {
	if (value < 0) {
		std::cerr << "<Warning>: Inputwaarde kan niet negatief zijn, we werken verder met de absolute waarde van de input." << std::endl;
		return abs(value);																														// Indien waarde strikt kleiner dan nul, return absolute waarde
	}
	else if (value == 0) {
		std::cerr << "<Error>: Inputwaarde kan niet nul zijn!" << std::endl;
		exit(1);																																// Beeindig programma bij input waarde nul voor constanten
	}
	else {
		return value;																															// Return input waarde
	}
};

// 'check' functie om de input bij de 'Heat' functie te controleren
float Bar::checkHeat(float value) {
	if (value < 0) {
		std::cerr << "<Warning>: Inputwaarde is negatief, we werken verder met de absolute waarde van de input." << std::endl;
		return abs(value);
	}
	else if (value == 0) {
		std::cerr << "<Error>: Inputwaarde kan niet nul zijn!" << std::endl;
		exit(1);
	}
	else {
		return value;
	}
};

// Weergave van vector op console
void Bar::displayVector(std::vector<float> vect) const {
	for (int i = 0; i < vect.size(); i++) {
		std::cout << vect.at(i) << "  ";
	}
	std::cout << "\n" << std::endl;
};

// Schrijf output van 'Heat' naar een bestand
void Bar::writeOutput(std::string addenum, std::vector<float> vect) const {
	std::string fileName = "Output file ";
	fileName += addenum;
	fileName += ".txt";

	std::ofstream outputFile(fileName, std::ios::out);

	if (!outputFile) {
		std::cerr << "<Error>: Outputfile niet gevonden." << std::endl;
		exit(1);
	} else {
		for (int i = 0; i < vect.size(); i++) {
			outputFile << vect.at(i) << std::endl;
		}
	}	
}

// 'Heat' functies, overladen om onderscheid te maken tussen Dirichlet en Neumann randvoorwaarden
std::vector<float> Bar::Heat(int t, float dx, float dt, float LB, float RB, std::string outputName) {											// Versie met Dirichlet randvoorwaarden
	// Check input waarden
	dx = checkHeat(dx);
	dt = checkHeat(dt);
	if (t < 0) {																																// Aparte check voor t omdat deze wel nul kan zijn (toont de beginvoorwaarde)
		std::cerr << "<Warning>: Inputwaarde voor de tijd is negatief, we werken verder met de absolute waarde van de input." << std::endl;
		t = abs(t);
	}

	// Initialiseer constanten
	float eta = (K * dt) / (C * rho * dx * dx);
	int xsteps = ceil(L / dx);																													// Bepaal aantal ruimtestappen
	int tsteps = ceil((float) t / dt);																											// Bepaal aantal tijdstappen

	// Controlleer stabiliteit m.b.v. criterium
	if (eta > 0.5) {
		std::cerr << "<Warning>: Oplossing instabiel, eta = " << eta  << " > 1/2." << std::endl;
	}
	else {
		std::cout << "Oplossing stabiel, eta = " << eta << " < 1/2." << std::endl;
	}
	
	// Initialiseer vectoren
	std::vector<float> vect1;																													// Ik heb twee vectoren nodig om de 'i+1'-de stap te berekenen uit de 'i'-de stap
	std::vector<float> vect2;

	// Beginvoorwaarden
	vect1.resize(xsteps, RB);
	vect1.at(0) = LB;
	vect2 = vect1;

	// Main loop: maakt gebruik van gegeven discretisatie van de diffusie vergelijking
	for (int i = 0; i < tsteps; i++) {
		vect2.front() = LB;
		vect2.back() = RB; 
		for (int j = 1; j < xsteps - 1; j++) {
			vect2.at(j) = vect1.at(j) + eta * (vect1.at(j + 1) + vect1.at(j - 1) - 2 * vect1.at(j));
		}
		vect1 = vect2;
	}

	// Output
	std::string name = outputName;
	name += " op tijdstip t = ";
	name += std::to_string(t);

	displayVector(vect1);
	writeOutput(name, vect1);
	return vect1;
};

std::vector<float> Bar::Heat(int t, float dx, float dt, std::string outputName) {																// Versie met Neumann randvoorwaarden
	// Check input waarden
	dx = checkHeat(dx);
	dt = checkHeat(dt);
	if (t < 0) {																																// Aparte check voor t omdat deze wel nul kan zijn (toont de beginvoorwaarde)
		std::cerr << "<Warning>: Inputwaarde voor de tijd is negatief, we werken verder met de absolute waarde van de input." << std::endl;
		t = abs(t);
	}

	// Initialiseer constanten
	float eta = (K * dt) / (C * rho * dx * dx);
	int xsteps = ceil(L / dx);																													// Bepaal aantal ruimtestappen
	int tsteps = ceil((float)t / dt);																											// Bepaal aantal tijdstappen

	// Controlleer stabiliteit m.b.v. criterium
	if (eta > 0.5) {
		std::cerr << "<Warning>: Oplossing instabiel, eta = " << eta << " > 1/2." << std::endl;
	}
	else {
		std::cout << "Oplossing stabiel, eta = " << eta << " < 1/2." << std::endl;
	}

	// Initialiseer vectoren
	std::vector<float> vect1;
	std::vector<float> vect2;

	// Beginvoorwaarden
	vect1.resize(xsteps, 0);
	vect1.at(xsteps / 2) = 100;
	vect2 = vect1;

	// Main loop: maakt gebruik van gegeven discretisatie van de diffusie vergelijking
	for (int i = 0; i < tsteps; i++) {
		vect2.at(0) = vect2.at(1);
		vect2.at(xsteps - 1) = vect2.at(xsteps - 2);
		for (int j = 1; j < xsteps - 1; j++) {
			vect2.at(j) = vect1.at(j) + eta * (vect1.at(j + 1) + vect1.at(j - 1) - 2 * vect1.at(j));
		}
		vect1 = vect2;
	}

	// Output
	std::string name = outputName;
	name += " op tijdstip t = ";
	name += std::to_string(t);

	displayVector(vect1);
	writeOutput(name, vect1);
	return vect1;
};