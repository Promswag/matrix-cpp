#include "matrix.hpp"
#include "print.hpp"
#include <iostream>

int main() {
	{
		try {
			auto u = Vector<float>::from({2., 3.});
			const auto v = Vector<float>::from({5., 7.});
			std::cout << GREEN << u.add(v) << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
	}
	{
		try {
			auto u = Vector<float>::from({2., 3.});
			const auto v = Vector<float>::from({5., 7.});
			std::cout << GREEN << u.sub(v) << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
	}
	{
		try {
			auto u = Vector<float>::from({2., 3.});
			std::cout << GREEN << u.scl(2.) << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
	}
	{
		try {
			auto u = Matrix<float>::from({{1, 2}, {3, 4}});
			std::cout << GREEN << u.scl(2.) << std::endl;
		} catch (std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
	}
}