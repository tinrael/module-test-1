#pragma once

#include "Topic.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Message;

class User {
private:
	string name;
	int age;
	vector<User*> friends;
	vector<Message*> messages;
	vector<Topic*> favoriteTopics;

public:
	User(string name, int age, vector<Topic*> favoriteTopics);
	virtual ~User();

	bool isFriend(User* userToCheck);
	void addFriend(User* newFriend);
	void postMessage(Message* message);
	
	vector<User*> getFriends();
	vector<Topic*> getFavoriteTopics();
	string getName();
	int getAge();
};
