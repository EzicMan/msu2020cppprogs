#include "CIntN1.h"

CIntN1 operator+(const CIntN1& right, const CIntN& left)
{
	CIntN1 a = right;
	a += left;
	return a;
}

CIntN1 operator-(const CIntN1& right, const CIntN& left)
{
	CIntN1 a = right;
	a -= left;
	return a;
}

int CIntN1::output(const char* FileName){
	std::cout << this->N << " " << *this << std::endl;
	return 0;
}