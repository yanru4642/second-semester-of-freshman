#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class BoxOfProduce {
public:
    BoxOfProduce();
    void setItem0(string Item0Value);
    string getItem0() const;
    void setItem1(string Item1Value);
    string getItem1() const;
    void setItem2(string Item2Value);
    string getItem2() const;
    void output() const;
private:
    string item[3];
};

int main(void) {
    ifstream instream;
    instream.open("item list.txt");
    string freadItem[5];
    BoxOfProduce newBox;
    string itemList[3];//item in box
    int oldItem;//replaced item
    int newItem;//replacing item
    srand(time(NULL));
    //read file and store items into array
    for (int i = 0; i < 5; i++){
        getline(instream, freadItem[i]);
    }
    //randomly select 3 items
    for (int i = 0; i < 3; i++){
        itemList[i]=freadItem[rand()%5];
    }
    newBox.setItem0(itemList[0]);
    newBox.setItem1(itemList[1]);
    newBox.setItem2(itemList[2]);
    //select old item
    do{
        cout << "Select the item which would be replaced. Enter -1 if you want to escape." << endl;
        cout << "(Enter 0)  " << newBox.getItem0() << endl;
        cout << "(Enter 1)  " << newBox.getItem1() << endl;
        cout << "(Enter 2)  " << newBox.getItem2() << endl;
        cin >> oldItem;
        if (oldItem == -1) {
            break;
        }
        //select new item
        cout << "Select the new item that would replace old item. Enter -1 if you want to escape." << endl;
        for (int i = 0; i < 5; i++) {
            cout << "(Enter " << i << ")  " << freadItem[i] << endl;
        }
        cin >> newItem;
        if (newItem == -1) {
            break;
        }
        //replace item
        switch (oldItem) {
        case 0:
            newBox.setItem0(freadItem[newItem]);
            break;
        case 1:
            newBox.setItem1(freadItem[newItem]);
            break;
        case 2:
            newBox.setItem2(freadItem[newItem]);
            break;
        default:
            cout << "Error" << endl;
            break;
        }
    } while (true);

    newBox.output();


    system("pause");
    return 0;
}

BoxOfProduce::BoxOfProduce(){}
void BoxOfProduce::setItem0(string Item0Value) {
    item[0] = Item0Value;
}
string BoxOfProduce::getItem0() const {
    return item[0];
}
void BoxOfProduce::setItem1(string Item1Value) {
    item[1] = Item1Value;
}
string BoxOfProduce::getItem1() const {
    return item[1];
}
void BoxOfProduce::setItem2(string Item2Value) {
    item[2] = Item2Value;
}
string BoxOfProduce::getItem2() const {
    return item[2];
}
void BoxOfProduce::output() const {
    cout << "----- ITEMS IN THE BOX -----" << endl;
    for (int i = 0; i < 3; i++){
    cout << item[i] << endl;
    }
    cout << "----------------------------" << endl;
}