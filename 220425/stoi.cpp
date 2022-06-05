#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int toNum; //convert to integer
    cin >> str;
    cout << "str: " << str << endl;
    toNum = stoi(str);
    cout <<"num+1: " << ++toNum << endl;
    system("pause");
    return 0;
}
