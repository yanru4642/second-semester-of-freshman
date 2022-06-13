#include <string>
#include "universitystaff.h"
using namespace std;

UniversityStaff::UniversityStaff() {
	name = "NO Name";
}
UniversityStaff::UniversityStaff(string theName) :name(theName) {}
UniversityStaff::UniversityStaff(const UniversityStaff& theObject) {
	name = theObject.getName();
}
UniversityStaff::~UniversityStaff() {}

UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rtSide) {
	name = rtSide.getName();
	return *this;
}
ostream& operator <<(ostream& outStream, const UniversityStaff& staffObject) {
	outStream << staffObject.name;
	return outStream;
}
istream& operator >>(istream& inStream, UniversityStaff& staffObject) {
	string inName;
	inStream >> inName;
	staffObject.setName(inName);
	return inStream;
}