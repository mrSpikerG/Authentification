#pragma once
#include "c_User(client).h"
class c_UsersDB
{
private:
	c_User* users;
	size_t size;
public:

	c_UsersDB()
	{
		this->size = 0;
	}

	c_User& operator[](int index) {
		return users[index];
	}

	friend ostream& operator<<(ostream& out, const c_UsersDB& myDB) {
		for (int i = 0; i < myDB.size; i++) {
			out << myDB.users[i];
		}
		return out;
	}

	void add(string name, string fname, int age) {
		c_User* TEMP = new c_User[size + 1];

		for (int i = 0; i < size; i++) {
			TEMP[i] = users[i];
		}

		TEMP[size] = c_User(name, fname, age, size);

		if (size != 0) {
			delete[] users;
		}

		users = new c_User[size + 1];
		this->users = TEMP;

		//delete[] TEMP;

		this->size++;
	}

	void save() {

		FILE* pf;
		fopen_s(&pf, "DataBase.txt", "wt");

		if (pf) {

			fprintf(pf, "%i", this->size);

			for (int i = 0; i < this->size; i++) {

				fprintf(pf, "\n%i %i\n", this->users[i].getId(), this->users[i].getAge());
				fputs(this->users[i].getName().c_str(), pf);
				fprintf(pf, "\n");
				fputs(this->users[i].getFname().c_str(), pf);
			}


		}
		else {
			cout << "\nNullPointerException: save";
		}
		fclose(pf);
	}


};

