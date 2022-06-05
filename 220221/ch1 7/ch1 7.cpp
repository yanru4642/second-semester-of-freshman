#include <iostream>
using namespace std;

int main(void) {
	double speed = 0;		//in mile per hour
	double MET = 0;		//number of metabolic equivalents
	double weight = 0;	//in kilogram
	double calPerMin = 0;
	double totalCal = 0;

	cout << "Enter your weight(kg)> ";
	cin >> weight;

	//first 3 mins
	speed = 4;
	for (int i = 0; i < 3; i++)	{
		MET = speed * 5 / 3;
		calPerMin = 0.0175 * MET * weight;
		totalCal += calPerMin;
	}
	//the rest of mins
	for (int k = 0; k < 3; k++) {
		speed += 2;
		for (int j = 0; j < 4; j++)	{
			MET = speed * 5 / 3;
			calPerMin = 0.0175 * MET * weight;
			totalCal += calPerMin;
		}
	}


	//output the result
	cout << "Running on a treadmill for 15 mins, you burned "
		<< totalCal << " calories." << endl;

	system("pause");
	return 0;
}