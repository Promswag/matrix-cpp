#include "matrix.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 11 - Determinant", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "Operation: m1.row_echelon()" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.row_echelon() << std::endl;
			std::cout << CYAN << "Operation: m1.rref()" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.rref() << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}