#ifndef __MATRIX_HPP__
# define __MATRIX_HPP__

#include "vector.hpp"
#include <complex>

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

template<typename K, typename = std::enable_if_t<std::is_arithmetic<K>::value || std::is_same<K, std::complex<double>>::value>>
class Matrix {
	public:
		Matrix(const Matrix & other) : 
			_matrix(other._matrix),
			_shape(other._shape) {
		}
		Matrix(Vector<Vector<K>> & matrix) : _matrix(matrix) {
			_shape = "(" + std::to_string(matrix.size()) + ", " + std::to_string(matrix[0].size()) + ")";
		}
		auto operator=(Matrix<K> & other) {
			_matrix = other._matrix;
			_shape = other._shape;
		}

		// template<std::size_t N, std::size_t M>
		// static auto from(const K (&array)[N][M]) {
		// 	Vector<Vector<K>> matrix(N);
		// 	for (std::size_t i = 0; i < N; i++) {
		// 		Vector<K> vector(M);
		// 		for (std::size_t j = 0; j < M; j++) {
		// 			vector[j] = array[i][j];
		// 		}
		// 		matrix[i] = vector;
		// 	}
		// 	return Matrix(matrix);
		// }		
		
		template<std::size_t N, std::size_t M>
		static auto from(const K (&array)[N][M]) {
			Vector<Vector<K>> matrix(N, Vector<K>(M, K(0)));
			for (std::size_t i = 0; i < N; i++) {
				for (std::size_t j = 0; j < M; j++) {
					matrix[i][j] = array[i][j];
				}
			}
			return Matrix(matrix);
		}
		
		static auto identity(std::size_t N) {
			Vector<Vector<K>> matrix(N, Vector<K>(N, K(0)));
			for (std::size_t i = 0; i < matrix.size(); i++) {
				matrix[i][i] = 1;
			}
			return Matrix(matrix);
		}

		auto & add(Matrix<K> & other) {
			if (this->shape() != other.shape()) {
				throw MatrixException("add: Matrices should be of the same shape.");
			}
			for (std::size_t i = 0; i < _matrix.size(); i++) {
				for(std::size_t j = 0; j < _matrix[i].size(); j++) {
					_matrix[i][j] += other[i][j];
				}
			}
			return *this;
		}
		auto & add(const Matrix<K> & other) {
			if (this->shape() != other.shape()) {
				throw MatrixException("add: Matrices should be of the same shape.");
			}
			for (std::size_t i = 0; i < _matrix.size(); i++) {
				for(std::size_t j = 0; j < _matrix[i].size(); j++) {
					_matrix[i][j] += other[i][j];
				}
			}
			return *this;
		}
		auto & sub(Matrix<K> & other) {
			if (this->shape() != other.shape()) {
				throw MatrixException("sub: Matrices should be of the same shape.");
			}
			for (std::size_t i = 0; i < _matrix.size(); i++) {
				for(std::size_t j = 0; j < _matrix[i].size(); j++) {
					_matrix[i][j] -= other[i][j];
				}
			}
			return *this;
		}
		auto & sub(const Matrix<K> & other) {
			if (this->shape() != other.shape()) {
				throw MatrixException("sub: Matrices should be of the same shape.");
			}
			for (std::size_t i = 0; i < _matrix.size(); i++) {
				for(std::size_t j = 0; j < _matrix[i].size(); j++) {
					_matrix[i][j] -= other[i][j];
				}
			}
			return *this;
		}
		auto & scl(K k) {
			for (std::size_t i = 0; i < this->size(); i++) {
				for(std::size_t j = 0; j < (*this)[i].size(); j++) {
					_matrix[i][j] *= k;
				}
			}
			return *this;
		}
		auto mul_vec(Vector<K> & v) {
			Vector<K> result(this->size());
			for (std::size_t i = 0; i < this->size(); i++) {
				result[i] = v.dot((*this)[i]);
			}
			return result;
		}
		auto mul_mat(Matrix<K> & m) {
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
						for (std::size_t inner = pivot_row + 1; inner < result.size(); inner++) {
							if (result[inner][col] < result[pivot_row][col]) {
								result[inner] -= result[pivot_row] * (result[inner][col] / result[pivot_row][col]);
							}
							else {
								result[inner] -= (result[pivot_row] * result[inner][col]) * (1 / result[pivot_row][col]);
							}
						}
						pivot_row++;
						break;
					}
				}
			}
			return result;
		}
		auto rref() const {
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
							if (result[inner][col] < result[pivot_row][col]) {
								result[inner] -= result[pivot_row] * (result[inner][col] / result[pivot_row][col]);
							}
							else {
								result[inner] -= (result[pivot_row] * result[inner][col]) * (1 / result[pivot_row][col]);
							}
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
				throw MatrixException("Determinant: Matrix is not square");
			}
			K result(0);
			if (this->size() == 2) {
				return (*this)[0][0] * (*this)[1][1] - (*this)[1][0] * (*this)[0][1];
			} else {
				for (std::size_t col = 0; col < this->size(); col++) {
					if ((*this)[0][col] == 0) {
						continue;
					}
					Matrix m(Vector<Vector<K>>(this->size() - 1, Vector<K>(this->size() - 1)));
					for (std::size_t input_row = 1; input_row < this->size(); input_row++) {
						std::size_t output_col = 0;
						for (std::size_t input_col = 0; input_col < this->size(); input_col++) {
							if (input_col == col) {
								continue;
							}
							m[input_row - 1][output_col] = (*this)[input_row][input_col];
							output_col++;
						}
					}
					result += m.determinant() * (*this)[0][col] * (col % 2 ? -1 : 1);
				}
			}
			return result;
		}
		auto inverse() const {
			if (!this->isSquare()) {
				throw MatrixException("Inverse: Matrix is not square");
			}
			Matrix origin(*this);
			Matrix result = Matrix::identity(this->size());
			std::size_t pivot_row = 0;
			for (std::size_t col = 0; col < origin[0].size(); col++) {
				for (std::size_t row = pivot_row; row < origin.size(); row++) {
					if (origin[row][col] != 0) {
						if (row != pivot_row) {
							Vector<K> tmp = origin[pivot_row];
							origin[pivot_row] = origin[row];
							origin[row] = tmp;
							
							tmp = result[pivot_row];
							result[pivot_row] = result[row];
							result[row] = tmp;
						}
						result[pivot_row] = result[pivot_row] * (1 / origin[pivot_row][col]);
						origin[pivot_row] = origin[pivot_row] * (1 / origin[pivot_row][col]);
						for (std::size_t inner = 0; inner < origin.size(); inner++) {
							if (inner == pivot_row) {
								continue;
							}
							// if (origin[inner][col] < origin[pivot_row][col]) {
								// result[inner] -= result[pivot_row] * (origin[inner][col] / origin[pivot_row][col]);	
								// origin[inner] -= origin[pivot_row] * (origin[inner][col] / origin[pivot_row][col]);
							// }
							// else {
								// result[inner] -= result[pivot_row] * (origin[inner][col] * (1 / origin[pivot_row][col]));	
								// origin[inner] -= origin[pivot_row] * (origin[inner][col] * (1 / origin[pivot_row][col]));
							// }
							result[inner] -= result[pivot_row] * origin[inner][col] * (1 / origin[pivot_row][col]);	
							origin[inner] -= origin[pivot_row] * origin[inner][col] * (1 / origin[pivot_row][col]);	
						}
						pivot_row++;
						break;
					}
				}
			}
			return result;
		}
		auto rank() const {
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
			return pivot_row;
		}

		auto operator+(Matrix<K> & other) const {
			return Matrix(*this).add(other);
		}
		auto operator+(const Matrix<K> & other) const {
			return Matrix(*this).add(other);
		}
		auto & operator+=(Matrix<K> & other) {
			return add(other);
		}
		auto & operator+=(const Matrix<K> & other) {
			return add(other);
		}
		auto operator-(Matrix<K> & other) const {
			return Matrix(*this).sub(other);
		}
		auto operator-(const Matrix<K> & other) const {
			return Matrix(*this).sub(other);
		}
		auto & operator-=(Matrix<K> & other) {
			return sub(other);
		}
		auto & operator-=(const Matrix<K> & other) {
			return sub(other);
		}
		auto operator*(K k) const {
			return Matrix(*this).scl(k);
		}		
		auto & operator*=(K k) {
			return scl(k);
		}
		auto &operator[](std::size_t n) {
			if (n < this->size())
				return _matrix[n];
			else
				throw MatrixException("Index out of bounds");
		}
		auto operator[](std::size_t n) const {
			if (n < this->size())
				return _matrix[n];
			else
				throw MatrixException("Index out of bounds");
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
		void print() const {
			for (std::size_t i = 0; i < this->size(); i++) {
				for (std::size_t j = 0; j < (*this)[0].size(); j++) {
					std::cout << (*this)[i][j] << (j < (*this)[0].size() - 1 ? ", " : "");
				}
				std::cout << std::endl;
			}
		}
		std::string asString() const {
			std::string result = "";
			for (std::size_t i = 0; i < this->size(); i++) {
				for (std::size_t j = 0; j < (*this)[0].size(); j++) {
					result += std::to_string((*this)[i][j]);
					result += j < (*this)[0].size() - 1 ? ", " : "";
				}
				result += "\n";
			}
			return result;
		}

	private:
		Matrix() {}
		
		Vector<Vector<K>> _matrix;
		std::string _shape;
};

template<typename K>
std::string trail(K k) {
	K num = std::round(k * 1000) / 1000;
	if (num == 0)
		num = 0;
	std::string n = std::to_string(num);
	while (*--(n.end()) == '0')
		n.pop_back();
	if (*--(n.end()) == '.')
		n.pop_back();
	std::size_t offset = 0;
	if (n.front() == '-')
		offset = 1;
	while (n.size() > 5 + offset)
		n.pop_back();
	return n;
}

template<typename K>
auto& operator<<(std::ostream& os, Matrix<K>& matrix) {
	std::size_t length = 0;
	for (std::size_t i = 0; i < matrix.size(); i++) {
		for (std::size_t j = 0; j < matrix[0].size(); j++) {
			std::string n = trail(matrix[i][j]);
			if (n.length() > length)
				length = n.length();
		}
	}
	os << "Matrix of shape " << matrix.shape() << std::endl;
	for (std::size_t i = 0; i < matrix.size(); i++) {
		os << '[';
		for (std::size_t j = 0; j < matrix[0].size(); j++) {
			float number = std::round(matrix[i][j] * 1000) / 1000;
			if (number == 0)
				number = 0;
			std::string n = trail(number);
			std::size_t d = length - n.length();
			while (d--)
				os << " ";
			os << number;
			if (j < matrix[0].size() - 1)
				os << ",";
		}
		os << ']';
		if (i < matrix.size() - 1)
			os << '\n';
	}
	return os;
};

template<typename K>
auto& operator<<(std::ostream& os, const Matrix<K>& matrix) {
	std::size_t length = 0;
	for (std::size_t i = 0; i < matrix.size(); i++) {
		for (std::size_t j = 0; j < matrix[0].size(); j++) {
			std::string n = trail(matrix[i][j]);
			if (n.length() > length)
				length = n.length();
		}
	}
	os << "Matrix of shape " << matrix.shape() << std::endl;
	for (std::size_t i = 0; i < matrix.size(); i++) {
		os << '[';
		for (std::size_t j = 0; j < matrix[0].size(); j++) {
			float number = std::round(matrix[i][j] * 1000) / 1000;
			if (number == 0)
				number = 0;
			std::string n = trail(number);
			std::size_t d = length - n.length();
			while (d--)
				os << " ";
			os << number;
			if (j < matrix[0].size() - 1)
				os << ",";
		}
		os << ']';
		if (i < matrix.size() - 1)
			os << '\n';
	}
	return os;
};

// auto& operator<<(std::ostream& os, Matrix<char>& matrix) {
// 	os << "Matrix of shape " << matrix.shape() << std::endl;
// 	for (std::size_t i = 0; i < matrix.size(); i++) {
// 		os << '[';
// 		for (std::size_t j = 0; j < matrix[0].size(); j++) {
// 			os << matrix[i][j];
// 			if (j < matrix[0].size() - 1)
// 				os << ",";
// 		}
// 		os << ']';
// 		if (i < matrix.size() - 1)
// 			os << '\n';
// 	}
// 	return os;
// };
#endif