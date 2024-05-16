#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <deque>
#include <set>

int main()
{
	{
		typedef std::vector<int> Container;
		Container container;
		container.push_back(1);
		container.push_back(2);
		container.push_back(42);
		Container::const_iterator result1 = ::easyfind(container, 42);
		std::cout << *result1 << std::endl;
		try
		{
			Container::const_iterator result2 = ::easyfind(container, 21);
			std::cout << *result2 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		typedef std::list<int> Container;
		Container container;
		container.push_back(1);
		container.push_back(2);
		container.push_back(42);
		Container::const_iterator result1 = ::easyfind(container, 42);
		std::cout << *result1 << std::endl;
		try
		{
			Container::const_iterator result2 = ::easyfind(container, 21);
			std::cout << *result2 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		typedef std::deque<int> Container;
		Container container;
		container.push_back(1);
		container.push_back(2);
		container.push_back(42);
		Container::const_iterator result1 = ::easyfind(container, 42);
		std::cout << *result1 << std::endl;
		try
		{
			Container::const_iterator result2 = ::easyfind(container, 21);
			std::cout << *result2 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		typedef std::set<int> Container;
		Container container;
		container.insert(1);
		container.insert(2);
		container.insert(42);
		Container::const_iterator result1 = ::easyfind(container, 42);
		std::cout << *result1 << std::endl;
		try
		{
			Container::const_iterator result2 = ::easyfind(container, 21);
			std::cout << *result2 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}