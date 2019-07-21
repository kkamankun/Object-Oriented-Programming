#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

//open source code that sorts the words in ascending order
using namespace std;
namespace
{
	struct case_insensitive_less : public std::binary_function< char, char, bool >
	{
		bool operator () (char x, char y) const
		{
			return toupper(static_cast<unsigned char>(x)) <
				toupper(static_cast<unsigned char>(y));
		}
	};

	bool NoCaseLess(const string &a, const string &b)
	{
		return std::lexicographical_compare(a.begin(), a.end(),
			b.begin(), b.end(), case_insensitive_less());
	}
}

int main(void) {

	char buf_temp[20][20];
	vector <int> space;
	vector <string> word;
	ifstream fin("words.txt");

	/*reading a text file*/
	if (!fin.is_open()) {
		cout << "failed file read";
		return 0;
	}

	int row = 0;
	while (!fin.eof()) {
		fin.getline(buf_temp[row], sizeof(buf_temp));
		row++;
	}
	int element = row - 1;

	/*counting length of strings*/
	vector<int>length;
	for (int i = 0; i <= element; i++) {
		for (int j = 0; j < 20; j++) {
			if (buf_temp[i][j] == '\0')
				length.push_back(j + 1);
		}
	}

	/*gathering index information of words*/
	for (int i = 0; i <= element; i++) {
		space.push_back(0);
		for (int j = 0; j < length[i]; j++) {
			if (buf_temp[i][j] == ' ') {
				space.push_back(j - 1);
				space.push_back(j + 1);
			}
			if (buf_temp[i][j] == '\0')
				space.push_back(j - 1);
		}
	}
	/*cout << space.size() << endl;
	for (int i = 0; i < space.size(); i++)
		cout << space[i] << " ";
	cout << endl;*/

	row = 0;
	string temp;
	int check = 0;

	/*making words*/ 
	for (int i = 0; i < space.size(); i += 2) {
		temp = "";
		int start = space[i];
		if (start == 0 && check == 1)
			row++;
		int end = space[i + 1];
		for (int j = start; j <= end; j++)
			temp += buf_temp[row][j];
		check = 1;
		word.push_back(temp);
		/*cout << temp << " ";*/
	}

	cout << endl;

	/*sorting words in ascending order*/
	sort(word.begin(), word.end(), NoCaseLess);

	/*initializing original file and writing result*/
	ofstream outFile("words.txt",ios::trunc);
	for (int i = 0; i < word.size(); i++) {
		vector<char>output(word[i].begin(), word[i].end());
		output.push_back('\0');
		char* ptr = &output[0];
		outFile << ptr << endl;
		*ptr = NULL;
	}

	return 0;
}




	

		