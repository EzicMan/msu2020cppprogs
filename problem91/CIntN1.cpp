#include "CIntN1.h"

//CIntN1 operator+(const CIntN1& right, const CIntN& left)
//{
//	CIntN1 a = right;
//	a += left;
//	return a;
//}
//
//CIntN1 operator-(const CIntN1& right, const CIntN& left)
//{
//	CIntN1 a = right;
//	a -= left;
//	return a;
//}

int CIntN1::output(std::string FileName){
	if (FileName.empty()) {
		std::cout << "Error occured while working with file!" << std::endl;
		return 1;
	}
	std::ofstream out(FileName, std::ios::app);
	out << this->N << " " << *this << std::endl;
	out << std::endl;
	out.close();
	return 0;
}