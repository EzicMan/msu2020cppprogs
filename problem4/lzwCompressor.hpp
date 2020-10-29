#pragma once
#include <map>
#include <string>
#include <algorithm>
#include <vector>

class lzwCompressor {
	std::map<std::string, long long> def_dict;
	long long cur;
public:
	lzwCompressor();
	// custom alphabet constructor
	lzwCompressor(std::string a);

	std::string encode(const void* data, size_t size);
	void decode(void* buf, size_t size, std::string data);
};
