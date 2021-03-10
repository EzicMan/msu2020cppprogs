#include "Creator.h"
#include "AutoTest.hpp"
using namespace std;

int main() {
	if (!AutoTest()) {
		cout << "AutoTest not complete!" << endl;
		return 0;
	}
	cout << "AutoTest complete!" << endl;
	CIntN0 a;
	CIntN1 b(1, 1);
	CIntN1 c = a + b;
	cout << c << endl;
	Creator* create[2] = {new CreatorIntN0(), new CreatorIntN1()};
	ifstream in("input.txt");
	int n = 0;
	in >> n;
	CIntN** arr = new CIntN* [n];
	std::string* filenames = new std::string[n]();
	int j = 0;
	int s = 0;
	std::string num;
	std::string filename;
	for (int i = 0; i < n; i++) {
		in >> j;
		in >> filename;
		in >> s;
		in >> num;
		arr[i] = create[j]->create(s, num.c_str());
		filenames[i] = filename;
	}
	for (int i = 0; i < n; i++) {
		arr[i]->output(filenames[i].c_str());
	}
	for (int i = 0; i < n; i++) {
		delete arr[i];
		filenames[i].clear();
	}
	for (int i = 0; i < 2; i++) {
		delete create[i];
	}
	delete[] arr;
	delete[] filenames;
	return 0;
}