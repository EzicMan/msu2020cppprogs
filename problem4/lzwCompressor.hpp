#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Trie.hpp"

#define KOEF_TUEVA 5

class lzwCompressor {
	Trie dict;
	long long cur;
public:
	lzwCompressor();
	// custom alphabet constructor
	lzwCompressor(std::string a);

	std::string encode(const void* data, size_t size);
	std::string decode(std::string data);
	void compress(std::ifstream& in, std::ofstream& out);
	void decompress(std::ifstream& in, std::ofstream& out);
};
