//                          _
//  _._ _..._ .-',     _.._(`))
// '-. `     '  /-._.-'    ',/
//    )         \            '.
//   / _    _    |             \
//  |  a    a    /              |
//  \   .-.                     ;
//   '-('' ).-'       ,'       ;
//      '-;           |      .'
//         \           \    /
//         | 7  .__  _.-\   \
//         | |  |  ``/  /`  /
//        /,_|  |   /,_/   /
//           /,_/      '`-'
//
// Safety Pig Igor warns you: this code is unreadable and full of kostils.
// Listen to Safety Pig Igor and close the source code file right now.
// If you really want to continue, please consider taking Igor with yourself in case
// you need immediate medical help.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// And you WILL need it.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// Memetic kill agent activated. 7 days.
//

#include "CStringQueue.hpp"

CStringQueue::CStringQueue(int count) {
	bytes = new char[count];
	end = bytes + count - 1;
	this->count = count;
	beg = bytes;
	memset(bytes, '\0', count * sizeof(char));
	curu = bytes;
	cur = 0;
	popped = 0;
	deleted = 0;
}

CStringQueue::~CStringQueue()
{
	delete[] bytes;
	bytes = nullptr;
	beg = nullptr;
	end = nullptr;
	curu = nullptr;
	count = 0;
	cur = 0;
	popped = 0;
	deleted = 0;
}

CStringQueue::CStringQueue(const CStringQueue& r)
{
	bytes = new char[r.count];
	count = r.count;
	beg = bytes + (r.beg - r.bytes);
	end = bytes + (r.end - r.bytes);
	curu = bytes + (r.curu - r.bytes);
	memcpy(bytes, r.bytes, r.count * sizeof(char));
	cur = r.cur;
	popped = r.popped;
	deleted = r.deleted;
}

CStringQueue::CStringQueue(CStringQueue&& r) noexcept
{
	bytes = r.bytes;
	count = r.count;
	beg = r.beg;
	curu = r.curu;
	end = r.end;
	cur = r.cur;
	popped = r.popped;
	deleted = r.deleted;
	r.bytes = nullptr;
	r.beg = nullptr;
	r.curu = nullptr;
	r.end = nullptr;
	r.cur = 0;
	r.popped = 0;
	r.deleted = 0;
	r.count= 0;
}

CStringQueue& CStringQueue::operator=(const CStringQueue& r)
{
	delete[] bytes;
	bytes = new char[r.count];
	count = r.count;
	beg = bytes + (r.beg - r.bytes);
	end = bytes + (r.end - r.bytes);
	curu = bytes + (r.curu - r.bytes);
	memcpy(bytes, r.bytes, r.count * sizeof(char));
	cur = r.cur;
	popped = r.popped;
	deleted = r.deleted;
	return *this;
}

CStringQueue& CStringQueue::operator=(CStringQueue&& r) noexcept
{
	delete[] bytes;
	bytes = r.bytes;
	count = r.count;
	beg = r.beg;
	curu = r.curu;
	end = r.end;
	cur = r.cur;
	popped = r.popped;
	deleted = r.deleted;
	r.bytes = nullptr;
	r.beg = nullptr;
	r.curu = nullptr;
	r.end = nullptr;
	r.cur = 0;
	r.popped = 0;
	r.deleted = 0;
	r.count = 0;
	return *this;
}

void CStringQueue::add(const char* a) {
	if (strlen(a) + 1 > count) {
		throw std::invalid_argument("String size can't be bigger than queue size");
	}
	unsigned int size = strlen(a) + 1;
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (curu + i - k > end) {
			k = count;
		}
		if (*(curu + i - k) != '\0') {
			char* test = curu + i - k;
			cur--;
			deleted++;
			while (*test != '\0') {
				*test = '\0';
				test++;
				if (test > end) {
					test -= count;
				}
			}
			if (cur == 0) {
				beg = curu;
			}
			else {
				while (*test == '\0' && test <= end) {
					test++;
					if (test > end) {
						test = bytes;
					}
				}
				beg = test;
			}
		}
		*(curu + i - k) = a[i];
	}
	curu += size;
	if (curu > end) {
		curu -= count;
	}
	cur++;
}

char* CStringQueue::get() {
	char* ans;
	char* curcu = beg;
	int copysize = 0;
	while (*curcu != '\0') {
		curcu++;
		copysize++;
		if (curcu > end) {
			curcu -= count;
		}
	}
	copysize++;
	curcu = beg;
	ans = new char[copysize];
	for (int i = 0; i < copysize; i++) {
		ans[i] = *curcu;
		curcu++;
		if (curcu > end) {
			curcu -= count;
		}
	}
	return ans;
}

void CStringQueue::pop()
{
	if (cur == 0) {
		return;
	}
	cur--;
	popped++;
	while (*beg != '\0') {
		*beg = '\0';
		beg++;
		if (beg > end) {
			beg -= count;
		}
	}
	if (cur == 0) {
		beg = bytes;
		return;
	}
	while (*beg == '\0' && beg <= end) {
		beg++;
		if (beg > end) {
			beg = bytes;
		}
	}
}

void CStringQueue::clear()
{
	memset(bytes, '\0', count * sizeof(char));
	end = bytes + count - 1;
	beg = bytes;
	curu = bytes;
	cur = 0;
	popped = 0;
	deleted = 0;
}
