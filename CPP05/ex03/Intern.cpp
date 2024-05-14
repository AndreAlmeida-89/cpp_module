#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}

// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}

// Operators
Intern &Intern::operator=(const Intern &assign)
{
	(void)assign;
	return *this;
}

const char *Intern::FormNameDoesNotExist::what() const throw()
{
	return "[!] Form name does not exist!";
}


AForm *Intern::makeForm(std::string name, std::string target)
{

	std::string names[NUM_OF_FORM_TYPES];
	names[ROBOTOMY_REQUEST] = "robotomy request";
	names[PRESIDENTIAL_PARDON] = "presidential pardon";
	names[SHRUBBERY_CREATION] = "shrubbery creation";

	int type = NUM_OF_FORM_TYPES;
	for (int i = 0; i < NUM_OF_FORM_TYPES; i++)
	{
		if (name == names[i])
		{
			type = i;
			break;
		}
	}
	switch (type)
	{
	case ROBOTOMY_REQUEST:
		return new RobotomyRequestForm(target);
	case PRESIDENTIAL_PARDON:
		return new PresidentialPardonForm(target);
	case SHRUBBERY_CREATION:
		return new ShrubberyCreationForm(target);
	default:
		throw FormNameDoesNotExist();
	}
}