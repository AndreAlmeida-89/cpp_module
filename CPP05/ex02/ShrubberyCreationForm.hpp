#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string name);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);

	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &assingn);

	void execute(Bureaucrat const &executor) const throw();

private:
	static const int _gradeRequiredToSign;
	static const int _gradeRequiredToExecute;
};

#endif // SHRUBBERY_CREATION_FORM_HPP