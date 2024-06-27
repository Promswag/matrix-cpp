#include "matrix.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 03 - Dot Product", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({0, 0});
			auto v2 = Vector<float>::from({1, 1});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: v1.dot(v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.dot(v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({1, 1});
			auto v2 = Vector<float>::from({1, 1});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: v1.dot(v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.dot(v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 03
		std::cout << GREEN << "#### Test 03 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({-1, 6});
			auto v2 = Vector<float>::from({3, 2});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: v1.dot(v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.dot(v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}