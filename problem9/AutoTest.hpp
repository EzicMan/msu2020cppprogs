#pragma once

#include <chrono>

bool AutoTest() {
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	CIntN0 a(29);
	for (int i = -99; i < 99; i++) {
		for (int j = -99; j < 99; j++) {
			a = CIntN0(29,i);
			if (a + CIntN0(29,j) != CIntN0(29, i + j)) {
				return false;
			}
		}
	}
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    int elapsed_ms = static_cast<int>( std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() );
    std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
    start = std::chrono::system_clock::now();
	for (int i = -99; i < 99; i++) {
		for (int j = -99; j < 99; j++) {
			a = CIntN0(29, i);
			if (a - CIntN0(29, j) != CIntN0(29, i - j)) {
				return false;
			}
		}
	}
    end = std::chrono::system_clock::now();
    elapsed_ms = static_cast<int>( std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() );
    std::cout << "Subtraction operator runtime is " << elapsed_ms << " ms\n";
	return true;
}