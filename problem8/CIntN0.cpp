#include "CIntN0.h"

CIntN0 operator+(const CIntN0& right, const CIntN& left)
{
	CIntN0 a = right;
	a += left;
	return a;
}

CIntN0 operator-(const CIntN0& right, const CIntN& left)
{
	CIntN0 a = right;
	a -= left;
	return a;
}

int CIntN0::output(std::string FileName){
	if (FileName.empty()) {
		std::cout << "Error occured while working with file!" << std::endl;
		return 1;
	}
	std::ofstream out(FileName, std::ios::app);
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
			std::string b = std::to_string(abs(k));
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