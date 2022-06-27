#pragma once
#include <string>
using namespace std;

class Trapezoid{
public:
	Trapezoid();
	Trapezoid(double inhSide, double inlSide, double inHeight, string inLocation);
	double area();
	void sethSide(double inhSide);
	void setlSide(double inlSide);
	void setHeight(double inHeight);
	void setLocation(string inLocation);

	double gethSide()const { return hSide; }
	double getlSide()const { return lSide; }
	double getHeight()const { return height; }
	string getLocation() const { return location; }
private:
	double hSide;
	double lSide;
	double height;
	string location;
};

