#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class ZipCode {
public:
    ZipCode(){}
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
    }else if(strbuffer.size() == 27) {
        aCode = ZipCode(strbuffer);
    }
    else {
        cout << "Invalid data";
        exit(1);
    }

    //get value
    cout <<"\nBar    Code: " << aCode.getBarCode() << endl;
    cout << "Code Number: " << aCode.getCodeNumber() << endl;

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
    int digit7, digit4, digit2, digit1, digit0;
    bool found;
    for (int i = 4; i >= 0; i--){
        readDigit = CodeNumber % 10;
        CodeNumber /= 10;
        found = false;
        for (digit7 = 0; digit7 < 2; digit7++) {
            for (digit4 = 0; digit4 < 2; digit4++) {
                for (digit2 = 0;  digit2 < 2; digit2++) {
                    for (digit1 = 0; digit1 < 2; digit1++) {
                        for (digit0 = 0; digit0 < 2; digit0++) {
                            if ((7 * digit7 + 4 * digit4 + 2 * digit2 + digit1) == readDigit && digit7+digit4+digit2+digit1+digit0==2) {
                                code[i].push_back(digit7);
                                code[i].push_back(digit4);
                                code[i].push_back(digit2);
                                code[i].push_back(digit1);
                                code[i].push_back(digit0);
                                found = true;
                            }
                        }
                    }
                }
            }
        }
        if (!found){
            code[i].push_back(1);
            code[i].push_back(1);
            code[i].push_back(0);
            code[i].push_back(0);
            code[i].push_back(0);
        }
    }
}

string ZipCode::getBarCode() {
    string temp;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < code[i].size(); j++) {
            temp += code[i][j] + '0';
        }
    }
    
    return temp;
}

int ZipCode::getCodeNumber() {
    int temp=0;

    for (int i = 0; i < 5; i++){
        temp *= 10;
        if (!(code[i][0]+code[i][1]==2)){
            temp += 7 * code[i][0] + 4 * code[i][1] + 2 * code[i][2] + code[i][3];
        } 
    }

    return temp;
}