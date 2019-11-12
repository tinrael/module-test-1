#include "User.h"

User::User(string name, int age, vector<Topic*> favoriteTopics) {
	this->name = name;
	this->age = age;
	this->favoriteTopics = favoriteTopics;
}

User::~User() {
	for (Message* message : this->messages) {
		delete message;
	}
}

bool User::isFriend(User* userToCheck) {
	for (User* currentUser : this->friends) {
		if (currentUser == userToCheck) {
			return true;
		}
	}
	return false;
}

void User::addFriend(User* newFriend) {
	if (this->isFriend(newFriend)) {
		return;
	}
	this->friends.push_back(newFriend);
}

void User::postMessage(Message* message) {
	this->messages.push_back(message);
}

vector<User*> User::getFriends() {
	return this->friends;
}

vector<Topic*> User::getFavoriteTopics() {
	return this->favoriteTopics;
}

string User::getName() {
	return name;
}

int User::getAge() {
	return age;
}