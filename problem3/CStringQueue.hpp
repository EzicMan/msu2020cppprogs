#pragma once
#include <cstring>
#include <stdexcept>
#include <iostream>

class CStringQueue {
	char* bytes;
	char* beg;
	char* end;
	char* curu;
	int count;
public:
	int cur;
	int popped;
	int deleted;
	
	CStringQueue(int count);
	~CStringQueue();
	CStringQueue(const CStringQueue& r);
	CStringQueue(CStringQueue&& r) noexcept;

	CStringQueue& operator=(const CStringQueue& r);
	CStringQueue& operator=(CStringQueue&& r) noexcept;

	void add(const char* a);
	char* get();
	void pop();
	void clear();
};