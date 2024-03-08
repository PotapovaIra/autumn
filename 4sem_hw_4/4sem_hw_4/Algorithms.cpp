#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

int main() 
{
	//1) Created P1
	std::vector<int> P1(101);
	std::iota(P1.begin(), P1.end(), 0);
	std::cout << "Created P1 sequence: ";
	for (int num : P1) {
		std::cout << num << " ";
	}
	std::cout <<  std::endl;
	// 2) Added some new numbers from std::cin
	int x;
	std::cout << "Enter numbers(if you want to stop, enter -2)" << std::endl;
	while (std::cin >> x && x != -2) 
	{
		P1.push_back(x);
	}
	std::cout << "P1 sequence after adding: ";
	for (int num : P1) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// 3) Mixed P1
	std::random_shuffle(P1.begin(), P1.end());
	std::cout << "Mixed P1 sequence: ";
	for (int num : P1) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// 4) Deleted dublicates
	P1.erase(std::unique(P1.begin(), P1.end()), P1.end());
	std::cout << "P1 sequence after deleting duplicates: ";
	for (int num : P1) {
		std::cout << num << " ";
	}
	// 5) Counted amount of %2 == 0 numbers
	std::cout << "Amount of %2==0 numbers in P1: " << std::count_if(P1.begin(), P1.end(), [](int x) {return x % 2 == 0;}) << std::endl;
	// 6) Minimum/maximum
	auto minimum = *std::min_element(P1.begin(), P1.end());
	auto maximum = *std::max_element(P1.begin(), P1.end());
	std::cout << "Mimimum number value in P1: " << minimum << ", Maximim number value in P1: " << maximum << std::endl;
	// 7) Find prime number

	// 8) Changed every number value by its square
	std::transform(P1.begin(), P1.end(), P1.begin(), [](int x) {return x * x;});
	std::cout << "P1 sequence after changing each value by its square: ";
	for (int num : P1) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	//auto squares = *

	// 9) Created P2(size P1 + random number values)
	std::vector<int> P2(P1.size());
	std::generate(P2.begin(), P2.end(), []() {return rand() % 100;});
	std::cout << "P2 sequence: ";
	for (int num : P2) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// 10) Count sum of P2 elements
	auto sum_P2 = std::accumulate(P2.begin(), P2.end(), 0);
	std::cout << "Sum of P2 elements: " << sum_P2 << std::endl;
	//11) Change some elemets in P2 by 1
	auto numbers = 7;
	std::fill_n(P2.begin(), numbers, 1);
	std::cout << "Sequence P2 with first elements changes by 1: ";
	for (int num : P2) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// 12) Create P3 = P1- P2
	std::vector<int> P3(P1.size());
	std::transform(P1.begin(), P1.end(), P2.begin(), P3.begin(), std::minus<int>());
	std::cout << "P3: ";
	for (int num : P3) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// 13) Change each negative element by 0
	std::replace_if(P3.begin(), P3.end(), [](int x) {return x < 0;}, 0);
	std::cout << "P3 after changing negative elemets by 0: ";
	for (int num : P3) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// 14) Delete all nulls from P3
	P3.erase(std::remove(P3.begin(), P3.end(), 0), P3.end());
	std::cout << "P3 after deleting all 0: ";
	for (int num : P3) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
} 
