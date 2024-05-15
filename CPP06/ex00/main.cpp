#include "ScalarConverter.hpp"


int main(const int argc, const char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cerr << "[!] Invalid number of argument. Enter only one argument." << std::endl;
	return (0);
}