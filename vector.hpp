#include <iostream>
#include <sstream>
#include <vector>

template<typename K>
class Vector : public std::vector<K> {
	public:
		Vector() : std::vector<K>() {}
		Vector(std::size_t size) : std::vector<K>(size) {}
		Vector(const Vector& other) : std::vector<K>(other) {}

		template<std::size_t N>
		static auto from(const K (&array)[N]) {
			Vector<K> vector(N);
			for (std::size_t i = 0; i < N; i++) {
				vector[i] = array[i];
			}
			return vector;
		}

		auto operator+(Vector<K> other) {
			auto len = std::max(this->size(), other.size());
			Vector<K> vector(len);
			for (std::size_t i = 0; i < len; i++) {
				vector[i] =
					(i < this->size() ? (*this)[i] : K()) + 
					(i < other.size() ? other[i] : K());
			}
			return vector; 
		}

		auto add(Vector<K> other) {
			if (other.size() > this->size())
				this->resize(other.size());
			for (std::size_t i = 0; i < other.size(); i++)
				(*this)[i] += other[i];
			return *this;
		}
		
		auto operator-(Vector<K> other) {
			auto len = std::max(this->size(), other.size());
			Vector<K> vector(len);
			for (std::size_t i = 0; i < len; i++) {
				vector[i] =
					(i < this->size() ? (*this)[i] : K()) - 
					(i < other.size() ? other[i] : K());
			}
			return vector; 
		}

		auto sub(Vector<K> other) {
			if (other.size() > this->size())
				this->resize(other.size());
			for (std::size_t i = 0; i < other.size(); i++)
				(*this)[i] -= other[i];
			return *this;
		}

		auto operator*(K k) {
			Vector<K> vector(*this);
			for (std::size_t i = 0; i < vector.size(); i++) {
				vector[i] *= k;
			}
			return vector; 
		}		
		
		auto mul(K k) {
			for (std::size_t i = 0; i < this->size(); i++) {
				(*this)[i] *= k;
			}
			return *this; 
		}
		
		auto asString() const {
			std::stringstream os;
			os << "[";
			for (std::size_t i = 0; i < this->size(); i++) {
				os << ((*this)[i] < 0 ? "": " ") << (*this)[i] << (i != this->size() - 1 ? "," : "");
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
		os << (vector[i] < 0 ? "": " ") << vector[i] << (i != vector.size() - 1 ? "," : ""); 
	}
	os << "]";
	return os;
};