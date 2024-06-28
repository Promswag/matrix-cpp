#include "matrix.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 12 - Inverse", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "Operation: m1.inverse()" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.inverse() << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "Operation: m1.inverse()" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.inverse() << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 03
		std::cout << GREEN << "#### Test 03 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{8, 5, -2}, {4, 7, 20}, {7, 6, 1}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "Operation: m1.inverse()" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.inverse() << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}