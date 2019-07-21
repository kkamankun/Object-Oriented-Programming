#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "class.h"

using namespace std;

int main(void) {
	
	/*read words from the file*/
	ifstream in("Sentences.txt");
	string s;
	vector <string>v;
	char *str;
	while (!in.eof()) {
		getline(in, s);
		str = new char[s.size() + 1];
		strcpy(str, s.c_str());
	}

	/*seperate words by non-alphabet characters*/
	char *tok = strtok(str, " . , \0");
	while (tok != NULL) {
		string tmp(tok);
		v.push_back(tmp);
		tok = strtok(NULL, " . , \0");
	}

	CacheManager cm;
	int timestamp = 1;

	for (int i = 0; i < v.size(); i++) {
			cm.INPUT(v[i], timestamp++);
			cm.Print();
	}
	
}