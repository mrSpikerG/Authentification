#include <iostream>
#include "c_usersDB(client).h"
using namespace std;

int main() {


	setlocale(LC_ALL, "");
	c_UsersDB* MYDB = new c_UsersDB();




	string name;
	cout << "������� ���: ";
	getline(cin, name);

	string fname;
	cout << "������� �������: ";
	getline(cin, fname);

	int age;
	cout << "������� �������: ";
	cin >> age;
	cin.ignore();
	MYDB->add(name, fname, age);

	cout << "������� ���: ";
	getline(cin, name);

	cout << "������� �������: ";
	getline(cin, fname);

	cout << "������� �������: ";
	cin >> age;
	cin.ignore();


	MYDB->add(name, fname, age);

	cout << *MYDB;
	MYDB->save();


}