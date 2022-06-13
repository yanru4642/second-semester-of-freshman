#include <iostream>
#include <string>
#include "sciencestudent.h"
using namespace std;

ScienceStudent::ScienceStudent():Student() {
	discipline = "no discipline";
	course = "no course";
}
ScienceStudent::ScienceStudent(string proctorName, string inUniversityName, int inRegistrationNum
	, string inDiscipline, string inCourse)
	:Student( proctorName,  inUniversityName,  inRegistrationNum){
	discipline = inDiscipline;
	course = inCourse;
}
ScienceStudent::ScienceStudent(const ScienceStudent& rtSide) :Student(rtSide){
	discipline = rtSide.getDiscipline();
	course = rtSide.getCourse();
}
ScienceStudent::~ScienceStudent(){}

ScienceStudent& ScienceStudent::operator =(const ScienceStudent& rtSide) {
	Student::operator=(rtSide);
	discipline = rtSide.getDiscipline();
	course = rtSide.getCourse();
	return *this;
}
void ScienceStudent::output() const {
	cout << "---------------------" << endl;
	Student::output();
	cout << "discipline: " << discipline << endl;
	cout << "course: " << course << endl;
	cout << "---------------------" << endl;
}