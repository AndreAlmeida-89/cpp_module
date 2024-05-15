#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "\e[0;33mDefault Constructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
	std::cout << "\e[0;33mCopy Constructor called of ScalarConverter\e[0m" << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "\e[0;31mDestructor called of ScalarConverter\e[0m" << std::endl;
}

// Operators
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void)assign;
	return *this;
}

bool ScalarConverter::_isChar(std::string &literal)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
	{
		std::stringstream ss;
		ss << static_cast<int>(literal[0]);
		literal = ss.str();
		return (true);
	}
	return (false);
}

bool ScalarConverter::_isPseudoLiterals(const std::string &literal)
{
	const size_t numOfPseudoLiterails = 8;
	const std::string pseudoLiterals[8] = {
		"inff"
		"+inff",
		"-inff",
		"nanf",
		"inf",
		"+inf",
		"-inf",
		"nan",
	};
	for (size_t i = 0; i < numOfPseudoLiterails; i++)
		if (pseudoLiterals[i] == literal)
			return (true);
	return (false);
}

bool ScalarConverter::_isDigit(const std::string &literal)
{
	if (_isPseudoLiterals(literal))
		return (true);
	const char *str = literal.c_str();
	size_t i = 0;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == 'f')
		{
			i++;
			continue;
		}
		if (!std::isdigit(str[i++]))
			return (false);
	}
	return (true);
}

// Member functions
void ScalarConverter::convert(const std::string &_literal)
{
	try
	{
		std::string literal = _literal;
		if (!_isChar(literal) && !_isDigit(literal))
			throw std::exception();
		try
		{
			if (_isPseudoLiterals(literal))
				throw std::exception();
			int i = std::atoi(literal.c_str());
			char c = static_cast<char>(i);
			if (std::isprint(c))
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			std::cout << "int: " << i << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}

		try
		{
			float f = std::atof(literal.c_str());
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "float: impossible" << std::endl;
		}

		try
		{
			double d = std::atof(literal.c_str());
			std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "double: impossible" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}