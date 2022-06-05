#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    vector<int>grade;
    int inGrade;
    int maxGrade; //store maximum grade
    int count; //count how many people in one grade

    cout << "Enter stdudents' grade. Enter negative number to escape." << endl;
    cin >> inGrade; 
    while (inGrade >= 0 ) {
        grade.push_back(inGrade);
        cin >> inGrade;
    }
    //find max
    maxGrade = grade[0];
    for (int i = 0; i < grade.size(); i++){
        if (grade[i]>maxGrade){
            maxGrade = grade[i];
        }
    }
    //show histogram
    for (int i = 0; i <= maxGrade; i++){
        count = 0;
        for (int j = 0; j < grade.size(); j++){
            if (grade[j]==i){
                count++;
            }
        }
        if (count!=0){
            cout << "Grade " << i << " has " << count << " student(s)" << endl;

        }
        
    }

    system("pause");
    return 0;
}