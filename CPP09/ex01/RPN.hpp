#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class RPN
{
public:
	static void calculate(const int argc, const char **argv);

	class RPNError : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	// Constructors
	RPN();
	RPN(const RPN &copy);

	// Destructor
	~RPN();

	// Operators
	RPN &operator=(const RPN &assign);

	static void _executeOperation(std::stack<int> &s, char c);
};

#endif