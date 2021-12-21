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

	}

	c_User(string name, string fname, int age)
	{
		strcpy_s((char*)this->name.c_str(), strlen(name.c_str()) + 1, name.c_str());
		strcpy_s((char*)this->fname.c_str(), strlen(fname.c_str()) + 1, fname.c_str());
		this->age = age;
		this->id = 0;
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


	long getId() {
		return this->id;
	}
	void setId(long id) {
		this->id = id;
	}


	int getAge() {
		return this->age;
	}
	void setAge() {
		this->age = age;
	}



};

