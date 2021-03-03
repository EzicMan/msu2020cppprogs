#include "CIntN.hpp"
#include "AutoTest.hpp"
#include <map>
using namespace std;

int main() {
	if (!AutoTest()) {
		cout << "AutoTest not complete!" << endl;
		return 0;
	}
	cout << "AutoTest complete!" << endl;
	map<int,unique_ptr<Creator>> create;
	create[0] = make_unique<CreatorIntN0>();
	create[1] = make_unique<CreatorIntN1>();
	ifstream in("input.txt");
	std::remove("out.txt");
	int n = 0;
	in >> n;
	vector<unique_ptr<CIntN>> arr(n);
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
	arr.clear();
	create.clear();
	return 0;
}