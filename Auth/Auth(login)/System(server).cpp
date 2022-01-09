#include <iostream>
#include "c_UsersDB(server).h"
using namespace std;

int main() {

	c_UsersDB* MYDB = new c_UsersDB();
	c_User* user = new c_User("Vasya","Petrov",14,0);

	MYDB->load();

	cout << *MYDB;

	MYDB->removeById(1);
	cout << "\n" << *MYDB;

	MYDB->removeByUser(*user);
	cout << "\n" << *MYDB;
}