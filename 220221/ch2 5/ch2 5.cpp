#include <iostream>

using namespace std;
#define LEN 5

int DecodeWord(char word[], int T, int O, int G, int D);

int main(void){
    int letterT;
    int letterO;
    int letterG;
    int letterD;
    char word1[LEN] = "TOO";
    char word2[LEN] = "TOO";
    char word3[LEN] = "TOO";
    char word4[LEN] = "TOO";
    char wordAns[LEN] = "GOOD";
    int tempAns;
    int ans;

    cout << "TOO + TOO + TOO + TOO = GOOD\n" << "----------------" << endl;
    for (letterT = 0; letterT < 10; letterT++){
        for (letterO = 0; letterO < 10; letterO++) {
            for (letterG = 0; letterG < 10; letterG++) {
                for (letterD = 0; letterD < 10; letterD++) {
                    if (letterT==letterO || letterT==letterG|| letterT == letterD){
                        continue;
                    }else if (letterO==letterG||letterO==letterD){
                        continue;
                    }else if (letterG == letterD) {
                        continue;
                    }
                    tempAns = 0;
                    tempAns += DecodeWord(word1,letterT,letterO,letterG,letterD);
                    tempAns += DecodeWord(word2, letterT, letterO, letterG, letterD);
                    tempAns += DecodeWord(word3, letterT, letterO, letterG, letterD);
                    tempAns += DecodeWord(word4, letterT, letterO, letterG, letterD);
                    ans= DecodeWord(wordAns, letterT, letterO, letterG, letterD);
                    if (tempAns==ans){
                        cout << "T=" << letterT << " O=" << letterO << " G=" << letterG << " D=" << letterD << endl;
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}

int DecodeWord(char word[], int T, int O, int G, int D) {
    int tempAns = 0;
    for (int i = 0; i < strlen(word); i++){
        switch (word[i]) {
        case 'T':
            tempAns *= 10;
            tempAns += T;
            break;
        case 'O':
            tempAns *= 10;
            tempAns += O;
            break;
        case 'G':
            tempAns *= 10;
            tempAns += G;
            break;
        case 'D':
            tempAns *= 10;
            tempAns += D;
            break;
        default:
            break;
        }
    }
    return tempAns;
}