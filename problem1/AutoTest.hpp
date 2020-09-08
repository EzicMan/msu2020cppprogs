#pragma once
#include "CIntN.hpp"

bool AutoTest() {
	CIntN a;
	for (int i = 0; i < 999; i++) {
		for (int j = 0; j < 999; j++) {
			a = i;
			if (a + j != i + j) {
				return false;
			}
		}
	}
	for (int i = 0; i < 999; i++) {
		for (int j = i + 1; j < 999; j++) {
			a = i;
			if (a - j != i - j) {
				return false;
			}
		}
	}
	return true;
}