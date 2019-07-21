#include<iostream>
using namespace std;

class Elevator {
private:
	int floor;
	int total_up;
	int total_down;
	int total_time;
public:
	void Init() {
		floor = 1;
		total_up = 0;
		total_down = 0;
		total_time = 0;
	}
	int Up(int n) {
		total_up += n - floor;
			floor = n;
			cout << "It is on the " << n << " floor." << endl << endl;
		return n;
	}
	int Down(int n) {
		if ((floor - n) <= 0)
			cout << "You can't go down to " << n << " floor." << endl << endl;
		else {
			total_down += floor - n;
			floor = n;
			cout << "It is on the " << n << " floor." << endl << endl;
			return n;
		}
			
	}
	void ShowInfo() {
		total_time = (total_up + total_down)*0.5;
		cout << "Total up: " << total_up << endl;
		cout << "Total down: " << total_down << endl;
		cout << "Total time: " << total_time << 's'<< endl;
	}
};

int main(void) {
	Elevator el;
	el.Init();
	el.Up(7);
	el.Down(3);
	el.Down(5);
	el.Down(1);
	el.ShowInfo();
	return 0;
}
