#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void selection_sort(vector<int>& list);

int main(){
    ifstream inStream;
    inStream.open("list.txt");
    vector<int>list;
    int temp;
    while (!inStream.eof()){
        inStream >> temp;
        list.push_back(temp);
        cout << temp<<" ";
    }
    cout << endl;

    selection_sort(list);

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }

    inStream.close();
    system("pause");
    return 0;
}

void selection_sort(vector<int>& list) {
    int tempMinIdx;
    int temp;
    for (int i = 0; i < list.size(); i++){
        //find min
        tempMinIdx = i;
        for (int j = i; j < list.size(); j++){
            if (list[j]< list[tempMinIdx]){
                tempMinIdx = j;
            }
        }
        //swap
        temp = list[i];
        list[i] = list[tempMinIdx];
        list[tempMinIdx] = temp;
    }
}
