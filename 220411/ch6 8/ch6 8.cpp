#include <iostream>
using namespace std;

class Money{
public:
    void setDollar(int inDollar);
    int getDollar();
    void setCent(int inCent);
    int getCent();
    double getMonetaryAmount();
private:
    int dollar;
    int cent;
};

int main(void){
    Money money1, money2;//create two objects
    int dollar;
    int cent;
    double sum;
    //money1
    cout << "Enter Money1 dollar>";
    cin >> dollar;
    money1.setDollar(dollar);
    cout << "Enter Money1 cent>";
    cin >> cent;
    money1.setCent(cent);
    //get dollar
    cout << "money1.getDollar: " << money1.getDollar() << endl;
    //get cent
    cout << "money1.getCent: " << money1.getCent() << endl;
    //get sum
    sum = money1.getMonetaryAmount();
    cout << "Monetary Amount: " << sum << "$" << endl;

    //money2
    cout << "\nEnter Money2 dollar>";
    cin >> dollar;
    money2.setDollar(dollar);
    cout << "Enter Money2 cent>";
    cin >> cent;
    money2.setCent(cent);
    //get dollar
    cout << "money2.getDollar: " << money2.getDollar() << endl;
    //get cent
    cout << "money2.getCent: " << money2.getCent() << endl;
    //get sum
    sum = money2.getMonetaryAmount();
    cout << "Monetary Amount: " << sum << "$" << endl;
    system("pause");
    return 0;
}

void Money::setDollar(int inDollar) {
    dollar = inDollar;
}
int Money::getDollar() {
    return dollar;
}
void Money::setCent(int inCent) {
    cent = inCent;
}
int Money::getCent() {
    return cent;
}
double Money::getMonetaryAmount() {
    double sum;
    sum = dollar + cent/100.0;
    return sum;
}