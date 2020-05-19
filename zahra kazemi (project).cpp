// zahra kazemi (project).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<fstream>
#include<map>
using namespace std;
multimap <int, string> savedpatient;
class Person {

protected:
	string name, family, address, phone;
	int age;

public:

	Person() {}
	Person(string name, string family, string address, string phone, int age) {

		this->name = name;
		this->family = family;
		this->address = address;
		this->phone = phone;
		this->age = age;
	}
	void setName(string name) {
		this->name = name;
	}
	void setFamily(string family) {
		this->family = family;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setPhone(string phone) {
		this->phone = phone;
	}
	void setAge(int age) {
		this->age = age;
	}

	string getName() const {
		return name;
	}
	string getFamily()const {
		return family;
	}
	string getAddress()const {
		return address;
	}
	string getPhone()const {
		return phone;
	}
	int getAge()const {
		return age;
	}

	void report() const {

		cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << endl;

	}
};
class Patien:public Person
{
private:
	int codep;
	string bimari,namedoctor;
public:
	Patien() {}
	Patien(string name, string family, string address, string phone, int age, int codep, string bimari,string namedoctor) :Person(name, family, address, phone, age) {
		this->codep = codep;
		this->bimari = bimari;
		this->namedoctor = namedoctor;
	}
	void setCodep(int codep) {
		this->codep = codep;
	}
	void setbimari(string bimari) {
		this->bimari = bimari;
	}
	void setnamedoctor(string namedoctor) {
		this->namedoctor = namedoctor;
	}
	int getcodep()const {
		return codep;
	}
	string getbimari()const {
		return bimari;
	}
	string getnamedoctor()const {
		return namedoctor;
	}
	void report() const {

		cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4)<<bimari<<setw(4)<<codep<<setw(4)<< namedoctor <<endl;

	}
};
class Doctor :public Person {
private:
	int codedoctor;
	string takhasos;
public:
	Doctor() {}
	Doctor(string name, string family, string address, string phone, int age, int codedoctor, string takhasos) :Person(name, family, address, phone, age) {
		this->codedoctor = codedoctor;
		this->takhasos = takhasos;
	}
	void setcodedoctor(int codedoctor)
	{
		this->codedoctor = codedoctor;
	}
	void settakhasos(string takhasos) {
		this->takhasos = takhasos;
	}
	int getcodedoctor()const {
		return codedoctor;
	}
	string gettakhasos()const {
		return takhasos;
	}
	void report() const {

		cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << setw(4) << takhasos << setw(4) << codedoctor << endl;

	}
};
//##############################################################
//
//#########################  PATIEN  ###########################

vector <Patien> listp, listp2;
fstream outputfile;
void writest() {
	int codep,age;
	string name, family, address, phone,bimari,namedoctor;

	cout << "\n Enter the code of Patien: ";
	cin >> codep;
	cout << "\n Enter the name of Patien: ";
	cin >> name;
	cout << "\n Enter the family of Patien: ";
	cin >> family;
	cout << "\n Enter the address of Patien: ";
	cin >> address;
	cout << "\n Enter the phone of Patien: ";
	cin >> phone;
	cout << "\n Enter the bimari of Patien: ";
	cin >> bimari;
	cout << "\n Enter the namedoctor of Patien: ";
	cin >> namedoctor;
	cout << "\n Enter the age of Patien : ";
	cin >> age;
	listp.push_back(Patien( name, family, address, phone,age,codep, bimari, namedoctor));
	outputfile.open("Patien.csv", ios::app);
	outputfile << name + "," + family + "," + address + "," + bimari + "," + namedoctor + "," + to_string(codep) << endl;
	_getch();
}
void displayallpa() {

	system("cls");
	cout << "\n\n\t\tALL PATIEN RESULT \n\n";
	cout << "====================================================================================\n";
	cout << "Name       Family        Address    Phone      Bimari       Namedoctor         Codep  \n";
	cout << "====================================================================================\n";
	for (int i = 0; i < listp.size(); i++)
	{

		listp[i].report();
	}
	_getch();
}
void displayonepa(int codep) {

	system("cls");
	cout << "\n\n\t\tALL PATIEN RESULT \n\n";
	cout << "==============================================================================\n";
	cout << "Name       Family        Address     Phone     Bimari      codep   namedoctor " << endl;
	cout << "==============================================================================\n";

	for (int i = 0; i < listp.size(); i++)
	{
		if (listp[i].getcodep() == codep) {
			listp[i].report();
		}
	}
	_getch();
}
void modify(int codep) {
	string name, family, phone;
	int a;
	for (int i = 0; i < listp.size(); i++)
	{
		if (listp[i].getcodep() == codep) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. PHONE";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;
			switch (a)
			{
			case 1: cout << "Enter a name" << endl; cin >> name; listp[i].setName(name); break;
			case 2: cout << "Enter a family" << endl; cin >> family; listp[i].setFamily(family); break;
			case 3: cout << "Enter a phone" << endl; cin >> phone; listp[i].setPhone(phone); break;

			}

		}
	}

}
void deleteallpatien() {

	listp.clear();

}
void delete_patien(int codep) {

	for (int i = 0; i < listp.size(); i++) {

		if (listp[i].getcodep() != codep) {

			listp2.push_back(listp[i]);
		}
	}
	listp = listp2;
	vector<Patien>().swap(listp2);
}
multimap <int, string> getsavedpatien() {
	return savedpatient;
}

//##############################################################
//
//#########################  DOCTOR  ###########################
vector <Doctor> listdo, listdo2;
fstream outputfiledo;
void writedo() {

	int codedoctor,age;
	string name, family, address, phone,takhasose;

	cout << "\n Enter the codedoctor of Doctor: ";
	cin >> codedoctor;
	cout << "\n Enter the name of Doctor: ";
	cin >> name;
	cout << "\n Enter the family of Doctor: ";
	cin >> family;
	cout << "\n Enter the address of Doctor: ";
	cin >> address;
	cout << "\n Enter the phone of Doctor: ";
	cin >> phone;

	cout << "\n Enter the takhasose of Doctor: ";
	cin >> takhasose;
	cout << "\n Enter the age of Doctor: ";
	cin >> age;
	listdo.push_back(Doctor(name, family, address, phone, age, codedoctor, takhasose));
	outputfiledo.open("Doctor.csv", ios::app);
	outputfiledo << name + "," + family + "," + address + "," + to_string(age) + phone + ","
		+ to_string(codedoctor) + "," + takhasose << endl;
	_getch();
}
void displayallDoctor() {

	system("cls");
	cout << "\n\n\t\tALL Doctor RESULT \n\n";
	cout << "===========================================================================\n";
	cout << "Name       Family        Address   Phone   age   codedoctor    takhasose  " << endl;
	cout << "===========================================================================\n";
	for (int i = 0; i < listdo.size(); i++)
	{

		listdo[i].report();
	}
	_getch();
}
void displayoneDoctor(int codedoctor) {

	system("cls");
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
	cout << "==========================================================================\n";
	cout << "Name       Family        Address   Phone   age      codedoctor    takhasose  " << endl;
	cout << "===========================================================================\n";

	for (int i = 0; i < listdo.size(); i++)
	{
		if (listdo[i].getcodedoctor() == codedoctor) {
			listdo[i].report();
		}
	}
	_getch();
}
void modifyDoctor(int codedoctor) {
	string name, family, phone;
	int a;
	for (int i = 0; i < listdo.size(); i++)
	{
		if (listdo[i].getcodedoctor() == codedoctor) {
			cout << "\n\n\n\tSELECT MENU";
			cout << "\n\n\n\t1. NAME";
			cout << "\n\n\t2. FAMILY";
			cout << "\n\n\t3. PHONE";
			cout << "\n\n\n\tEnter Choice (1/2/3)? ";
			cin >> a;
			switch (a)
			{
			case 1: cout << "Enter a name" << endl; cin >> name; listdo[i].setName(name); break;
			case 2: cout << "Enter a family" << endl; cin >> family; listdo[i].setFamily(family); break;
			case 3: cout << "Enter a phone" << endl; cin >> phone; listdo[i].setPhone(phone); break;

			}

		}
	}

}
void deletealldo() {

	listdo.clear();

}
void delete_do(int codedoctor) {
	for (int i = 0; i < listdo.size(); i++) {

		if (listdo[i].getcodedoctor() != codedoctor) {
			listdo2.push_back(listdo[i]);
		}
	}

	listdo= listdo2;
	vector<Doctor>().swap(listdo2);
}
void printsavedpatien(int codep) {

	multimap<int, string> list = getsavedpatien();
	for (multimap<int, string> ::iterator it = list.begin(); it != list.end(); it++) {

		if (codep == it->first) {
			cout << it->second;
		}
	}
}
//##############################################################################
//
//###################################  MENU ####################################
void intro() {
	system("cls");
	cout << "\n\n\n\t\t  SYSTEM UNIVERSITY";
	cout << "\n\n\t\t  ADVANCED C++ PROJECT";
	cout << "\n\n\n\tMADE BY : ZAHRA KAZEMI";
	cout << "\n\tSCHOOL : QOM UNIVERSITY";
	cin.get();
	_getch();
}
void report_men() {

	int a, e, f, code;
	system("cls");
	cout << "\n\n\n\tREPORT MENU";
	cout << "\n\n\n\t1. REPORTS";
	cout << "\n\n\t2. Back to Main Menu";
	cout << "\n\n\n\tEnter Choice (1/2/3)? ";
	cin >> a;
	switch (a)
	{
	case 1:
	{	system("cls");
	cout << "\n\n\n\tREPORTs MENU";
	cout << "\n\n\t1. patien Reports";
	cout << "\n\n\t2.doctor Reports";
	cout << "\n\n\n\tEnter Choice (1/2)? ";
	cin >> e;
	switch (e)
	{
	case 1:
	{	system("cls");
	cout << "\n\n\n\tSELECT";
	cout << "\n\n\t1. All patien Report";
	cout << "\n\n\t2. patien Report";
	cout << "\n\n\n\tEnter Choice (1/2)? ";
	cin >> f;
	switch (f)
	{
	case 1:  displayallpa(); break;
	case 2: cout << "\n Enter the number of student: "; cin >> code;
		displayonepa(code); break;
	default:
		break;
	}

	break; }
	case 2:
	{	system("cls");
	cout << "\n\n\n\tSELECT";
	cout << "\n\n\t1. All doctor Report";
	cout << "\n\n\t2. doctor Report";
	cout << "\n\n\n\tEnter Choice (1/2)? ";
	cin >> f;
	switch (f)
	{
	case 1:  displayallDoctor(); break;
	case 2: cout << "\n Enter the number of teacher: "; cin >> code;
		displayoneDoctor(code); break;
	default:
		break;
	}

	break; }


	default:
		break;
	}


	break;

	}
	case 2:break;
	}
	_getch();
}
void entry_men()
{
	int a, num;
	char choice;
	system("cls");
	cout << "\n\n\n\tENTRY MENU";
	cout << "\n\n\t1.ENTRY MENU PATIONT";
	cout << "\n\n\t2.ENTRY MENU DOCTOR";
	cout << "\n\n\t3.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-3) ";

	cin >> a;
	switch (a)
	{
	case 1:
	{    system("cls");
	cout << "\n\n\n\tENTRY MENU PATIONT";
	cout << "\n\n\t1.CREATE PATIONT RECORD";
	cout << "\n\n\t2.MODIFY PATIONT RECORD";
	cout << "\n\n\t3.DELETE PATIONT RECORD";
	cout << "\n\n\t4.DELETE PATIONT RECORDS";
	cout << "\n\n\t5.SELECT COURSE";
	cout << "\n\n\t6.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-6) ";
	cin >> a;
	switch (a) {
	case 1:
		do {
			writest();
			cout << "\n patien record has been created";

			system("cls");
			cout << "Do you want to insert new record of patien? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2: cout << "\nEnter the number of patien " << endl;
		cin >> num; modify(num); break;
		break;
	case 3: cout << "\nEnter the number of patien " << endl;
		cin >> num; delete_patien(num); break;
		break;
	case 4:  deleteallpatien(); break;
	case 5: break;
	}
	break;
	}
	case 2:
	{   system("cls");
	cout << "\n\n\n\tENTRY MENU DOCTOR";
	cout << "\n\n\t1.CREATE DOCTOR RECORD";
	cout << "\n\n\t2.MODIFY DOCTOR RECORD";
	cout << "\n\n\t3.DELETE DOCTOR RECORD";
	cout << "\n\n\t4.DELETE DOCTOR RECORDS";
	cout << "\n\n\t5.BACK TO MAIN MENU";
	cout << "\n\n\tPlease Enter Your Choice (1-5) ";
	cin >> a;
	switch (a) {
	case 1:
		do {
			writedo();
			cout << "\n doctor record has been created";

			system("cls");
			cout << "Do you want to insert new record of doctor? Y|N";
			cin >> choice;
			system("cls");
		} while (choice == 'Y' || choice == 'y');
		break;
	case 2: cout << "\nEnter the number of doctor " << endl;
		cin >> num; modifyDoctor(num); break;
		break;
	case 3: cout << "\nEnter the number of doctor " << endl;
		cin >> num; delete_do(num); break;
		break;
	case 4:  deletealldo(); break;
	case 5: break;
	}

	break;
	}

	case 4:break;

	}
	_getch();
}
int main()
{
	int a;
	do {
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. REPORT MENU";
		cout << "\n\n\t02. ENTRY/EDIT MENU";
		cout << "\n\n\t03. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-3) ";
		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:report_men(); break;
		case 2:entry_men();
		case 3:break;
		}
	} while (a != 3);
	_getch();
	return 0;
}