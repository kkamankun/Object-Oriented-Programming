#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	ifstream in("numbers.txt");

	string s;
	vector <int>input;
	int temp;

	/*reading the number of the file*/
	if (!in.is_open())
		cout << "File open failure";
	while(!in.eof()) {
		getline(in, s);
		temp = stoi(s);
		input.push_back(temp);
	}

	int sum;
	int a = 0;
	while (1) {
		sum = 0;

		/*peforming the addition*/
		if (a + 3 > input.size())
			break;
		else {
			/*writing the result to the end*/
			sum += input[a] + input[a + 1] + input[a + 2];
			input.push_back(sum);
			a += 2;
		}
	}

	/*outputing the results*/
	ofstream out("result.txt");
	for (int i = 0; i < input.size(); i++)
		out << input[i] << endl;

	system("pause");
	return 0;
}