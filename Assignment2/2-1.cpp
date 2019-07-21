#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

int main(void)
{
	/*read information from a file*/
	ifstream fin("flight_time.txt");
	vector<string> input_format;
	string s;
	if (!fin.is_open()) {
		cout << "failed file read" << endl;
		return 0;
	}

	cout << "flight_time.txt"<<endl;

	while (!fin.eof())
	{
		getline(fin,s);
		cout << s << endl;
		input_format.push_back(s);
	}
	fin.close();

	cout << "----------------------------" << endl;

	/*store the information of the destination and the flight time*/
	vector<pair<string, int>>data;
	for (int i = 0; i < input_format.size(); i++) {
		string temp_a;
		string temp_b;
		for (int j = 0; j < input_format[i].length(); j++) {
			
			if (97 <= input_format[i][j] && input_format[i][j] <= 122) {
				temp_a += input_format[i][j];
			}
			if (65 <= input_format[i][j] && input_format[i][j] <= 90) {
				temp_a += input_format[i][j];
			}
			if (48<=input_format[i][j]&&input_format[i][j]<=57)
			{
				temp_b += input_format[i][j];
			}
		}
		int temp_c;
		temp_c = stoi(temp_b);
	
		pair<string,int>p;
		p = make_pair(temp_a, temp_c);
		data.push_back(p);

	}
	
	/*for (int i = 0; i < data.size(); i++)
		cout << data[i].first <<' '<< data[i].second << endl;*/

	/*calculate the expected arrival date and time*/ 
	string departure_date; // ex) 2019/04/05
	string departure_time; // ex) 23:59
	string destination; // ex) Tokyo
	
	cout << "Input from users" << endl;
	cout << "Departure date:"; cin >> departure_date;
	cout << "Departure time:"; cin >> departure_time;
	cout << "Destination: "; cin >> destination;
	cout << endl;

		/*1)calculate the expected arrival date*/
	
		string temp;

		for (int i = 8; i <10; i++) {
			temp += departure_date[i];
		}

		int departure_date_new = stoi(temp);
		/*cout << departure_date_new << endl;*/

	

		/*2) calculate the expected arrival time*/
		int departure_minute;
		int departure_hour;
		string temp_a;

		for (int i = 0; i <= 1; i++)
			temp_a = temp_a + departure_time[i];

		departure_hour = stoi(temp_a);

		string temp_b;

		for (int j = 3; j <= 4; j++)
			temp_b = temp_b + departure_time[j];

		departure_minute = stoi(temp_b);

		/*cout << departure_hour << ' ' << departure_minute << endl;*/

		int time;

		for (int i = 0; i < data.size(); i++)
		{
			if (destination == data[i].first)
				time = data[i].second;
		}

		int hour = time / 60;
		int minute = time % 60;

		departure_hour += hour;
		int flag = 0;
		if (departure_hour > 24) {
			departure_hour -= 24;
			flag = 1;
		}

		departure_minute += minute;
		if (departure_minute >= 60) {
			departure_hour++;
			departure_minute -= 60;
		}

		if (flag == 1)
			departure_date_new++;

		/*print out result*/
		cout << "----------------------------" << endl;
		cout << "Departure date : " << departure_date << endl;
		cout << "Departure time : " << departure_time << endl;
		cout << "Destination : " << destination << endl;
		cout << "Arrival date : ";
		for (int i = 0; i < 9; i++) {
			cout << departure_date[i];
		}

		cout << departure_date_new << endl;

		cout << "Arrival time : ";
		cout.width(2); cout.fill('0');
		cout<< departure_hour << ':' << departure_minute << endl;

	/*wirte the result to a file*/
	ofstream out("output_file.txt");

	if (out.is_open()) {
		out << "Departure date : " << departure_date << endl;
		out << "Departure time : " << departure_time << endl;
		out << "Destination : " << destination << endl;
		out << "Arrival date : ";
		for (int i = 0; i < 9; i++) {
			out << departure_date[i];
		}

		out << departure_date_new << endl;

		out << "Arrival time : ";
		out.width(2); out.fill('0');
		out << departure_hour << ':' << departure_minute << endl;
	}

	out.close();

	system("pause");
	return 0;

}