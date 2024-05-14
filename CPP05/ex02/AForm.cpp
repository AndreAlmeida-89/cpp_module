#include "AForm.hpp"

// Constructors
AForm::AForm() : _name("Unnamed"),
			   _isSigned(false),
			   _gradeRequiredToSign(_minGrade),
			   _gradeRequiredToExecute(_minGrade)
{
	_checkGradeRequiredToSign();
	std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()),
							   _isSigned(copy.getIsSigned()),
							   _gradeRequiredToSign(copy.getGradeRequiredToSign()),
							   _gradeRequiredToExecute(copy.getGradeRequiredToExecute())
{
	_checkGradeRequiredToSign();
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const std::string name,
		   const int gradeRequiredToSign,
		   int gradeRequiredToExecute) : _name(name),
										 _isSigned(false),
										 _gradeRequiredToSign(gradeRequiredToSign),
										 _gradeRequiredToExecute(gradeRequiredToExecute)
{
	_checkGradeRequiredToSign();
	std::cout << "\e[0;33mFields Constructor called of AForm\e[0m" << std::endl;
}

// Destructor
AForm::~AForm()
{
	std::cout << "\e[0;31mDestructor called of AForm\e[0m" << std::endl;
}

// Operators
AForm &AForm::operator=(const AForm &assign)
{
	_isSigned = assign.getIsSigned();
	return *this;
}

// Getters / Setters
std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeRequiredToExecute() const
{
	return _gradeRequiredToExecute;
}

int AForm::getGradeRequiredToSign() const
{
	return _gradeRequiredToSign;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeRequiredToSign)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

void AForm::_checkGradeRequiredToSign() const
{
	if (_gradeRequiredToSign < _maxGrade)
		throw GradeTooHighException();
	else if (_gradeRequiredToSign > _minGrade)
		throw GradeTooLowException();
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return "[!] Grade is too high!";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "[!] Grade is too low";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const AForm &object)
{
	stream
		<< object.getName()
		<< ", form grade "
		<< object.getGradeRequiredToSign()
		<< " is signed: "
		<< object.getIsSigned()
		<< "."
		<< std::endl;
	return stream;
}

// Static variables
const int AForm::_maxGrade = 1;
const int AForm::_minGrade = 150;
