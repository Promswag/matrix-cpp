#include "matrix.hpp"
#include "print.hpp"
#include "lalgebra.hpp"
#include <fstream>
#include <complex>
#include <chrono>

#define COMPLEX_DOUBLE std::complex<double>

int main() {
	
	auto start = std::chrono::system_clock::now();
	{
		//
	}
	auto end = std::chrono::system_clock::now();
	std::cout << std::chrono::duration<double>(end - start).count() * 1000000 << "ns" << std::endl;
}