#include "Message.h"

Message::Message(vector<Topic*> topics, User* author, string text, Message* replyFor)
	: topics(topics), rating(0), author(author), text(text), replyFor(replyFor) {}

Message::~Message() {
	for (Reaction* reaction : this->reactions) {
		delete reaction;
	}
}

void Message::addMention(User* user) {
	this->mentions.push_back(user);
}

void Message::addMentions(vector<User*> users) {
	for (User* user : users) {
		this->addMention(user);
	}
}

bool Message::hasReacted(User* userToCheck) {
	for (Reaction* reaction : this->reactions) {
		if (reaction->user == userToCheck) {
			return true;
		}
	}

	return false;
}

void Message::react(User* user, ReactionType type) {
	if (this->hasReacted(user)) {
		return;
	}

	int reactionValue;
	if (type == LIKE) {
		reactionValue = 1;
	}
	else {
		reactionValue = -1;
	}
	this->reactions.push_back(new Reaction(reactionValue, user));
	this->rating += reactionValue;
}

Message* Message::repost(User* author) {
	return this->repost(author, vector<User*>());
}

Message* Message::repost(User* newAuthor, vector<User*> additionalMentions) {
	Message* result = new Message(this->topics, newAuthor, this->text);

	result->addMentions(this->mentions);
	result->addMentions(additionalMentions);

	return result;
}

vector<Reaction*> Message::getReactions() {
	return this->reactions;
}

int Message::getRating() {
	return this->rating;
}