#pragma once
#include<string>
#include <iostream>

using namespace std;

class CacheNode
{
	friend class CacheManager;
private:
	string Word;
	int Timestamp;
	CacheNode* NextNode;
};

class CacheManager
{
private:
	CacheNode *HeadNode;
	int listSize; // maximum listsize is 5
public:
	CacheManager();
	~CacheManager();
	void INPUT(string word,int timestamp);
	void INSERT(string word, int timestamp,int min);
	void Print();
	int FindMIN();
	int getlistSize();
};

CacheManager::CacheManager()
{
	HeadNode = NULL;
	listSize = 0;
}

CacheManager::~CacheManager() {};

int CacheManager::getlistSize() 
{
	return listSize;
}

void CacheManager::INPUT(string inputWord, int inputTimestamp)
{
	int state = 0;
	CacheNode*curr = NULL;
	CacheNode*prev = NULL;
	CacheNode*new_Node = new CacheNode;
	new_Node->Timestamp = inputTimestamp;
	new_Node->Word = inputWord;
	new_Node->NextNode = NULL;

	if (HeadNode == NULL)
	{
		cout << "Miss ";
		HeadNode = new_Node;
		listSize++;
	}
	else
	{
		curr = HeadNode;
		while (curr->NextNode != NULL)
		{
			string temp1 = curr->Word; 
			string temp2 = inputWord;

			/*changing all characters to lowercase*/
			for (int i = 0; i < temp1.size(); i++) {
				temp1[i] = tolower(temp1[i]);
			}
			for (int i = 0; i < temp2.size(); i++) {
				temp2[i] = tolower(temp2[i]);
			}

			if (temp1 == temp2)
			{
				state = 1;
				break;
			}
				curr = curr->NextNode;
		}
		if (state == 0) {
			cout << "Miss ";
			//if cache is full
			if(listSize>=5)
			{ 
				int min = FindMIN();
				curr = HeadNode;
				while (curr->NextNode != NULL)
				{
					if (curr->Timestamp == min)
					{
						if (curr == HeadNode)
						{
							HeadNode = new_Node;
							new_Node->NextNode = curr->NextNode;
						}
						else
						{
							prev->NextNode = new_Node;
							new_Node->NextNode = curr->NextNode;
							break;
						}
					}
					prev = curr;
					curr = curr->NextNode;
				}
			}
			//if cache is not full
			else
			{
				curr->NextNode = new_Node;
				listSize++;
			}
			
		}
		//if the same words as the word from input file exists in linked lists
		else if (state == 1) {
			cout << "Hit  ";
			curr->Timestamp = inputTimestamp;
		}
	}
}

void CacheManager::INSERT(string w, int ts, int min)
{
	CacheNode*curr = NULL;
	CacheNode*prev = NULL;
	CacheNode*new_Node = new CacheNode;
	new_Node->Timestamp = ts;
	new_Node->Word = w;
	new_Node->NextNode = NULL;

	curr = HeadNode;
	while (curr->NextNode != NULL)
	{
		if (curr->Timestamp == min)
		{
			cout << "Miss ";
			prev = curr;
			new_Node->NextNode = curr->NextNode;
			prev->NextNode = new_Node;
			
		}
		curr = curr->NextNode;

	}
}

void CacheManager::Print() {
	CacheNode * current = HeadNode;

	while (current != NULL) {
		cout << current->Word << ": " << current->Timestamp << " ";
		current = current->NextNode;
	}
	cout << endl;
}

//finds the smallest word in the timestamp.
int CacheManager::FindMIN()
{
	CacheNode* curr = HeadNode;
	int min = curr->Timestamp;
	if (HeadNode == NULL)
		return 0;
	while (curr->NextNode != NULL)
	{
		if (curr->Timestamp < min)
			min = curr->Timestamp;
		curr = curr->NextNode;
	}
	return min;
}
