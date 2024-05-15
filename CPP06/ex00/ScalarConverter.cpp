#include "ScalarConverter.hpp"
#include <iomanip>

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

// Member functions
void ScalarConverter::convert(const std::string &_literal)
{
	try
	{
		std::string literal = _literal;
		if (_literal.length() == 1 && std::isprint(_literal.front()) && !std::isdigit(_literal.front()))
			literal = std::to_string(_literal.front());
		try
		{
			int i = std::stoi(literal);
			char c = static_cast<char>(i);
			if (std::isprint(c))
			{
				std::cout << "char: '" << c << "'" << std::endl;
			}
			else
			{
				std::cout << "char: Non displayable" << std::endl;
			}
			std::cout << "int: " << i << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}

		try
		{
			float f = std::stof(literal);
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "float: impossible" << std::endl;
		}

		try
		{
			double d = std::stod(literal);
			std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "double: impossible" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}