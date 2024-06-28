#include "matrix.hpp"
#include "maths.hpp"
#include "print.hpp"
#include <complex>
#include <iostream>

#define COMPLEX_DOUBLE std::complex<double>

int main() {
	header("Exercice 15 - Bonus: Complex vector spaces", BLUE);
	header("Exercice 15.0 - Add, Substract and Scale", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(2, -1), COMPLEX_DOUBLE(1, 2)});
			auto v2 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(7, 0), COMPLEX_DOUBLE(4, 4)});
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
			auto v1 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(2, -1), COMPLEX_DOUBLE(1, 2)});
			auto v2 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(7, 0), COMPLEX_DOUBLE(4, 4)});
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
			auto v1 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(2, -1), COMPLEX_DOUBLE(1, 2)});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: v1.scl((5, -3))" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.scl(COMPLEX_DOUBLE(5, -3)) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	header("Exercice 15.1 - Linear Combination", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(1, 0), COMPLEX_DOUBLE(0, 1)});
			auto v2 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(-1, -1), COMPLEX_DOUBLE(-1, -1)});
			auto v3 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(5, -5), COMPLEX_DOUBLE(5, -5)});	
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "v3: " << DEFAULT << v3 << std::endl;
			std::cout << CYAN << "Operation: linear_combination({v1, v2, v3}, {10, -2, 0.5})" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << linear_combination<COMPLEX_DOUBLE, 3>(
				{v1, v2, v3}, 
				{10, -2, 0.5}) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto v1 = Vector<COMPLEX_DOUBLE>::from({
				COMPLEX_DOUBLE(1, 1), 
				COMPLEX_DOUBLE(2, 2), 
				COMPLEX_DOUBLE(3, 3), 
				COMPLEX_DOUBLE(4, 4), 
				COMPLEX_DOUBLE(5, 5), 
				COMPLEX_DOUBLE(6, 6), 
				COMPLEX_DOUBLE(7, 7), 
				COMPLEX_DOUBLE(8, 8), 
				COMPLEX_DOUBLE(9, 9), 
				COMPLEX_DOUBLE(10, 10)});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: linear_combination({v1, v1, v1}, {(1, -1), (-10, 10), (100, -100)})" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << linear_combination<COMPLEX_DOUBLE, 3>(
				{v1, v1, v1}, 
				{COMPLEX_DOUBLE(1, -1), COMPLEX_DOUBLE(-10, 10), COMPLEX_DOUBLE(100, -100)}) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	header("Exercice 15.2 - Linear Interpolation", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			std::cout << CYAN << "Operation: lerp((0, 8), (10, -10), 0.5)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << lerp(COMPLEX_DOUBLE(0, 8), COMPLEX_DOUBLE(10, -10), 0.5) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	{
		// TEST 02
		std::cout << GREEN << "#### Test 02 ####" << std::endl;
		try {
			auto m1 = Matrix<COMPLEX_DOUBLE>::from({{COMPLEX_DOUBLE(1, 0), COMPLEX_DOUBLE(0, 10)}, {COMPLEX_DOUBLE(10, 0), COMPLEX_DOUBLE(0, 1)}});
			auto m2 = Matrix<COMPLEX_DOUBLE>::from({{COMPLEX_DOUBLE(8, 2), COMPLEX_DOUBLE(6, 4)}, {COMPLEX_DOUBLE(4, 6), COMPLEX_DOUBLE(2, 8)}});
			std::cout << CYAN << "m1: " << DEFAULT << m1 << std::endl;
			std::cout << CYAN << "m2: " << DEFAULT << m2 << std::endl;
			std::cout << CYAN << "Operation: lerp(m1, m2, 0.5)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << lerp(m1, m2, 0.5) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	header("Exercice 15.3 - Dot Product", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(1, 1), COMPLEX_DOUBLE(2, 2), COMPLEX_DOUBLE(3, 4)});
			auto v2 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(2, 2), COMPLEX_DOUBLE(1, -1), COMPLEX_DOUBLE(3, 4)});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "v2: " << DEFAULT << v2 << std::endl;
			std::cout << CYAN << "Operation: v1.dot(v2)" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.dot(v2) << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	header("Exercice 15.4 - Norm", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			auto v1 = Vector<COMPLEX_DOUBLE>::from({COMPLEX_DOUBLE(1, -1), COMPLEX_DOUBLE(-2, 2), COMPLEX_DOUBLE(-3, 4)});
			std::cout << CYAN << "v1: " << DEFAULT << v1 << std::endl;
			std::cout << CYAN << "Operation: v1.norm_1(), v1.norm(), v1.norm_inf()" << std::endl;
			std::cout << CYAN << "result: " << DEFAULT << v1.norm_1() << ", " << v1.norm() << ", " << v1.norm_inf() << std::endl;
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	
	std::cout << std::abs(std::complex<float>(5, 13)) << std::endl;
}