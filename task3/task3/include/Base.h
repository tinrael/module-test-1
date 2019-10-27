#pragma once

class Base {
public:
	Base();
	virtual ~Base() = 0;
	int getId();

protected:
	static int n;
	int id = 0;
};

