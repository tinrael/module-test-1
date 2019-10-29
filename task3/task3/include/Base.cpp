#include "Base.h"

int Base::nextN = 1;
int Base::S = 1;

Base::Base() {
	N = nextN;
	nextN++;
}

Base::~Base() {
	S = changeS(S);
}

int Base::getS() {
	return S;
}

int Base::getN() {
	return N;
}

int Base::changeS(int value) {
	return value / 2 - 2 * N + 22;
}
