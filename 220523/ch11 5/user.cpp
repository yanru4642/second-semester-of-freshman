#include <iostream>
#include <string>
#include "user.h"
using namespace std;

namespace {
	string username;
	bool isValid() {
		if (username.size() == 8) {
			return true;
		}
		return false;
	}
}

namespace Authenticate {
	void inputUserName(){
		do{
			cout << "Enter your username (8 characters)> ";
			cin >> username;
		} while (!isValid());
	}
	string getUserName() {
		return username;
	}
}