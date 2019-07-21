#include<iostream>
#include <cstdlib>
#include <ctime> //for time()
#include <iomanip>

using namespace std;

void transpose(int arr1[9][3], int arr2[3][9]);

int main(void) {

	srand((unsigned int)time(NULL)); //use the return value of time()

	int original[9][3];
	int transposed[3][9];

	/*generate the random values and initialize*/
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 3; j++) {
			original[i][j] = rand() % 65;
		}
	}

	transpose(original, transposed);

	/*output the original matrix*/
	cout << "<Original>" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 3; j++) {
			cout << setw(3) << original[i][j] << " ";
		}cout << endl;
	}

	cout << endl;

	/*output the transposed matrix*/
	cout << "<Transposed>" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			cout << setw(3) << transposed[i][j] << " ";
		}cout << endl;
	}

	system("pause");
	return 0;
}

void transpose(int arr1[9][3], int arr2[3][9]) {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 3; j++)
			arr2[j][i] = arr1[i][j];
}