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

#include "CIntN.hpp"

CIntN::CIntN() {
	size = 1;
	N = 1;
	number = new int32_t[1];
	number[0] = 0;
}

CIntN::CIntN(size_t N) {
	size = N / 9 + ((N % 9) > 0);
	this->N = N;
	number = new int32_t[size];
	for (size_t i = 0; i < size; i++) {
		number[i] = 0;
	}
}

CIntN::CIntN(size_t N, long long a) {
	size = N / 9 + ((N % 9) > 0);
	this->N = N;
	number = new int32_t[size];
	for (size_t i = 0; i < size; i++) {
		number[i] = a % 1000000000;
		a -= number[i];
		a /= 1000000000;
	}
}

CIntN::CIntN(size_t N, int a)
	: CIntN(N, (long long)a)
{
}

CIntN::CIntN(const CIntN& r) {
	size = r.size;
	this->N = r.N;
	number = new int32_t[size];
	memcpy(number, r.number, size * sizeof(int32_t));
}

CIntN::CIntN(CIntN&& r) noexcept
{
	size = r.size;
	this->N = r.N;
	number = r.number;
	r.size = 0;
	r.number = nullptr;

}

CIntN::~CIntN() {
	delete[] number;
	number = nullptr;
}

CIntN::CIntN(size_t N, const char* a) {
	size = N / 9 + ((N % 9) > 0);
	this->N = N;
	number = new int32_t[size];
	int stringSize = 0;
	int kon = 0;
	if (a[0] == '-') {
		kon = 1;
	}
	while (a[stringSize] != '\0') { stringSize++; }
	stringSize -= kon;
	for (size_t k = 0; k < size; k++) {
		int tenth = 1;
		number[k] = 0;
		for (int i = 0; i < 9; i++) {
			if (stringSize - i - (int)k * 9 - 1 < 0) {
				break;
			}
			number[k] += (a[stringSize - i - (int)k * 9 - 1 + kon] - '0') * tenth;
			tenth *= 10;
		}
		if (kon) {
			number[k] = -number[k];
		}
	}
}

std::ostream& operator<<(std::ostream& os, const CIntN& r)
{
	int trim = r.N - (r.size - 1) * 9;
	int tenth = 1;
	for (; trim > 0; trim--) {
		tenth *= 10;
	}
	for (int i = 0; i < r.size; i++) {
		if (r.number[i] < 0) {
			os << '-';
			break;
		}
	}
	//r.number[r.size - 1] %= tenth;
	bool skipZeroes = true;
	for (int i = r.size - 1; i >= 0; i--) {
		char a[10];
		int b = 0;
		if (r.number[i] < 0) {
			b = -r.number[i];
		}
		else {
			b = r.number[i];
		}
		if (b == 0 && skipZeroes && i == 0) {
			os << "0";
			break;
		}
		if (b == 0 && skipZeroes) {
			continue;
		}
		a[9] = '\0';
		for (int j = 8; j >= 0; j--) {
			a[j] = b % 10 + '0';
			b /= 10;
		}
		const char* p = a;
		if (skipZeroes) {
			while (*p == '0') p++;
		}
		os << p;
		skipZeroes = false;
	}
	return os;
}

CIntN0 operator+(const CIntN0& right, const CIntN& left)
{
	CIntN0 a = right;
	a += left;
	return a;
}

CIntN0 operator-(const CIntN0& right, const CIntN& left)
{
	CIntN0 a = right;
	a -= left;
	return a;
}

CIntN1 operator+(const CIntN1& right, const CIntN& left)
{
	CIntN1 a = right;
	a += left;
	return a;
}

CIntN1 operator-(const CIntN1& right, const CIntN& left)
{
	CIntN1 a = right;
	a -= left;
	return a;
}

CIntN& CIntN::operator+=(const CIntN& right) {
	int ost = 0;
	for (size_t i = 0; i < size; i++) {
		number[i] += right.number[i] + ost;
		ost = number[i] / 1000000000;
		number[i] %= 1000000000;
	}
	return *this;
}

CIntN& CIntN::operator-=(const CIntN& right)
{
	int ost = 0;
	int last = 0;
	for (long long i = size - 1; i >= 0; i--) {
		if (number[i] != 0) {
			last = i;
			break;
		}
	}
	for (size_t i = 0; i < size; i++) {
		number[i] -= ost;
		if (number[i] < right.number[i]) {
			if (i < last) {
				ost = 1;
			}
		}
		number[i] -= right.number[i];
	}
	return *this;
}

CIntN& CIntN::operator=(const CIntN& r)
{
	if (&r == this) {
		return *this;
	}
	size = r.size;
	delete[] number;
	number = new int32_t[size];
	memcpy(number, r.number, size * sizeof(int32_t));
	return *this;
}

CIntN& CIntN::operator=(CIntN&& r) noexcept
{
	if (&r == this) {
		return *this;
	}
	size = r.size;
	delete[] number;
	number = r.number;
	r.size = 0;
	r.number = nullptr;
	return *this;
}

bool CIntN::operator==(const CIntN& right) const
{
	for (int i = 0; i < (int)size; i++) {
		if (number[i] != right.number[i]) {
			return false;
		}
	}
	return true;
}

bool CIntN::operator!=(const CIntN& right) const
{
	if (*this == right) {
		return false;
	}
	return true;
}
