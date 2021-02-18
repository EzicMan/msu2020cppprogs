#include "CIntN.hpp"
#include "AutoTest.hpp"
#include <string>
using namespace std;

int main() {
	if (AutoTest()) {
		cout << "AutoTest not complete!" << endl;
		return 0;
	}
	cout << "AutoTest complete!" << endl;
	Creator* create[2] = {new CreatorIntN0(), new CreatorIntN1()};
	ifstream in("input.txt");
	int n = 0;
	in >> n;
	CIntN** arr = new CIntN* [n];
	int j = 0;
	int s = 0;
	std::string num;
	for (int i = 0; i < n; i++) {
		in >> j;
		in >> s;
		in >> num;
		arr[i] = create[j]->create(s, num.c_str());
	}
	for (int i = 0; i < n; i++) {
		arr[i]->output("out.txt");
	}
	for (int i = 0; i < n; i++) {
		delete arr[i];
	}
	for (int i = 0; i < 2; i++) {
		delete create[i];
	}
	delete[] arr;
	return 0;
}