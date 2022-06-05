#include <iostream>
using namespace std;

int main(){
	int temp;
	int capacity = 0;
	int* old_list_p = new int[capacity];
	int* new_list_p;
	while (true)
	{
		capacity++;
		new_list_p = new int[capacity];
		for (int i = 0; i < capacity-1; i++)
		{
			new_list_p[i] = old_list_p[i];
		}
		cout << "enter -1 to escape> ";
		cin >> temp;
		if (temp == -1) {
			break;
		}
		new_list_p[capacity - 1] = temp;
		delete[]old_list_p;
		old_list_p = new_list_p;

		for (int i = 0; i < capacity; i++){
			cout << *(old_list_p + i) << " ";
		}
		cout << endl;
	}
	


}