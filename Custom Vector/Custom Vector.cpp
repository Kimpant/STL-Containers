#include <iostream>

using namespace std;

template <typename T>
class Vector {
public:
	Vector() {
		arr = new T[1];
		cp = 1;

	}
	Vector(Vector& other) {
		if (this != &other) {
			delete[]arr;
			arr = new T[other.cp];
			for (size_t i = 0; i < other.sz; i++) {
				arr[i] = other.arr[i];
			}
			sz = other.sz;
			cp = other.cp;

		}
	}
	Vector(Vector&& other) noexcept {
		if (this != other) {
			delete[]arr;
			arr = other.arr;
			sz = other.sz;
			cp = other.cp;
			other.arr = nullptr;
			other.sz = other.cp = 0;
		}
	}
	~Vector() {
		delete[]arr;
	}
	Vector& operator = (Vector& other) {
		if (this != &other) {
			delete[] arr;
			arr = new T[other.cp];
			for (size_t i = 0; i < other.sz; i++) {
				arr[i] = other.arr[i];
			}
			sz = other.sz;
			cp = other.cp;
		}
		return *this;
	}
	Vector& operator = (Vector&& other) noexcept {
		if (this != &other) {
			delete[]arr;
			arr = other.arr;
			sz = other.sz;
			cp = other.cp;
			other.arr = nullptr;
			other.sz = other.cp = 0;
		}
		return *this;
	}
	bool Empty() const {
		return sz == 0;
	}
	size_t Size() const {
		return sz;
	}
	size_t Capacity() const {
		return cp;
	}
	void pushBack(const T& value) {
		if (sz >= cp) {
			addMemory();
		}
		arr[sz++] = value;
	}
	void Remove(size_t ind) {
		for (size_t i = ind + 1; i < sz; i++) {
			arr[i - 1] = arr[i];
		}
		--sz;
	}
	T* begin() {
		return &arr[0];
	}
	const T* begin() const {
		return &arr[0];
	}
	T* end() {
		return &arr[sz];
	}
	const T* end() const {
		return &arr[sz];
	}
	T& operator [](size_t ind) {
		return arr[ind];
	}
	const T& operator [](size_t ind) const {
		return arr[ind];
	}
private:
	void addMemory() {
		cp *= 2;
		T* temp = arr;
		arr = new T[cp];
		for (size_t i = 0; i < sz; i++) {
			arr[i] = temp[i];
		}
		delete[] temp;
	}

	T* arr;
	size_t sz{};
	size_t cp{};
};

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
	for (const T& x : vec) {
		os << x << " ";
	}
	return os;
}

