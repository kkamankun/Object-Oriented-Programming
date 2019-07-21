#include<iostream>
#include"Çì´õ.h"

using namespace std;

int main(void)
{
	NeuList NL;

	/*Initial state(First state)*/
	for (int i = 1; i <= 9; i++)
	{
		NL.append(i);
	}
	
	/*State update*/
	NL.connbreak();
	
	/*Final state(Fourth state)*/
	NL.calcu();

	system("pause");
	return 0;
	
}