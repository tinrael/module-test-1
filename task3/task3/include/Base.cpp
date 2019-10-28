#include "Base.h"

int Base::nextN = 1;

Base::Base() {
	N = nextN;
	nextN++;
}

Base::~Base() {

}

int Base::getN() {
	return N;
}
