#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <sstream>


class ScalarConverter
{
public:
	// Destructor
	~ScalarConverter();

	// Member functions
	static void convert(const std::string &literal);

private:
	// Constructors
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	// Operators
	ScalarConverter &operator=(const ScalarConverter &assign);

	// Member Functions
	static bool _isDigit(const std::string &literal);
	static bool _isPseudoLiterals(const std::string &literal);
	static bool _isChar(std::string &literal);
};

#endif