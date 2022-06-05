#include <iostream>
using namespace std;

void callByRef(int* &listptr, int &size) {
	cout << "list in func(before add): ";
	for (int i = 0; i < size; i++) {
		cout << listptr[i] << " ";
	}
	cout << endl;
	cout << "list loc: " << listptr << endl;

	cout << "adding an number..." << endl;
	cout << "Enter a number> ";
	int temp;
	cin >> temp;
	int* tempptr = listptr;
	int oldsize = size;
	size++;
	listptr = new int[size];
	for (int i = 0; i < oldsize; i++) {
		listptr[i] = tempptr[i];
	}
	listptr[size-1] = temp;
	delete[] tempptr;

	cout << "list in func(after add): ";
	for (int i = 0; i < size; i++) {
		cout << listptr[i] << " ";
	}
	cout << endl;
	cout << "list loc: " << listptr << endl;
}

int main() {
	int size = 5;
	int* list = new int[size];
	cout << "Enter 5 integer numbers> ";
	for (int i = 0; i < size; i++) {
		cin >> list[i];
	}

	cout << "list in main(before add): ";
	for (int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
	cout<<"list loc: " << list << endl;

	callByRef(list, size);

	cout << "list in main(after add): ";
	for (int i = 0; i < size; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
	cout << "list loc: " << list << endl;

	system("pause");
	return 0;
}