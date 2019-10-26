#pragma once
#include <cmath>

template<typename T>
int f(T x) {
	return 1642;
}

template<>
int f<double>(double d) {
	return (int)exp(1 / sin(d)) % 364;
}