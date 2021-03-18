#pragma once
#include "include.h"

//constexpr size_t N = 29;

class CIntN {
public:
	std::vector<int32_t> number;
	size_t size;
	size_t N;
public:
	CIntN();
	CIntN(size_t);
	CIntN(size_t, long long);
	CIntN(size_t, int);
	CIntN(size_t, std::string);
	CIntN(const CIntN&);
	CIntN(CIntN&&) noexcept;
	virtual ~CIntN();
	friend std::ostream& operator<<(std::ostream&, const CIntN&);
	CIntN& operator+=(const CIntN&);
	//CIntN& operator+(const CIntN& right);
	CIntN& operator-=(const CIntN&);
	//CIntN& operator-(const CIntN& right);
	CIntN& operator=(const CIntN&);
	CIntN& operator=(CIntN&&) noexcept;
	bool operator==(const CIntN& right) const;
	bool operator!=(const CIntN& right) const;

	virtual int output(std::string FileName = nullptr) = 0;
};