#pragma once

#include <vector>
#include "User.h"
#include "Theme.h"

using std::vector;

class Message {
private:
	vector<Theme*> themes;
	char* text;
	User* author;
	int rating;

public:
	Message(Theme* theme, User* author, char* text);
	Message(vector<Theme*> themes, User* author, char* text);
	virtual ~Message();

	void addTheme(Theme* theme);
};

