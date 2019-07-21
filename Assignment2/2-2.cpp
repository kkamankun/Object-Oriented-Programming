#include<iostream>

using namespace std;

int CMPandCAT(char*, char*, char*);

int main(void) {

	char src1[1000];
	char src2[1000];
	char copy_result[1000];

	cout << "Input string : "<<endl;
	cout << "src1 : "; cin >> src1; 
	cout << "src2 : "; cin >> src2;
	
	int return_value=CMPandCAT(src1, src2, copy_result);
	
	/*printing the result*/
	cout << "Output string : " << endl;
	cout << "return_value : "<< return_value << endl;
	int temp = 0;
	cout << "copy_result : ";
	while (copy_result[temp] != '\0') {
		cout << copy_result[temp];
		temp++;
	}
	cout << endl;

	system("pause");
	return 0;
}

int CMPandCAT(char*src1, char*src2, char*copy_result)
{
	int idx = 0;

	/*counting length of src1 and src2*/
	while (src1[idx] != '\0')
		idx++;
	int length_of_src1 = --idx;

	idx = 0;

	while (src2[idx] != '\0')
		idx++;
	int length_of_src2 = --idx;

	int lenght_of_copy_result = length_of_src1 + length_of_src2;
	idx = 0;

	/*comparing src1 and src2 and return and integer value*/
	while (src1[idx]!='\0' || src2[idx]!='\0') {
		if (src1[idx] < src2[idx])
		{
			for (int i = 0; i <= length_of_src2; i++)
				copy_result[i] = src2[i];
			int current = length_of_src2 + 1;
			for (int j = 0; j <= length_of_src1; j++)
				copy_result[current++] = src1[j];
			copy_result[(lenght_of_copy_result)+2] = '\0';
			return  -1;
		}
		else if (src1[idx] > src2[idx])
		{
			for (int i = 0; i <= length_of_src1; i++)
				copy_result[i] = src1[i];
			int current = length_of_src1+1;
			for (int j = 0; j <= length_of_src2; j++)
				copy_result[current++] = src2[j];
			copy_result[(lenght_of_copy_result) + 2] = '\0';
			return 1;
		}
		else if(src1[idx]==src2[idx])
			idx++;
	}

	/*copying src1 and src2 to copy_result*/
	for (int i = 0; i <= length_of_src1; i++)
		copy_result[i] = src1[i];
	int current = length_of_src1 + 1;
	for (int j = 0; j <= length_of_src2; j++)
		copy_result[current++] = src2[j];
	copy_result[(lenght_of_copy_result)+2] = '\0';
	return 0;

}