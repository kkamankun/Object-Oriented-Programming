#include<iostream>
using namespace std;

int main(void) {
	int a, b, c;
	int x;
	int result;

	cout << "Enter the value of variable a, b, c:";
	cin >> a;
	cin >> b;
	cin >> c;

	/***********case 1***********/
	if (a > 0) {

		// 1) 30<x
		x = 30;
		result = (a*x*x) + (b*x) + c;
		cout << "minimum values(30<x):" << result << endl;
		// 2) x<-30
		x = -30;
		result = (a*x*x) + (b*x) + c;
		cout << "minimum values(x<-30):" << result << endl;
		// 3) -30<=x<=30
		x = -b / (2 * a);
		result = c - (b*b) / (4 * a);
		cout << "minimum values(-30<=x<=30):" << result << endl;



	}
	/***********case 2***********/
	else if (a < 0) {

		// 1) 30<x
		x = 30;
		result = (a*x*x) + (b*x) + c;
		cout << "maximum values(30<x):" << result << endl;

		// 2) x<-30
		x = -30;
		result = (a*x*x) + (b*x) + c;
		cout << "maximum values(x<-30):" << result << endl;

		// 3) -30<=x<=30
		x = -b / (2 * a);
		result = c - (b*b) / (4 * a);
		cout << "maximum values(-30<=x<=30):" << result << endl;

	}

	else {
		system("pause");
		return 0;
	}
}