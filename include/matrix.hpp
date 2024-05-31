#ifndef __MATRIX_HPP__
# define __MATRIX_HPP__

#include "vector.hpp"

class MatrixException : public std::exception {
	public:
		MatrixException(std::string msg) {
			message = "MatrixException: " + msg;
		}
		const char *what() const noexcept override {
			return message.c_str();
		}

	private:
		std::string message;
};

template<typename K>
class Matrix {
	public:
		Matrix(const Matrix& other) : 
			_matrix(other._matrix),
			_shape(other._shape) {
		}
		Matrix(const Vector<Vector<K>>& matrix) : _matrix(matrix) {
			_shape = "(" + std::to_string(matrix.size()) + ", " + std::to_string(matrix[0].size()) + ")";
		}
		auto operator=(Matrix<K>& other) {
			_matrix = other._matrix;
			_shape = other._shape;
		}

		template<std::size_t N, std::size_t M>
		static auto from(const K (&array)[N][M]) {
			Vector<Vector<K>> matrix(N);
			for (std::size_t i = 0; i < N; i++) {
				Vector<K> vector(M);
				for (std::size_t j = 0; j < M; j++) {
					vector[j] = array[i][j];
				}
				matrix[i] = vector;
			}
			return Matrix(matrix);
		}

		auto add(Matrix<K> other) {
			if (this->shape() != other.shape())
				return Matrix(*this);
			for (std::size_t i = 0; i < _matrix.size(); i++) {
				for(std::size_t j = 0; j < _matrix[i].size(); j++) {
					_matrix[i][j] += other[i][j];
				}
			}
			return *this;
		}
		auto sub(Matrix<K> other) {
			if (this->shape() != other.shape())
				return Matrix(*this);
			for (std::size_t i = 0; i < _matrix.size(); i++) {
				for(std::size_t j = 0; j < _matrix[i].size(); j++) {
					_matrix[i][j] -= other[i][j];
				}
			}
			return *this;
		}
		auto mul(K k) {
			for (std::size_t i = 0; i < this->size(); i++) {
				for(std::size_t j = 0; j < (*this)[i].size(); j++) {
					_matrix[i][j] *= k;
				}
			}
			return *this;
		}
		auto mul_vec(Vector<K> v) {
			Vector<K> result(this->size());
			for (std::size_t i = 0; i < this->size(); i++) {
				result[i] = v.dot((*this)[i]);
			}
			return result;
		}
		auto mul_mat(Matrix<K> m) {
			Vector<Vector<K>> result(this->size(), Vector<K>(m[0].size()));
			for (std::size_t i = 0; i < m[0].size(); i++) {
				for (std::size_t j = 0; j < this->size(); j++) {
					for (std::size_t k = 0; k < m.size(); k++) {
						result[j][i] += (*this)[j][k] * m[k][i];
					}
				}
			}
			return Matrix(result);
		}
		auto trace() const {
			if (!this->isSquare())
				throw MatrixException("Can not compute the Trace of a non-square matrix.");
			K result(0);
			for (std::size_t i = 0; i < this->size(); i++) {
				result += (*this)[i][i];
			}
			return result;
		}
		auto transpose() const {
			Vector<Vector<K>> result((*this)[0].size(), Vector<K>(this->size()));
			for (std::size_t i = 0; i < this->size(); i++) {
				for (std::size_t j = 0; j < (*this)[0].size(); j++) {
					result[j][i] = (*this)[i][j];
				}
			}
			return Matrix(result);
		}
		auto row_echelon() const {
			Matrix result(*this);
			std::size_t pivot_row = 0;
			for (std::size_t col = 0; col < result[0].size(); col++) {
				for (std::size_t row = pivot_row; row < result.size(); row++) {
					if (result[row][col] != 0) {
						if (row != pivot_row) {
							Vector<K> tmp = result[pivot_row];
							result[pivot_row] = result[row];
							result[row] = tmp;
						}
						result[pivot_row] = result[pivot_row] * (1 / result[pivot_row][col]);
						for (std::size_t inner = 0; inner < result.size(); inner++) {
							if (inner == pivot_row) {
								continue;
							}
							result[inner] -= result[pivot_row] * (result[inner][col] / result[pivot_row][col]);	
						}
						pivot_row++;
						break;
					}
				}
			}
			return result;
		}
		auto determinant() const {
			if (!this->isSquare()) {
				throw MatrixException("Determinant: Matrix need to be square");
			}
			K result(0);
			if (this->size() == 2) {
				return (*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1];
			} else {
				int sign = 1;
				for (std::size_t row = 0; row < this->size(); row++) {
					for (std::size_t col = 0; col < this->size(); col++) {
						Matrix m(Vector<Vector<K>>(this->size() - 1, Vector<K>(this->size() - 1)));
						std::size_t output_row = 0;
						for (std::size_t input_row = 0; input_row < this->size(); input_row++) {
							if (input_row == row) {
								continue;
							}
							std::size_t output_col = 0;
							for (std::size_t input_col = 0; input_col < this->size(); input_col++) {
								if (input_col == col) {
									continue;
								}
								K k = (*this)[input_row][input_col];
								m[output_row][output_col] = k;
								output_col++;
							}
							output_row++;
						}
						result += m.determinant() * (*this)[0][col] * sign;
						sign = -sign;
					}
				}
			}
			return result;
		}

		auto operator+(Matrix<K> other) const {
			return Matrix(*this).add(other);
		}
		auto operator+=(Matrix<K> other) {
			return add(other);
		}
		auto operator-(Matrix<K> other) const {
			return Matrix(*this).sub(other);
		}
		auto operator-=(Matrix<K> other) {
			return sub(other);
		}
		auto operator*(K k) const {
			return Matrix(*this).mul(k);
		}		
		auto operator*=(K k) {
			return mul(k);
		}
		auto &operator[](std::size_t n) {
			return _matrix[n];
		}
		auto operator[](std::size_t n) const {
			return _matrix[n];
		}

		auto shape() const {
			return _shape;
		}
		auto size() const {
			return _matrix.size();
		}
		bool isSquare() const {
			return _matrix.size() == _matrix[0].size();
		}

	private:
		Matrix() {}
		
		Vector<Vector<K>> _matrix;
		std::string _shape;
};

template<typename K>
// auto& operator<<(std::ostream& os, Matrix<K>& matrix) {
// 	os << "Matrix of shape " << matrix.shape() << std::endl;
// 	for (std::size_t j = 0; j < matrix[0].size(); j++) {
// 		os << "[";
// 		for (std::size_t i = 0; i < matrix.size(); i++) {
// 			os << matrix[i][j] << (i < matrix.size() - 1 ? "," : "");
// 		}
// 		os << "]" << std::endl;
// 	}
// 	return os;
// };
auto& operator<<(std::ostream& os, Matrix<K>& matrix) {
	os << "Matrix of shape " << matrix.shape() << std::endl;
	for (std::size_t i = 0; i < matrix.size(); i++) {
		os << matrix[i].asString();
		if (i < matrix.size() - 1)
			os << '\n';
	}
	return os;
};
#endif