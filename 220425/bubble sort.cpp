#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& list);

int main() {
    ifstream inStream;
    inStream.open("list.txt");
    vector<int>list;
    int temp;
    while (!inStream.eof()) {
        inStream >> temp;
        list.push_back(temp);
        cout << temp << " ";
    }
    cout << endl;

    bubble_sort(list);

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }

    inStream.close();
    system("pause");
    return 0;
}

void bubble_sort(vector<int>& list) {
    int temp;
    cout << endl;
    for (int i = list.size()-1; i > 0; i--) {
        for (int j = 0; j < i; j++){
            if (list[j]>list[j+1]){ //if j is bigger than j+1, then swap
                temp=list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
