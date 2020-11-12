#include "lzwCompressor.hpp"
#include <limits>
#include <iostream>
#include <map>

lzwCompressor::lzwCompressor() {
	for (int i = 0; i < 256; i++) {
		dict.insert(std::string(1,(uint8_t)i),i);
	}
	cur = 258;
}

lzwCompressor::lzwCompressor(std::string a) {
	for (int i = 0; i < a.size(); i++) {
		dict.insert(std::string(1, (uint8_t)a[i]), i);
	}
	cur = a.size() + 1;
}

std::string lzwCompressor::encode(const void* data, size_t size)
{
	std::vector<uint32_t> nums;
	std::string w = "";
	long long cur = this->cur;
	uint8_t* s = (uint8_t*)data;
	long long impNum = 0;
	long long limpNum = 0;

	int nextTarget = 0;

	for (int i = 0; i < size; i++) {
		if (i >= nextTarget * (size / 100))
		{
			printf("Status: %.2f%%\n", (double)i / size * 100.0);
			printf("Trie memory usage: %.3f MiB\n", dict.nodes.size() * 256 * 4 / 1024.0 / 1024.0);
			nextTarget++;
		}

		if (dict.nodes.size() * 256 * 4 / 1024.0 / 1024.0 > 6000) {
			nums.push_back(limpNum);
			w.clear();
			nums.push_back(256);
			dict.clear();
			for (int i = 0; i < 256; i++) {
				dict.insert(std::string(1, (uint8_t)i), i);
			}
			cur = 258;
		}

		if (w == "") {
			w += s[i];
			limpNum = (uint8_t)s[i];
			continue;
		}

		std::string tmp = w + (char)s[i];
		
		if (!dict.checkWord(tmp, impNum)) {
			nums.push_back(limpNum);
			if (cur < std::numeric_limits<uint32_t>::max()) {
				dict.insert(tmp, cur);
				cur++;
			}
			//std::cout << w << "\n";
			w = s[i];
			dict.checkWord(w, limpNum);
		}
		else if (tmp.size() >= KOEF_TUEVA)
		{
			//std::cout << w << "\n";
			nums.push_back(impNum);
			nums.push_back(257);
			w.clear();
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
	cur = 258;
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
	long long cur = 258;
	int nextTarget = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (i >= nextTarget * (nums.size() / 100))
		{
			printf("Status: %.2f%%\n", (double)i / nums.size() * 100.0);
			nextTarget++;
		}
		if (nums[i] == 256) {
			back_dict.clear();
			for (int j = 0; j < 256; j++) {
				back_dict[j] = (uint8_t)j;
			}
			last.clear();
			cur = 258;
			continue;
		}
		if (nums[i] == 257) {
			last.clear();
			continue;
		}
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
