#include "Land.h"

Land::Land()
{
	location = "NO LOC";
}
Land::Land(string inLoc) {
	location = inLoc;
}

double Land::area()
{
	cout << "Error. Land area is invalid." << endl;
	return -1;
}
