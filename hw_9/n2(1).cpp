#include <iostream>
#include<stdexcept>


template<typename T, std::size_t N>
class array {
private:
	T arr[N];
public:
	//constructor
	array() = default;
	array(const array& info) {
		std::copy(info.arr, info.arr + N, arr);
	}
	array(array&& info) noexcept {
		std::swap(arr, info.arr);
	}
	//destructor
	~array() = default;
	// op =
	array& operator=(const array& info) {
		if (this != &info) {
			std::copy(info.arr, info.arr + N, arr);
		}
		return *this;
	}
	array& operator=(array&& info) noexcept {
		std::swap(arr, info.arr);
		return *this;
	}
	//reading and writing op
	T& operator[](std::size_t ind) {
		if (ind >= N) {
			throw std::out_of_range("Error,out range");
		}
		return arr[ind];
	}
	const T& operator[](std::size_t ind) const {
		if (ind >= N) {
			throw std::out_of_range("Error, out range");
		}
		return arr[ind];
	}
	//front
	T& front() {
		if (N == 0) {
			throw std::out_of_range("Empty array");
		}
		return arr[0];
	}
	const T& front() const {
		if (N == 0) {
			throw std::out_of_range("Empty array");
		}
		return arr[0];
	}
	//back
	T& back() {
		if (N == 0) {
			throw std::out_of_range("Empty array");
		}
		return arr[N - 1];
	}
	const T& back() const {
		if (N == 0) {
			throw std::out_of_range("Empty array");
		}
		return arr[N - 1];
	}
	//empty
	bool empty() const {
		return N == 0;
	}
	//size
	std::size_t size() const {
		return N;
	}
	//swap
	void swap(array& info) noexcept;
	//max_size
	std::size_t max_size() const {
		return N;
	}
};
template<typename T, std::size_t N>
void array<T, N>::swap(array& info) noexcept {
	std::swap(arr, info.arr);
}