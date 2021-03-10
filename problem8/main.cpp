#include "Creator.h"
#include "AutoTest.hpp"
using namespace std;

int main() {
	if (!AutoTest()) {
		cout << "AutoTest not complete!" << endl;
		return 0;
	}
	cout << "AutoTest complete!" << endl;
	map<string,unique_ptr<Creator>> create;
	create["Hori"] = make_unique<CreatorIntN0>();
	create["Vert"] = make_unique<CreatorIntN1>();
	ifstream in("input.txt");
	CIntN0 a;
	CIntN1 b(1, 1);
	CIntN1 c = a + b;
	cout << c << endl;
	int n = 0;
	in >> n;
	vector<pair<unique_ptr<CIntN>,std::string>> arr(n);
	std::string j;
	int s = 0;
	std::string num;
	std::string filename;
	for (auto i = arr.begin(); i != arr.end(); i++) {
		in >> j;
		in >> filename;
		in >> s;
		in >> num;
		for (const auto& k : create) {
			if (k.first == j) {
				*i = make_pair((k.second)->create(s, num.c_str()),filename);
				break;
			}
		}
	}
	for (auto i = arr.begin(); i != arr.end(); i++) {
		(*i).first->output((*i).second);
	}
	arr.clear();
	create.clear();
	return 0;
}