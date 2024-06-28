#include "matrix.hpp"
#include "maths.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 15 - Linear Combination", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({1, 0, 0});
			auto v2 = Vector<float>::from({0, 1, 0});
			auto v3 = Vector<float>::from({0, 0, 1});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "v3: " << DEFAULT << v3 << std::endl;
			std::cout << CYAN << "Operation: linear_combination({v1, v2, v3}, {10, -2, 0.5})" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << linear_combination<float, 3>({v1, v2, v3}, {10, -2, 0.5}) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: linear_combination({v1, v1, v1}, {1, -10, 100})" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << linear_combination<float, 3>({v1, v1, v1}, {1, -10, 100}) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}