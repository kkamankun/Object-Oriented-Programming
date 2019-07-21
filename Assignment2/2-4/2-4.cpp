#include <iostream>
#include <cstring>
#include "Namecard.h"

using namespace std;

Namecard::Namecard()
{
	m_Name[10] = {0};
	m_Phonenumber[15] = { 0 };
	m_Address[20] = { 0 };
	m_Age = 0;
}

Namecard::~Namecard()
{
	m_Name[10] = { 0 };
	m_Phonenumber[15] = { 0 };
	m_Address[20] = { 0 };
	m_Age = 0;
}

void Namecard::SetName(char*name)
{
	strcpy(m_Name, name);
}

void Namecard::SetPhonenumber(char*phonenumber)
{
	strcpy(m_Phonenumber,phonenumber);
}

void Namecard::SetAddress(char*address)
{
	strcpy(m_Address,address);
}

void Namecard::SetAge(int age)
{
	m_Age = age;
}

char* Namecard::GetName()
{
	return m_Name;
}

char* Namecard::GetPhonenumber()
{
	return m_Phonenumber;
}

char* Namecard::GetAddress()
{
	return m_Address;
}

int Namecard::GetAge()
{
	return m_Age;
}

int main(void) {

	/*1) Student_A*/
	Namecard Student_A;
	Student_A.SetName("Son");
	Student_A.SetPhonenumber("01012341512");
	Student_A.SetAddress("seoul");
	Student_A.SetAge(24);

	cout << "Student_A Name: " << Student_A.GetName() << endl;
	cout << "Student_A Phonenumber: " << Student_A.GetPhonenumber() << endl;
	cout << "Student_A Address: " << Student_A.GetAddress() << endl;
	cout << "Student_A Age: " << Student_A.GetAge() << endl;
	cout << "-------------------------------------" << endl;

	/*2) Student_B*/
	Namecard Student_B;
	Student_B.SetName("Hazard");
	Student_B.SetPhonenumber("01012417135");
	Student_B.SetAddress("America");
	Student_B.SetAge(2);

	cout << "Student_B Name: " << Student_B.GetName() << endl;
	cout << "Student_B Phonenumber: " << Student_B.GetPhonenumber() << endl;
	cout << "Student_B Address: " << Student_B.GetAddress() << endl;
	cout << "Student_B Age: " << Student_B.GetAge() << endl;
	cout << "-------------------------------------" << endl;

	/*3) Student_C*/
	Namecard Student_C;
	Student_C.SetName("Messi");
	Student_C.SetPhonenumber("0161239135");
	Student_C.SetAddress("Japan");
	Student_C.SetAge(29);

	cout << "Student_C Name: " << Student_C.GetName() << endl;
	cout << "Student_C Phonenumber: " << Student_C.GetPhonenumber() << endl;
	cout << "Student_C Address: " << Student_C.GetAddress() << endl;
	cout << "Student_C Age: " << Student_C.GetAge() << endl;
	cout << "-------------------------------------" << endl;

	/*4) Student_D*/
	Namecard Student_D;
	Student_D.SetName("Drogba");
	Student_D.SetPhonenumber("021239135");
	Student_D.SetAddress("Hongdae");
	Student_D.SetAge(40);

	cout << "Student_D Name: " << Student_D.GetName() << endl;
	cout << "Student_D Phonenumber: " << Student_D.GetPhonenumber() << endl;
	cout << "Student_D Address: " << Student_D.GetAddress() << endl;
	cout << "Student_D Age: " << Student_D.GetAge() << endl;
	cout << "-------------------------------------" << endl;

	/*5) Student_E*/
	Namecard Student_E;
	Student_E.SetName("Kane");
	Student_E.SetPhonenumber("031231135");
	Student_E.SetAddress("Songpa");
	Student_E.SetAge(72);

	cout << "Student_E Name: " << Student_E.GetName() << endl;
	cout << "Student_E Phonenumber: " << Student_E.GetPhonenumber() << endl;
	cout << "Student_E Address: " << Student_E.GetAddress() << endl;
	cout << "Student_E Age: " << Student_E.GetAge() << endl;
	cout << "-------------------------------------" << endl;

}
