#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Security.h"

class Administrator:Security{
public:
	static bool Login(string username, string password);
};

#endif // !ADMINISTRATOR_H