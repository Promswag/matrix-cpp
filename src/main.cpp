#include "matrix.hpp"
#include "print.hpp"
#include "maths.hpp"
#include <fstream>

int main() {
	// {
	// 	auto A = Vector<int>::from({1, 2, 3});
	// 	PRINT(GREEN, "A");
	// 	PRINT(WHITE, A);
	// 	ENDL;

	// 	auto B = Vector<int>::from({-1, 2, 0});
	// 	PRINT(GREEN, "B");
	// 	PRINT(WHITE, B);
	// 	ENDL;

	// 	PRINT(GREEN, "A + B");
	// 	PRINT(WHITE, A + B);
	// 	ENDL;

	// 	PRINT(GREEN, "A - B");
	// 	PRINT(WHITE, A - B);
	// 	ENDL;

	// 	PRINT(GREEN, "A * 2");
	// 	PRINT(WHITE, A * 2);
	// 	ENDL;

	// 	auto C = A.add(B);
	// 	PRINT(GREEN, "C = A.add(B)");
	// 	PRINT(WHITE, C);
	// 	ENDL;

	// 	A.add(C);
	// 	PRINT(GREEN, "A.add(C)");
	// 	PRINT(WHITE, A);
	// 	ENDL;
	// }
	// {
	// 	auto M = Matrix<float>::from({{0, 1}, {1, 0}});
	// 	PRINT(GREEN, (M.isSquare() ? "Square" : "Non-square"));
	// 	PRINT(WHITE, M);
	// }
	// {
	// 	auto M = Matrix<float>::from({{0, 1}, {1, 0}, {3, 5}});
	// 	PRINT(GREEN, (M.isSquare() ? "Square" : "Non-square"));
	// 	PRINT(WHITE, M);
	// }
	// {
	// 	auto M = Matrix<float>::from({{0, 1, 5}, {3, 5, 9}});
	// 	PRINT(GREEN, (M.isSquare() ? "Square" : "Non-square"));
	// 	PRINT(WHITE, M);
	// }
	// {
	// 	auto M = Matrix<float>::from({{0, -1, 2}, {-3, 4, -5}, {6, -7, 8}});
	// 	PRINT(GREEN, (M.isSquare() ? "Square" : "Non-square"));
	// 	PRINT(WHITE, M);
	// }
	// {
	// 	auto M = Matrix<float>::from({{0.7, -1, 2}, {-3, 4, -5}});
	// 	PRINT(GREEN, "M");
	// 	PRINT(WHITE, M);
	// 	auto N = Matrix<float>::from({{0, -1, 2}, {-3, 4, -5}});
	// 	PRINT(GREEN, "N");
	// 	PRINT(WHITE, N);
	// 	auto O = M + N;
	// 	PRINT(GREEN, "O = M + N");
	// 	PRINT(WHITE, O);

	// 	O.add(M);
	// 	PRINT(GREEN, "O.add(M)");
	// 	PRINT(WHITE, O);

	// 	auto X = O * 5;
	// 	PRINT(GREEN, "X = O * 5");5
	// 	PRINT(WHITE, X);
	// 	PRINT(GREEN, "O");
	// 	PRINT(WHITE, O);

	// 	X *= 5;
	// 	PRINT(GREEN, "X *= 5");
	// 	PRINT(WHITE, X);

	// 	X += X;
	// 	PRINT(GREEN, "X += X");
	// 	PRINT(WHITE, X);
	// }
	// {
	// 	auto A = Vector<int>::from({10, 0, -10});
	// 	PRINT(GREEN, "A");
	// 	PRINT(WHITE, A);
	// 	ENDL;

	// 	auto B = Vector<int>::from({5, -1, 10});
	// 	PRINT(GREEN, "B");
	// 	PRINT(WHITE, B);
	// 	ENDL;

	// 	auto C = linear_combination({A, B}, {5, 10});
	// 	PRINT(GREEN, "LINEAR COMBINATION ({A, B}, {5, 10})");
	// 	PRINT(WHITE, C);
	// 	ENDL;
	// }
	// {
	// 	auto A = Vector<int>::from({10, 0, -10});
	// 	auto B = Vector<int>::from({5, -1, 10});
	// 	auto C = A.dot(B);
	// 	PRINT(GREEN, "DOT PRODUCT A.dot(B)");
	// 	PRINT(WHITE, C);
	// 	try {
	// 		A.dot(Vector<int>::from({10, 0}));
	// 	} catch(VectorException &e) {
	// 		PRINT(RED, e.what());
	// 	}
	// }
	// {
	// 	auto A = lerp(0., 1., 0.5);
	// 	PRINT(GREEN, "LINEAR INTERPOLATION (0, 1, 0.5)");
	// 	PRINT(WHITE, A);
	// }
	// {
	// 	auto A = Vector<float>::from({-10, -5, 0});
	// 	auto B = Vector<float>::from({-50, -60, -70});
	// 	auto C = lerp(A, B, 0.4);
	// 	PRINT(GREEN, "LINEAR INTERPOLATION ({-10, -10, -10}, {-50, -50, -50}, 0.5)");
	// 	PRINT(WHITE, C);
	// }
	// {
	// 	auto A = Vector<float>::from({10, 0, -10});
	// 	auto B = Vector<float>::from({5, -1, 10});
	// 	auto C = lerp(A, B, 0.5);
	// 	PRINT(GREEN, "LINEAR INTERPOLATION ({10, 0, -10}, {5, -1, 10}, 0.5)");
	// 	PRINT(WHITE, C);
	// }
	// {
	// 	auto A = Matrix<float>::from({{0, 20, 40}, {60, 80, 100}});
	// 	auto B = Matrix<float>::from({{100, 80, 60}, {40, 20, 0}});
	// 	auto C = lerp(A, B, 0.1);
	// 	PRINT(GREEN, A);
	// 	PRINT(GREEN, B);
	// 	PRINT(WHITE, C);
	// }
	// {
	// 	auto A = Vector<int>::from({10, 0, -10});
	// 	PRINT(GREEN, "norm_1");
	// 	PRINT(WHITE, A.norm_1());
	// }
	// {
	// 	auto A = Vector<int>::from({-1, -2});
	// 	PRINT(GREEN, "norm");
	// 	PRINT(WHITE, A.norm());
	// }
	// {
	// 	auto A = Vector<int>::from({10, 0, -100, 37, -1});
	// 	PRINT(GREEN, "norm_inf");
	// 	PRINT(WHITE, A.norm_inf());
	// }
	// {
	// 	auto A = Vector<int>::from({0, 0});
	// 	auto B = Vector<int>::from({0, 0});
	// 	PRINT(GREEN, "angle_cos(A, B)");
	// 	PRINT(WHITE, angle_cos(A, B));
	// }
	// {
	// 	auto A = Vector<float>::from({1., 2., 3.});
	// 	auto B = Vector<float>::from({4., 5., 6.});
	// 	PRINT(GREEN, "angle_cos(A, B)");
	// 	PRINT(WHITE, angle_cos(A, B));
	// }
	// {
	// 	auto A = Vector<float>::from({4., 2., -3.});
	// 	auto B = Vector<float>::from({-2., -5., 16.});
	// 	PRINT(GREEN, "cross_product(A, B)");
	// 	PRINT(WHITE, cross_product(A, B));
	// }
	// {
	// 	auto u = Matrix<float>::from({{1., 0.}, {0., 1.}});
	// 	auto v = Vector<float>::from({4., 2.});
	// 	PRINT(GREEN, "u.mul_vec(v)");
	// 	PRINT(WHITE, u.mul_vec(v));
	// }
	// {
	// 	auto u = Matrix<float>::from({{2., 0.}, {0., 2.}});
	// 	auto v = Vector<float>::from({4., 2.});
	// 	PRINT(GREEN, "u.mul_vec(v)");
	// 	PRINT(WHITE, u.mul_vec(v));
	// }
	// {
	// 	auto u = Matrix<float>::from({{2., -2.}, {-2., 2.}});
	// 	auto v = Vector<float>::from({4., 2.});
	// 	PRINT(GREEN, "u.mul_vec(v)");
	// 	PRINT(WHITE, u.mul_vec(v));
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({{1., 0.}, {0., 1.}});
	// 		auto v = Vector<float>::from({4., 2., 100., 500., 1000., 0., 0.});
	// 		PRINT(GREEN, "u.mul_vec(v)");
	// 		PRINT(WHITE, u.mul_vec(v));
	// 	} catch (VectorException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({{1., 0.}, {-1., -3.}, {2., 1.}});
	// 		auto v = Vector<float>::from({2., 1., 0.,});
	// 		PRINT(GREEN, "u.mul_vec(v)");
	// 		PRINT(WHITE, u.mul_vec(v));
	// 	} catch (VectorException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({{0., -4,}, {4., -3.}, {-2., 0.}});
	// 		auto v = Matrix<float>::from({{0., 1., 2.}, {1., -1, 3.}});
	// 		auto x = u.mul_mat(v);
	// 		PRINT(GREEN, "u.mul_mat(v)");
	// 		PRINT(WHITE, x);
	// 	} catch (VectorException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({{0., 4, -2,}, {-4., -3., 0}});
	// 		auto v = Matrix<float>::from({{0., 1.}, {1., -1}, {2., 3.}});
	// 		auto x = u.mul_mat(v);
	// 		PRINT(GREEN, "u.mul_mat(v)");
	// 		PRINT(WHITE, x);
	// 	} catch (VectorException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({{3., -5.}, {6., 8.}});
	// 		auto v = Matrix<float>::from({{2., 1.}, {4., 2.}});
	// 		auto x = u.mul_mat(v);
	// 		PRINT(GREEN, "u.mul_mat(v)");
	// 		PRINT(RED, u);
	// 		PRINT(RED, v);
	// 		PRINT(WHITE, x);
	// 	} catch (VectorException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({{3., 6.}, {-5., 8.}});
	// 		auto v = Matrix<float>::from({{2., 4.}, {1., 2.}});
	// 		auto x = u.mul_mat(v);
	// 		PRINT(GREEN, "u.mul_mat(v)");
	// 		PRINT(RED, u);
	// 		PRINT(RED, v);
	// 		PRINT(WHITE, x);
	// 	} catch (VectorException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({{3., 6.}, {-5., 8.}});
	// 		PRINT(GREEN, "u.trace()");
	// 		PRINT(RED, u.trace());
	// 	} catch (MatrixException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({{3., 6., 5.}, {-5., 8., 2.}});
	// 		PRINT(GREEN, "u.trace()");
	// 		PRINT(RED, u.trace());
	// 	} catch (MatrixException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	// TRANSPOSE
	// 	auto u = Matrix<float>::from({{3., 6., 5.}, {-5., 8., 2.}});
	// 	PRINT(GREEN, u);
	// 	auto v = u.transpose();
	// 	PRINT(RED, v);
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({
	// 			{-88, -2., -3., -4., -5.}, 
	// 			{-5., -4., -3., -2., -1.}, 
	// 			{1., 2., 3., 4., 5.},
	// 			{0., 0., 0., 0., 0.}});
	// 		PRINT(GREEN, "u.row_echelon()");
	// 		auto v = u.row_echelon();
	// 		PRINT(RED, v);
	// 		PRINT(YELLOW, v.rank());
	// 	} catch (MatrixException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({
	// 			{1, -1}, 
	// 			{-1, 1}
	// 			});
	// 		PRINT(GREEN, "u.determinant()");
	// 		PRINT(RED, u.determinant());
	// 	} catch (MatrixException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({
	// 			{2, 0, 0}, 
	// 			{0, 2, 0}, 
	// 			{0, 0, 2},
	// 			});
	// 		PRINT(GREEN, "u.determinant()");
	// 		PRINT(RED, u.determinant());
	// 	} catch (MatrixException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({
	// 			{8, 5, -2}, 
	// 			{4, 7, 20}, 
	// 			{7, 6, 1},
	// 			});
	// 		PRINT(GREEN, "u.determinant()");
	// 		PRINT(RED, u.determinant());
	// 	} catch (MatrixException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({
	// 			{8, 5, -2, 4}, 
	// 			{4, 2.5, 20, 4}, 
	// 			{8, 5, 1, 4},
	// 			{28, -4, 17, 1},
	// 			});
	// 		PRINT(GREEN, "u.determinant()");
	// 		PRINT(RED, u.determinant());
	// 	} catch (MatrixException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({
	// 			{3.2, 1.7, -0.5, 2.1, 4.8, 0.9,},
	// 			{-2.4, 5.6, 0.3, 1.1, -1.8, 3.7,},
	// 			{4.5, -1.2, 2.9, 0.7, 3.1, -0.4,},
	// 			{-3.6, 2.5, -1.9, 4.2, 1.5, 2.8,},
	// 			{0.6, -4.1, 3.4, -2.7, 1.3, 5.2,},
	// 			{-1.8, 3.9, -2.2, 4.6, -3.5, 1.6,}, 
	// 			});
	// 		PRINT(GREEN, "u.determinant()");
	// 		PRINT(RED, u.determinant());
	// 	} catch (MatrixException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto u = Matrix<float>::from({
	// 			{1., 2., 3., 4., 4.}, 
	// 			{0., 2., 3., 13., 5.}, 
	// 			{7., 0., 20., 4., 5.},
	// 			{0., 0., 0., 4., 5.},
	// 			{0., 0., 9., 0., 5.}});
	// 		PRINT(GREEN, "u.inverse()");
	// 		auto v = u.inverse();
	// 		PRINT(RED, v);
	// 		auto w = Matrix<float>::identity(v.size());
			
	// 		auto U = u.mul_mat(v);
	// 		PRINT(GREEN, U);
	// 		auto V = v.mul_mat(u);
	// 		PRINT(GREEN, V);
	// 	} catch (MatrixException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto matrix = Matrix<float>::from({
	// 			{1., 2., -1.,}, 
	// 			{-2., 0., 1.,}, 
	// 			{1., -1., 0.,}});
	// 		PRINT(GREEN, "MATRIX");
	// 		PRINT(GREEN, matrix);
	// 		ENDL;
			
	// 		auto inverse = matrix.inverse();
	// 		PRINT(RED, "MATRIX INVERSE");
	// 		PRINT(RED, inverse);
	// 		ENDL;
			
	// 		auto identity = Matrix<float>::identity(matrix.size());
	// 		PRINT(YELLOW, "IDENTITY MATRIX");
	// 		PRINT(YELLOW, identity);
	// 		ENDL;
			
	// 		auto mxr = matrix.mul_mat(inverse);
	// 		PRINT(GREEN, "MATRIX * INVERSE");
	// 		PRINT(GREEN, mxr);
	// 		ENDL;
			
	// 		auto rxm = inverse.mul_mat(matrix);
	// 		PRINT(RED, "INVERSE * MATRIX");
	// 		PRINT(RED, rxm);
	// 		ENDL;
			
	// 	} catch (MatrixException &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }
	// {
	// 	try {
	// 		auto matrix = Matrix<float>::from({
	// 			{1., 2., -1.,}, 
	// 			{-2., 0., 1.,}, 
	// 			{1., -1., 0.,}});
	// 		PRINT(RED, matrix);
	// 		PRINT(RED, "Rank of the matrix : " + std::to_string(matrix.rank()));
	// 	} catch (std::exception &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	// }

	{
		Matrix<float> proj = projection(45., 1.2, 0.1, 100.00);
		std::ofstream proj_file;
		proj_file.open("matrix_display/proj");
		proj_file << proj.asString();
		proj_file.close();
		std::cout << proj.asString();
		// proj.print();
	}
}