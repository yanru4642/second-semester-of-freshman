#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

int* SortList(const int* list,const int size);
void swap(int* a, int* b);

int main(){
	int* unsort_p;
	int* sorted_p;
	int size = 10;
	unsort_p = new int[size] {0};
	srand(time(NULL));

	cout << "unsort: ";
	for (int i = 0; i < size; i++)
	{
		*(unsort_p + i) = rand()%50;
		cout << unsort_p[i] << " ";
	}
	cout << endl;

	sorted_p = SortList(unsort_p,size);
	cout << "sorted: ";
	for (int i = 0; i < size; i++)
	{
		cout << sorted_p[i] << " ";
	}
}

int* SortList(const int* list, const int size) {
	int* sorted_p=new int[size];
	for (int i = 0; i < size; i++){
		sorted_p[i] = *(list + i);
	}
	for (int i = 0; i < size; i++)
	{
		int tempMinIdx = i;
		for (int j = i; j < size; j++)
		{
			if (sorted_p[tempMinIdx]>sorted_p[j])
			{
				tempMinIdx = j;
			}
		}

		swap(sorted_p[i], sorted_p[tempMinIdx]);

		/*cout << "sorted: ";
		for (int i = 0; i < size; i++)
		{
			cout << sorted_p[i] << " ";
		}
		cout << endl;*/
	}

	return sorted_p;
}
void swap(int* a, int* b) {
	int* temp ;
	temp = a;
	a = b;
	b = temp;
}