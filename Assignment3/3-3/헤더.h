#pragma once
#ifndef Header
#define Header
#include <string>
#include <ctime>

using namespace std;

class Neuron
{
	friend class NeuList;
private:
	int value;
	string op;
	Neuron* RightNeuron;
	Neuron* DownNeuron;
public:
	Neuron(int v, string o, Neuron* r, Neuron* d)
	{
		value = v;
		op = o;
		RightNeuron = r;
		DownNeuron = d;
	}
};

class NeuList
{
private:
	Neuron *HeadNeuron;
public:
	NeuList();
	~NeuList();
	void append(int n);
	void print();
	void connbreak();
	void calcu();
	int conv(int, string, int);
	char oper(string);
};

NeuList::NeuList()
{
	HeadNeuron = NULL;
}

NeuList::~NeuList() {}

// append Neuron at Neuron List
void NeuList::append(int n) 
{
	Neuron* NewNeu = NULL;
	Neuron* curr = NULL;
	if (n == 1)
		NewNeu = new Neuron(9, "add", NULL, NULL);
	else if (n == 2)
		NewNeu = new Neuron(0, "mul", NULL, NULL);
	else if (n == 3)
		NewNeu = new Neuron(6, "", NULL, NULL);
	else if (n == 4)
		NewNeu = new Neuron(5, "div", NULL, NULL);
	else if (n == 5)
		NewNeu = new Neuron(3, "sub", NULL, NULL);
	else if (n == 6)
		NewNeu = new Neuron(2, "", NULL, NULL);
	else if (n == 7)
		NewNeu = new Neuron(1, "add", NULL, NULL);
	else if (n == 8)
		NewNeu = new Neuron(7, "div", NULL, NULL);
	else if (n == 9)
		NewNeu = new Neuron(4, "", NULL, NULL);

	if (HeadNeuron == NULL) // if list is empty
		HeadNeuron = NewNeu;
	else
	{
		curr = HeadNeuron;
		if (n == 4)
		{
			curr->DownNeuron = NewNeu;
		
		}
		if (n == 7)
		{
			curr->DownNeuron->DownNeuron = NewNeu;
		}
		if (n > 4 && n < 7)
			curr = HeadNeuron->DownNeuron;
		else if (n > 7)
			curr = HeadNeuron->DownNeuron->DownNeuron;
		if(n!=4 && n!=7){
			while (curr->RightNeuron != NULL)
			{
				curr = curr->RightNeuron;
			}
			curr->RightNeuron = NewNeu;
		}
	}
}

// display Neuron List
void NeuList::print() 
{
	Neuron *curr = NULL;
	Neuron *tmp = NULL;;
	
	tmp = HeadNeuron;
	curr = tmp;

	while (tmp != NULL) {
		while (curr->RightNeuron != NULL) {
			cout << curr->value << endl;
			curr = curr->RightNeuron;
		}
		cout << endl;
		tmp = tmp->DownNeuron;
		curr = tmp;
	}
}

//break connection between neurons
void NeuList::connbreak() 
{	
	Neuron *curr = NULL;
	Neuron *tmp = NULL;
	srand(1);

	int state = 1;
	while (state != 4)
	{
		tmp = HeadNeuron;
		curr = tmp;
		int i = 0;
		while (tmp != NULL) {
			while (curr->RightNeuron != NULL) {
				int Connbreak = rand() % 10;
				if (Connbreak == 0) {
					curr->RightNeuron = NULL;
				}
				else
					curr = curr->RightNeuron;
			}
			tmp = tmp->DownNeuron;
			curr = tmp;
		}
		state++;
	}
}

//calculate and return result
int NeuList::conv(int v1, string o, int v2)
{
	int result;
	if (o == "add")
		return result = v1 + v2;
	else if (o == "sub")
		return result = v1 - v2;
	else if (o == "mul")
		return result = v1 * v2;
	else if (o == "div")
		return result = v1 / v2;
	else
		return 0;

}

char NeuList::oper(string o)
{
	if (o == "add")
		return '+';
	else if (o == "sub")
		return '-';
	else if (o == "mul")
		return '*';
	else if (o == "div")
		return '/';
	else
		return NULL;
}

//calculate final state
void NeuList::calcu() {
	Neuron *curr = HeadNeuron;
	Neuron* tmp = HeadNeuron;

	while (tmp != NULL)
	{
		cout << curr->value;
		while (curr->RightNeuron != NULL) {
			if (curr->RightNeuron != NULL) {
				cout << oper(curr->op) << curr->RightNeuron->value;
				curr->RightNeuron->value = conv(curr->value, curr->op, curr->RightNeuron->value);
				curr = curr->RightNeuron;
			}
		}
		cout << "=" << curr->value << endl;
		tmp = tmp->DownNeuron;
		curr = tmp;
	}
}

#endif