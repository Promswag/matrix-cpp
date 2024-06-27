#include "matrix.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 04 - Norm", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({0, 0, 0});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: v1.norm_1(), v1.norm(), v1.norm_inf()" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.norm_1() << ", " << v1.norm() << ", " << v1.norm_inf() << std::endl;
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
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: v1.norm_1(), v1.norm(), v1.norm_inf()" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.norm_1() << ", " << v1.norm() << ", " << v1.norm_inf() << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({-1, -2});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: v1.norm_1(), v1.norm(), v1.norm_inf()" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.norm_1() << ", " << v1.norm() << ", " << v1.norm_inf() << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}