#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HotDogStand {
public:
    HotDogStand();
    HotDogStand(string IDvalue, int hotDogSoldValue);
    void JustSold();
    string getID();
    int getHotDogSold();
    static int getTotalSold();
private:
    string ID;
    int hotDogSold;
    static int totalSold;
};

int main(void) {
    string inID; //input stand's ID
    int inHotDogSold; //input hot dog sold
    int isSold;//determine a hot dog is sold or not
    vector <HotDogStand> stand;
    HotDogStand temp;

    //stand 1
    for (int i = 0; i < 3; i++) {
        cout << "Enter the stand's ID and how many hot dogs are sold. ";
        cin >> inID >> inHotDogSold;
        temp = HotDogStand::HotDogStand(inID, inHotDogSold);
        stand.push_back(temp);
        do {
            cout << "Enter 1 if you sell a hot dog. Enter 0 to escape.";
            cin >> isSold;
            if (isSold == 1) {
                stand[i].JustSold();
            }
        } while (isSold);
        cout << "Stand " << stand[i].getID() << " sells " << stand[i].getHotDogSold() << " hot dog(s)." << endl;

    }
    //show all hot dogs sold
    cout << "-------------------------------------------------" << endl;
    cout << "Three hot dog stands sold " << HotDogStand::getTotalSold() << " hot dog(s) in total." << endl;

    system("pause");
    return 0;
}

HotDogStand::HotDogStand() {}

HotDogStand::HotDogStand(string IDvalue, int hotDogSoldValue) {
    ID = IDvalue;
    hotDogSold = hotDogSoldValue;
    totalSold += hotDogSoldValue;
}

void HotDogStand::JustSold() {
    hotDogSold += 1;
    totalSold++;
}

string HotDogStand::getID() {
    return ID;
}

int HotDogStand::getHotDogSold() {
    return hotDogSold;
}

int HotDogStand::totalSold = 0;
int HotDogStand::getTotalSold() {
    return totalSold;
}