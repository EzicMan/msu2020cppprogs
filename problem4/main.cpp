#include <iostream>
#include "lzwCompressor.hpp"
#include "AutoTest.hpp"
#include <fstream>
#include <sstream>
using namespace std;

//D:\Games\GTASA\gta_sa\setup-1.bin

std::string slurp(std::ifstream& in) {
	std::ostringstream sstr;
	sstr << in.rdbuf();
	return sstr.str();
}

int main() {
	if (!AutoTest()) {
		cout << "AutoTest not complete!" << endl;
		return 0;
	}
	cout << "AutoTest complete!" << endl;
	lzwCompressor c;
	cout << "Enter filename:";
	string a;
	cin >> a;
	ifstream in(a, std::ios::in | std::ios::binary);
	ofstream out(a + ".scompr", std::ios::out | std::ios::binary);
	c.compress(in, out);
	in.close();
	out.close();
	return 0;
}