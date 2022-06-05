#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int rollDice(void);
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);


int main(void){
	int hTotScore = 0; //human Total Score
	int cTotScore = 0; //computer Total Score
	int round = 1;
	srand(time(NULL));

	do
	{
		cout << "--------------------------------" << endl;
		cout << "Round " << round++ << endl;
		cout << "Y O U R    SCORE: " << hTotScore << endl;
		cout << "COMPUTER'S SCORE: " << cTotScore << endl;
		hTotScore += humanTurn(hTotScore);
		if (hTotScore>=100){
			cout << "==============" << endl;
			cout << "You win." << endl;
			cout << "==============" << endl;
			break;
		}
		cTotScore += computerTurn(cTotScore);
		if (cTotScore >= 100) {
			cout << "==============" << endl;
			cout << "Computer wins." << endl;
			cout << "==============" << endl;
			break;
		}
	} while (true);
	system("pause");
	return 0;
}
int rollDice(void) {
	int dice = 0;
	dice = rand()%6+1;
	return dice;
}
int humanTurn(int humanTotalScore) {
	int point = 0;
	int dice;
	char rollOrHold;
	string buffer;
	cout << "\nYour turn:" << endl;
	do
	{
		dice = rollDice();
		cout << "Dice:" << dice;
		if (dice == 1) {
			cout << "\nIn this round, you get 0 point." << endl;
			return 0;
		}
		point += dice;
		cout << "  Point:" << point << endl;
		cout << "You want to roll or hold? (r/h)> ";
		do{
			getline(cin, buffer);
			rollOrHold = buffer[0];
			if (rollOrHold=='R'||rollOrHold=='r' || rollOrHold == 'H' || rollOrHold == 'h') {
				break;
			}
			cout << "Error. Enter again.";
		} while (true);
		if (rollOrHold == 'H' || rollOrHold == 'h') {
			cout << "In this round, you get " << point << " point(s)." << endl;
			return point;
		}
	} while (true);
	return -1;
}
int computerTurn(int computerTotalScore) {
	int point = 0;
	int dice;
	cout << "\nComputer's turn:" << endl;
	do{
		dice = rollDice();
		point += dice;
		if (dice==1){
			cout << "Computer gets 0 point in this round." << endl;
			return 0;
		}
		else if (point>=20){
			cout << "Computer gets " << point << " point(s) in this round." << endl;
			return point;
		}
	} while (true);
	return -1;
}