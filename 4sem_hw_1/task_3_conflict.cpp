#include <iostream>

using namespace std;

int main()
{
	auto n = 0;
	cout << "���������� ���������: ";
	cin >> n;

	int mass[n];
	for (int i = 0; i < n; ++i)
	{
		cout << i + 1 << "-�� �������: ";
		cin >> mass[i];
	}
	cout << "�������� ������: ";
	for (int i = 0; i < n; ++i)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
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
	cout << "��������������� ������: ";
	for (int i = 0; i < n; ++i)
	{
		cout << mass[i] << " ";
	}
	cout << endl;



	return 0;
}