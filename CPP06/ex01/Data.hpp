#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

struct Data
{
public:
	// Constructors
	Data(const std::string content);

	// Destructor
	~Data();

	// Getters / Setters
	const std::string getContent() const;

private:
	const std::string _content;
};

#endif