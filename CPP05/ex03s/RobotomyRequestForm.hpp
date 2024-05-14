#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);

	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &assingn);

	void execute(Bureaucrat const &executor) const;

private:
	static const int _gradeRequiredToSign;
	static const int _gradeRequiredToExecute;

	class UnableToRobotomize : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif // ROBOTOMY_REQUEST_FORM_HPP