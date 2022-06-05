#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string lineBuffer;
	string word;
	bool stop = false;

	getline(cin, lineBuffer);
	cout << "linebuffer: " << lineBuffer << endl;

	for (int i = 0; i < lineBuffer.size(); i++) {

		if (!isalpha(lineBuffer[i])) {
			if (word != ""){
				cout << "word: " << word << endl;
				word = "";
			}
		}
		else {
			word += lineBuffer[i];
		}
			
	}
	cout << "word: " << word << endl;

	return 0;
}