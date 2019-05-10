#pragma once
#ifndef ROOT_H
#define ROOT_H

#include <iostream>
using namespace std;

double root2(double S, double x0, double epsilon);
double rootn(double S, double x0, double epsilon, int n);
double root2alt(double S, double x0, double epsilon);

#endif