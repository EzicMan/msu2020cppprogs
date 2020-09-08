#pragma once
#include <iostream>
#include <cstdint>

constexpr size_t N = 3;

class CIntN {
	uint32_t* number;
	size_t size;
public:
	CIntN();
	CIntN(long long);
	CIntN(int);
	CIntN(const char*);
	CIntN(const CIntN&);
	CIntN(CIntN&&) noexcept;
	~CIntN();
	friend std::ostream& operator<<(std::ostream&, const CIntN&);
	CIntN& operator+=(const CIntN&);
	friend CIntN operator+(const CIntN& left, const CIntN& right);
	CIntN& operator-=(const CIntN&);
	friend CIntN operator-(const CIntN& left, const CIntN& right);
	CIntN& operator=(const CIntN&);
	CIntN& operator=(CIntN&&) noexcept;
};