#include <iostream>
#include<stdexcept>


template<typename T, std::size_t N>
struct array {
public:
	//constructor
	array() = default;
	array(const array& info) {
		std::copy(info.arr, info.arr + N, info);
	}
	array(array&& info) noexcept {
		std::swap(arr, info.arr);
	}
	//destructor
	~array() = default;
	// op =
	array& operator=(const array& info) {
		if (this != & info) {
			std::copy(info.arr, info.arr + N, info);
		}
		return *this;
	}
	array& operator=(array&& info) noexcept {
		std::swap(arr, info.arr);
		return *this;
	}
	array(array&& info) noexcept {
		std::swap(arr, info.arr);
	}
	//reading and writing op
	T& operator[](std::size_t ind) {
		return arr[ind];
	}
	const T& operator[](std::size_t ind) const {
		return arr[ind];
	}
	//front
	T& front() {
		return arr[0];
	}
	const T& front() const {
		return arr[0];
	}
	//back
	T& back() {
		return arr[N - 1];
	}
	const T& back() const {
		return arr[N - 1];
	}
	//empty
	bool empty()const {
		return N == 0;
	}
	//size
	std::size_t size() const {
		return N;
	}
	//swap
	void swap(array& info) noexcept {
		std::swap(arr, info.arr);
	}
	//max_size
	std::size_t max_size() const {
		return N;
	}
};