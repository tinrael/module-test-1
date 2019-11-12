#include "include/Message.h"
#include "include/Reaction.h"
#include "include/Topic.h"
#include "include/User.h"

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>

using std::cout;
using std::find;
using std::string;
using std::size_t;

const size_t TOPICS_COUNT = 25;
const size_t USERS_COUNT = 100;
const size_t MAX_FRIENDS_COUNT = 20;
const size_t MESSAGES_COUNT = 200;

vector<Topic*> allTopics;
vector<User*> allUsers;

string generateString(size_t length) {
	string result = "";
	for (size_t i = 0; i < length; i++) {
		result += ('A' + rand() % 26);
	}
	return result;
}

vector<Topic*> getRandomTopics() {
	vector<Topic*> result;
	int index;
	Topic* currentTopic;

	for (int i = 3 + rand() % 8; i >= 0; i--) {
		index = rand() % allTopics.size();
		currentTopic = allTopics[index];
		if (find(result.begin(), result.end(), currentTopic) == result.end()) {
			result.push_back(currentTopic);
		}
	}

	return result;
}

User* createRandomUser() {
	return new User(generateString(3 + rand() % 4), 18 + rand() % 80, getRandomTopics());
}

void generateTopics() {
	for (size_t i = 0; i < TOPICS_COUNT; i++) {
		allTopics.push_back(new Topic(generateString(10)));
	}
}

void generateUsers() {
	for (size_t i = 0; i < USERS_COUNT; i++) {
		allUsers.push_back(createRandomUser());
	}
}

void addFriends() {
	int friendsAdded;
	int friendsCount;
	size_t index;
	User* newFriend;

	for (User* user : allUsers) {
		friendsAdded = 0;
		friendsCount = 1 + rand() % MAX_FRIENDS_COUNT;
		while (friendsAdded < friendsCount) {
			index = rand() % allUsers.size();
			newFriend = allUsers[index];
			if (newFriend != user && !user->isFriend(newFriend)) {
				user->addFriend(newFriend);
				friendsAdded++;
			}
		}
	}
}

void postMessages() {
	User* author;
	Message* message;
	ReactionType reactionType;
	string text;
	bool anybodyWasMentioned;

	for (int i = 0; i < MESSAGES_COUNT; i++) {
		author = allUsers[rand() % allUsers.size()];
		text = generateString(20);
		message = new Message(author->getFavoriteTopics(), author, text);
		author->postMessage(message);
		cout << author->getName() << " posts \"" << text << "\" and mentions ";
		anybodyWasMentioned = false;
		for (User* otherUser : author->getFriends()) {
			if (rand() % 10 == 0) {
				message->addMention(otherUser);
				if (anybodyWasMentioned) {
					cout << ", ";
				}
				cout << otherUser->getName();
				anybodyWasMentioned = true;
			}

			if (rand() % 5 == 0) {
				reactionType = DISLIKE;
			}
			else {
				reactionType = LIKE;
			}
			message->react(otherUser, reactionType);
		}
		if (!anybodyWasMentioned) {
			cout << "nobody";
		}
		cout << "\n";
		for (Reaction* reaction : message->getReactions()) {
			cout << " - " << reaction->user->getName() << " ";
			if (reaction->value > 0) {
				cout << "likes it\n";
			}
			else {
				cout << "dislikes it\n";
			}
		}
		cout << " - Rating summary is " << message->getRating() << "\n";
	}
}

int main() {
	generateTopics();
	generateUsers();
	addFriends();
	postMessages();

	for (User* user : allUsers) {
		delete user;
	}
	for (Topic* topic : allTopics) {
		delete topic;
	}
}