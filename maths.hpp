#ifndef __MATHS_HPP__
# define __MATHS_HPP__

#include "Vector.hpp"

template<typename K, std::size_t N>
auto linear_combination(const Vector<K> (&vector)[N], const K (&coefs)[N]) {
	Vector<K> result;
	for (std::size_t i = 0; i < N; i++) {
		result += vector[i] * coefs[i];
	}
	return result;
}

template<typename K>
auto lerp(K u, K v, float t) {
	return K(u + (v - u) * t);
}

#endif