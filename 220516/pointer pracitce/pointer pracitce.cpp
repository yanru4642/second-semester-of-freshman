#include <iostream>
using namespace std;

int main()
{
    int* p;
    int v = 7;
    p = new int(v);

    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    cout << "v: " << v << endl;
    cout << "&v: " << &v << endl;
    v++;
    (*p)--;
    cout << "p: " << p << endl;
    cout << "*p: " << *p << endl;
    cout << "v: " << v << endl;
    cout << "&v: " << &v << endl;
}