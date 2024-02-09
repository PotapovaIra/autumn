#include <iostream>

using namespace std;

int main()
{
	auto x = 1;
	auto n = 0;
	cout << "Количество элементов: ";
	cin >> n;

	auto mass[n];
	for (auto i = 0; i < n; ++i)
	{
		cout << i + 1 << "-ый элемент: ";
		cin >> mass[i];
	}
	cout << "Исходный массив: ";
	for (int i = 0; i < n; ++i)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
	for (auto i = 1; i < n; ++i)
	{
		for (auto r = 0; r < n - i; r++)
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
	cout << "Отсортированный массив: ";
	for (auto i = 0; i < n; ++i)
	{
		cout << mass[i] << " ";
	}
	cout << endl;



	return 0;
}