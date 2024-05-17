#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// Constructors
	MutantStack() : std::stack<T>()
	{
		std::cout << "\e[0;33mDefault Constructor called of MutantStack\e[0m" << std::endl;
	}
	MutantStack(const MutantStack &copy) : std::stack<T>(copy)
	{
		std::cout << "\e[0;33mCopy Constructor called of MutantStack\e[0m" << std::endl;
	}

	// Destructor
	~MutantStack()
	{
		std::cout << "\e[0;31mDestructor called of MutantStack\e[0m" << std::endl;
	}

	// Operators
	MutantStack &operator=(const MutantStack &assign)
	{
		if (*this != assign)
			std::stack<T>::operator=(assign);
		return *this;
	}

private:
};

#endif