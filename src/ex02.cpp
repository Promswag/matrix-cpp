#include "matrix.hpp"
#include "lalgebra.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	header("Exercice 02 - Linear Interpolation", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			std::cout << CYAN << "Operation: lerp(0., 1., 0.)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << lerp(0., 1., 0.) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			std::cout << CYAN << "Operation: lerp(0., 1., 1.)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << lerp(0., 1., 1.) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 03
		std::cout << GREEN << "#### Test 03 ####" << std::endl;
		try {
			std::cout << CYAN << "Operation: lerp(0., 1., 0.5)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << lerp(0., 1., 0.5) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 04
		std::cout << GREEN << "#### Test 04 ####" << std::endl;
		try {
			std::cout << CYAN << "Operation: lerp(21., 42., 0.3)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << lerp(21., 42., 0.3) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 05
		std::cout << GREEN << "#### Test 05 ####" << std::endl;
		try {
			auto v1 = Vector<float>::from({2, 1});
			auto v2 = Vector<float>::from({4, 2});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: lerp(v1, v2, 0.3)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << lerp(v1, v2, 0.3) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 06
		std::cout << GREEN << "#### Test 06 ####" << std::endl;
		try {
			auto m1 = Matrix<float>::from({{2., 1.}, {3., 4.}});
			auto m2 = Matrix<float>::from({{20., 10.}, {30., 40.}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "m2: " << DEFAULT << m2 << std::endl;
			std::cout << CYAN << "Operation: lerp(m1, m2, 0.5)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << lerp(m1, m2, 0.5) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}