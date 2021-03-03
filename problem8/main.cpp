#include "CIntN.hpp"
#include "AutoTest.hpp"
#include <map>
#include <utility>
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
	std::remove("out.txt");
	int n = 0;
	in >> n;
	vector<unique_ptr<CIntN>> arr(n);
	std::string j;
	int s = 0;
	std::string num;
	for (auto i = arr.begin(); i != arr.end(); i++) {
		in >> j;
		in >> s;
		in >> num;
		for (const auto& k : create) {
			if (k.first == j) {
				*i = (k.second)->create(s, num.c_str());
				break;
			}
		}
	}
	for (auto i = arr.begin(); i != arr.end(); i++) {
		(*i)->output("out.txt");
	}
	arr.clear();
	create.clear();
	return 0;
}