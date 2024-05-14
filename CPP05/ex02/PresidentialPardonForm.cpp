#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Unnamed",
														 "NoTarget",
														 _gradeRequiredToSign,
														 _gradeRequiredToExecute)
{
	std::cout << "\e[0;33mDefault Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Unnamed",
																				 target,
																				 _gradeRequiredToSign,
																				 _gradeRequiredToExecute)
{

	std::cout << "\e[0;33mFields Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &assingn)
{
	if (this != &assingn)
		AForm::operator=(assingn);
	return (*this);
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	_checkIfCanEexecute(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const int PresidentialPardonForm::_gradeRequiredToSign = 25;
const int PresidentialPardonForm::_gradeRequiredToExecute = 5;