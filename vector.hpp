#include <iostream>
#include <vector>
#include <array>

template<typename K>
class Vector : public std::vector<K> {
	public:
		Vector(const Vector& other) : std::vector<K>(other) {}

		// template<std::size_t N>
		// static Vector<K> from(const std::array<K, N>& array) {
		// 	Vector<K> vec(N);
		// 	for (std::size_t i = 0; i < N; i++) {
		// 		vec[i] = array[i];
		// 	}
		// 	return vec;
		// }

		template<std::size_t N>
		static Vector<K> from(const K (&array)[N]) {
			Vector<K> vec(N);
			for (std::size_t i = 0; i < N; i++) {
				vec[i] = array[i];
			}
			return vec;
		}

		Vector<K> operator+(Vector<K> other) {
			std::size_t len = std::max(this->size(), other.size());
			Vector<K> vec(len);
			for (std::size_t i = 0; i < len; i++) {
				vec[i] =
					(i < this->size() ? (*this)[i] : K()) + 
					(i < other.size() ? other[i] : K());
			}
			return vec; 
		}

		Vector<K> add(Vector<K> other) {
			auto result = operator+(other);
			std::size_t len = std::max(this->size(), other.size());
			for (std::size_t i = 0; i < len; i++) {
				if (i < this->size())
					(*this)[i] += other[i];
				else
					this->push_back(other[i]);
			}
			return result;
		}
		
		Vector<K> operator-(Vector<K> other) {
			std::size_t len = std::max(this->size(), other.size());
			Vector<K> vec(len);
			for (std::size_t i = 0; i < len; i++) {
				vec[i] =
					(i < this->size() ? (*this)[i] : K()) - 
					(i < other.size() ? other[i] : K());
			}
			return vec; 
		}

		Vector<K> operator*(K k) {
			Vector<K> vec(*this);
			for (std::size_t i = 0; i < vec.size(); i++) {
				vec[i] *= k;
			}
			return vec; 
		}

	private:
		Vector() : std::vector<K>() {}
		Vector(std::size_t size) : std::vector<K>(size) {}
};

template<typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K>& vec) {
	os << "Vector: {";
	for (std::size_t i = 0; i < vec.size(); i++) {
		os << vec[i] << (i != vec.size() - 1 ? ", " : ""); 
	}
	os << "}";
	return os;
};