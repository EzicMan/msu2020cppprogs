#pragma once
#include "CIntN.hpp"

class CIntN0 : public CIntN {
public:
	using CIntN::CIntN;
	using CIntN::operator=;

	friend CIntN0 operator+(const CIntN0& right, const CIntN& left);
	friend CIntN0 operator-(const CIntN0& right, const CIntN& left);

	CIntN0() = default;
	CIntN0(const CIntN& r) : CIntN(r) {}
	CIntN0(CIntN&& r) noexcept : CIntN(std::move(r)) {}

	int output(const char* FileName = nullptr) override;
};
