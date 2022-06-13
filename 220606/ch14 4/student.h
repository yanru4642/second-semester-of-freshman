#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "universitystaff.h"
using namespace std;

class Student:public UniversityStaff{
public:
	Student();
	Student(string proctorName, string inUniversityName, int inRegistrationNum);
	Student(const Student& rtSide);
	~Student(){}
	Student& operator =(const Student& rtSide);

	void setUniversityName(string inUniversityName) { universityName = inUniversityName; }
	void setRegistrationNum(int inRegistrationNum) { registrationNum = inRegistrationNum; }
	string getUniversityName() const { return universityName; }
	int getRegistrationNum() const { return registrationNum; }

	void output() const;
private:
	string universityName;
	int registrationNum;
};

#endif