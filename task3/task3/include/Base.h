#pragma once
#include <vector>

using std::vector;

class Base {
public:
	const int NUMBER_OF_SUBOBJECTS = 2;
	Base* subObjects[2];
	Base();
	virtual ~Base() = 0;
	static int getS();
	int getN();
	virtual int changeS(int value) = 0;
	int baseChangeS(int value);
	static int predictS(const vector<Base*>& objects);

protected:
	static int nextN;
	static int S;
	int N;
};