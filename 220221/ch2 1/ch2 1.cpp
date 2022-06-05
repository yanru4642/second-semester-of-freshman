#include <iostream>
using namespace std;

int main(void){
    int floor;  //number of floors
    double basePrice;
    double amenityRate;
    double taxRate;
    double amenityCharge;
    double taxCharge;
    double totalCharge;

    cout << "Enter the stories of the building> ";
    cin >> floor;
    cout << "Enter the base price on the first floor> ";
    cin >> basePrice;
    cout << "Enter the rates of the charges on amenities> ";
    cin >> amenityRate;
    cout << "Enter the rates of the charges on taxes> ";
    cin >> taxRate;

    for (int i = 0; i < floor; i++){
        amenityCharge = basePrice * amenityRate;
        taxCharge = (basePrice + amenityCharge) * taxRate;
        totalCharge = basePrice + amenityCharge + taxCharge;
        cout << "Floor " << i + 1 << endl;
        cout << "Base price: " << basePrice << endl;
        cout << "Charges on amenity: " << amenityCharge << endl;
        cout << "Charges on tax: " << taxCharge << endl;
        cout << "Total price: " << totalCharge << endl;
        cout << "----------------" << endl;
        basePrice *= 1.02;
    }

    system("pause");
    return 0;
}