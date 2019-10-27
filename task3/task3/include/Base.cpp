#include "Base.h"

int Base::n = 1;

Base::Base() {
	id = n;
	n++;
}

Base::~Base() {

}

int Base::getId() {
	return id;
}
