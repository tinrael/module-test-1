#include "Message.h"

Message::Message(Theme* theme, User* author, char* text) 
	: rating(0), author(author), text(text) {
	addTheme(theme);
}

Message::Message(vector<Theme*> themes, User* author, char* text) 
	: rating(0), author(author), text(text) {
	this->themes = themes;
}

Message::~Message() {
	delete text;
}

void Message::addTheme(Theme* theme) {
	this->themes.push_back(theme);
}
