#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	typename T::const_iterator iterator = std::find(container.begin(), container.end(), value);
	if (iterator == container.end())
	{
		throw std::runtime_error("[!] Error: value not found!");
	}
	return iterator;
}

#endif