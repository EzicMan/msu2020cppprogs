#include "lzwCompressor.hpp"
#include <limits>
#include <iostream>
#include <map>

lzwCompressor::lzwCompressor() {
	for (int i = 0; i < 256; i++) {
		dict.insert(std::string(1,(uint8_t)i),i);
	}
	cur = 256;
}

lzwCompressor::lzwCompressor(std::string a) {
	for (int i = 0; i < a.size(); i++) {
		dict.insert(std::string(1, (uint8_t)a[i]), i);
	}
	cur = a.size();
}

std::string lzwCompressor::encode(const void* data, size_t size)
{
std::vector<long long> nums;
std::string w = "";
long long cur = this->cur;
uint8_t* s = (uint8_t*)data;
long long impNum = 0;
long long limpNum = 0;
for (int i = 0; i < size; i++) {
	if (w == "") {
		w += s[i];
		limpNum = (uint8_t)s[i];
		continue;
	}
	if (!dict.checkWord(w + (char)s[i], impNum)) {
		nums.push_back(limpNum);
		if (cur < std::numeric_limits<long long>::max()) {
			dict.insert(w + (char)s[i],cur);
			cur++;
		}
		w = s[i];
		dict.checkWord(w, limpNum);
	}
	else {
		w += s[i];
		limpNum = impNum;
	}
}
if (dict.checkWord(w, impNum)) {
	nums.push_back(impNum);
}
std::string ans = "";
for (int i = 0; i < nums.size(); i++) {
	if (nums[i] == 0) {
		ans += (char)0;
	}
	while (nums[i] != 0) {
		uint8_t t = (nums[i] & 0b01111111) << 1;
		nums[i] >>= 7;
		if (nums[i] != 0) {
			t += 1;
		}
		ans += t;
	}
}
dict.clear();
for (int i = 0; i < 256; i++) {
	dict.insert(std::string(1,(uint8_t)i), i);
}
cur = 256;
return ans;
}

std::string lzwCompressor::decode(std::string data)
{
	std::vector<long long> nums;
	nums.push_back(0);
	int ni = 0;
	int x = 0;
	for (int i = 0; i < data.size(); i++) {
		uint8_t t = data[i];
		if (t % 2 == 0) {
			t >>= 1;
			nums[ni] += t << x;
			ni++;
			x = 0;
			nums.push_back(0);
			continue;
		}
		t >>= 1;
		nums[ni] += t << x;
		x += 7;
	}
	std::string origin = "";
	std::map<long long, std::string> back_dict;
	for (int i = 0; i < 256; i++) {
		back_dict[i] = (uint8_t)i;
	}
	std::string last = "";
	long long cur = this->cur;
	for (int i = 0; i < nums.size(); i++) {
		if (last == "") {
			last = back_dict[nums[i]];
			origin += back_dict[nums[i]];
			continue;
		}
		if (back_dict.find(nums[i]) == back_dict.end()) {
			back_dict[nums[i]] = last + last[0];
			origin += back_dict[nums[i]];
			last = back_dict[nums[i]];
			cur++;
		}
		else {
			back_dict[cur] = last + back_dict[nums[i]][0];
			origin += back_dict[nums[i]];
			last = back_dict[nums[i]];
			cur++;
		}
	}
	back_dict.clear();
	return origin;
}

void lzwCompressor::compress(std::ifstream& in, std::ofstream& out)
{
	std::vector<uint8_t> data;
	in.seekg(0, in.end);
	size_t size = in.tellg();
	in.seekg(0, in.beg);
	data.resize(size);
	in.read((char*)data.data(), size);
	out << encode(data.data(), size);
}

void lzwCompressor::decompress(std::ifstream& in, std::ofstream& out)
{
	std::string data;
	in.seekg(0, in.end);
	size_t size = in.tellg();
	in.seekg(0, in.beg);
	data.resize(size);
	in.read((char*)data.data(), size);
	out << decode(data);
}
