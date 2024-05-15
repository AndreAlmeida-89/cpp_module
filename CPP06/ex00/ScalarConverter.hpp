#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

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
};

#endif