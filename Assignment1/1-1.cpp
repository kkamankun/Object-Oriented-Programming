#include <iostream>
using namespace std;

void DrawAsterisk();
void DrawDiamond();

int main(void) {

	DrawAsterisk();
	
	DrawDiamond();

	system("pause");
	return 0;

}

void DrawAsterisk() {

	int size;

	cout << "Enter the size of asterisk:";
	cin >> size;

	int row, col;

	/*input value range and condition*/
	if (size >= 5 && size <= 29 && size % 2 == 1) {
		row, col = size;
		for (row = 0; row < size; row++) {
			for (col = 0; col < size; col++)
			{
				if (col == size / 2)
					cout << "$";
				else if (col == row)
					cout << "$";
				else if (col + row == size - 1)
					cout << "$";
				else
					cout << " ";
			}
			cout << endl;
		}
	}
}

void DrawDiamond() {

	int size;

	cout << "Enter the size of diamond:";
	cin >> size;

	int row;
	int colSpace, colStar;
	if (size >= 5 && size <= 29 && size % 2 == 1) {
		/*drawing upper triangle*/
		for (row = 0; row <= size / 2; row++) {
			/*loop for initially space, before '$' printing*/
			for (colSpace = size / 2 - row; colSpace >= 1; colSpace--) {
				cout << ' ';
			}
			/*print '$'*/
			for (colStar = 1; colStar <= 2 * row + 1; colStar++) {
				cout << '$';
			}
			cout << endl;
		}
		/*drawing lower triangle*/
		for (row = size / 2; row >= 1; row--) {
			for (colSpace = 0; colSpace <= size / 2 - row; colSpace++) {
				cout << ' ';
			}
			for (colStar = 1; colStar <= 2 * row - 1; colStar++) {
				cout << '$';
			}
			cout << endl;
		}
	}
}
