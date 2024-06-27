#include "matrix.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 00 - Add, Substract and Scale", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({2., 3.});
			auto v2 = Vector<float>::from({5., 7.});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: v1.add(v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.add(v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({2., 3.});
			auto v2 = Vector<float>::from({5., 7.});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: v1.sub(v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.sub(v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 03
		std::cout << GREEN << "#### Test 03 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({2., 3.});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: v1.scl(2.)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.scl(2.) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 04
		std::cout << GREEN << "#### Test 04 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{1, 2}, {3, 4}});
			auto m2 = Matrix<float>::from({{7, 4}, {-2, 2}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "m2: " << DEFAULT << m2 << std::endl;
			std::cout << CYAN << "Operation: m1.add(m2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.add(m2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 05
		std::cout << GREEN << "#### Test 05 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{1, 2}, {3, 4}});
			auto m2 = Matrix<float>::from({{7, 4}, {-2, 2}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "m2: " << DEFAULT << m2 << std::endl;
			std::cout << CYAN << "Operation: m1.sub(m2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.sub(m2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 06
		std::cout << GREEN << "#### Test 06 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{1, 2}, {3, 4}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "Operation: m1.scl(2.)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.scl(2.) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}