#pragma once
#include "lzwCompressor.hpp"
#include <cstring>
#include <string>

bool AutoTest() {
	lzwCompressor a1;
	std::string ans;
	char* a = new char[6];
	ans = a1.decode(a1.encode("ababa", 6));
	if (strcmp(ans.c_str(), "ababa") != 0) {
		delete[] a;
		return false;
	}
	delete[] a;
	a = new char[7];
	ans = a1.decode(a1.encode("aaaaaa", 7));
	if (strcmp(ans.c_str(), "aaaaaa") != 0) {
		delete[] a;
		return false;
	}
	delete[] a;
	a = new char[25];
	ans = a1.decode(a1.encode("TOBEORNOTTOBEORTOBEORNOT", 25));
	if (strcmp(ans.c_str(), "TOBEORNOTTOBEORTOBEORNOT") != 0) {
		delete[] a;
		return false;
	}
	delete[] a;
	return true;
}