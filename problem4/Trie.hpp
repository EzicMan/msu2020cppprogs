#pragma once
#include <vector>
#include <string>

class Trie {
public:
	typedef long long ll;
	std::vector<std::vector<uint32_t>> nodes;
	std::vector<bool> nodef;
	std::vector<uint32_t> nums;
	ll alphabetSize;
public:
	Trie() {
		nodes.resize(1);
		alphabetSize = 256;
		nodes[0].resize(alphabetSize);
	}
	Trie(ll alphabetSize) {
		nodes.resize(1);
		this->alphabetSize = alphabetSize;
		nodes[0].resize(alphabetSize);
	}
	void insert(std::string word, long long num) {
		ll j = 0;
		for (ll i = 0; i < word.size(); i++) {
			uint8_t c = (uint8_t)word[i];

			if (nodes[j][c] == 0) {
				nodes.push_back(std::vector<uint32_t>(alphabetSize, 0));
				nodes[j][c] = nodes.size() - 1;
				j = nodes.size() - 1;
			}
			else {
				j = nodes[j][c];
			}
		}
		nodef.resize(nodes.size());
		nums.resize(nodes.size());
		nodef[j] = true;
		nums[j] = num;
	}
	bool checkWord(std::string word, ll& ret) {
		ll j = 0;
		for (ll i = 0; i < word.size(); i++) {
			if (nodes[j][int((uint8_t)word[i])] == 0) {
				return false;
			}
			j = nodes[j][int((uint8_t)word[i])];
		}
		if (!nodef[j]) {
			return false;
		}
		ret = nums[j];
		return true;
	}
	ll size() {
		return nodes.size();
	}
	void clear() {
		for (ll i = 0; i < nodes.size(); i++) {
			nodes[i].clear();
		}
		nodes.clear();
		nodef.clear();
		nums.clear();
		nodes.resize(1);
		this->alphabetSize = alphabetSize;
		nodes[0].resize(alphabetSize);
	}
};
