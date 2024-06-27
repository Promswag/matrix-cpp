#include "matrix.hpp"
#include "maths.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 05 - Cosine", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({1, 0});
			auto v2 = Vector<float>::from({1, 0});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: angle_cos(v1, v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << angle_cos(v1, v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({1, 0});
			auto v2 = Vector<float>::from({0, 1});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: angle_cos(v1, v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << angle_cos(v1, v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 03
		std::cout << GREEN << "#### Test 03 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({-1, 1});
			auto v2 = Vector<float>::from({1, -1});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: angle_cos(v1, v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << angle_cos(v1, v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 04
		std::cout << GREEN << "#### Test 04 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({2, 1});
			auto v2 = Vector<float>::from({4, 2});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: angle_cos(v1, v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << angle_cos(v1, v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 05
		std::cout << GREEN << "#### Test 05 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({1, 2, 3});
			auto v2 = Vector<float>::from({4, 5, 6});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: angle_cos(v1, v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << angle_cos(v1, v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}