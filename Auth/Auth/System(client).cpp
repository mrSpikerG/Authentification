#include <iostream>
#include "c_usersDB(client).h"
using namespace std;

int main() {


	setlocale(LC_ALL, "");
	c_UsersDB* MYDB = new c_UsersDB();




	string name;
	cout << "¬ведите им€: ";
	getline(cin, name);

	string fname;
	cout << "¬ведите фамилию: ";
	getline(cin, fname);

	int age;
	cout << "¬ведите возраст: ";
	cin >> age;
	cin.ignore();
	MYDB->add(name, fname, age);

	cout << "¬ведите им€: ";
	getline(cin, name);

	cout << "¬ведите фамилию: ";
	getline(cin, fname);

	cout << "¬ведите возраст: ";
	cin >> age;
	cin.ignore();


	MYDB->add(name, fname, age);

	cout << *MYDB;
	MYDB->save();


}