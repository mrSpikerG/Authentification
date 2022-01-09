#pragma once
#include "c_User(server).h"
class c_UsersDB
{
private:
	c_User* users;
	size_t size;

	void deleteEndL(char* text) {
		for (int i = 0; i < strlen(text); i++) {
			if (text[i] == '\n') {
				text[i] = '\0';
			}
		}
	}
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

	c_User getById(int id) {
		return users[id];
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

	void removeById(int id) {
		if (id > this->size || id < 0) {
			return;
		}

		int j = 0;
		c_User* TEMP = new c_User[size + 1];
		for (int i = 0; i < size; i++) {
			if (i != id) {
				TEMP[j] = users[i];
				TEMP[j].setId(j);
				j++;
			}
		}
		delete[] users;
		this->users = TEMP;
		size--;
	}

	void removeByUser(c_User human) {
		for (int i = 0; i < size; i++) {
			if (_stricmp(users[i].getName().c_str(), human.getName().c_str()) == 0
				&& _stricmp(users[i].getFname().c_str(), human.getFname().c_str()) == 0
				&& users[i].getAge() == human.getAge()) {

				removeById(i);

			}
		}
	}

	void load() {

		FILE* pf;
		fopen_s(&pf, "DataBase.txt", "rt");

		if (pf) {

			int tempsize;
			fscanf_s(pf, "%i", &tempsize);
			for (int i = 0; i < tempsize; i++) {
				int id;
				int age;
				string name, fname;
				fscanf_s(pf, "\n%i %i\n", &id, &age);

				fgets((char*)name.c_str(), 256, pf);
				deleteEndL((char*)name.c_str());

				fscanf_s(pf, "\n");

				fgets((char*)fname.c_str(), 256, pf);
				deleteEndL((char*)fname.c_str());

				add(name, fname, age);
			}
		}
		else {
			cout << "\nNullPointerException: save";
		}
		fclose(pf);
	}
};

