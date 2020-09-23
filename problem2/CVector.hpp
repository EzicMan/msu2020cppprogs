#pragma once
#include <iostream>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <cfloat>
#include <cmath>

class CVector {
	double* coords;
	size_t size;
public:
	CVector();
	CVector(long long);
	CVector(int);
	CVector(const CVector&);
	CVector(CVector&&) noexcept;
	CVector(size_t, double*);
	~CVector();
	double* getCoords() const {
		return coords;
	}
	size_t getSize() const {
		return size;
	}
	friend std::ostream& operator<<(std::ostream&, const CVector&);
	CVector& operator+=(const CVector&);
	friend CVector operator+(const CVector&, const CVector&);
	CVector& operator*=(double);
	friend CVector operator*(const CVector&, double);
	friend CVector operator*(double, const CVector&);
	CVector& operator/=(double);
	friend CVector operator/(const CVector&, double);
	CVector& operator-=(const CVector&);
	friend CVector operator-(const CVector&, const CVector&);
	friend double operator*(const CVector&, const CVector&);
	CVector& operator=(const CVector&);
	CVector& operator=(CVector&&) noexcept;
	bool operator==(const CVector&) const;
	bool operator!=(const CVector&) const;
};