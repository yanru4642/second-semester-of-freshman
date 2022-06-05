#ifndef USER_H
#define USER_H

#include "Security.h"

class User:Security {
public:
	static bool Login(string username, string password);
};

#endif // !USER_H