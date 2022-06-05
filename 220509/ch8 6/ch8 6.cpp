#include <iostream>
#include <string>
using namespace std;

class MyInteger{
public:
    MyInteger() { number = 0; numStr = ""; }
    MyInteger(int numberValue);
    const int& operator [](int idx);
private:
    int number;
    string numStr;
};

int main(void){
    MyInteger myInteger;
    int number;
    int idx;

    //input a number
    cout << "Enter an integer number> ";
    cin >> number;
    myInteger = MyInteger(number);

    //find the digit in index
    cout << "Enter index (enter -1 to stop)> ";
    cin >> idx;
    while (idx != -1){
        cout << "Digit: ";
        cout << myInteger[idx] << endl;
        cout << "Enter index (enter -1 to stop)> ";
        cin >> idx;
    }

    system("pause");
    return 0;
}

MyInteger::MyInteger(int numberValue):number(numberValue) {
    int temp = number;
    do{
        numStr += temp % 10 + '0';
        temp /= 10;
    } while (temp!=0);
    cout << numStr << endl;
}

const int& MyInteger::operator [](int idx) {
    if (idx<0||idx>=numStr.size()){
        return -1;
    }else{
        return numStr[idx]-'0';
    }
}