#include "Base.h"

int Base::nextN = 1;
int Base::S = 1;

Base::Base() {
	N = nextN;
	nextN++;
}

Base::~Base() {
	S = S / 2 - 2 * N + 22;
}

int Base::getS()
{
	return S;
}

int Base::getN() {
	return N;
}
