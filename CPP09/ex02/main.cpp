#include "PmergeMe.hpp"


int main(const int argc, const char **argv)
{
	PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > > pmVec("std::deque");
	PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > pmDeq("std::vector");

	if (argc < 2)
	{
		std::cerr << "usage: " << argv[0] << " ...numbers" << std::endl;
		return (1);
	}

	try
	{
		pmVec.sort(argv);
		pmDeq.sort(argv);
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