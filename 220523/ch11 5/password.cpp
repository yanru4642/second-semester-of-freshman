#include <iostream>
#include <string>
#include <cctype>
#include "password.h"
using namespace std;

namespace {
	string password;
	bool isValid() {
		int numNonLetter = 0;
		if (password.size()<8){
			return false;
		}
		for (int i = 0; i < password.size(); i++){
			if (!isalpha(password[i])){
				numNonLetter++;
			}
		}
		if (numNonLetter==0){
			return false;
		}
		else {
			return true;
		}
	}
}

namespace Authenticate {
	void inputPassword() {
		do{
			cout << "Enter your password (at least 8 characters "
				<< "and at least one non-letter)> ";
			cin >> password;
		} while (!isValid());
	}
	string getPassword() {
		return password;
	}
}