#pragma once
#include <iostream>
#include <string>
using namespace  std;

class Land
{
public:
	Land();
	Land(string inLoc);
	double area();
protected:
	string location;
};
