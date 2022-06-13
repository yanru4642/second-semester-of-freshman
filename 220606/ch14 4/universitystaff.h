#ifndef UNIVERSITYSTAFF_H
#define UNIVERSITYSTAFF_H

#include <iostream>
#include <string>

using namespace std;

class UniversityStaff
{
public:
	UniversityStaff();
	UniversityStaff(string theName);
	UniversityStaff(const UniversityStaff& theObject);
	~UniversityStaff();
	void setName(string inName) { name = inName; }
	string getName() const { return name; }
	UniversityStaff& operator=(const UniversityStaff& rtSide);
	friend ostream& operator <<(ostream& outStream, const UniversityStaff& staffObject);
	friend istream& operator >>(istream& inStream, UniversityStaff& staffObject);
private:
	string name;
};

#endif // !UNIVERSITYSTAFF_H

