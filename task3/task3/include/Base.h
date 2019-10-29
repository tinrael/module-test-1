#pragma once

class Base {
public:
	Base();
	virtual ~Base() = 0;
	static int getS();
	int getN();
	virtual int changeS(int value);

protected:
	static int nextN;
	static int S;
	int N;
};

