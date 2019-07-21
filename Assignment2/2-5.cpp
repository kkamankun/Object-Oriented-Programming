//An input should be separated by a space
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

struct oper {
	int p; 
	string o; 
};

stack<oper> op;
stack<int> operand; 

void calc(); //calculating arithmetic operations 

int main() {

	string input; cout << "Input: ";
	getline(cin, input);
	istringstream ss(input);

	// operation priority
	string str_tok;
	while (ss >> str_tok) {
		if (str_tok == "(") {
			op.push({ 0, str_tok });
		} 
		else if (str_tok == ")") {
			while (op.top().o != "(")
				calc();
			op.pop();
		}
		/*determining operation priority*/
		else if (str_tok == "*" || str_tok == "/" || str_tok == "+" || str_tok == "-") {
			int prior;
			if (str_tok == "*")
				prior = 2;
			else if (str_tok == "/")
				prior = 2;
			else if (str_tok == "+")
				prior = 1;
			else if (str_tok == "-")
				prior = 1;

			while (!op.empty() && prior <= op.top().p)
				calc();
			op.push({ prior, str_tok });
		}
		else 
			operand.push(stoi(str_tok));
	}
	while (!op.empty())
		calc();

	cout << "Output: ";
	cout << operand.top();

	return 0;
}

void calc()
{
	/*initializing operands*/
	int temp_a, temp_b, result;
	temp_b = operand.top();
	operand.pop();
	temp_a = operand.top();
	operand.pop();
	string oper = op.top().o;
	op.pop();

	if (oper == "*")
		result = temp_a * temp_b;
	else if (oper == "/") {
		result = temp_a / temp_b;
		if (temp_b == 0)
			cout << "no division by zero" << endl;
	}
	else if (oper == "+")
		result = temp_a + temp_b;
	else if (oper == "-")
		result = temp_a - temp_b;
	// save 'result' at 'num' stack
	operand.push(result);
}

