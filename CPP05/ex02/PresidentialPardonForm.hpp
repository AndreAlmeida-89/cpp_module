#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);

	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &assingn);

	void execute(Bureaucrat const &executor) const;

private:
	static const int _gradeRequiredToSign;
	static const int _gradeRequiredToExecute;
};

#endif // PRESIDENTIAL_PARDON_FORM_HPP