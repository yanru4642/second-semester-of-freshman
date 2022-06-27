#pragma once
#include <iostream>
#include <string>
using namespace  std;

class Land
{
public:
	Land();
	Land(string inLoc);
	virtual double area() ;
protected:
	string location;
};
