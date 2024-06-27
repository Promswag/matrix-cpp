#include "matrix.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 10 - Row-Echelon Form", BLUE);
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
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{1, 2}, {3, 4}});
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
	{
		// TEST 03
		std::cout << GREEN << "#### Test 03 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{1, 2}, {2, 4}});
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
	{
		// TEST 04
		std::cout << GREEN << "#### Test 04 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}});
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