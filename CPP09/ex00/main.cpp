#include "BitcoinExchange.hpp"

int main(const int argc, const char **argv)
{
	try
	{
		if (argc != 2)
			throw BitcoinExchange::UnableToOpenFile();
		BitcoinExchange::calculate(argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}