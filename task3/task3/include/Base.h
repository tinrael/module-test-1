#pragma once

class Base {
public:
	Base();
	virtual ~Base() = 0;
	int getN();

protected:
	static int nextN;
	int N = 0;
};

