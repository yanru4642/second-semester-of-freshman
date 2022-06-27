#include "Square.h"

Square::Square():Land()
{
	side = 0;
}

Square::Square(double inSide, string inLocation):Land(inLocation)
{
	side = inSide;
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
