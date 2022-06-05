#include <iostream>
#include <string>
using namespace std;


int main(){
    string line;
    char* head;
    char* tail;
    int headWordCnt = 1; //head word count
    int tailWordCnt = 1; //tail word count

    cout << "Enter a sentence> ";
    getline(cin, line);
    //set head and tail
    head = &line[0];
    tail = &line[line.size()-1];
    //iterate
    if (*head == ' ') {
        headWordCnt++;
    }
    if (*tail == ' ') {
        tailWordCnt++;
    }
    for (int i = 0; i < line.size()-1; i++){
        head++;
        tail--;
        if (*head == ' ') {
            headWordCnt++;
        }
        if (*tail == ' ') {
            tailWordCnt++;
        }
    }
    cout << "head word counts: " << headWordCnt << endl;
    cout << "tail word counts: " << tailWordCnt << endl;
    
    system("pause");
    return 0;
}