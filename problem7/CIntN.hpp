#pragma once
#include <iostream>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <string>
#include <exception>

//constexpr size_t N = 29;

class CIntN {
public:
	int32_t* number;
	size_t size;
	size_t N;
public:
	CIntN();
	CIntN(size_t);
	CIntN(size_t, long long);
	CIntN(size_t, int);
	CIntN(size_t, const char*);
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

	virtual int output(const char* FileName = nullptr) = 0;
};