#include "include/Alpha.h"
#include "include/Beta.h"
#include "include/Gamma.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Base* a = new Alpha();
	Base* b = new Beta();
	Base* c = new Gamma();
	Base* d = new Alpha();
	vector<Base*> objects{a, b, c, d};
	cout << "Predict S before deletion: " << Base::predictS(objects) << endl;
	delete a;
	delete b;
	delete c;
	delete d;
	cout << "S after deletion all objects: " << Base::getS() << endl;
}