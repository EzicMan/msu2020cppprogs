#pragma once

bool AutoTest() {
	CIntN0 a(29);
	for (int i = -99; i < 99; i++) {
		for (int j = -99; j < 99; j++) {
			a = CIntN0(29,i);
			if (a + CIntN0(29,j) != CIntN0(29, i + j)) {
				return false;
			}
		}
	}
	for (int i = -99; i < 99; i++) {
		for (int j = -99; j < 99; j++) {
			a = CIntN0(29, i);
			if (a - CIntN0(29, j) != CIntN0(29, i - j)) {
				return false;
			}
		}
	}
	return true;
}