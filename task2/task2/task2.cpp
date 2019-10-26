#include "include/ComputeFunction.h"
#include <iostream>
#include <utility>
#include <vector>

using std::cout;
using std::endl;

void printText(char* text) {
	int i = 0;
	while (text[i] != '\0') {
		cout << text[i];
		i++;
	}
}

int main()
{
	cout << "Every time function f() is called. Implementation differs due to type of the parameter." << endl;
	cout << "Here some examples of usage." << endl << endl;
	int n = 5;
	cout << "Input: " << n << " | Result: " << f(n) << endl;
	
	n = -2;
	cout << "Input: " << n << " | Result: " << f(n) << endl;
	
	double d = 2.3;
	cout << "Input: " << d << " | Result: " << f(d) << endl;
	
	char symbols[] = "ab#56bSh";
	cout << "Input: ";
	printText(symbols);
	cout << " | Result: " << f(symbols) << endl;
	
	pair<int, double> myPair(3, 2.3);
	cout << "Input: (" << myPair.first << ", " << myPair.second << ") | Result: " << f(&myPair)
		<< endl;

	vector<int> v;
	v.push_back(5);
	v.push_back(-3);
	v.push_back(7);
	v.push_back(2);
	cout << "Input: ";
	for (size_t i = 1; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << " | Result: " << f(v);
}
