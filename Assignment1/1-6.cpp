#include<iostream>
#include <string.h> // memset 함수 사용을 위해 include 
#include <math.h>

using namespace std;

int main(void) {
	int num;
	cin >> num;
	int row = num; int col = 6;

	/* memory allocation */
	int **arr = new int*[row];
	for (int i = 0; i < row; ++i) {
		arr[i] = new int[col];
		memset(arr[i], 0, sizeof(int)*col);
	}

	/*arr initialization*/
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
		}
	}

	/*caculate distance between two points A, B*/
	for (int i = 0; i < num; i++) {
		int a, b;
		double c;
		a = pow(arr[i][0] - arr[i][3], 2);
		b = pow(arr[i][1] - arr[i][4], 2);
		c = sqrt(a + b);

		double d;
		d = arr[i][2] + arr[i][5];

		/*calculate the number of coordinates at which point C can be located*/
		if (arr[i][0] == arr[i][3] && arr[i][3] == arr[i][1]
		&& arr[i][1] == arr[i][4] && arr[i][2] == arr[i][5])
		cout << "-1" << endl;
		else if (c > d)
			cout << "0" << endl;
		else if (c == d)
			cout << "1" << endl;
		else if (c < d)
			cout << "2" << endl;
	}

	/* memory deallocation */
	for (int i = 0; i < row; ++i) {
		delete[] arr[i];
	} delete[] arr;

	system("pause");
	return 0;
}



