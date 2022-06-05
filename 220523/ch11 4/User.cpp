#include <iostream>
#include "User.h"
using namespace std;

bool User::Login(string username, string password) {
	if (validate(username, password) != 0) {
		return true;
	}
	return false;
}