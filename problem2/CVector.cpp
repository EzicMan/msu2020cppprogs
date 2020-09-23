//                          _
//  _._ _..._ .-',     _.._(`))
// '-. `     '  /-._.-'    ',/
//    )         \            '.
//   / _    _    |             \
//  |  a    a    /              |
//  \   .-.                     ;
//   '-('' ).-'       ,'       ;
//      '-;           |      .'
//         \           \    /
//         | 7  .__  _.-\   \
//         | |  |  ``/  /`  /
//        /,_|  |   /,_/   /
//           /,_/      '`-'
//
// Safety Pig Igor warns you: this code is unreadable and full of kostils.
// Listen to Safety Pig Igor and close the source code file right now.
// If you really want to continue, please consider taking Igor with yourself in case
// you need immediate medical help.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// And you WILL need it.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// Memetic kill agent activated. 7 days.
//

#include "CVector.hpp"

CVector::CVector() {
	size = 3;
	coords = new double[size];
	coords[0] = 0;
	coords[1] = 0;
	coords[2] = 0;
}

CVector::CVector(long long a) {
	size = 1;
	coords = new double[size];
	coords[0] = static_cast<double>(a);
}

CVector::CVector(int a)
	: CVector(static_cast<long long>(a))
{
}

CVector::CVector(const CVector& r) {
	size = r.size;
	coords = new double[size];
	memcpy(coords, r.coords, size * sizeof(double));
}

CVector::CVector(CVector&& r) noexcept
{
	size = r.size;
	coords = r.coords;
	r.size = 0;
	r.coords = nullptr;
}

CVector::CVector(size_t size, double* coords)
{
	this->size = size;
	this->coords = new double[size];
	memcpy(this->coords, coords, size * sizeof(double));
}

CVector::~CVector() {
	delete[] coords;
	coords = nullptr;
}

std::ostream& operator<<(std::ostream& os, const CVector& r)
{
	os << "(";
	for (size_t i = 0; i < r.size - 1; i++) {
		os << r.coords[i] << ",";
	}
	os << r.coords[r.size - 1] << ")";
	return os;
}

CVector operator+(const CVector& left, const CVector& right)
{
	CVector a = left;
	a += right;
	return a;
}

CVector operator*(const CVector& left, double r)
{
	CVector a = left;
	a *= r;
	return a;
}

CVector operator*(double r, const CVector& left)
{
	CVector a = left;
	a *= r;
	return a;
}

CVector operator/(const CVector& left, double r)
{
	CVector a = left;
	a /= r;
	return a;
}

CVector operator-(const CVector& left, const CVector& right)
{
	CVector a = left;
	a -= right;
	return a;
}

double operator*(const CVector& left, const CVector& right)
{
	double ans = 0;
	for (size_t i = 0; i < std::min(left.size, right.size); i++) {
		ans += left.coords[i] * right.coords[i];
	}
	return ans;
}

CVector& CVector::operator+=(const CVector& right) {
	size_t newSize = std::max(size, right.size);
	double* newCoords = new double[newSize];
	memset(newCoords, 0, newSize * sizeof(double));
	for (size_t i = 0; i < size; i++) {
		newCoords[i] += coords[i];
	}
	for (size_t i = 0; i < right.size; i++) {
		newCoords[i] += right.coords[i];
	}
	size = newSize;
	coords = newCoords;
	newCoords = nullptr;
	return *this;
}

CVector& CVector::operator*=(double r)
{
	for (size_t i = 0; i < size; i++) {
		coords[i] *= r;
	}
	return *this;
}

CVector& CVector::operator/=(double r)
{
	for (size_t i = 0; i < size; i++) {
		coords[i] /= r;
	}
	return *this;
}

CVector& CVector::operator-=(const CVector& right)
{
	size_t newSize = std::max(size, right.size);
	double* newCoords = new double[newSize];
	memset(newCoords, 0, newSize * sizeof(double));
	for (size_t i = 0; i < size; i++) {
		newCoords[i] += coords[i];
	}
	for (size_t i = 0; i < right.size; i++) {
		newCoords[i] -= right.coords[i];
	}
	size = newSize;
	coords = newCoords;
	newCoords = nullptr;
	return *this;
}

CVector& CVector::operator=(const CVector& r)
{
	if (&r == this) {
		return *this;
	}
	size = r.size;
	coords = new double[size];
	memcpy(coords, r.coords, size * sizeof(double));
	return *this;
}

CVector& CVector::operator=(CVector&& r) noexcept
{
	if (&r == this) {
		return *this;
	}
	size = r.size;
	coords = r.coords;
	r.size = 0;
	r.coords = nullptr;
	return *this;
}

bool CVector::operator==(const CVector& right) const
{
	for (size_t i = 0; i < size; i++) {
		if (fabs(coords[i] - right.coords[i]) > DBL_MIN) {
			return false;
		}
	}
	return true;
}

bool CVector::operator!=(const CVector& right) const
{
	if (*this == right) {
		return false;
	}
	return true;
}
