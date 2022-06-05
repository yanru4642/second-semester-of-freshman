#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class ZipCode {
public:
    ZipCode() {}
    ZipCode(string barCode);
    ZipCode(int CodeNumber);
    string getBarCode();
    int getCodeNumber();
private:
    vector<int>code[5];
};

int main(void) {
    ZipCode aCode;
    string strbuffer; //string buffer
    int intbuffer = 0; //int buffer

    //input
    cout << "Eneter Bar Code or Code Number> ";
    cin >> strbuffer;
    //110100101000101011000010011

    if (strbuffer.size() == 5) {
        for (int i = 0; i < 5; i++) {
            intbuffer *= 10;
            intbuffer += strbuffer[i] - '0';
        }
        aCode = ZipCode(intbuffer);
    }
    else if (strbuffer.size() == 27) {
        aCode = ZipCode(strbuffer);
    }
    else {
        cout << "Invalid data";
        exit(1);
    }

    //get value
    cout << "\nBar    Code:" << aCode.getBarCode() << endl;
    cout << "Code Number:" << aCode.getCodeNumber() << endl;

    system("pause");
    return 0;
}

ZipCode::ZipCode(string barCode) {
    int idx = 1;
    int buffer;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            buffer = barCode[idx++] - '0';
            code[i].push_back(buffer);
        }
    }
}

ZipCode::ZipCode(int CodeNumber) {
    //convert from decimal to binary
    int readDigit;
    //construct the convert table
    int digitWeight[] = { 7,4,2,1,0 };
    vector<int>convertTable[4];
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            convertTable[i].push_back(digitWeight[i] + digitWeight[j]);
        }
    }

    for (int dig = 4; dig >= 0; dig--) {
        //read a digit
        readDigit = CodeNumber % 10;
        CodeNumber /= 10;
        if (readDigit==0){
            readDigit = 11;
        }
        //convert to binary code 
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < convertTable[i].size(); j++) {
                if (readDigit==convertTable[i][j]){
                    //store the value
                    code[dig] = { 0,0,0,0,0 };
                    code[dig][i] = 1;
                    code[dig][i+j+1] = 1;
                }
            }
        }

    }
}

string ZipCode::getBarCode() {
    string temp;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < code[i].size(); j++) {
            temp += code[i][j] + '0';
        }
    }

    return temp;
}

int ZipCode::getCodeNumber() {
    int temp = 0;

    for (int i = 0; i < 5; i++) {
        temp *= 10;
        if (!(code[i][0] + code[i][1] == 2)) {
            temp += 7 * code[i][0] + 4 * code[i][1] + 2 * code[i][2] + code[i][3];
        }
    }

    return temp;
}