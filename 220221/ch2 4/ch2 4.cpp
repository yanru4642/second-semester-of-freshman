#include <iostream>
using namespace std;

int main(void){
    int found = 0;
    cout << "PRIME NUMBERS BETWEEN 3 AND 100" << endl;
    for (int i = 3; i < 101; i++){
        for (int j = 2; j < i; j++){
            found = 1;
            if (i%j == 0){
                found = 0;
                break;
            }
        }
        if (found){
            cout << i << endl;
        }
    }
    system("pause");
    return 0;
}