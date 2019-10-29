#include "Beta.h"

Beta::~Beta() {
	S = changeS(S);
}

int Beta::changeS(int value) {
	return value - 2 * N;
}
