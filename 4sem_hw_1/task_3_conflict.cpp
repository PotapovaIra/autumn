#include <iostream>

int main()
{
	int n = 0;
	std::cout << "���������� ���������: ";
	std::cin >> n;

	int mass[n];
	for (auto i = 0; i < n; ++i)
	{
		std::cout << i + 1 << "-�� �������: ";
		std::cin >> mass[i];
	}
	std::cout << "�������� ������: ";
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
				// ����� �������
				int temp = mass[r];
				mass[r] = mass[r + 1];
				mass[r + 1] = temp;
			}
		}
	}
	std::cout << "��������������� ������: ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << mass[i] << " ";
	}
	std::cout << std::endl;



	return 0;
}