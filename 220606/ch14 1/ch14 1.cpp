#include <iostream>
using namespace std;
#include "administrator.h"


int main() {
	string theName;
	string theSsn;
	double theWeeklySalary;
	string SupervisorName;
	cout << "Enter Admin's name> ";
	getline(cin, theName);
	cout << "Enter " << theName << "'s ssn> ";
	getline(cin, theSsn);
	cout << "Enter the weekly salary> ";
	cin >> theWeeklySalary;
	Administrator admin1(theName,theSsn,theWeeklySalary);
	admin1.readData();
	cout << "Enter " << admin1.getName() << "'s supervisor> ";
	getline(cin, SupervisorName);
	admin1.setSupervisor(SupervisorName);
	admin1.print();
	admin1.printCheck();


	system("pause");
	return 0;
}