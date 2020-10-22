#pragma once
#include "lzwCompressor.hpp"
#include <cstring>

bool AutoTest() {
	lzwCompressor a1;
	char* a = new char[6];
	a1.decode(a, 6, a1.encode("ababa", 6));
	if (strcmp(a, "ababa") != 0) {
		delete[] a;
		return false;
	}
	delete[] a;
	a = new char[7];
	a1.decode(a, 7, a1.encode("aaaaaa", 7));
	if (strcmp(a, "aaaaaa") != 0) {
		delete[] a;
		return false;
	}
	delete[] a;
	a = new char[25];
	a1.decode(a, 25, a1.encode("TOBEORNOTTOBEORTOBEORNOT", 25));
	if (strcmp(a, "TOBEORNOTTOBEORTOBEORNOT") != 0) {
		delete[] a;
		return false;
	}
	delete[] a;
	int b;
	int* c = new int;
	b = 5;
	a1.decode(c, sizeof(int), a1.encode(&b, sizeof(int)));
	if (*c != b) {
		delete c;
		return false;
	}
	delete c;
	return true;
}