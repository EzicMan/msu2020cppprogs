#pragma once

#include <chrono>

bool AutoTest() {
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	int limit = 99;
	CIntN0 a(29);
	for (int i = -limit; i < limit; i++) {
		for (int j = -limit; j < limit; j++) {
			a = CIntN0(29,i);
			if (a + CIntN0(29,j) != CIntN0(29, i + j)) {
				return false;
			}
		}
	}
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    int elapsed_ms = static_cast<int>( std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() );
    std::cout << "Many additions operator runtime is " << elapsed_ms << " ms\n";
    start = std::chrono::system_clock::now();
	for (int i = -limit; i < limit; i++) {
		for (int j = -limit; j < limit; j++) {
			a = CIntN0(29, i);
			if (a - CIntN0(29, j) != CIntN0(29, i - j)) {
				return false;
			}
		}
	}
    end = std::chrono::system_clock::now();
    elapsed_ms = static_cast<int>( std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() );
    std::cout << "Many subtractions operator runtime is " << elapsed_ms << " ms\n";
	long long num_dimensions = 10e7;

	std::string digits_1, digits_2;
	for (int i = 0; i < num_dimensions; ++i) // Gens rnadom numbers
	{
		digits_1.push_back(rand() % 10 + '0');
		digits_2.push_back(rand() % 10 + '0');
	}

	start = std::chrono::system_clock::now();

	CIntN0 num_1(num_dimensions, digits_1.c_str(),false);
	CIntN0 num_2(num_dimensions, digits_1.c_str(),false);

	CIntN0 tmpplus = num_1 + num_2;
	
	end = std::chrono::system_clock::now();
	elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	std::cout << "One big addition without omp operator runtime is " << elapsed_ms << " ms\n";

	start = std::chrono::system_clock::now();

	CIntN0 num_11(num_dimensions, digits_1.c_str(),true);
	CIntN0 num_21(num_dimensions, digits_1.c_str(),true);

	CIntN0 tmp1plus = num_11 + num_21;

	end = std::chrono::system_clock::now();
	elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	std::cout << "One big addition with omp operator runtime is " << elapsed_ms << " ms\n";

	start = std::chrono::system_clock::now();

	CIntN0 tmpminus = num_1 - num_2;

	end = std::chrono::system_clock::now();
	elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	std::cout << "One big substraction without omp operator runtime is " << elapsed_ms << " ms\n";

	start = std::chrono::system_clock::now();

	CIntN0 tmp1minus = num_11 - num_21;

	end = std::chrono::system_clock::now();
	elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
	std::cout << "One big substraction with omp operator runtime is " << elapsed_ms << " ms\n";
	if (tmp1plus != tmpplus && tmp1minus != tmpminus) {
		return false;
	}
	return true;
}