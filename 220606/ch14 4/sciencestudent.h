#pragma once
#include <string>
#include "student.h"
using namespace std;

class ScienceStudent :public Student {
public:
	ScienceStudent();
	ScienceStudent(string proctorName, string inUniversityName, int inRegistrationNum
	, string inDiscipline, string inCourse);
	ScienceStudent(const ScienceStudent& rtSide);
	~ScienceStudent();
	ScienceStudent& operator =(const ScienceStudent& rtSide);

	void setDiscipline(string inDiscipline) { discipline = inDiscipline; }
	void setCourse(string inCourse) { course = inCourse; }
	string getDiscipline() const { return discipline; }
	string getCourse()const { return course; }

	void output() const;

private:
	string discipline;
	string course; //undergraduate or postgraduate course
};