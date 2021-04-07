#include "Creator.h"

std::unique_ptr<CIntN> CreatorIntN0::create(size_t size, std::string num){
	return std::make_unique<CIntN0>(size, num);
}

std::unique_ptr<CIntN> CreatorIntN1::create(size_t size, std::string num){
	return std::make_unique<CIntN1>(size, num);
}