#include <iostream>
#include <string>
using namespace std;


int main(){
    typedef int* IntPtr;
    IntPtr p = new int[5];
    *p = 7;
    *(p + 3) = 8;
    *(++p) = 10;
    p--;
    for (int i = 0; i < 5; i++){
        cout << *(p + i) << endl;
    }

    IntPtr p1;
    int capacity;
    cout << "enter capacity>";
    cin >> capacity;
    p1 = new int[capacity];
    for (int i = 0; i < capacity; i++){
        cin >> *(p1+i);
    }
    cout << "p1 " << p1 << endl;
    cout << "*p1 " << *p1 << endl;
    cout << "delete p1" << endl;
    delete[] p1;
    p1 = nullptr;
}