#include <iostream>
#include "Security.h"
using namespace std;

int Security::validate(string username, string password){
	if (username=="abbot"&&password=="monday"){
		return 1;
	}
	if (username == "costello" && password == "tuesday"){
		return 2;
	}

	return 0;
}