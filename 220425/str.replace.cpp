#include <iostream>
#include <string>
using namespace std;

int main(){
    string oldStr = "a string";
    string newStr = "456";
    cout << oldStr << endl;
    oldStr.replace(1, 0, newStr); //從哪開始 取代幾個 新字串
    cout << oldStr << endl;
    string strAssign;
    strAssign.assign(oldStr, 0, 2);
    cout << strAssign;
    
    system("pause");
    return 0;
}