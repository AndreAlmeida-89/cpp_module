#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Unnamed",
													   _gradeRequiredToSign,
													   _gradeRequiredToExecute)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm(name,
																			 _gradeRequiredToSign,
																			 _gradeRequiredToExecute)
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assingn)
{
	if (this != &assingn)
		AForm::operator=(assingn);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	
	_checkIfCanEexecute(executor);
	std::cout << "execute by " << executor.getName() << "\n";
}

const int ShrubberyCreationForm::_gradeRequiredToSign = 25;
const int ShrubberyCreationForm::_gradeRequiredToExecute = 5;