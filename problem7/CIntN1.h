#pragma once
#include "CIntN.hpp"

class CIntN1 : public CIntN {
public:
	using CIntN::CIntN;
	using CIntN::operator=;

	friend CIntN1 operator+(const CIntN1& right, const CIntN& left);
	friend CIntN1 operator-(const CIntN1& right, const CIntN& left);

	CIntN1() = default;
	CIntN1(const CIntN& r) : CIntN(r) {}
	CIntN1(CIntN&& r) noexcept : CIntN(std::move(r)) {}

	int output(const char* FileName = nullptr) override;
};

