#include "User.h"

User::User(string name, int age) {
	this->name = name;
	this->age = age;
}

User::~User() {
}

string User::getName() {
	return name;
}

int User::getAge() {
	return age;
}


