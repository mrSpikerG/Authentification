#pragma once
#include "c_User(server).h"
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

	void load() {

		FILE* pf;
		fopen_s(&pf, "DataBase.txt", "rt");

		if (pf) {

			fscanf_s(pf, "%i", &this->size);

			for (int i = 0; i < this->size; i++) {

				int id,age;
				string name, fname;
				fscanf_s(pf, "\n%i %i\n", id, age);
				fgets((char*)name.c_str(), 256, pf);
				fscanf_s(pf,"\n");
				fgets((char*)fname.c_str(), 256, pf);
			}


		}
		else {
			cout << "\nNullPointerException: save";
		}
		fclose(pf);
	}


};

