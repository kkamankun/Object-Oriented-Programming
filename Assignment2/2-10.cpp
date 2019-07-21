#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char* argv[]) {

	string s;
	int num1 = 0; int num2 = 0;
	vector<string> file1;
	vector<string> file2;
	ifstream fin1(argv[1]);
	while (!fin1.eof()) {
		getline(fin1, s);
		file1.push_back(s);
		num1++;
	}
	ifstream fin2(argv[2]);
	while (!fin2.eof()) {
		getline(fin2, s);
		file2.push_back(s);
		num2++;
	}
	int same = 0;
	if (num1 == num2)
		for (int i = 0; i < num1; i++)
			if (file1[i] == file1[2])
				same++;
	if (same == num1)
		cout << "The two files are same." << endl;
	else
		cout << "The two files are different." << endl;

	system("pause");
	return 0;
}