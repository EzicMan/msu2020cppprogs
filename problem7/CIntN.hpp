#pragma once
#include <iostream>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <exception>

//constexpr size_t N = 29;

class CIntN {
public:
	int32_t* number;
	size_t size;
	size_t N;
public:
	CIntN(size_t);
	CIntN(size_t, long long);
	CIntN(size_t, int);
	CIntN(size_t, const char*);
	CIntN(const CIntN&);
	CIntN(CIntN&&) noexcept;
	virtual ~CIntN();
	friend std::ostream& operator<<(std::ostream&, const CIntN&);
	CIntN& operator+=(const CIntN&);
	CIntN& operator+(const CIntN& right);
	CIntN& operator-=(const CIntN&);
	CIntN& operator-(const CIntN& right);
	CIntN& operator=(const CIntN&);
	CIntN& operator=(CIntN&&) noexcept;
	bool operator==(const CIntN& right) const;
	bool operator!=(const CIntN& right) const;

	virtual int output(const char* FileName = nullptr) = 0;
};

class CIntN0 : public CIntN {
public:
	using CIntN::CIntN;
	int output(const char* FileName = NULL) override {
		if (FileName == nullptr) {
			std::cout << "Error occured while working with file!" << std::endl;
			return 1;
		}
		std::ofstream out(FileName,std::ios::app);
		out << this->N << std::endl << *this << std::endl;
		out.close();
		return 0;
	}
};

class CIntN1 : public CIntN {
public:
	using CIntN::CIntN;
	int output(const char* FileName = NULL) override {
		std::cout << this->N << std::endl << *this << std::endl;
		return 0;
	}
};

class Creator {
public:
	virtual CIntN* create(size_t size, const char* num)=0;
};

class CreatorIntN0 : public Creator {
public:
	CIntN* create(size_t size, const char* num) override {
		return new CIntN0(size, num);
	}
};

class CreatorIntN1 : public Creator {
public:
	CIntN* create(size_t size, const char* num) override {
		return new CIntN1(size, num);
	}
};