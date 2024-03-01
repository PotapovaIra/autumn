#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>

std::size_t hash(const char* s)
{
	auto h = 0U;

	for (auto p = s; *p != '\0'; ++p)
	{
		h = h * 31 + static_cast <unsigned int> (*p);
	}

	return h % 128;
}
struct Fields {
	int integer;
	double doubl;
	std::string str;
};
int main()
{
	std::unordered_set<std::size_t> hashCodes;
	//hash_func
	const auto numExamples = 1000; //examples
	for (int i = 0; i < numExamples; i++)
	{
		Fields field;
		field.integer = rand();
		//field.doubl = ///
		field.str = std::to_string(i);

		//count hash-code for examples
		std::size_t hashCode = hash(field.str.c_str());
		hashCodes.insert(hashCode);
	}

	std::ofstream out("hash_codes.txt");
	for (auto code : hashCodes)
	{
		out << code << std::endl;
	}
	out.close();
	std::cout << "Succesfully saved" << std::endl;

}



//int main(int argc, char** argv)
//{
//	std::cout << hash("ivanov") << std::endl;
//
//	system("pause");
//
//	return EXIT_SUCCESS;
//}