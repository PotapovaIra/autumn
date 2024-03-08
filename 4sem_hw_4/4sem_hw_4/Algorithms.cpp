#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

int main() 
{
	//1) Created P1
	std::vector<int> P1(101);
	std::iota(P1.begin(), P1.end(), 0);
	std::cout << "Created sequence: ";
	for (int num : P1) {
		std::cout << num << " ";
	}
	std::cout <<  std::endl;
	// 2) Added some new numbers from std::cin
	int x;
	std::cout << "¬вод нескольких чисел(остановка - ввести -2)" << std::endl;
	while (std::cin >> x && x != -2) 
	{
		P1.push_back(x);
	}
	std::cout << "Sequence after adding: ";
	for (int num : P1) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// 3) Mixed P1
	std::random_shuffle(P1.begin(), P1.end());
	std::cout << "Mixed sequence: ";
	for (int num : P1) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
	// 4) Deleted dublicates
	P1.erase(std::unique(P1.begin(), P1.end()), P1.end());
	for (int num : P1) {
		std::cout << num << " ";
	}
	// 5) Counted amount of %2 == 0 numbers

}