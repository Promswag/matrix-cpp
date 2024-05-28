#ifndef __MATRIX_HPP__
# define __MATRIX_HPP__

#include "vector.hpp"

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
			for (auto i = 0; i < _matrix.size(); i++) {
				for(auto j = 0; j < _matrix[i].size(); j++) {
					_matrix[i][j] += other[i][j];
				}
			}
			return *this;
		}
		auto sub(Matrix<K> other) {
			if (this->shape() != other.shape())
				return Matrix(*this);
			for (auto i = 0; i < _matrix.size(); i++) {
				for(auto j = 0; j < _matrix[i].size(); j++) {
					_matrix[i][j] -= other[i][j];
				}
			}
			return *this;
		}
		auto mul(K k) {
			for (auto i = 0; i < this->size(); i++) {
				for(auto j = 0; j < (*this)[i].size(); j++) {
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
						// std::cout << i << " " << j << " " << k << std::endl;
						result[j][i] += (*this)[j][k] * m[k][i];
						// std::cout << result << " += " << (*this)[j][k] << " * " << m[k][i] << std::endl;
					}
				}
			}
			return Matrix(result);
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
		auto operator[](std::size_t n) {
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
		os << matrix[i].asString() << std::endl;
	}
	return os;
};
#endif