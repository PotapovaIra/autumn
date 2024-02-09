#include <iostream>

int main()
{
	int n = 0;
	std::cout << "Количество элементов: ";
	std::cin >> n;

	int mass[n];
	for (auto i = 0; i < n; ++i)
	{
		std::cout << i + 1 << "-ый элемент: ";
		std::cin >> mass[i];
	}
	std::cout << "Исходный массив: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 1; i < n; ++i)
	{
		for (int r = 0; r < n - i; r++)
		{
			if (mass[r] < mass[r + 1])
			{
				// Обмен местами
				int temp = mass[r];
				mass[r] = mass[r + 1];
				mass[r + 1] = temp;
			}
		}
	}
	std::cout << "Отсортированный массив: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;



	return 0;
}