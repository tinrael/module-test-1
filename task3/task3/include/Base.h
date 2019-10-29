#pragma once
#include <iostream>

using namespace std;

class Base {
public:
	Base();
	virtual ~Base() = 0;
	static int getS();
	int getN();

protected:
	static int nextN;
	static int S;
	int N;
};

