#pragma once
#include <vector>

using namespace std;

class Bar
{
public:
	Bar(int,double ,double, double,double); //constructor 
	~Bar(); //destructor
	double setLengte(double);
	double setK(double);
	double setrho(double);
	double setC(double);
	int setN(int);
	double setdiscretisatie(double);
	double checketa();
	vector <double> settemperature(double );
	vector <double> T;
	vector <double> Temperatuur;
	vector <double> getT();
	void getTemperatuur(string& fileName);
	void outputvector(const vector <double> & outvec);
private:
	double Lengte;
	int aantalopdelingen;
	double warmtegeleidingscoef;
	double Dichtheid;
	double Warmtecapaciteit;
	double K; 
	double rho; 
	double C;
	double delta_x;
	double delta_t;
	double eta; 
	//vector <double> Heat(double delta_t, int delta_x, double n, vector <double> T);
	const int N; 
	const double K1;
	const double C1; 
	const double rho1; 
	const double Lengte1;
	
	//vector <double> setTemperature;

};