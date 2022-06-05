#include <iostream>
#include "user.h"
#include "password.h"
using namespace std;
using namespace Authenticate;


int main() {

    inputUserName();
    inputPassword();
    cout << "Your username is: " << getUserName() << endl;
    cout << "Your password is: " << getPassword() << endl;

    system("pause");
    return 0;
}