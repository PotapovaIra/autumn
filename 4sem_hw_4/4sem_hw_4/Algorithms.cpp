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
	std::cout << "Enter numbers(if you want to stop, enter -2)" << std::endl;
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
	std::cout << "Sequence after deleting duplicates: ";
	for (int num : P1) {
		std::cout << num << " ";
	}
	// 5) Counted amount of %2 == 0 numbers
	std::cout << "Amount of %2==0 numbers: " << std::count_if(P1.begin(), P1.end(), [](int x) {return x % 2 == 0;}) << std::endl;
	// 6) Minimum/maximum
	auto minimum = *std::min_element(P1.begin(), P1.end());
	auto maximum = *std::max_element(P1.begin(), P1.end());
	std::cout << "Mimimum number value in P1: " << minimum << ", Maximim number value in P1: " << maximum << std::endl;
	// 7) Find prime number

	// 8) Change every number value by its square
	std::transform(P1.begin(), P1.end(), P1.begin(), [](int x) {return x * x;});
}