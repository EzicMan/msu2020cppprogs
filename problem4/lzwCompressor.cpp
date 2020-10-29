#include "lzwCompressor.hpp"
#include <limits>
#include <iostream>

lzwCompressor::lzwCompressor() {
	for (int i = 0; i < 256; i++) {
		def_dict[{(char)i}] = i;
	}
	cur = 256;
}

lzwCompressor::lzwCompressor(std::string a) {
	for (int i = 0; i < a.size(); i++) {
		def_dict[{a[i]}] = i;
	}
	cur = a.size();
}

std::string lzwCompressor::encode(const void* data, size_t size)
{
std::map<std::string, long long> dict = def_dict;
std::vector<long long> nums;
std::string w = "";
long long cur = this->cur;
char* s = (char*)data;
for (int i = 0; i < size; i++) {
	if (w == "") {
		w += s[i];
		continue;
	}
	if (dict.find(w + s[i]) == dict.end()) {
		nums.push_back(dict[w]);
		dict[w + s[i]] = cur;
		if (cur < std::numeric_limits<long long>::max()) {
			cur++;
		}
		w = s[i];
	}
	else {
		w += s[i];
	}
}
if (w != "") {
	nums.push_back(dict[w]);
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
dict = def_dict;
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
	for (auto a : def_dict) {
		back_dict[a.second] = a.first;
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
	std::map<std::string, long long> dict;
	std::vector<long long> nums;
	nums.resize(1000000);
	std::string w = "";
	long long cur = 0;
	long long mcur = 0;
	long long perc = 0;
	in.seekg(0, in.end);
	size_t size = in.tellg();
	in.seekg(0, in.beg);
	std::vector<uint8_t> data;
	data.resize(size);
	in.read((char*)data.data(), size);
	for(long long i = 0; i < size; i++) {
		if (mcur > 1000000) {
			std::cout << ((double)perc / 738.0) * 100.0 << std::endl;
			perc++;
			if (w != "") {
				nums[mcur] = dict[w];
			}
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] == 0) {
					out << (char)0;
				}
				while (nums[i] != 0) {
					uint8_t t = (nums[i] & 0b01111111) << 1;
					nums[i] >>= 7;
					if (nums[i] != 0) {
						t += 1;
					}
					out << t;
				}
			}
			mcur = 0;
		}
		if (w == "") {
			w += data[i];
			continue;
		}
		if (dict.find(w + (char)data[i]) == dict.end()) {
			nums[mcur] = dict[w];
			dict[w + (char)data[i]] = cur;
			mcur++;
			if (cur < std::numeric_limits<long long>::max()) {
				cur++;
			}
			w = data[i];
		}
		else {
			w += data[i];
		}
	}
	if (w != "") {
		nums[mcur] = dict[w];
		mcur++;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) {
			out << (char)0;
		}
		while (nums[i] != 0) {
			uint8_t t = (nums[i] & 0b01111111) << 1;
			nums[i] >>= 7;
			if (nums[i] != 0) {
				t += 1;
			}
			out << t;
		}
	}
}
