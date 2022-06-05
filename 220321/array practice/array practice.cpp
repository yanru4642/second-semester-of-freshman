#include <iostream>
using namespace std;

void fillArr(int arr[], int& numUsed);
void printArr(int arr[], int numUsed);

int main(void){
	int numUsed=0;
	int arr[5];
	fillArr(arr, numUsed);
	printArr(arr, numUsed);
	return 0;
}
void fillArr(int arr[], int& numUsed) {
	char ans;
	do{
		cin >> arr[numUsed++];
		cout << "Continue? y/n> ";
		cin >> ans;
	} while (ans=='y');

}
void printArr(int arr[], int numUsed) {
	for (int i = 0; i < numUsed; i++){
		if (i!=0){
			cout << ", ";
		}
		cout << arr[i];
	}
	cout << endl;
}
