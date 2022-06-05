#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	ifstream inStream;
	ofstream outStream;
	inStream.open("input.txt");
	outStream.open("output.txt",ios::app);
	vector<int> digit;
	int temp;


	while (!inStream.eof()) {
		inStream >> temp;
		digit.push_back(temp);
		cout << temp;
	}
	for (int i = 0; i < digit.size(); i++){
		outStream << digit[i]<<" ";
	}
	outStream << endl;
	
	

	inStream.close();
	outStream.close();
	system("pause");
	return 0;
}