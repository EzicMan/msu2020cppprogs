#include "Creator.h"

CIntN* CreatorIntN0::create(size_t size, const char* num){
	return new CIntN0(size, num);
}

CIntN* CreatorIntN1::create(size_t size, const char* num) {
	return new CIntN1(size, num);
}