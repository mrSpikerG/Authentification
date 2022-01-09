#include <iostream>
#include "c_usersDB(client).h"
using namespace std;

int main() {

	c_UsersDB* MYDB = new c_UsersDB();




	string name;
	cout << "Введите имя: ";
	getline(cin, name);

	string fname;
	cout << "Введите фамилию: ";
	getline(cin, fname);

	int age;
	cout << "Введите возраст: ";
	cin >> age;
	cin.ignore();
	MYDB->add(name, fname, age);

	cout << "Введите имя: ";
	getline(cin, name);

	cout << "Введите фамилию: ";
	getline(cin, fname);

	cout << "Введите возраст: ";
	cin >> age;
	cin.ignore();


	MYDB->add(name, fname, age);

	cout << *MYDB;
	MYDB->save();


}