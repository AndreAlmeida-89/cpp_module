#include "RPN.hpp"

int main(const int argc, const char **argv)
{
	try
	{
		RPN::calculate(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}