#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <set>

int main()
{
	const unsigned int size = 100000;
	std::srand(static_cast<unsigned int>(std::time(0)));

	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp << std::endl;
	}

	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(42);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		Span sp = Span(size);
		std::vector<int> numbers(size);
		std::generate(numbers.begin(), numbers.end(), std::rand);
		sp.addNumbers(numbers.begin(), numbers.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		Span sp = Span(size);
		std::set<int> numbers;
		while (numbers.size() < size)
			numbers.insert(std::rand());
		sp.addNumbers(numbers.begin(), numbers.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		try
		{
			Span sp = Span(size);
			std::vector<int> numbers(size + 1);
			std::generate(numbers.begin(), numbers.end(), std::rand);
			sp.addNumbers(numbers.begin(), numbers.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}