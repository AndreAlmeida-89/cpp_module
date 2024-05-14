#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.cpp"

class Intern
{
public:
	// Constructors
	Intern();
	Intern(const Intern &copy);

	// Destructor
	~Intern();

	// Operators
	Intern &operator=(const Intern &assign);

	//Member function
	AForm *makeForm(std::string name, std::string target);

private:
};

#endif