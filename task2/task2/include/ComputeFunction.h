#pragma once
#include <cmath>
#include <utility>
#include <vector>

using std::pair;
using std::vector;
using std::size_t;

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1);
}

template<typename T>
int f(T x) {
	return 1642;
}

template<>
int f<int>(int n) {
	if (n >= 0) {
		return factorial(n) % 164;
	}
	return (int)pow(n, 3) % 264;
}

template<>
int f<double>(double d) {
	return (int)exp(1 / sin(d)) % 364;
}

template<>
int f<char*>(char* s) {
	int result = 0;

	char vowels[] = "AaEeIiOoUuYy";
	size_t size = sizeof(vowels) / sizeof(vowels[0]);

	int index = 0;
	while (s[index] != '\0') {
		for (size_t i = 0; i < size; i++) {
			if (s[index] == vowels[i]) {
				result++;
				break;
			}
		}
		index++;
	}
	return result;
}

template<typename T, typename U>
int f(pair<T, U> p) {
	return (int)pow(f(p.first), f(p.second));
}

template<typename T>
int f(vector<T>& v) {
	int result = 0;
	for (size_t i = 1; i < v.size(); i++) {
		result += f(v[i]) * f(v[i - 1]);
	}
	return result;
}