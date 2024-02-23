#include <iostream>
#include <vector>

int main() {
	std::vector <int> vectr;

	std::cout << "Capacity:" << vectr.capacity() << std::endl;

	for (auto i = 33; i < 70; i++) {
		vectr.push_back(i);
		if (vectr.capacity() > vectr.size()) {
			std::cout << "Capacity increased: " << vectr.capacity() / vectr.size() << std::endl;
		}
		///std::cout << vectr.capacity() / vectr.size() << std::endl;
	}

	vectr.clear();
	vectr.reserve(1000);

	std::cout << "New capacity after reserv: " << vectr.capacity() << std::endl;

	vectr.clear();
	// Запрашиваем большое количество памяти
	vectr.reserve(1000000000); // 1 миллиард элементов

	// Пытаемся добавить элементы, чтобы увеличить размер вектора
	for (auto i = 0; i < 1000; i++) {
		vectr.push_back(i);
	}

	// Пробуем добавить еще один элемент
	try {
		vectr.push_back(1001);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;


}
