#pragma once
#include <string>
#include "Land.h"
using namespace std;

class Square:public Land{
public:
	Square();
	Square(double inSide, string inLocation);
	double area();
	void setSide(double inSide);
	void setLocation(string inLocation);
	double getSide() const;
	string getLocation() const;
private:
	double side;
};

