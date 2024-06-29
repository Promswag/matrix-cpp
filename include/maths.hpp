#ifndef __MATHS_HPP__
# define __MATHS_HPP__

#include <complex>
#include <cmath>

template<typename K>
float norm(std::complex<K> & k) {
	return k.real() * k.real() + k.imag() * k.imag();
}

template<typename K>
float norm(const std::complex<K> & k) {
	return k.real() * k.real() + k.imag() * k.imag();
}

template<typename K>
float norm(const K k) {
	return k * k;
}

template<typename K>
float abs(K k) {
	return pow(norm(k), 0.5);
}

template<typename K>
auto conjugate(std::complex<K> & k) {
	return std::complex<K>(k.real(), -k.imag());
}

template<typename K>
auto conjugate(const std::complex<K> & k) {
	return std::complex<K>(k.real(), -k.imag());
}

template<typename K>
auto conjugate(K k) {
	return k;
}

#endif