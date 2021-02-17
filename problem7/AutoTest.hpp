#pragma once
#include "CIntN.hpp"

bool AutoTest() {
	CIntN0 a(3,29);
	for (int i = 0; i < 999; i++) {
		for (int j = 0; j < 999; j++) {
			a = i;
			if (a + CIntN0(3,j) != CIntN0(3, i) + CIntN0(3, j)) {
				return false;
			}
		}
	}
	for (int i = 0; i < 999; i++) {
		for (int j = i + 1; j < 999; j++) {
			a = i;
			if (a - CIntN0(3, j) != CIntN0(3, i) - CIntN0(3, j)) {
				return false;
			}
		}
	}
	return true;
}