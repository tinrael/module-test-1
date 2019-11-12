#pragma once

#include "User.h"

enum ReactionType { LIKE, DISLIKE };

class Reaction {
public:
	int value;
	User* user;

	Reaction(int value, User* user);
};
