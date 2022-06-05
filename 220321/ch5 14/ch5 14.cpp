#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define NUM_OF_REVIEWER 4
#define NUM_OF_MOVIE 6

void fillUserTable(int userRate[],int numUsed[]);
int match(int userRate[],int numUsed[],int movieRateTable[][NUM_OF_MOVIE]);
int findMin(int arr[]);

int main(void){
	int movieRateTable[NUM_OF_REVIEWER][NUM_OF_MOVIE] =
	{{3,1,5,2,1,5},
	 {4,2,1,4,2,4},
	 {3,1,2,4,4,1},
	 {5,1,4,2,4,2}};
	int userRate[NUM_OF_MOVIE] = {0};
	int numUsed[3];
	int matchedReviewer;

	//fill in the user table
	fillUserTable(userRate, numUsed);
	//find the matchest reviewer
	matchedReviewer = match(userRate, numUsed, movieRateTable);
	//output the result
	cout << "----------------" << endl;
	cout << "The cloest match is reviewer " << matchedReviewer << "." << endl;
	cout << "Predict rating for another three movies: " << endl;
	for (int i = 0; i < NUM_OF_MOVIE; i++){
		if (i==numUsed[0]|| i == numUsed[1]||i == numUsed[2]){
			continue;
		}else{
			cout << "Movie " << i + 100 << ": " << movieRateTable[matchedReviewer][i]<<endl;
		}
	}

	system("pause");
	return 0;
}

void fillUserTable(int userRate[], int numUsed[]) {
	int movieNO;
	int rating;
	string buffer;
	for (int i = 0; i < 3; i++){
		//input movie NO
		cout << "(" << i + 1 << "/3)"<<endl;
		cout << "Enter movie NO. (100~105)> ";
		cin >> movieNO;
		// invalid input
		while (movieNO < 100 || movieNO>105){
			cout << "Invalid movie NO.. Enter again>";
			cin >> movieNO;
		}
		cout << "Enter movie " << movieNO << "'s rating (1~5)>";
		getline(cin, buffer);
		//input rating
		cin >> rating;
		// invalid input
		while (rating < 1 || rating>5) {
			cout << "Invalid rating score. Enter again>";
			cin >> rating;
		}
		getline(cin, buffer);

		//save the result
		movieNO -= 100;
		userRate[movieNO] = rating;
		numUsed[i] = movieNO;
	}
}
int match(int userRate[], int numUsed[], int movieRateTable[][NUM_OF_MOVIE]) {
	int distance[NUM_OF_REVIEWER];
	int matchedReviewer;
	double d[3];
	//calculate the distance
	for (int i = 0; i < NUM_OF_REVIEWER; i++){
		for (int j = 0; j < 3; j++){
			d[j]= userRate[numUsed[j]] - movieRateTable[i][numUsed[j]];
		}
		distance[i] = sqrt(pow(d[0],2) + pow(d[1],2) + pow(d[2],2));
	}
	//find the min value
	matchedReviewer = findMin(distance);
	return matchedReviewer;
}
int findMin(int arr[]) {
	int MinIdx = 0;
	for (int i = 0; i < NUM_OF_REVIEWER; i++){
		if (arr[MinIdx]>arr[i]){
			MinIdx = i;
		}
	}
	return MinIdx;
}