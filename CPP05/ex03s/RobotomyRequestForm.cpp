#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request",
												   "NoTarget",
												   _gradeRequiredToSign,
												   _gradeRequiredToExecute)
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("robotomy request",
																		   target,
																		   _gradeRequiredToSign,
																		   _gradeRequiredToExecute)
{

	std::cout << "\e[0;33mFields Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assingn)
{
	if (this != &assingn)
		AForm::operator=(assingn);
	return (*this);
}

const char *RobotomyRequestForm::UnableToRobotomize::what() const throw()
{
	return "[!] Unable to robotomize!";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	_checkIfCanEexecute(executor);
	srand(time(0));
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized." << std::endl;
	else
		throw UnableToRobotomize();
}

const int RobotomyRequestForm::_gradeRequiredToSign = 72;
const int RobotomyRequestForm::_gradeRequiredToExecute = 45;