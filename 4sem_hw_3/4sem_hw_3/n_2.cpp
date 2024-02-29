#include <iostream>

std::size_t hash(const char* s)
{
	auto h = 0U;

	for (auto p = s; *p != '\0'; ++p)
	{
		h = h * 31 + static_cast <unsigned int> (*p);
	}

	return h % 128;
}

int main(int argc, char** argv)
{
	std::cout << hash("ivanov") << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}