#pragma once
#include "CIntN.hpp"
#include "CIntN0.h"
#include "CIntN1.h"

class Creator {
public:
	virtual CIntN* create(size_t size, const char* num) = 0;
};

class CreatorIntN0 : public Creator {
public:
	CIntN* create(size_t size, const char* num) override;
};

class CreatorIntN1 : public Creator {
public:
	CIntN* create(size_t size, const char* num) override;
};

