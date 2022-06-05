#include <iostream>
#include <string>
using namespace std;

class PrimeNumber {
public:
    PrimeNumber() { nowPrimeNum = 1; }
    PrimeNumber(int inputPrimeNum);
    int getNowPrimeNum() { return nowPrimeNum; }
    friend void operator++(PrimeNumber& nowPrime); //increment prefix
    friend void operator++(PrimeNumber& nowPrime, int); //increment postfix
    friend void operator--(PrimeNumber& nowPrime); //decrement crefix
    friend void operator--(PrimeNumber& nowPrime, int); //decrement postfix
private:
    int nowPrimeNum;
};

bool isPrime(int number) {
    if (number<0){
        return false;
    }
    for (int i = 2; i <= number/2; i++){
        if (number%i==0){
            return false;
        }
        if (i==number/2){
            return true;
        }
    }
}

int main(void){
    PrimeNumber primeNum;
    int inputPrimeNumber;
    string buffer;
    cout << "Enter a number> ";
    cin >> inputPrimeNumber;
    primeNum = PrimeNumber(inputPrimeNumber);
    cout << "Now number: " << primeNum.getNowPrimeNum() << endl;
    cout << "Enter \'+\' to get the next prime number" << endl;
    cout << "Enter \'-\' to get the previous prime number" << endl;
    cout << "Enter \'0\' to escape" << endl;
    cout << "--------------------------------------------" << endl;
    do{
        cin >> buffer;
        if (buffer == "+"){
            primeNum++;
        }else if (buffer=="-"){
            --primeNum;
        }
        else if (buffer == "0") {
            break;
        }
        cout << "Now prime number: " << primeNum.getNowPrimeNum() << endl;
    } while (true);
    

    system("pause");
    return 0;
}

PrimeNumber::PrimeNumber(int inputPrimeNumber):nowPrimeNum(inputPrimeNumber){}


void operator++(PrimeNumber& nowPrime) {
    do {
        nowPrime.nowPrimeNum++;
    } while (!isPrime(nowPrime.nowPrimeNum));
}
void operator++(PrimeNumber& nowPrime, int) {
    do {
        nowPrime.nowPrimeNum++;
    } while (!isPrime(nowPrime.nowPrimeNum));
}
void operator--(PrimeNumber& nowPrime) {
    do {
        if (nowPrime.nowPrimeNum <= 2) {
            break;
        }
        nowPrime.nowPrimeNum--;
    } while (!isPrime(nowPrime.nowPrimeNum));
}
void operator--(PrimeNumber& nowPrime, int) {
    do {
        if (nowPrime.nowPrimeNum <= 2) {
            break;
        }
        nowPrime.nowPrimeNum--;
    } while (!isPrime(nowPrime.nowPrimeNum));
}