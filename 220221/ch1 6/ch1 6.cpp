#include <iostream>
using namespace std;

int main(void){
    double dist;
    double time;
    double distFare;
    double timeFare;
    double totalFare;
    //show instructions and input
    cout << "CAB FAIR CALCULATOR\n"
        << "--------------------\n";
    cout << "Enter the travel distance(km)> ";
    cin >> dist;
    cout << "Enter the travel time(min)> ";
    cin >> time;
    //calculate distance fare
    if (dist <= 2) {
        distFare = 2;
    }else {
        distFare = 2;
        dist -= 2;
        if (dist<=6){
            distFare += 0.5 * dist;
        }else{
            distFare += 0.5 * 6;
            dist -= 6;
            distFare += 1 * dist;
        }
    }
    //calculate time fare
    timeFare = 0.2 * time;
    //total fare
    totalFare = distFare + timeFare;
    //output the result
    cout << "Fair: " << totalFare << " $" << endl;

    system("pause");
    return 0;
}
