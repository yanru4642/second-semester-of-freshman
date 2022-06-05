#include <iostream>
#include <string>
#include "Administrator.h"
#include "User.h"
using namespace std;


int main() {
    string  username, password;

    //input
    cout << "Enter  username> ";
    cin >> username;
    cout << "Enter  password> ";
    cin >> password;
    //show result
    cout << "Administrator: ";
    if (Administrator::Login(username, password)){
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    cout << "User: ";
    if (User::Login(username, password)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    system("pause");
    return 0;
}