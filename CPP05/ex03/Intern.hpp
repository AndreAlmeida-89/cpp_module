#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

// class AForm;

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

	// Member function
	AForm *makeForm(std::string name, std::string target);

private:
	enum FormType
	{
		ROBOTOMY_REQUEST = 0,
		PRESIDENTIAL_PARDON,
		SHRUBBERY_CREATION,
		NUM_OF_FORM_TYPES
	};

	class FormNameDoesNotExist : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif