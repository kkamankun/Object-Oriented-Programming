#pragma once
#ifndef _3_1_H1
#define _3_1_H1

#include<iostream>

using namespace std;

class Human
{
	friend class Monster;
	friend class HumanList;
private:
	int health;
	int power;
	int row;
	int column;
	int index;
	Human* prev;
	Human* next;
	
public:
	Human(int h, int po, int row, int col, int i, Human* p, Human* n)
		:health(h), power(po), row(row), column(col), index(i), prev(p), next(n) {}
	virtual void action(Monster*);
	Human* GetPrev() { return prev; }
	Human* GetNext() { return next; }
	int GetRow() { return row; }
	int GetColumn() { return column; }
	int GetIndex() { return index; }
	int GetPower() { return power; }
	int GetHealth() { return health; }
	void SetColumn(int col) { column = col; }
	void SetHealth(int h) { health = h; }
	void SetRow(int r) { row = r; }
};

class Monster
{
	friend class MonsterList;
private:
	int health = 20;
	int power = 7;
	int row;
	int column;
	char index;
	Monster* prev;
	Monster* next;

public:
	Monster(int row, int col, char i, Monster* p, Monster* n)
		:row(row), column(col), index(i), prev(p), next(n) {}
	void action(Human*);
	Monster* GetPrev() { return prev; }
	Monster* GetNext() { return next; }
	int GetRow() { return row; }
	int GetColumn() { return column; }
	char GetIndex() { return index; }
	int GetHealth() { return health; }
	void SetHealth(int h) { health = h; }

};

class HumanList
{
private:
	Human* Head;
	Human* Tail;
	int size;
	int deathlist[5];
	int i;
public:
	HumanList();
	~HumanList();
	void insert(int);
	void DeleteDead();
	void displayList();
	Human* GetHead() { return Head; }
	Human* GetTail() { return Tail; }
	int GetSize() { return size; }
	void setDeathList(int i, int idx) { deathlist[i] = idx;}
	void displayDeathList();
};

HumanList::HumanList()
{
	Head = NULL;
	size = 0;
	memset(deathlist, -1, sizeof(deathlist)); // initial state
	i = 0;
}

HumanList::~HumanList() {}

class Peasant : public Human
{
public:
	Peasant(int h, int po, int row, int col, int i, Human* p, Human* n) :
		Human(h, po, row, col, i, p, n) {}
};

class Sword : public Human
{
public:
	Sword(int h, int po, int row, int col, int i, Human* p, Human* n) :
		Human(h, po, row, col, i, p, n) {}
};

class Archer : public Human
{
	friend class Monster;
public:
	Archer(int h, int po, int row, int col, int i, Human* p, Human* n) :
		Human(h, po, row, col, i, p, n) {}
	void action(Monster*); // overriding

};

void Archer::action(Monster* MT)
{
	//attack if monster is in attack range
	Monster* t = MT;
	int hit = 0;
	if (t->GetColumn() <= GetColumn() + 2 && t->GetColumn() >= GetColumn() - 2)
	{
		t->SetHealth(t->GetHealth()-GetPower()); hit = 1; 
	}

	//move
	if (hit == 0)
	{
		if (t->GetColumn() == GetColumn())
		{
			if (t->GetRow() < GetRow())
			{
				SetRow(GetRow() - 1);
			}
			else if (t->GetRow() > GetRow())
			{
				SetRow(GetRow() + 1);
			}
		}
		else
		{
			if (t->GetColumn() > GetColumn())
			{
				SetColumn(GetColumn() + 1);  //cout << "move Hu" << endl;
			}
			else if (t->GetColumn() < GetColumn())
			{
				SetColumn(GetColumn() - 1);
			}
		}
	}
}

class Warlock : public Human
{
private:
	bool mana; 
public:
	Warlock(int h, int po, int row, int col, int i, Human* p, Human* n, bool b) :
		Human(h, po, row, col, i, p, n) {
		mana = b;
	}
	void action(Monster*);
};

void Warlock::action(Monster* t)
{
	int hit = 0;

	// warlock can attack per two turns
	if (mana == 1)
	{   // attack
		mana = 0;
	}
	else if (mana == 0)
	{
		// move
		mana = 1;
	}

	// move
	if (t->GetColumn() == GetColumn())
	{
		if (t->GetRow() < GetRow())
		{
			SetRow(GetRow() - 1);
		}
		else if (t->GetRow() > GetRow())
		{
			SetRow(GetRow() + 1);
		}
	}
	else
	{
		if (t->GetColumn() > GetColumn())
		{
			SetColumn(GetColumn() + 1);  
		}
		else if (t->GetColumn() < GetColumn())
		{
			SetColumn(GetColumn() - 1);
		}
	}
}

void HumanList::displayList()
{
	Human* curr = Head;
	while (curr != NULL)
	{
		cout << curr->index << endl;
		curr = curr->next;
	}
}


void HumanList::insert(int n)
{
	Human* prev = NULL;
	Human* curr = NULL;
	Human* NewHu = NULL;

	if (n == 0)
		NewHu = new Peasant(5, 5, 0, 0, 1, NULL, NULL);//peasant army
	else if(n==1)
		NewHu = new Sword(10, 10, 1, 0, 2, NULL, NULL);//sword master
	else if(n==2)
		NewHu = new Sword(10, 10, 2, 0, 3, NULL, NULL);//sword master
	else if(n==3)
		NewHu = new Archer(7, 10, 3, 0, 4, NULL, NULL);//archer
	else if(n==4)
		NewHu = new Warlock(3, 10, 4, 0, 5, NULL, NULL, 1);//warlock
	
	if (Head == NULL) // if list is empty
	{
		Head = NewHu;
		size++;
	}
	else
	{
		curr = Head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		NewHu->prev = curr;
		NewHu->next = NULL;
		curr->next = NewHu;
		size++;
		if (curr->next=NewHu)
		{
			Tail = NewHu;
		}
	}
}

void Human::action(Monster* t)
{
	/*1) if target is in the attack range, attack */
	int hit = 0;
	if (t->GetRow() == row)
	{
		if (t->GetColumn() == column + 1)
		{
			t->SetHealth(t->GetHealth()-power); hit = 1; 
		}
		else if (t->GetColumn() == column - 1)
		{
			t->SetHealth(t->GetHealth() - power); hit = 1;
		}
		else if (t->GetColumn() == column)
		{
			t->SetHealth(t->GetHealth() - power); hit = 1; 
		}
		
	}
	else if (t->GetColumn() == column)
	{
		if (t->GetRow() == row + 1)
		{
			t->SetHealth(t->GetHealth() - power); hit = 1;
		}
		else if (t->GetRow() == row - 1)
		{
			t->SetHealth(t->GetHealth() - power); hit = 1;
		}
	}

	/*if not, move */
	if (hit == 0)
	{
		if (t->GetColumn() == column)
		{
			if (t->GetRow() < row)
			{
				row = row - 1;
			}
			else if (t->GetRow() > row)
			{
				row = row + 1;
			}
		}
		else
		{
			if (t->GetColumn() > column)
			{
				column = column + 1; 
			}
			else if (t->GetColumn() < column)
			{
				column = column - 1;
			}
		}
	}

}

void HumanList::displayDeathList()
{
	/*print dead human */
	for (int i = 0; i < 5; i++)
	{
		if (deathlist[i] != -1)
		{
			cout << "Human " << deathlist[i] << " has died" << endl;
		}
	}
	i = 0;
	memset(deathlist, -1, sizeof(deathlist)); // reset
}

void HumanList::DeleteDead() // delete dead instance
{ 
	Human* curr = Head;

	if (size == 1)
	{
		if (curr->health <= 0)
		{
			Head = NULL;
			setDeathList(i, curr->GetIndex()); i++;
			delete curr;
			size--;
		}
	}
	else if (size > 1)
	{
		while (curr != NULL) 
		{
			if (curr->health <= 0)
			{
				if (curr == Head) //delete a node curr in the head
				{
					Head = curr->next;
					Head->prev = NULL;
					setDeathList(i, curr->GetIndex()); i++;
					delete curr; size--; break;
				}
				else if (curr == Tail) //delete a node curr in the tail
				{
					(curr->prev)->next = NULL;
					setDeathList(i, curr->GetIndex()); i++;
					delete curr; size--; break;
				}
				else //delete a node curr in the middle
				{
					(curr->prev)->next = curr->next;
					(curr->next)->prev = curr->prev;
					setDeathList(i, curr->GetIndex()); i++;
					delete curr; size--; break;
				}
			}
			curr = curr->next;
		}
	}
	else
		return;
	
}

class MonsterList
{
private:
	Monster* Head;
	Monster* Tail;
	int size;
	char deathlist[5];
	int i;
public:
	MonsterList();
	~MonsterList();
	void insert(int);
	void DeleteDead();
	void displayList();
	Monster* GetHead() { return Head; }
	Monster* GetTail() { return Tail; }
	int GetSize() { return size; }
	void setDeathList(int i, char idx) { deathlist[i] = idx; }
	void displayDeathList();
};

void MonsterList::displayDeathList()
{
	/*print dead monsters*/
	for (int i = 0; i < 5; i++)
	{
		if (deathlist[i] != '1')
		{
			cout << "Monster " << deathlist[i] << " has died" << endl;
		}
	}
	i = 0;
	memset(deathlist, '1', sizeof(deathlist)); // reset
}

MonsterList::MonsterList()
{
	Head = NULL;
	size = 0;
	memset(deathlist, '1', sizeof(deathlist));
	i = 0;
}

MonsterList::~MonsterList() {}

void MonsterList::insert(int n)
{
	Monster* prev = NULL;
	Monster* curr = NULL;
	Monster* NewMon = NULL;

	if (n == 0)
		NewMon = new Monster(0, 4, 'A', NULL, NULL);
	else if (n == 1)
		NewMon = new Monster(1, 4, 'B', NULL, NULL);
	else if (n == 2)
		NewMon = new Monster(2, 4, 'C', NULL, NULL);
	else if (n == 3)
		NewMon = new Monster(3, 4, 'D', NULL, NULL);
	else if (n == 4)
		NewMon = new Monster(4, 4, 'E', NULL, NULL);

	if (Head == NULL) // if list is empty
	{
		Head = Tail = NewMon;
		size++;
	}
	else
	{
		curr = Head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		NewMon->prev = curr;
		NewMon->next = NULL;
		curr->next = NewMon;
		size++;
		if (curr->next=NewMon)
		{
			Tail = NewMon;
		}
	}
}

void MonsterList::displayList()
{
	Monster* curr = Head;
	while (curr != NULL)
	{
		cout << curr->index << endl;
		curr = curr->next;
	}
}

void Monster::action(Human* t)
{
	/*1) if target is in the attack range, attack */
	int hit = 0;
	if (t->GetRow() == row)
	{
		if (t->GetColumn() == column + 1)
		{
			t->SetHealth(t->GetHealth() - power); hit = 1;
		}
		else if (t->GetColumn() == column - 1)
		{
			t->SetHealth(t->GetHealth() - power); hit = 1;
		}
		else if (t->GetColumn() == column)
		{
			t->SetHealth(t->GetHealth() - power); hit = 1;
		}
	}
	else if (t->GetColumn() == column)
	{
		if (t->GetRow() == row + 1)
		{
			t->SetHealth(t->GetHealth() - power); hit = 1;
		}
		else if (t->GetRow() == row - 1)
		{
			t->SetHealth(t->GetHealth() - power); hit = 1;
		}
	}
	else if (t->GetRow() == row + 1 && t->GetColumn() == column + 1 ||
		t->GetRow() == row + 1 && t->GetColumn() == column - 1||
		t->GetRow() == row - 1 && t->GetColumn() == column + 1||
		t->GetRow() == row - 1 && t->GetColumn() == column - 1)
	{
		t->SetHealth(t->GetHealth() - power); hit = 1;
	}

	/* if not, move*/
	if (hit == 0)
	{
		if (t->GetColumn() == column)
		{
			if (t->GetRow() < row)
			{
				row = row - 1;
			}
			else if (t->GetRow() > row)
			{
				row = row + 1;
			}
		}
		else
		{
			if (t->GetColumn() > column)
			{
				column = column + 1;  
			}
			else if (t->GetColumn() < column)
			{
				column = column - 1;
			}
		}
	}
}

void MonsterList::DeleteDead() // delete dead instance
{
	
	Monster* curr = Head;

	if (size == 1)
	{
		if (curr->health <= 0)
		{
			Head = NULL;
			setDeathList(i, curr->GetIndex()); i++;
			delete curr; size--;
		}
	}
	else if(size > 1)
	{
		while (curr!= NULL)
		{
			if (curr->health <= 0)
			{
				if (curr == Head) //delete a node curr in the head
				{
					Head = curr->next;
					Head->prev = NULL;
					setDeathList(i, curr->GetIndex()); i++;
					delete curr; size--; break;
				}
				else if (curr == Tail) //delete a node curr in the tail
				{
					(curr->prev)->next = NULL;
					setDeathList(i, curr->GetIndex()); i++;
					delete curr; size--; break;
				}
				else //delete a node curr in the middle
				{
					(curr->prev)->next = curr->next;
					(curr->next)->prev = curr->prev;
					setDeathList(i, curr->GetIndex()); i++;
					delete curr; size--; break;
				}
			}
		curr = curr->next;
		}
	}
	else
		return;
}
#endif

