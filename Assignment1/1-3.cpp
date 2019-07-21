#include<iostream>
#include<string>
#include <algorithm>
#define row 2
using namespace std;

int stuInfo[2][6];

void PrintingAnArray(int col) {
	for (int j = 0; j < col; j++) {
		cout << stuInfo[0][j] << " "; //student ID
	}
	cout << endl;
	for (int j = 0; j < col; j++) {
		cout << stuInfo[1][j] << " "; //mathscore
	}
	cout << endl;
}

int main(void) {

	string F;
	int stuId, mathScore;
	int col = 0;

	while (1) {
		cout << "#Enter function:";
		cin >> F;

		/*program end condition*/
		if (F == "End")
			break;

		/*append function*/
		else if (F == "Append") {
			cin >> stuId; cin >> mathScore;

			stuInfo[0][col] = stuId;
			stuInfo[1][col] = mathScore;
			col++;

			PrintingAnArray(col);
		}

		/*search function*/
		else if (F == "Search") {
			cin >> stuId;

			for (int j = 0; j < col; j++) {
				if (stuInfo[0][j] == stuId) {
					cout << stuInfo[0][j] << endl; //student ID
					cout << stuInfo[1][j] << endl; //mathscore
				}
			}
		}

		/*sort function*/
		else if (F == "Sort") {
			string D;
			cin >> D;

			/*bubble sort*/
			if (D == "ID") {
				for (int i = 0; i < col - 1; i++) {
					for (int j = 0; j < col - 1 - i; j++)
						if (stuInfo[0][j] > stuInfo[0][j + 1]) {
							swap(stuInfo[0][j], stuInfo[0][j + 1]);
							swap(stuInfo[1][j], stuInfo[1][j + 1]);
						}
				}
			}
			/*bubble sort*/
			else if (D == "Score") {
				for (int i = 0; i < col - 1; i++) {
					for (int j = 0; j < col - 1 - i; j++)
						if (stuInfo[1][j] > stuInfo[1][j + 1]) {
							swap(stuInfo[0][j], stuInfo[0][j + 1]);
							swap(stuInfo[1][j], stuInfo[1][j + 1]);
						}
				}
			}

			PrintingAnArray(col);
		}

		/*delete function*/
		else if (F == "Delete") {
			cin >> stuId;
			int key;

			for (int j = 0; j < col; j++) {
				if (stuInfo[0][j] == stuId) {
					key = j;
				}
			}
			for (int j = 0; j < col - 1; j++) {
				stuInfo[0][key] = stuInfo[0][key + 1];
				stuInfo[1][key] = stuInfo[1][key + 1];
			}
			col--;

			PrintingAnArray(col);

		}

	}
	system("pause");
	return 0;
}

