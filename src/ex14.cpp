#include "matrix.hpp"
#include "lalgebra.hpp"
#include "print.hpp"
#include <iostream>
#include <fstream>

int main() {
	header("Exercice 14 - Bonus: Projection matrix", BLUE);
	{
		// TEST 01
		std::cout << GREEN << "#### Test 01 ####" << std::endl;
		try {
			Matrix<float> proj = projection(90., 1., 0.1, 100.00);
			std::ofstream proj_file;
			proj_file.open("matrix_display/proj");
			if (proj_file.is_open()) {
				proj_file << proj.asString();
				std::cout << "Projection matrix saved in matrix_display/proj" << std::endl;
			}
			else {
				std::cerr << RED << "Could not open matrix_display/proj" << DEFAULT << std::endl;
			}
			proj_file.close();
		} catch (const std::exception &e) {
			std::cout << RED << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}