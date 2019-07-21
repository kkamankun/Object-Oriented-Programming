#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main(void) {
	string input;

	cout << "Input:";
	getline(cin, input);

	int numofchars = input.length();

	/*Count the number of characters in a string*/
	for (unsigned int i = 0; i < input.length(); i++) {
		if (input.at(i) == ' ')
			numofchars--;
	}
	
	double cnt[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0 };

	/*count the number of each character*/
	for (int i = 0; i < input.length(); i++) {
		for (int j = 0; j < 26; j++) {
			if (input.at(i) == 65 + j || input.at(i) == 97 + j)
				cnt[j]++;
		}
	}

	char temp = 65; //temp='A'
	char temp2 = 97; //temp2='a'
	double result;

	/*output the result*/
	for (int i = 0; i < 26; i++) {
		if (cnt[i] > 0) {
			temp += i;
			temp2 += i;
			result = cnt[i] / numofchars; //calculate frequency
			cout << temp << "(" << temp2 << ")" << "  " <<
				fixed << setprecision(6) << result << endl;
			temp -= i;
			temp2 -= i;
		}

	}

	system("pause");
	return 0;
}
