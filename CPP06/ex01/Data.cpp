#include "Data.hpp"

Data::Data(const std::string content) : _content(content)
{
	std::cout << "\e[0;33mFields Constructor called of Data\e[0m" << std::endl;
}

// Destructor
Data::~Data()
{
	std::cout << "\e[0;31mDestructor called of Data\e[0m" << std::endl;
}

// Getters / Setters
const std::string Data::getContent() const
{
	return _content;
}
