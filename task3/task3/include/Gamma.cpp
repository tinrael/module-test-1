#include "Gamma.h"

Gamma::~Gamma() {
	S = changeS(S);
}

int Gamma::changeS(int value) {
	return value + N - 22;
}
