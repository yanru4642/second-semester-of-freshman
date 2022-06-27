#include <iostream>
#include"Circle.h"
#include"Square.h"
#include"Trapezoid.h"
using namespace std;
#define UPRICE 330

double Calcu_Price(Circle& inCircle);
double Calcu_Price(Square& inSquare);
double Calcu_Price(Trapezoid& inTrapezoid);

int main(){
	Circle c (10, "Taipei");
	Square s(2.5, "LA");
	Trapezoid t(7, 3, 20, "NY");
	cout << Calcu_Price(c) << endl;
	cout << Calcu_Price(s) << endl;
	cout << Calcu_Price(t) << endl;
}

double Calcu_Price(Circle& inCircle)
{
	return inCircle.area()* UPRICE;
}

double Calcu_Price(Square& inSquare)
{
	return inSquare.area()* UPRICE;
}

double Calcu_Price(Trapezoid& inTrapezoid)
{
	return inTrapezoid.area()* UPRICE;
}
