#include <iostream>
#include <string>
using namespace std;

int main(){
	string lineBuffer;
	string word;
	const string delim = "!"; /* 使用哪些符號切割 */
	bool stop;

	getline(cin, lineBuffer);
	cout << "linebuffer: " << lineBuffer << endl;;
	stop = false;
	for (int i = 0; i < lineBuffer.size(); i++){
		for (int j = 0; j < delim.size(); j++){
			if (lineBuffer[i]==delim[j]) {
				stop = true;
				break;
			}
		}
		if (stop){
			break;
		}
		word += lineBuffer[i];
	}
	cout << "word: " << word << endl;
}