#pragma once

#include <string>

using std::string;

class Topic {
private:
	string name;

public:
	Topic(string name);
	virtual ~Topic();
};
