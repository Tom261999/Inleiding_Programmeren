// Opdracht4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Bar.h"
#include <sstream>

int main()
{
int delen = 100; 
double L = 1; 
double C = 0.45;
double K = 80.4; 
double rho = 7874; 
double n = 100;
double t = 100; // tijd in seconden 
Bar myBar(delen,L,C,K,rho);
myBar.setC(C);
myBar.setK(K);
myBar.setLengte(L);
myBar.setrho(rho); // Alle ingegeven elementen nakijken of dit wel mag
myBar.setdiscretisatie(t);
//myBar.checketa(); 
//vector <double> settemperature(double t);
myBar.settemperature(t);
//string filename = "Taak 1";
//myBar.getTemperatuur(filename); 
return 0; 
}

