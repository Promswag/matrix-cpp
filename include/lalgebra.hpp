#ifndef __LALGEBRA_HPP__
# define __LALGEBRA_HPP__

#include "vector.hpp"
#include "matrix.hpp"
#include <cmath>

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
	K k(v - u);
	k *= t;
	k += u;
	return k;
}

template<typename K>
auto angle_cos(Vector<K> u, Vector<K> v) {
	return float(u.dot(v) / (u.norm() * v.norm()));
}
template<typename K>
auto angle_cos(Vector<std::complex<K>> u, Vector<std::complex<K>> v) {
	return float((u.dot(v).real()) / (u.norm() * v.norm()));
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

Matrix<float> projection(float fov, float ratio, float near, float end) {
	const float PI = 3.14159265359;
	float tanFov = tan(fov * 0.5 * (PI/180));
	return Matrix<float>::from({
		{1 / (tanFov * ratio), 0., 0., 0.,},
		{0., 1 / tanFov, 0., 0.,},
		{0., 0., -(end + near) / (end - near), -1.,},
		{0., 0., -(2 * end * near) / (end - near), 0.,},
	});
}


#endif