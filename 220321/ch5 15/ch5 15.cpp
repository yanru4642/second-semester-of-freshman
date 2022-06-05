#include <iostream>
#include <ctime>
using namespace std;
int randomNum(void);
bool InputPassword(int arr[], char buffer[]);
int check(int encodePIN[], int userInput[]);

int main(void){
	int encodeChart[10];
	char buffer[64];
	int PIN[5];
	int encodePIN[5];
	int userInput[5];
	bool valid;
	bool correct;
	srand(time(NULL));
	for (int i = 0; i < 10; i++){
		encodeChart[i] = randomNum();
	}

	cout << "Enter 5-digit PIN: ";
	valid = InputPassword(PIN, buffer);
	do{
		if (!valid){
			cout << "Invalid PIN. Enter again." << endl;
			valid = InputPassword(PIN, buffer);
		}
	} while (!valid);
	//encode
	for (int i = 0; i < 5; i++){
		encodePIN[i] = encodeChart[PIN[i]];
	}

	//print the convert chart
	cout << "--------------------------" << endl;
	cout << "PIN:  ";
	for (int i = 0; i < 10; i++){
		cout << i << " ";
	}
	cout << endl;
	cout << "NUM:  ";
	for (int i = 0; i < 10; i++) {
		cout << encodeChart[i] << " ";
	}
	cout << endl;
	cout << "--------------------------" << endl;

	//input encoded PIN
	cout << "Enter encoded PIN: ";
	valid = InputPassword(userInput, buffer);
	do {
		if (!valid) {
			cout << "Invalid PIN. Enter again." << endl;
			valid = InputPassword(userInput, buffer);
		}
	} while (!valid);

	//check
	correct=check(encodePIN, userInput);
	if (correct){
		cout << "Correct." << endl;
	}else{
		cout << "Incorrect." << endl;
	}

	system("pause");
	return 0;
}
int randomNum(void) {
	return rand()%10;
}
bool InputPassword(int arr[], char buffer[]) {
	cin >> buffer;
	for (int i = 0; i < 5; i++){
		if (buffer[i]>='0'&&buffer[i]<='9') {
			arr[i] = buffer[i]-'0';
		}else{
			return false;
		}
	}
	return true;
}
int check(int encodePIN[], int userInput[]) {
	for (int i = 0; i < 5; i++){
		if (encodePIN[i]!= userInput[i]){
			return false;
		}
	}
	return true;
}