#include <iostream>
#include <string>
#include "student.h"
using namespace std;

Student::Student() :UniversityStaff() {
	universityName = "NO universityName";
	registrationNum = 0;
}
Student::Student(string proctorName, string inUniversityName, int inRegistrationNum)
	:UniversityStaff(proctorName),
	universityName(inUniversityName), registrationNum(inRegistrationNum) {}
Student::Student(const Student& rtSide) :UniversityStaff(rtSide) {
	universityName = rtSide.getUniversityName();
	registrationNum = rtSide.getRegistrationNum();
}
Student& Student::operator =(const Student& rtSide) {
	UniversityStaff::operator=(rtSide);
	universityName = rtSide.getUniversityName();
	registrationNum = rtSide.getRegistrationNum();
	return *this;
}
void Student::output() const{
	cout << "proctorName: " << getName() << endl;
	cout << "universityName: " << universityName << endl;
	cout << "registrationNum: " << registrationNum << endl;
}