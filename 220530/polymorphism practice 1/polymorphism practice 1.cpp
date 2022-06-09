#include <iostream>
using namespace std;

class Animal {
public:
	virtual void speak() = 0;
};
class Cat :public Animal {
public:
	int getCatAge() { return 2; }
	void speak() {
		cout << "Cat speaking~" << endl;
	}
};
class Dog :public Animal {
public:
	int getDogAge() { return 5; }
	void speak() {
		cout << "Dog speaking~" << endl;
	}
};

void doSpeak(Animal* pAnimail) {
	pAnimail->speak();
	if (Cat* pCat = dynamic_cast<Cat*>(pAnimail)) {
		cout << "Cat's age: " << pCat->getCatAge() << endl;
	}
	if (Dog* pDog = dynamic_cast<Dog*>(pAnimail)) {
		cout << "Dog's age: " << pDog->getDogAge() << endl;
	}
}

int main() {
	Cat cat;
	doSpeak(&cat);
	Dog dog;
	doSpeak(&dog);
}