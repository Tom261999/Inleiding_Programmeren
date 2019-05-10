#include "pch.h"
#include "AccessByPointer.h"
#include <iostream>

void AccessByPtr(int* z) {
	std::cout << "Functie krijgt als input adres " << z << std::endl;

	*z += 10;
}

void AccessByRef(int& a) {
	a -= 3;
	a++;
}