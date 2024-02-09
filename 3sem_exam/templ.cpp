#include <iostream>
#include <stdexcept>

template<typename T>
class array {
private:
	T* num;//on mas &?
	size_t amount;///גלוסעטלמסעü
	size_t size; //now size of mas
public:
	array() =default,;//constructor
	//copy
	array(const array& other) : num(new T[other.amount]), amount(other.amount), size(other.size) {
		for (size_t i = 0; i < size; ++i) {
			num[i] = other.num[i];
		}
	}
	//move op
	array(array&& other) noexcept : num(other.num), amount(other.amount), size(other.size) {
		other.num = nullptr;
		other.amount = 0;
		other.size = 0;
	}
	//destructor
	~array() {
		delete[] num;
	}
	// +=
	array& operator+=(const array& other) {
		for (size_t i = 0; i < other.size; ++i) {
			num[size + i] = other.num[i];
		}
		size += other.size;
		return *this;
	}
	// get the element with index
	T& operator[](size_t index) {
		if (index >= size) {
			throw std::out_of_range("out of range");
		}
		return num[index];
	}
	//first el
	T& front() {
		if (size == 0) {
			throw std::out_of_range("empty");
		}
		return data[0];
	}
	//delete from the end
	void pop_back() {
		if (size > 0) {
			--size;
		}
	}
	// last
	T& back() {
		if (size == 0) {
			throw std::out_of_range("empty");
		}
		return num[size - 1];
	}
	//swap
	void swap(array& other) noexcept {
		std::swap(num, other.num);
		std::swap(amount, other.amount);
		std::swap(size, other.size);
	}
};
int main() {
	array<int> vec1(5);

	
}