#include <iostream>
#include "lzwCompressor.hpp"
#include "AutoTest.hpp"
#include <fstream>
#include <sstream>
using namespace std;

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
	string in1;
	in1 = slurp(in);
	string out1 = c.encode(in1.c_str(), in1.size());
	ofstream out(a + ".scompr", std::ios::out | std::ios::binary);
	for (int i = 0; i < out1.size(); i++) {
		out << out1[i];
	}
	out.close();
	in.close();
	in1.clear();
	out1.clear();
	cout << "Now decoding..." << endl;
	in.open(a + ".scompr", std::ios::in | std::ios::binary);
	in1 = slurp(in);
	out1 = c.decode(in1);
	out.open(a + ".sdecompr", std::ios::out | std::ios::binary);
	for (int i = 0; i < out1.size(); i++) {
		out << out1[i];
	}
	out.close();
	in.close();
	in1.clear();
	out1.clear();
	return 0;
}