#pragma once
#include <iostream>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <exception>
#include <vector>
#include <string>
#include <memory>

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
	CIntN& operator+(const CIntN& right);
	CIntN& operator-=(const CIntN&);
	CIntN& operator-(const CIntN& right);
	CIntN& operator=(const CIntN&);
	CIntN& operator=(CIntN&&) noexcept;
	bool operator==(const CIntN& right) const;
	bool operator!=(const CIntN& right) const;

	virtual int output(std::string FileName = nullptr) = 0;
};

class CIntN0 : public CIntN {
public:
	using CIntN::CIntN;
	using CIntN::operator=;

	CIntN0(const CIntN& r) : CIntN(r){}
	CIntN0(CIntN&& r) noexcept : CIntN(r) {}
	
	int output(std::string FileName = nullptr) override {
		if (FileName.empty()) {
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
	using CIntN::operator=;

	CIntN1(const CIntN& r) : CIntN(r) {}
	CIntN1(CIntN&& r) noexcept : CIntN(r) {}

	int output(std::string FileName = nullptr) override {
		std::cout << this->N << std::endl << *this << std::endl;
		return 0;
	}
};

class Creator {
public:
	virtual std::unique_ptr<CIntN> create(size_t size, std::string num)=0;
};

class CreatorIntN0 : public Creator {
public:
	std::unique_ptr<CIntN> create(size_t size, std::string num) override {
		return std::make_unique<CIntN0>(size, num);
	}
};

class CreatorIntN1 : public Creator {
public:
	std::unique_ptr<CIntN> create(size_t size, std::string num) override {
		return std::make_unique<CIntN1>(size, num);
	}
};