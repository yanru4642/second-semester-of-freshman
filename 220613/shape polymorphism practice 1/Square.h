#pragma once
#include <string>
using namespace std;

class Square{
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
	string location;
};

