#include<iostream>
#include"instance.h"
#include<cmath>

using namespace std;

double CalcuDistance(int a,int b,int c,int d) // Calculate distance between human and monster
{
	return sqrt(pow(((c)-(a)), 2) + (pow(((d)-(b)), 2))); 
}

int main(void) {
	
	HumanList HL;
	MonsterList ML;

	for (int i = 0; i < 5; i++)
	{
		HL.insert(i);
		ML.insert(i);
	}
	
	int round = 1;
	
	while (1)
	{	
		/*HUMAN Turn*/
		//1) calculate distance 
		Human* HuCurr = HL.GetHead();
		Monster* MonCurr = ML.GetHead();
		Monster* MonTarget=NULL;
		double distance;
		
		while (HuCurr != NULL) //1~5
		{
			MonTarget = NULL;
			distance = 5000.0;
			MonCurr = ML.GetHead();
			while (MonCurr != NULL)// A~E
			{ 
				if (distance > CalcuDistance(HuCurr->GetRow(),HuCurr->GetColumn(),MonCurr->GetRow(),MonCurr->GetColumn())) //거리가 더 가까운 monster가 있다면
				{
					MonTarget = MonCurr;
					distance = CalcuDistance(HuCurr->GetRow(), HuCurr->GetColumn(), MonCurr->GetRow(), MonCurr->GetColumn());
				}
				else if (distance == CalcuDistance(HuCurr->GetRow(), HuCurr->GetColumn(), MonCurr->GetRow(), MonCurr->GetColumn())) //최소 거리가 같다면 인덱스를 비교해서 낮은 monster를 target
				{
					if (MonCurr->GetIndex() < MonTarget->GetIndex())
						MonTarget = MonCurr;
				}
				MonCurr = MonCurr->GetNext();
			}
			if (MonTarget != NULL)
			{
				HuCurr->action(MonTarget); // closest monster
			}
			else
			{
				break;
			}
			ML.DeleteDead(); // delete dead monster
			HuCurr = HuCurr->GetNext();
		}

		/*MONSTER Turn*/
		//1) calculate distance
		HuCurr = HL.GetHead();
		MonCurr = ML.GetHead();
		Human* HuTarget = NULL;

		while (MonCurr != NULL)
		{
			HuTarget = NULL;
			distance = 5000.0;
			HuCurr = HL.GetHead();
			while (HuCurr!=NULL)
			{
				if (distance > CalcuDistance(HuCurr->GetRow(), HuCurr->GetColumn(), MonCurr->GetRow(), MonCurr->GetColumn())) //거리가 더 가까운 monster가 있다면
				{
					HuTarget = HuCurr;
					distance = CalcuDistance(HuCurr->GetRow(), HuCurr->GetColumn(), MonCurr->GetRow(), MonCurr->GetColumn());
				}
				else if (distance == CalcuDistance(HuCurr->GetRow(), HuCurr->GetColumn(), MonCurr->GetRow(), MonCurr->GetColumn())) //최소 거리가 같다면 인덱스를 비교해서 낮은 monster를 target
				{
					if (MonCurr->GetIndex() < HuTarget->GetIndex())
						HuTarget = HuCurr;
				}
				HuCurr = HuCurr->GetNext();
			}
			if (HuTarget != NULL)
			{
				MonCurr->action(HuTarget); // closest human
			}
			else
			{
				break;
			}
			HL.DeleteDead();
			MonCurr = MonCurr->GetNext();
		}

		/*result screen*/
		cout << "###Result of round " << round << "###" << endl;
		if (HL.GetHead() != NULL && ML.GetHead() == NULL) //몬스터 패
		{
			cout << "<Human>" << endl;
			HL.displayList();
			cout << "<Monster>" << endl;
			
			cout << "#### Final result of battle ####" << endl;
			cout << "Monster has been defeated" << endl;
			break;
		}
		else if (HL.GetHead() == NULL && ML.GetHead() != NULL)//인간 패
		{
			cout << "<Human>" << endl;
			cout << "<Monster>" << endl;
			ML.displayList();

			cout << "#### Final result of battle ####" << endl;
			cout << "Human has been defeated" << endl;
			break;
		}
		else if (HL.GetHead() == NULL && ML.GetHead() == NULL)
		{
			cout << "<Human>" << endl;
			cout << "<Monster>" << endl;
			cout << "#### Final result of battle ####" << endl;
			cout << "draw" << endl;
			break;
		}
		else if (HL.GetHead() != NULL && ML.GetHead() != NULL)
		{
			cout << "<Human>" << endl;
			HL.displayList();
			cout << "<Monster>" << endl;
			ML.displayList();
			HL.displayDeathList(); // display dead human
			ML.displayDeathList(); // display dead monster
			
		}
		
		cout << endl;
		round++;
	}
	
	system("pause");
	return 0;
}