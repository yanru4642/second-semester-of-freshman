#include <iostream>
#include "Administrator.h"
using namespace std;

bool Administrator::Login(string username, string password) {
	if (validate(username,password)==1)	{
		return true;
	}
	return false;
}