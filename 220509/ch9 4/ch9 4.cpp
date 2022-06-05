#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string lineBuffer;
	string word;
	string resultSentence;

	while (true)
	{
		resultSentence = "";
		//input the word
		cout << "Input a sentence>" << endl;
		getline(cin, lineBuffer);
		//if enter -1, escape
		if (lineBuffer == "-1") {
			break;
		}
		//change word if the number of char is 4 and show the result
		for (int i = 0; i < lineBuffer.size(); i++) {
			if (!isalpha(lineBuffer[i])) {
				if (word.size() == 4) { //change word if the number of char is 4
					word = "love";
				}
				resultSentence += word; //show word
				word = ""; //clear the word
				resultSentence += lineBuffer[i];
			}
			else {
				word += lineBuffer[i];
			}
		}
		resultSentence += word; //show the last word
		word = ""; //clear the last word

		//first char to upper
		resultSentence[0] = toupper(resultSentence[0]);
		cout << resultSentence << endl;
		cout << "Enter -1 to escape. ";
	}

	system("pause");
	return 0;
}