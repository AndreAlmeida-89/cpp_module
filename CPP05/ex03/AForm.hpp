#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	// Constructors
	AForm();
	AForm(const AForm &copy);
	AForm(const std::string name,
		  const std::string target,
		  const int gradeRequiredToSign,
		  const int gradeRequiredToExecute);

	// Destructor
	virtual ~AForm();

	// Operators
	AForm &operator=(const AForm &assign);

	// Getters / Setters
	std::string getName() const;
	std::string getTarget() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;

	// Member functions
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class FormIsNotSigned : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	const std::string _name;
	const std::string _target;
	bool _isSigned;
	const int _gradeRequiredToSign;
	const int _gradeRequiredToExecute;
	void _checkGradeRequiredToSign() const;
	void _checkIfCanEexecute() const;

	// Static
	static const int _maxGrade;
	static const int _minGrade;

protected:
	void _checkIfCanEexecute(Bureaucrat const &executor) const;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const AForm &object);

#endif