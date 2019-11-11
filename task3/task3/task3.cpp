#include "include/Alpha.h"
#include "include/Beta.h"
#include "include/Gamma.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	Base* a = new Alpha();
	a->subObjects[0] = new Beta();
	a->subObjects[1] = new Gamma();
	a->subObjects[1]->subObjects[0] = new Alpha();
	
	Base* b = new Beta();
	
	Base* c = new Gamma();
	c->subObjects[0] = new Alpha();
	c->subObjects[0]->subObjects[0] = new Gamma();
	c->subObjects[0]->subObjects[1] = new Beta();

	vector<Base*> objects{a, b, c};
	cout << "Predict S before deletion all objects: " << Base::predictS(objects) << endl;
	delete a;
	delete b;
	delete c;
	cout << "S after deletion: " << Base::getS() << endl;
}