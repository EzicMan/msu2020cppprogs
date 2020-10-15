#pragma once
#include "CStringQueue.hpp"

bool AutoTest() {
	CStringQueue a(6);
	a.add("a");
	a.add("b");
	a.add("c");
	if (a.cur != 3 || a.popped != 0 && a.deleted != 0) {
		return false;
	}
	char* b = a.get();
	if (strcmp("a", b) != 0) {
		return false;
	}
	a.pop();
	delete[] b;
	b = a.get();
	if (strcmp("b", b) != 0) {
		return false;
	}
	a.pop();
	delete[] b;
	b = a.get();
	if (strcmp("c",b) != 0) {
		return false;
	}
	a.pop();
	delete[] b;
	b = a.get();
	if (strcmp("", b) != 0) {
		return false;
	}
	delete[] b;
	a.clear();
	if (a.cur != 0) {
		return false;
	}
	b = a.get();
	if (strcmp("", b) != 0) {
		return false;
	}
	delete[] b;
	CStringQueue c(10);
	c.add("test");
	c.add("tset");
	if (c.cur != 2) {
		return false;
	}
	b = c.get();
	if (strcmp("test", b) != 0) {
		return false;
	}
	delete[] b;
	c.add("deletetwo");
	if (c.cur != 1 || c.deleted != 2) {
		return false;
	}
	b = c.get();
	if (strcmp("deletetwo", b) != 0) {
		return false;
	}
	delete[] b;
	c.clear();
	return true;
}