#pragma once
#include <vector>

using std::vector;

class Base {
public:
	const int NUMBER_OF_SUBOBJECTS = 2;
	Base* subObjects[2];
	
	Base();
	virtual ~Base() = 0;
	
	virtual int changeS(int value) = 0;
	int baseChangeS(int value);

	int getN();

	static int getS();
	static int predictS(const vector<Base*>& objects);
	static int predictSingeObjectS(Base* object, int value);

protected:
	static int nextN;
	static int S;
	int N;
};