#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>
using namespace std;

Circle::Circle():Land() {
	radius = 0;
}

Circle::Circle(double inRadius, string inLocation)
	:Land(inLocation),radius(inRadius){}

void Circle::setRadius(double inRadius){
	radius = inRadius;
}

void Circle::setLocation(string inLocation){
	location = inLocation;
}

double Circle::getRadius() const
{
	return radius;
}

string Circle::getLocation() const
{
	return location;
}

double Circle::area () 
{
	return radius*radius*M_PI;
}
