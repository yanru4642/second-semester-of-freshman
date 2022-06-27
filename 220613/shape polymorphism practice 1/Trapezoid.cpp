#include "Trapezoid.h"

Trapezoid::Trapezoid()
{
	hSide = 0;
	lSide = 0;
	height = 0;
	location = "NO LOC";
}

Trapezoid::Trapezoid(double inhSide, double inlSide, double inHeight, string inLocation)
{
	hSide = inhSide;
	lSide = inlSide;
	height = inHeight;
	location = inLocation;
}

double Trapezoid::area()
{
	return (hSide + lSide) * height / 2.0;
}

void Trapezoid::sethSide(double inhSide)
{
	hSide = inhSide;
}

void Trapezoid::setlSide(double inlSide)
{
	lSide = inlSide;
}

void Trapezoid::setHeight(double inHeight)
{
	height = inHeight;
}

void Trapezoid::setLocation(string inLocation)
{
	location = inLocation;
}
