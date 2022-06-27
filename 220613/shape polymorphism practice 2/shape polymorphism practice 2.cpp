#include <iostream>
#include"Circle.h"
#include"Square.h"
#include"Trapezoid.h"
using namespace std;
#define UPRICE 1


double Calcu_Price(Land& inLand);
double Calcu_Price(Land* inLand);

int main() {
	Circle c(10, "Taipei");
	Square s(2.5, "LA");
	Trapezoid t(7, 3, 20, "NY");
	Land* landlist[2];
	landlist[0] = &c;
	landlist[1] = &s;
	Land* p_land = &c;
	cout << Calcu_Price(*landlist[0]) << endl;
	cout << Calcu_Price(landlist[1]) << endl;
	cout << Calcu_Price(*p_land) << endl;

}

double Calcu_Price(Land& inLand) {
	return inLand.area() * UPRICE;
}
double Calcu_Price(Land* inLand) {
	return inLand->area() * UPRICE;
}