#include <iostream>
#include <string>
using namespace std;


class pizza{
public:
	pizza(){}
	void setPizza();
	void outputDescription();
	double computePrice();
private:
	int type;//deep dish (0)  hand tossed (1)  pan (2)
	int size;//small (0)  medium (1)  large (2)
	int pepperoni;
	int cheese;
};

int main(void){
	pizza newPizza;//a new object called newPizza
	double price;//pizza price

	newPizza.setPizza();

	newPizza.outputDescription();

	price = newPizza.computePrice();
	if (price==-1){
		cout << "Error while computing prize." << endl;
	}else{
		cout << "\nPizza price: " << price <<"$\n" << endl;
	}

	system("pause");
	return 0;
}
void pizza::setPizza() {
	string buffer;
	//input pizza type
	cout << "Input the pizza's type>\ndeep dish (0)  hand tossed (1)  pan (2)> ";
	while (true){
		getline(cin,buffer);
		if (buffer=="deep dish"||buffer=="0"){
			type = 0;
			break;
		}else if (buffer == "hand tossed" || buffer == "1") {
			type = 1;
			break;
		}else if (buffer == "pan" || buffer == "2") {
			type = 2;
			break;
		}
		else{
			cout << "Invalid data, please enter again." << endl;
		}
	}
	//input pizza size
	cout << "\nInput the pizza's size>\nsmall (0)  medium (1)  large (2)> ";
	while (true) {
		getline(cin, buffer);
		if (buffer == "small" || buffer == "0") {
			size = 0;
			break;
		}
		else if (buffer == "medium" || buffer == "1") {
			size = 1;
			break;
		}
		else if (buffer == "large" || buffer == "2") {
			size = 2;
			break;
		}
		else {
			cout << "Invalid data, please enter again." << endl;
		}
	}
	//input number of pepperoni
	cout << "Input number of pepperoni> ";
	cin >> pepperoni;
	//input number of cheese
	cout << "Input number of pepperoni> ";
	cin >> cheese;
}
void pizza::outputDescription() {
	cout << "\n--------PIZZA INFO--------" << endl;
	cout << "Type: " << type << endl;
	cout << "Size: " << size << endl;
	cout << "Number of pepperoni: " << pepperoni << endl;
	cout << "Number of cheese: " << cheese << endl;
	cout << "--------------------------" << endl;
}
double pizza::computePrice() {
	double prize = 0;
	switch (size){
	case 0:
		prize = 10 + 2 * (pepperoni + cheese);
		break;
	case 1:
		prize = 14 + 2 * (pepperoni + cheese);
		break;
	case 2:
		prize = 17 + 2 * (pepperoni + cheese);
		break;
	default:
		prize = -1;
		break;
	}
	return prize;
}
