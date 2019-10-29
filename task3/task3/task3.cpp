#include "include/Alpha.h"
#include "include/Beta.h"
#include "include/Gamma.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Base* a = new Alpha();
	a->subObjects[0] = new Beta();
	a->subObjects[1] = new Gamma();
	Base* b = new Beta();
	Base* c = new Gamma();
	c->subObjects[0] = new Alpha();

	vector<Base*> objects{a, b, c};
	cout << "Predict S before deletion all objects: " << Base::predictS(objects) << endl;
	delete a;
	delete b;
	delete c;
	cout << "S after deletion: " << Base::getS() << endl;
}