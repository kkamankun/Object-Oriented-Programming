#pragma once

class Namecard
{
private:
	char m_Name[10];
	char m_Phonenumber[15];
	char m_Address[20];
	int m_Age;
public:
	Namecard();
	~Namecard();
	void SetName(char*name);
	void SetPhonenumber(char*phonenumber);
	void SetAddress(char*address);
	void SetAge(int age);
	char* GetName();
	char* GetPhonenumber();
	char *GetAddress();
	int GetAge();

};