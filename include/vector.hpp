#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

#include <stdexcept>
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>

#include "maths.hpp"
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

		auto & add(Vector<K> & other) {
			if (other.size() > this->size())
				this->resize(other.size());
			for (std::size_t i = 0; i < this->size(); i++)
				(*this)[i] += other[i];
			return *this;
		}
		auto & add(const Vector<K> & other) {
			if (other.size() > this->size())
				this->resize(other.size());
			for (std::size_t i = 0; i < this->size(); i++)
				(*this)[i] += other[i];
			return *this;
		}
		auto & sub(Vector<K> & other) {
			if (other.size() > this->size())
				this->resize(other.size());
			for (std::size_t i = 0; i < other.size(); i++)
				(*this)[i] -= other[i];
			return *this;
		}
		auto & sub(const Vector<K> & other) {
			if (other.size() > this->size())
				this->resize(other.size());
			for (std::size_t i = 0; i < other.size(); i++)
				(*this)[i] -= other[i];
			return *this;
		}
		auto & scl(K k) {
			for (std::size_t i = 0; i < this->size(); i++) {
				(*this)[i] *= k;
			}
			return *this;
		}
		auto dot(Vector<K> & other) {
			if (other.size() != this->size()) {
				throw VectorException("Vectors are of different dimensions.");
			}
			K result(0);
			for (std::size_t i = 0; i < this->size(); i++) {
				result += (*this)[i] * ::conjugate(other[i]);
			}
			return result;
		}
		auto dot(const Vector<K> & other) {
			if (other.size() != this->size()) {
				throw VectorException("Vectors are of different dimensions.");
			}
			K result(0);
			for (std::size_t i = 0; i < this->size(); i++) {
				result += (*this)[i] * ::conjugate(other[i]);
			}
			return result;
		}
		auto norm_1() {
			float r = 0;
			for (std::size_t i = 0; i < this->size(); i++) {
				r += ::abs((*this)[i]);
			}
			return r;
		}
		auto norm() {
			float r = 0;
			for (std::size_t i = 0; i < this->size(); i++) {
				r += ::norm((*this)[i]);
			}
			return pow(r, 0.5);
		}
		auto norm_inf() {
			float r = 0;
			for (std::size_t i = 0; i < this->size(); i++) {
				float c = ::abs((*this)[i]);
				r = r < c ? c : r;
			}
			return r;
		}

		auto operator+(Vector<K> & other) const {
			return Vector(*this).add(other);
		}
		auto operator+(const Vector<K> & other) const {
			return Vector(*this).add(other);
		}
		auto & operator+=(Vector<K> & other) {
			return add(other);
		}
		auto & operator+=(const Vector<K> & other) {
			return add(other);
		}
		auto operator-(Vector<K> & other) const {
			return Vector(*this).sub(other);
		}
		auto operator-(const Vector<K> & other) const {
			return Vector(*this).sub(other);
		}
		auto & operator-=(Vector<K> & other) {
			return sub(other);
		}
		auto & operator-=(const Vector<K> & other) {
			return sub(other);
		}
		auto operator*(K k) const {
			return Vector(*this).scl(k);
		}
		auto & operator*=(K k) {
			return scl(k);
		}
		auto &operator[](std::size_t n) {
			if (n < this->size())
				return *(this->_M_impl._M_start + n);
			else
				throw VectorException("Index out of bounds");
		}
		auto operator[](std::size_t n) const {
			if (n < this->size())
				return *(this->_M_impl._M_start + n);
			else
				throw VectorException("Index out of bounds");
		}
};

template<typename K>
auto& operator<<(std::ostream& os, Vector<K>& vector) {
	os << "Vector of size " << vector.size() << " ";
	os << "[";
	for (std::size_t i = 0; i < vector.size(); i++) {
		os << vector[i];
		if (i < vector.size() - 1)
			os << ", ";
	}
	os << "]";
	return os;
};

template<typename K>
auto& operator<<(std::ostream& os, const Vector<K>& vector) {
	os << "Vector of size " << vector.size() << " ";
	os << "[";
	for (std::size_t i = 0; i < vector.size(); i++) {
		os << vector[i];
		if (i < vector.size() - 1)
			os << ", ";
	}
	os << "]";
	return os;
};

#endif