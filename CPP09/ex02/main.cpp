#include "PmergeMe.hpp"

int main(const int argc, const char **argv)
{
	PmergeMe<std::deque<int> > pmVec("std::deque");
	PmergeMe<std::vector<int> > pmDeq("std::vector");

	try
	{
		pmVec.sort(argc, argv);
		pmDeq.sort(argc, argv);
		pmVec.printInfo();
		pmVec.printTime();
		pmDeq.printTime();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}