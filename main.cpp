#include "vector.hpp"
#include <iostream>

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

	// std::array<float, 3> arr = {1.1, 2.0, 3.0};
	// std::array<float, 4> arr2 = {1.1, 2.0, 3.0, 12};
	// std::array<char, 5> t = {'p', 'r', 'o', 'u', 't'};
	// std::array<char, 2> g = {'a', 'i'};
	// // std::array<std::string, 3> h = 
	// 	{std::string("Test"), std::string("e"), std::string("")};
	// std::array<std::string, 1> j = 
	// 	{std::string("B")};

	// Vector x = Vector<float>::from(arr);
	// Vector y = Vector<float>::from(arr2);
	// Vector z = x + y;
	// std::cout << z << std::endl;
	// z = z - y;
	// std::cout << z << std::endl;
	// z = z * 2;
	// z = z - x * 2;
	// std::cout << z << std::endl;
	// // Vector y = Vector<int>::from([1, 2, 3]);
	// std::cout << x << std::endl;
	// std::cout << y << std::endl;

	// std::cout << (Vector<char>::from(t) + Vector<char>::from(g)) << std::endl;
	// std::cout << (Vector<std::string>::from(h) + Vector<std::string>::from(j)) << std::endl;
}