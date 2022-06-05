#include <iostream>
#include <string>
using namespace std;
class MyClass
{
public:
    MyClass() { x = 1; y = 1; }
    void func() { this->x = 5; };
    int x;

private:
    int y;
};

int main(int argc, char* argv[]){
    string x="12345678901234";
    x.append("5");

    cout << "x: " << x << endl;
    cout << "capacity: " << x.capacity() << endl;
    cout << "size: " << x.size() << endl;
    cout << "max_size: " << x.max_size() << endl;
    cout << "----------------------------" << endl;
    x.reserve(50);
    cout << "reserve\nx: " << x << endl;
    cout << "capacity: " << x.capacity() << endl;
    cout << "size: " << x.size() << endl;
    cout << "max_size: " << x.max_size() << endl;
    cout << "----------------------------" << endl;
    x.shrink_to_fit();
    cout << "shrink_to_fit\nx: " << x << endl;
    cout << "capacity: " << x.capacity() << endl;
    cout << "size: " << x.size() << endl;
    cout << "max_size: " << x.max_size() << endl;
    cout << "----------------------------" << endl;
    MyClass obj;
    cout << obj.x;
    obj.x = 4;
    MyClass* obj1 = new MyClass;
    cout << obj.x;
    obj1->x = 4;
    (*obj1).x = 4;

    system("pause");
    return 0;
}