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

template<typename K>
auto angle_cos(Vector<K> u, Vector<K> v) {
	return float(u.dot(v) / (u.norm() * v.norm()));
}

template<typename K>
auto cross_product(Vector<K> u, Vector<K> v) {
	if (u.size() != 3 || v.size() != 3)
		throw VectorException("Both vectors shall be 3D");
	Vector<K> result(3);
	result[0] = u[1] * v[2] - u[2] * v[1];
	result[1] = u[2] * v[0] - u[0] * v[2];
	result[2] = u[0] * v[1] - u[1] * v[0];
	return result;
}


#endif