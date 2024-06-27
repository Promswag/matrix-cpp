#include "matrix.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 07 - Linear map, Matrix multiplication", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{1., 0}, {0, 1}});
			auto v1 = Vector<float>::from({4, 2});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: m1.mul_vec(v1)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.mul_vec(v1) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{2., 0}, {0, 2}});
			auto v1 = Vector<float>::from({4, 2});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: m1.mul_vec(v1)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.mul_vec(v1) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 03
		std::cout << GREEN << "#### Test 03 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{2., -2}, {-2, 2}});
			auto v1 = Vector<float>::from({4, 2});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: m1.mul_vec(v1)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.mul_vec(v1) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 04
		std::cout << GREEN << "#### Test 04 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{1., 0}, {0, 1}});
			auto m2 = Matrix<float>::from({{1., 0}, {0, 1}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "m2: " << DEFAULT << m2 << std::endl;
			std::cout << CYAN << "Operation: m1.mul_mat(m2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.mul_mat(m2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 05
		std::cout << GREEN << "#### Test 05 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{1., 0}, {0, 1}});
			auto m2 = Matrix<float>::from({{2., 1}, {4, 2}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "m2: " << DEFAULT << m2 << std::endl;
			std::cout << CYAN << "Operation: m1.mul_mat(m2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.mul_mat(m2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 06
		std::cout << GREEN << "#### Test 06 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{3., -5}, {6, 8}});
			auto m2 = Matrix<float>::from({{2., 1}, {4, 2}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "m2: " << DEFAULT << m2 << std::endl;
			std::cout << CYAN << "Operation: m1.mul_mat(m2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << m1.mul_mat(m2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}