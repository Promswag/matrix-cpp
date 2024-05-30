#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

#include "print.hpp"

class VectorException : public std::exception {
	public:
		VectorException(std::string msg) {
			message = "VectorException: " + msg;
		}
		const char *what() const noexcept override {
			return message.c_str();
		}

	private:
		std::string message;
};

template<typename K>
class Vector : public std::vector<K> {
	public:
		Vector() : std::vector<K>() {}
		Vector(std::size_t size) : std::vector<K>(size) {}
		Vector(std::size_t size, K v) : std::vector<K>(size, v) {}
		Vector(const Vector& other) : std::vector<K>(other) {}
		auto& operator=(const Vector& other) {
			if (this != &other) {
				std::vector<K>::operator=(other);
			}
			return *this;
		}

		template<std::size_t N>
		static auto from(const K (&array)[N]) {
			Vector<K> vector(N);
			for (std::size_t i = 0; i < N; i++) {
				vector[i] = array[i];
			}
			return vector;
		}

		auto add(Vector<K> other) {
			if (other.size() > this->size())
				this->resize(other.size());
			for (std::size_t i = 0; i < this->size(); i++)
				(*this)[i] += other[i];
			return *this;
		}
		auto sub(Vector<K> other) {
			if (other.size() > this->size())
				this->resize(other.size());
			for (std::size_t i = 0; i < other.size(); i++)
				(*this)[i] -= other[i];
			return *this;
		}
		auto mul(K k) {
			for (std::size_t i = 0; i < this->size(); i++) {
				(*this)[i] *= k;
			}
			return *this; 
		}
		auto dot(Vector<K> other) {
			if (other.size() != this->size()) {
				throw VectorException("Vectors are of different dimensions.");
			}
			K result(0);
			for (std::size_t i = 0; i < this->size(); i++) {
				result += (*this)[i] * other[i];
			}
			return result;
		}
		auto norm_1() {
			float r = 0;
			for (std::size_t i = 0; i < this->size(); i++) {
				r += ((*this)[i] < 0 ? -(*this)[i] : (*this)[i]);
			}
			return r;
		}
		auto norm() {
			float r = 0;
			for (std::size_t i = 0; i < this->size(); i++) {
				r += (*this)[i] * (*this)[i];
			}
			return sqrt(r);
		}
		auto norm_inf() {
			float r = 0;
			for (std::size_t i = 0; i < this->size(); i++) {
				K c((*this)[i] < 0 ? -(*this)[i] : (*this)[i]);
				r = r < c ? c : r;
			}
			return r;
		}

		auto operator+(Vector<K> other) const {
			return Vector(*this).add(other);
		}
		auto operator+=(Vector<K> other) {
			return add(other);
		}
		auto operator-(Vector<K> other) const {
			return Vector(*this).sub(other);
		}
		auto operator-=(Vector<K> other) {
			return sub(other);
		}
		auto operator*(K k) const {
			return Vector(*this).mul(k);
		}		
		auto operator*=(K k) {
			return mul(k);
		}		
		
		auto asString() const {
			std::stringstream os;
			os << "[";
			for (std::size_t i = 0; i < this->size(); i++) {
				os << (*this)[i] << (i != this->size() - 1 ? "," : "");
			}
			os << "]";
			return os.str();
		}

	private:
};

template<typename K>
auto& operator<<(std::ostream& os, const Vector<K>& vector) {
	os << "Vector of size " << vector.size() << " ";
	os << "[";
	for (std::size_t i = 0; i < vector.size(); i++) {
		os << vector[i] << (i != vector.size() - 1 ? "," : ""); 
	}
	os << "]";
	return os;
};

#endif