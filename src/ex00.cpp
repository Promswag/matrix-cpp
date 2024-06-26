#include "matrix.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto u = Vector<float>::from({2., 3.});
			auto v = Vector<float>::from({5., 7.});
			std::cout << CYAN << "u: " << DEFAULT << u << std::endl;
			std::cout << CYAN << "v: " << DEFAULT << v << std::endl;
			std::cout << CYAN << "Operation: u.add(v)" << std::endl;
			std::cout << CYAN << "u: " << DEFAULT << u.add(v) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto u = Vector<float>::from({2., 3.});
			auto v = Vector<float>::from({5., 7.});
			std::cout << CYAN << "u: " << DEFAULT << u << std::endl;
			std::cout << CYAN << "v: " << DEFAULT << v << std::endl;
			std::cout << CYAN << "Operation: u.sub(v)" << std::endl;
			std::cout << CYAN << "u: " << DEFAULT << u.sub(v) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 03
		std::cout << GREEN << "#### Test 03 ####" << std::endl;
		try {
			auto u = Vector<float>::from({2., 3.});
			std::cout << CYAN << "u: " << DEFAULT << u << std::endl;
			std::cout << CYAN << "Operation: u.scl(2.)" << std::endl;
			std::cout << CYAN << "u: " << DEFAULT << u.scl(2.) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 04
		std::cout << GREEN << "#### Test 04 ####" << std::endl;
		try {
			auto u = Matrix<float>::from({{1, 2}, {3, 4}});
			auto v = Matrix<float>::from({{7, 4}, {-2, 2}});
			std::cout << CYAN << "u: " << DEFAULT << u << std::endl;
			std::cout << CYAN << "v: " << DEFAULT << v << std::endl;
			std::cout << CYAN << "Operation: u.add(v)" << std::endl;
			std::cout << CYAN << "u: " << DEFAULT << u.add(v) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 05
		std::cout << GREEN << "#### Test 05 ####" << std::endl;
		try {
			auto u = Matrix<float>::from({{1, 2}, {3, 4}});
			auto v = Matrix<float>::from({{7, 4}, {-2, 2}});
			std::cout << CYAN << "u: " << DEFAULT << u << std::endl;
			std::cout << CYAN << "v: " << DEFAULT << v << std::endl;
			std::cout << CYAN << "Operation: u.sub(v)" << std::endl;
			std::cout << CYAN << "u: " << DEFAULT << u.sub(v) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 06
		std::cout << GREEN << "#### Test 06 ####" << std::endl;
		try {
			auto u = Matrix<float>::from({{1, 2}, {3, 4}});
			std::cout << CYAN << "u: " << DEFAULT << u << std::endl;
			std::cout << CYAN << "Operation: u.scl(2.)" << std::endl;
			std::cout << CYAN << "u: " << DEFAULT << u.scl(2.) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	// {
	// 	// TEST 06
	// 	std::cout << GREEN << "#### Test 06 ####" << std::endl;
	// 	try {
	// 		auto u = Matrix<char>::from({{'1', '2'}, {'3', '4'}});
	// 		std::cout << CYAN << "u: " << DEFAULT << u << std::endl;
	// 		std::cout << CYAN << "Operation: u.scl(2.)" << std::endl;
	// 		std::cout << CYAN << "u: " << DEFAULT << u.scl('1') << std::endl;
	// 	} catch (const std::exception &e) {
	// 		std::cout << RED << e.what() << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// }
}