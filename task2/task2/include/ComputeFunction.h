#pragma once
#include <cmath>
#include <utility>
#include <vector>

using std::pair;
using std::vector;

template<typename T>
int f(T x) {
	return 1642;
}

template<>
int f<double>(double d) {
	return (int)exp(1 / sin(d)) % 364;
}

template<>
int f<char*>(char* s) {
	int result = 0;

	char vowels[] = "AaEeIiOoUuYy";
	int size = sizeof(vowels) / sizeof(vowels[0]);
	
	int index = 0;
	while (s[index] != '\0') {
		for (int i = 0; i < size; i++) {
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
	return (int)pow(f<T>(p.first), f<U>(p.second));
}
