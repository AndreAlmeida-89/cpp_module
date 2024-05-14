#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);

	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assingn);

	void execute(Bureaucrat const &executor) const;

private:
	static const int _gradeRequiredToSign;
	static const int _gradeRequiredToExecute;

	class UnableToOpenFile : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif // SHRUBBERY_CREATION_FORM_HPP