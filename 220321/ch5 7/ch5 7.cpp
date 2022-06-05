#include <iostream>
#define NUM_OF_LIST 6
using namespace std;

void fillList(int list[]);
void printList(int list[]);

int main(void){
	int gradeList[NUM_OF_LIST]={0};
	cout << "Enter students' grades from 0 to 5. (enter -1 to escape)>  "<<endl;
	fillList(gradeList);
	printList(gradeList);

	system("pause");
	return 0;
}
void fillList(int list[]) {
	int tempGrade;
	do{
		cin >> tempGrade;
		if (tempGrade==-1){
			break;
		}
		else if (tempGrade>=0&&tempGrade<=5){
			switch (tempGrade){
			case 0:
				list[0]++;
				break;
			case 1:
				list[1]++;
				break;
			case 2:
				list[2]++;
				break;
			case 3:
				list[3]++;
				break;
			case 4:
				list[4]++;
				break;
			case 5:
				list[5]++;
				break;
			default:
				break;
			}
		}
		else {
			cout << "Invalid data, enter again." << endl;
		}

	} while (true);
}
void printList(int list[]) {
	cout << "------------" << endl;
	for (int i = 0; i < NUM_OF_LIST; i++){
		cout  << "Grade " << i <<": " << list[i]<<" student(s)" << endl;
	}
	cout << "------------" << endl;
}