#include "PmergeMe.hpp"

int main(const int argc, const char **argv)
{
	try
	{
		PmergeMe::sort(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}