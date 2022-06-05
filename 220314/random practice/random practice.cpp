#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void){
	srand(time(NULL));  //用系統時間當作rand()的種子碼
	cout << "隨機產生數字" << endl;
	for (int i = 0; i < 5; i++){
		cout << rand() << endl;
	}
	cout << "隨機產生數字0~5" << endl;
	for (int i = 0; i < 5; i++) {
		cout << rand()%6 << endl;
	}
	cout << "隨機產生數字10~20" << endl;
	for (int i = 0; i < 5; i++) {
		cout << rand()%11 + 10<< endl;
	}
	cout << "隨機產生數字0~1" << endl;
	for (int i = 0; i < 5; i++) {
		cout << rand()/(double)RAND_MAX << endl;
	}

	system("pause");
	return(0);
}
