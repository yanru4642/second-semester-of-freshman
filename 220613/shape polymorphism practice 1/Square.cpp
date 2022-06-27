#include "Square.h"

Square::Square()
{
	side = 0;
	location = "NO LOC";
}

Square::Square(double inSide, string inLocation)
{
	side = inSide;
	location = inLocation;
}

double Square::area()
{
	return side*side;
}

void Square::setSide(double inSide)
{
	side = inSide;
}

void Square::setLocation(string inLocation)
{
	location = inLocation;
}

double Square::getSide() const
{
	return side;
}

string Square::getLocation() const
{
	return location;
}
