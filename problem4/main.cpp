#include <iostream>
#include "lzwCompressor.hpp"
#include "AutoTest.hpp"
#include <fstream>
#include <sstream>
using namespace std;

//D:\Games\GTASA\gta_sa\setup-1.bin
//D:\1step.mp4

std::string slurp(std::ifstream& in) {
	std::ostringstream sstr;
	sstr << in.rdbuf();
	return sstr.str();
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	if (!AutoTest()) {
		cout << "AutoTest not complete!" << endl;
		return 0;
	}
	cout << "AutoTest complete!" << endl;
	lzwCompressor c;
	cout << "Enter filename:";
	//string a = "client.pdb";
	//string a = "2020-10-27 20-31-00.mp4";
	//string a = "client.zip";
	string a;
	cin >> a;
	ifstream in(a, std::ios::in | std::ios::binary);
	ofstream out(a + ".scompr", std::ios::out | std::ios::binary);

	if (in.fail())
	{
		cout << "Can't open file\n";
		return -1;
	}

	c.compress(in, out);
	in.close();
	out.close();
	cout << "--------------------------" << endl;
	cout << "Started decoding...." << endl;
	cout << "--------------------------" << endl;
	in.open(a + ".scompr", std::ios::in | std::ios::binary);
	out.open(a + ".decompr", std::ios::out | std::ios::binary);
	c.decompress(in, out);
	in.close();
	out.close();
	return 0;
}