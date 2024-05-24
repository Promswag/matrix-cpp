#include "matrix.hpp"
// #include "vector.hpp"
// #include <iostream>

int main() {
	auto A = Vector<int>::from({1, 2, 3});
	std::cout << A << std::endl;
	auto B = Vector<int>::from({-1, 2, 0});
	std::cout << B << std::endl;

	std::cout << A + B << std::endl;
	std::cout << A - B << std::endl;
	std::cout << A * 2 << std::endl;

	auto C = A.add(B);
	std::cout << C << std::endl;
	std::cout << A << std::endl;
	A.add(B);
	std::cout << C << std::endl;
	std::cout << A << std::endl;
	
	
	{
		auto M = Matrix<float>::from({{0, 1}, {1, 0}});
		std::cout << M << std::endl;
		std::cout << (M.isSquare() ? "Square" : "Non-square") << std::endl;
		std::cout << std::endl;
	}
	{
		auto M = Matrix<float>::from({{0, 1}, {1, 0}, {3, 5}});
		std::cout << M << std::endl;
		std::cout << (M.isSquare() ? "Square" : "Non-square") << std::endl;
		std::cout << std::endl;
	}
	{
		auto M = Matrix<float>::from({{0, 1, 5}, {3, 5, 9}});
		std::cout << M << std::endl;
		std::cout << (M.isSquare() ? "Square" : "Non-square") << std::endl;
		std::cout << std::endl;
	}
	{
		auto M = Matrix<float>::from({{0, -1, 2}, {-3, 4, -5}, {6, -7, 8}});
		std::cout << M << std::endl;
		std::cout << (M.isSquare() ? "Square" : "Non-square") << std::endl;
		std::cout << std::endl;
	}
	{
		auto M = Matrix<float>::from({{0, -1, 2}, {-3, 4, -5}});
		auto N = Matrix<float>::from({{0, -1, 2}, {-3, 4, -5}});
		auto O = M + N;
		std::cout << O << std::endl;
		O.add(M);
		std::cout << O << std::endl;
		auto X = O * 5;
		std::cout << X << std::endl;
		X += X;
		std::cout << X << std::endl;
	}
}