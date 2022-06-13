#include <iostream>
#include <string>
#include "administrator.h"
using namespace std;

Administrator::Administrator(): SalariedEmployee() {
	annualSalary = 0;
	title = "";
	responsibility = "";
	supervisor = "";
}
Administrator::Administrator(const string& theName, const string& theSsn, double theWeeklySalary)
	:SalariedEmployee(theName,theSsn,theWeeklySalary){
	annualSalary = salary * 52;
	title = "";
	responsibility = "";
	supervisor = "";
	setNetPay(annualSalary);
}
void Administrator::setSupervisor(string SupervisorName) {
	supervisor = SupervisorName;
}
void Administrator::readData() {
	string inTitle;
	string inResponsibility;
	cout << "Enter " << getName() << "'s title> ";
	cin.ignore();
	getline(cin, inTitle);
	cout << "Enter area of Responsibility> ";
	getline(cin, inResponsibility);
	title = inTitle;
	responsibility = inResponsibility;
}
void Administrator::print() {
	cout << "\n__________________________________________________\n";
	cout << getName() << "'s info." << endl;
	cout << "Title: " << title << endl;
	cout << "Area of responsibility: " << responsibility << endl;
	cout << "Supervisor: " << supervisor << endl;
	cout << "SSN: " << getSsn() << endl;
	cout << "Weekly salary: " << salary << endl;
	cout << "Annual salary: " << annualSalary << endl;
	cout << "__________________________________________________\n";
}
void Administrator::printCheck() {
	cout << "\n__________________________________________________\n";
	cout << "Pay to the order of " << getName() << endl;
	cout << "The sum of " << getNetPay() << " Dollars\n";
	cout << "_________________________________________________\n";
	cout << "Check Stub NOT NEGOTIABLE \n";
	cout << "Number: " << getSsn() << endl;
	cout << "Administrator. Regular Pay: "
		<< annualSalary << endl;
	cout << "_________________________________________________\n";
}