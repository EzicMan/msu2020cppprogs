#pragma once
#include "CVector.hpp"

bool AutoTest() {
	double a1[3] = { 1,1,1 };
	double b1[3] = { 2,2,2 };
	double c1[4] = { 5,6,7,8 };
	CVector a(3, a1);
	CVector b(3, b1);
	CVector c = a + b;
	if (c.getSize() != 3 || (fabs(c.getCoords()[0] - 3) > DBL_MIN || fabs(c.getCoords()[1] - 3) > DBL_MIN || fabs(c.getCoords()[2] - 3) > DBL_MIN)) {
		return false;
	}
	CVector d(4, c1);
	c -= d;
	if (c.getSize() != 4 || (fabs(c.getCoords()[0] + 2) > DBL_MIN || fabs(c.getCoords()[1] + 3) > DBL_MIN || fabs(c.getCoords()[2] + 4) > DBL_MIN || fabs(c.getCoords()[3] + 5) > DBL_MIN)) {
		return false;
	}
	c = CVector(3, a1);
	c *= 3;
	if (c.getSize() != 3 || (fabs(c.getCoords()[0] - 3) > DBL_MIN || fabs(c.getCoords()[1] - 3) > DBL_MIN || fabs(c.getCoords()[2] - 3) > DBL_MIN)) {
		return false;
	}
	if (fabs(c * a - 9) > DBL_MIN) {
		return false;
	}
	return true;
}