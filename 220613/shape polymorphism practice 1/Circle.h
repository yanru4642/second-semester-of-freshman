#pragma once
#include <string>
#include "Land.h"
using namespace std;

class Circle:public Land{
public:
	Circle();
	Circle(double inRadius, string inLocation);
	double area() const;
	void setRadius(double inRadius);
	void setLocation(string inLocation);
	double getRadius() const;
	string getLocation() const;
private:
	double radius;
};

