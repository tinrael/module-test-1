#pragma once

#include "User.h"
#include "Reaction.h"
#include "Topic.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Message {
private:
	vector<Topic*> topics;
	string text;
	User* author;
	int rating;
	Message* replyFor;
	vector<Reaction*> reactions;
	vector<User*> mentions;

public:
	Message(vector<Topic*> topics, User* author, string text, Message* replyFor = nullptr);
	virtual ~Message();

	void addMention(User* user);
	void addMentions(vector<User*> users);
	bool hasReacted(User* userToCheck);
	void react(User* user, ReactionType type);
	Message* repost(User* newAuthor);
	Message* repost(User* newAuthor, vector<User*> additionalMentions);
	
	vector<Reaction*> getReactions();
	int getRating();
};