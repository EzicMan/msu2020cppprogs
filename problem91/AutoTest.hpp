#pragma once
#include <chrono>

bool AutoTest() {
	CIntN0 a(29);
	auto beg = std::chrono::system_clock::now();
	for (int i = -99; i < 99; i++) {
		for (int j = -99; j < 99; j++) {
			a = CIntN0(29,i);
			if (a + CIntN0(29,j) != CIntN0(29, i + j)) {
				return false;
			}
		}
	}
	for (int i = -99; i < 99; i++) {
		for (int j = -99; j < 99; j++) {
			a = CIntN0(29, i);
			if (a - CIntN0(29, j) != CIntN0(29, i - j)) {
				return false;
			}
		}
	}
	auto end = std::chrono::system_clock::now();
	int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - beg).count());
	std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";


	long long num_dimensions = 10e9;

	std::string digits_1, digits_2;
	/*srand(13517287);
	std::ofstream out1("supernum1.txt");
	std::ofstream out2("supernum2.txt");
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < num_dimensions; ++i) // Gens rnadom numbers
		{
			digits_1.push_back(rand() % 10 + '0');
			digits_2.push_back(rand() % 10 + '0');
		}
		out1 << digits_1;
		out2 << digits_2;
		digits_1.clear();
		digits_2.clear();
		std::cout << k << std::endl;
	}

	out1.close();
	out2.close();
	return true;*/

	/*std::ifstream in1("supernum1.txt");
	std::ifstream in2("supernum2.txt");

	in1 >> digits_1;
	in2 >> digits_2;

	std::cout << "Read succesfull" << std::endl;*/

	auto start = std::chrono::system_clock::now();

	CIntN0 num_1(num_dimensions, 0);
	CIntN0 num_2(num_dimensions, 0);

	CIntN0 tmpplus = num_1 + num_2;

	end = std::chrono::system_clock::now();
	elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	std::cout << "One big addition without omp operator runtime is " << elapsed_ms << " ms\n";
	return true;
}