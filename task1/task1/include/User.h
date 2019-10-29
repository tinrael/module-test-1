#pragma once
#include <string>

using std::string;

class User {
private:
	string name;
	int age;
	User* friends[10];

public:
	User(string name, int age);
	virtual ~User();	
	string getName();
	int getAge();
};

