#include "BitcoinExchange.hpp"

int main(const int argc, const char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange::calculateBTCAmoutByDate(argv[1]);
	return 0;
}