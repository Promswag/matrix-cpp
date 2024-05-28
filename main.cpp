#include "matrix.hpp"
#include "print.hpp"
#include "maths.hpp"

int main() {
	{
		auto A = Vector<int>::from({1, 2, 3});
		PRINT(GREEN, "A");
		PRINT(WHITE, A);
		ENDL;

		auto B = Vector<int>::from({-1, 2, 0});
		PRINT(GREEN, "B");
		PRINT(WHITE, B);
		ENDL;

		PRINT(GREEN, "A + B");
		PRINT(WHITE, A + B);
		ENDL;

		PRINT(GREEN, "A - B");
		PRINT(WHITE, A - B);
		ENDL;

		PRINT(GREEN, "A * 2");
		PRINT(WHITE, A * 2);
		ENDL;

		auto C = A.add(B);
		PRINT(GREEN, "C = A.add(B)");
		PRINT(WHITE, C);
		ENDL;

		A.add(C);
		PRINT(GREEN, "A.add(C)");
		PRINT(WHITE, A);
		ENDL;
	}
	{
		auto M = Matrix<float>::from({{0, 1}, {1, 0}});
		PRINT(GREEN, (M.isSquare() ? "Square" : "Non-square"));
		PRINT(WHITE, M);
	}
	{
		auto M = Matrix<float>::from({{0, 1}, {1, 0}, {3, 5}});
		PRINT(GREEN, (M.isSquare() ? "Square" : "Non-square"));
		PRINT(WHITE, M);
	}
	{
		auto M = Matrix<float>::from({{0, 1, 5}, {3, 5, 9}});
		PRINT(GREEN, (M.isSquare() ? "Square" : "Non-square"));
		PRINT(WHITE, M);
	}
	{
		auto M = Matrix<float>::from({{0, -1, 2}, {-3, 4, -5}, {6, -7, 8}});
		PRINT(GREEN, (M.isSquare() ? "Square" : "Non-square"));
		PRINT(WHITE, M);
	}
	{
		auto M = Matrix<float>::from({{0, -1, 2}, {-3, 4, -5}});
		PRINT(GREEN, "M");
		PRINT(WHITE, M);
		auto N = Matrix<float>::from({{0, -1, 2}, {-3, 4, -5}});
		PRINT(GREEN, "N");
		PRINT(WHITE, N);
		auto O = M + N;
		PRINT(GREEN, "O = M + N");
		PRINT(WHITE, O);

		O.add(M);
		PRINT(GREEN, "O.add(M)");
		PRINT(WHITE, O);

		auto X = O * 5;
		PRINT(GREEN, "X = O * 5");
		PRINT(WHITE, X);
		PRINT(GREEN, "O");
		PRINT(WHITE, O);

		X *= 5;
		PRINT(GREEN, "X *= 5");
		PRINT(WHITE, X);

		X += X;
		PRINT(GREEN, "X += X");
		PRINT(WHITE, X);
	}
	{
		auto A = Vector<int>::from({10, 0, -10});
		PRINT(GREEN, "A");
		PRINT(WHITE, A);
		ENDL;

		auto B = Vector<int>::from({5, -1, 10});
		PRINT(GREEN, "B");
		PRINT(WHITE, B);
		ENDL;

		auto C = linear_combination({A, B}, {5, 10});
		PRINT(GREEN, "LINEAR COMBINATION {A, B} {5, 10}");
		PRINT(WHITE, C);
		ENDL;
	}
	{
		auto A = Vector<int>::from({10, 0, -10});
		auto B = Vector<int>::from({5, -1, 10});
		try {
			auto C = A.dot(B);
			PRINT(GREEN, "DOT PRODUCT A.dot(B)");
			PRINT(WHITE, C);
		} catch(VectorException &e) {
			PRINT(RED, e.what());
		}
	}
}