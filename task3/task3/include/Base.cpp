#include "Base.h"

int Base::nextN = 1;
int Base::S = 1;

Base::Base() {
	N = nextN;
	nextN++;
}

Base::~Base() {
	S = baseChangeS(S);
}

int Base::getS() {
	return S;
}

int Base::getN() {
	return N;
}

int Base::baseChangeS(int value) {
	return value / 2 - 2 * N + 22;
}

int Base::predictS(const vector<Base*>& objects) {
	int result = S;
	for (Base* object : objects) {
		result = object->changeS(result);
		result = object->baseChangeS(result);
	}
	return result;
}
