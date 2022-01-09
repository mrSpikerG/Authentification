#pragma once
#include <iostream>
#include <string>
using namespace std;

class c_User
{

private:
	string name;
	string fname;
	int age;
	long id;

public:
	c_User()
	{
		/*	strcpy_s((char*)this->name.c_str(), 5, "Null");
			strcpy_s((char*)this->fname.c_str(), 5, "Null");
			this->age = -1;
			this->id = 0;*/
	}

	c_User(c_User& us)
	{

		strcpy_s((char*)this->name.c_str(), strlen(us.name.c_str()) + 1, us.name.c_str());
		strcpy_s((char*)this->fname.c_str(), strlen(us.fname.c_str()) + 1, us.fname.c_str());
		this->age = us.age;
		this->id = 0;
	}

	c_User(string name, string fname, int age, int id)
	{
		//this->name = name;
		//this->fname = fname;
		this->name.resize(strlen((char*)name.c_str()) );
		this->fname.resize(strlen((char*)fname.c_str()) );

		strcpy_s((char*)this->name.c_str(), strlen(name.c_str()) + 1, name.c_str());
		strcpy_s((char*)this->fname.c_str(), strlen(fname.c_str()) + 1, fname.c_str());
		this->age = age;
		this->id = id;
	}

	string getName() {
		return this->name;
	}
	void setName(string fname) {
		strcpy_s((char*)this->name.c_str(), strlen(name.c_str()) + 1, name.c_str());
	}

	string getFname() {
		return this->fname;
	}
	void setFname(string fname) {
		strcpy_s((char*)this->fname.c_str(), strlen(fname.c_str()) + 1, fname.c_str());
	}

	void setId(int id) {
		this->id = id;
	}
	long getId() {
		return this->id;
	}


	int getAge() {
		return this->age;
	}
	void setAge() {
		this->age = age;
	}

	friend ostream& operator<<(ostream& out, const c_User& user) {
		out << "\n" << user.id << ": " << user.name << "\t" << user.fname << "\tAge: " << user.age;
		return out;
	}

};

