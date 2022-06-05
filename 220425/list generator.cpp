#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ofstream outStream;
    outStream.open("list.txt");
    vector<int>list;
    int temp;
    cout << "Enter numbers. Enter 9999 to escape" << endl;
    cin >> temp;
    while (temp != 9999){
        list.push_back(temp);
        cin >> temp;
    }

    for (int i = 0; i < list.size(); i++) {
        if (i != 0) {
            outStream << " ";
        }
        outStream << list[i];
    }

    outStream.close();
    system("pause");
    return 0;
}
