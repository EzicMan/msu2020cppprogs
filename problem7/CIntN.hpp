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

class CIntN0 : public CIntN {
public:
	using CIntN::CIntN;
	using CIntN::operator=;

	friend CIntN0 operator+(const CIntN0& right, const CIntN& left);
	friend CIntN0 operator-(const CIntN0& right, const CIntN& left);

	CIntN0() = default;
	CIntN0(const CIntN& r) : CIntN(r) {}
	CIntN0(CIntN&& r) noexcept : CIntN(std::move(r)) {}

	int output(const char* FileName = nullptr) override {
		if (FileName == nullptr) {
			std::cout << "Error occured while working with file!" << std::endl;
			return 1;
		}
		std::ofstream out(FileName,std::ios::app);
		out << this->N << std::endl << std::endl;
		if (number[0] < 0) {
			out << "-" << std::endl;
		}
		bool skip = true;
		std::string a;
		for (long long i = size - 1; i >= 0; i--) {
			if (!skip) {
				int64_t k = abs(number[i]);
				k += 1000000000;
				std::string b = std::to_string(abs(number[i]));
				for (int i = 1; i < b.size(); i++) {
					a += b[i];
				}
			}
			else if (abs(number[i]) != 0) {
				skip = false;
				a = std::to_string(abs(number[i]));
			}
		}
		for (size_t i = 0; i < a.size(); i++) {
			out << a[i] << std::endl;
		}
		out << std::endl;
		out.close();
		return 0;
	}
};

class CIntN1 : public CIntN {
public:
	using CIntN::CIntN;
	using CIntN::operator=;

	friend CIntN1 operator+(const CIntN1& right, const CIntN& left);
	friend CIntN1 operator-(const CIntN1& right, const CIntN& left);

	CIntN1() = default;
	CIntN1(const CIntN& r) : CIntN(r) {}
	CIntN1(CIntN&& r) noexcept : CIntN(std::move(r)) {}

	int output(const char* FileName = nullptr) override {
		std::cout << this->N << " " << *this << std::endl;
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