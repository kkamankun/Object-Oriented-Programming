#include<iostream>
#include <iomanip>

using namespace std;

int main(void) {

	int size;

	cout << "Enter the size of Magic Square:";
	cin >> size;

	if (size >= 3 && size <= 15 && size % 2 == 1) {

		/*memory allocation*/
		int **ar = new int*[size];
		for (int i = 0; i < size; i++)
			ar[i] = new int[size];

		/*Making Magic Square algorithm*/
		for (int i = 0, j = size / 2, num = 1; num <= size * size; num++) {
			ar[i][j] = num;
			if (num%size == 0) {
				i++;
			}
			else {
				i--, j++;
				if (i < 0)
					i = size - 1;
				if (j > (size - 1))
					j = 0;
			}
		}

		/*output the Magic Square*/
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << setw(4) << ar[i][j];
			}
			cout << endl;
		}

		/*memory deallocation*/
		for (int i = 0; i < size; ++i) {
			delete ar[i];
		}delete ar;
	}

	system("pause");
	return 0;
}
