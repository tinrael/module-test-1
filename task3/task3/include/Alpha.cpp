#include "Alpha.h"

Alpha::~Alpha() {
	S = changeS(S);
}

int Alpha::changeS(int value) {
	return value + 3 * N;
}
