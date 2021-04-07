#pragma once
#include "CIntN.hpp"
#include "CIntN0.h"
#include "CIntN1.h"

class Creator {
public:
	virtual std::unique_ptr<CIntN> create(size_t size, std::string num) = 0;
};

class CreatorIntN0 : public Creator {
public:
	std::unique_ptr<CIntN> create(size_t size, std::string num) override;
};

class CreatorIntN1 : public Creator {
public:
	std::unique_ptr<CIntN> create(size_t size, std::string num) override;
};

