#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <string>
#include "salariedemployee.h"
using std::string;

class Administrator :public SalariedEmployee {
public:
	Administrator();
	Administrator(const string& theName, const string& theSsn, double theWeeklySalary);
	void setSupervisor(string SupervisorName);
	void readData();
	void print();
	void printCheck();
protected:
	double annualSalary;
private:
	string title;
	string responsibility;
	string supervisor;
};


#endif // !ADMINISTRATOR_H
