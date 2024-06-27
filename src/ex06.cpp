#include "matrix.hpp"
#include "maths.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 06 - Cross Product", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({0, 0, 1});
			auto v2 = Vector<float>::from({1, 0, 0});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: cross_product(v1, v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << cross_product(v1, v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({1, 2, 3});
			auto v2 = Vector<float>::from({4, 5, 6});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: cross_product(v1, v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << cross_product(v1, v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 03
		std::cout << GREEN << "#### Test 03 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({4, 2, -3});
			auto v2 = Vector<float>::from({-2, -5, 16});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: cross_product(v1, v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << cross_product(v1, v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}