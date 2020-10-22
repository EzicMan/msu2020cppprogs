#include "lzwCompressor.hpp"

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
	std::map<std::string, int> dict = def_dict;
	std::vector<int> nums;
	std::string w = "";
	int cur = this->cur;
	int bytes = 0;
	char* s = (char*)data;
	for (int i = 0; i < size; i++) {
		if (w == "") {
			w += s[i];
			continue;
		}
		if (dict.find(w + s[i]) == dict.end()) {
			nums.push_back(dict[w]);
			dict[w + s[i]] = cur;
			cur++;
			w = s[i];
		}
		else {
			w += s[i];
		}
	}
	if (w != "") {
		nums.push_back(dict[w]);
	}
	bytes = (cur - 1) / 256 + 1;
	std::string ans = "";
	ans += (char)bytes;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < bytes; j++) {
			if (nums[i] % 255 == 0 && nums[i] != 0) {
				ans += 255;
				nums[i] -= 255;
				continue;
			}
			ans += nums[i] % 255;
			nums[i] -= nums[i] % 255;
		}
	}
	dict = def_dict;
	return ans;
}

void lzwCompressor::decode(void* buf, size_t size, std::string data)
{
	std::vector<int> nums;
	int bytes = data[0];
	for (int i = 1; i < data.size(); i += bytes) {
		int temp = 0;
		for (int j = 0; j < bytes; j++) {
			if (data[i + j] < 0) {
				temp += 256 + data[i + j];
			}
			else {
				temp += data[i + j];
			}
		}
		nums.push_back(temp);
	}
	std::string origin = "";
	std::map<int, std::string> back_dict;
	for (auto a : def_dict) {
		back_dict[a.second] = a.first;
	}
	std::string last = "";
	int cur = this->cur;
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
	char* ukaz = (char*)buf;
	for (int i = 0; i < std::min(origin.size(), size); i++) {
		ukaz[i] = origin[i];
	}
	back_dict.clear();
}
