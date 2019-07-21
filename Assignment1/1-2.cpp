#include<iostream>
using namespace std;

int main(void) {

	int balance = 20000;
	int distance = 0;
	int fare;

	cout << "Initial balance: 20000" << endl;

	while (1) {
		cout << "Entering each travel distance:";
		cin >> distance;
		cout << "--------------------------------" << endl;

		/*program end condition*/
		if (distance == -1)
		{
			cout << "Program exit" << endl;;
			break;
		}
		else if (distance < 4 || distance >178)
		{
			cout << "Current balance:" << balance << endl;
			break;
		}

		/*calculate fare*/
		if (distance <= 40 && distance >= 4)
			fare = 720;
		else if (distance > 40 && distance <= 178)
			fare = 720 + (distance - 40) / 8 * 80;
		
		cout << "Fare:" << fare << endl;

		/*display the balance remaining*/
		if (balance > fare) {
			balance = balance - fare;
			cout << "Current balance:" << balance << endl;
		}
		else { //program end condition
			cout << "Current balance:" << balance << endl; 
			break;
		}
	}
	system("pause");
	return 0;
}

