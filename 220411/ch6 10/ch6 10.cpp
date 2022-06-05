#include <iostream>
#include <string>
using namespace std;

class Weight{
public:
    void setWeightPounds(double inWt);
    double getWeightPounds();
    void setWeightKilograms(double inWt);
    double getWeightKilograms();
    void setWeightOunces(double inWt);
    double getWeightOunces();
private:
    double wtLb;
};

int main(void){
    Weight newWeight;
    double wtInput;
    double wtLb;
    double wtKg;
    double wtOz;
    string unit;//單位

    //input
    do{
        cout << "Enter weight unit,\nPound(enter 0)  Kilogram(enter 1)  Ounce(enter 2)> ";
        getline(cin, unit);
        if (unit == "0") {
            cout << "Enter weight in pound> ";
            cin >> wtInput;
            newWeight.setWeightPounds(wtInput);
            break;
        }
        else if (unit == "1") {
            cout << "Enter weight in kilogram> ";
            cin >> wtInput;
            newWeight.setWeightKilograms(wtInput);
            break;
        }
        else if (unit == "2") {
            cout << "Enter weight in ounce> ";
            cin >> wtInput;
            newWeight.setWeightOunces(wtInput);
            break;
        }
        else {
            cout << "Invalid unit. Enter again.\n" << endl;
        }
    } while (true);

    //output
    wtLb = newWeight.getWeightPounds();
    wtKg = newWeight.getWeightKilograms();
    wtOz = newWeight.getWeightOunces();
    cout << "\nPounds: " << wtLb << endl;
    cout << "Kilograms: " << wtKg << endl;
    cout << "Ounces: " << wtOz << endl;
    
    system("pause");
    return 0;
    
}
void Weight::setWeightPounds(double inWt) {
    wtLb = inWt;
}
double Weight::getWeightPounds() {
    return this->wtLb;
}
void Weight::setWeightKilograms(double inWt) {
    wtLb = inWt * 2.21;
}
double Weight::getWeightKilograms() {
    return wtLb / 2.21;
}
void Weight::setWeightOunces(double inWt) {
    wtLb = inWt /16;
}
double Weight::getWeightOunces() {
    return wtLb * 16;
}