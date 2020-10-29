#include "lzwCompressor.hpp"
#include <limits>

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
		while(nums[i] != 0){
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
