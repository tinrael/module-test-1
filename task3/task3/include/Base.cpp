#include "Base.h"

int Base::nextN = 1;
int Base::S = 1;

Base::Base() : subObjects(){
	N = nextN;
	nextN++;
}

Base::~Base() {
	for (int i = 0; i < NUMBER_OF_SUBOBJECTS; i++) {
		delete subObjects[i];
	}
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
		for (int i = 0; i < object->NUMBER_OF_SUBOBJECTS; i++) {
			if (object->subObjects[i] != nullptr) {
				result = object->subObjects[i]->changeS(result);
				result = object->subObjects[i]->baseChangeS(result);
			}
		}
		result = object->baseChangeS(result);
	}
	return result;
}
