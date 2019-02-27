#pragma once


class Circle {
public:
	Circle(int r); // constructor maken
	~Circle(); // destructor maken
	double getSurface();

private:
	int radius;
	double surface;

};