#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollTwoDice(void);

int main(void){
	int dice;
	int point;
	int totalWin=0;
	int totalLoss=0;
	double odds;
	srand(time(NULL));
	for (int i = 0; i < 10000; i++){
		//initialize
		point = 0;
		//cout << "In game "<<setw(5)<< i + 1 << ", ";
		//come out roll
		dice = rollTwoDice();
		if (dice == 7 || dice == 11) {
			totalWin++;
			//cout << "you  win." << endl;
		}
		else if (dice == 2 || dice == 3 || dice == 12) {
			totalLoss++;
			//cout << "you loss." << endl;
		}
		else {
			//other rolls
			point = dice;
			while (true) {
				dice = rollTwoDice();
				if (dice == point) {
					totalWin++;
				//	cout << "you  win." << endl;
					break;
				}
				else if (dice == 7) {
					totalLoss++;
				//	cout << "you loss." << endl;
					break;
				}
			}
		}

	}
	//calculate the probability of winning
	odds = (double)totalWin / (totalWin + totalLoss);
	odds *= 100;

	cout << "==========TOTAL==========" << endl;
	cout << "Total wins:   " << totalWin << endl;
	cout << "Total losses: " << totalLoss << endl;
	cout << "Win rate: " << odds << "%" << endl;
	system("pause");
	return 0;
}

int rollTwoDice(void) {
	int dice1;
	int dice2;
	dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;
	return (dice1+dice2);
}