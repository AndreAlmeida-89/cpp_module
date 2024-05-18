#include "RPN.hpp"

// Constructors
RPN::RPN()
{
	std::cout << "\e[0;33mDefault Constructor called of RPN\e[0m" << std::endl;
}

RPN::RPN(const RPN &copy)
{
	(void)copy;
	std::cout << "\e[0;33mCopy Constructor called of RPN\e[0m" << std::endl;
}

// Destructor
RPN::~RPN()
{
	std::cout << "\e[0;31mDestructor called of RPN\e[0m" << std::endl;
}

// Operators
RPN &RPN::operator=(const RPN &assign)
{
	(void)assign;
	return *this;
}

void RPN::_executeOperation(std::stack<int> &s, char c)
{
	int a = s.top();
	s.pop();
	int b = s.top();
	s.pop();

	switch (c)
	{
	case '*':
		s.push(b * a);
		break;

	case '-':
		s.push(b - a);
		break;

	case '+':
		s.push(b + a);
		break;

	case '/':
		s.push(b / a);
		break;
	}
}

void RPN::calculate(const int argc, const char **argv)
{
	std::stack<int> s;
	if (argc != 2)
		throw RPNError();
	const char *str = argv[1];
	while (*str)
	{
		char c = *str++;
		switch (c)
		{
		case ' ':
			continue;

		case '*':
		case '-':
		case '+':
		case '/':
			if (s.size() < 2)
				throw RPNError();
			_executeOperation(s, c);
			break;

		default:
			if (!std::isdigit(c))
				throw RPNError();
			s.push(c - '0');
		}
	}
	if (s.size() != 1)
		throw RPNError();
	std::cout << s.top() << std::endl;
}

const char *RPN::RPNError::what() const throw()
{
	return "Error.";
}
