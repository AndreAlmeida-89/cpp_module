#include "AForm.hpp"

// Constructors
AForm::AForm() : _name("Unnamed"),
				 _target("NoTarget"),
				 _isSigned(false),
				 _gradeRequiredToSign(_minGrade),
				 _gradeRequiredToExecute(_minGrade)
{
	_checkGradeRequiredToSign();
	std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()),
								  _target(copy.getTarget()),
								  _isSigned(copy.getIsSigned()),
								  _gradeRequiredToSign(copy.getGradeRequiredToSign()),
								  _gradeRequiredToExecute(copy.getGradeRequiredToExecute())
{
	_checkGradeRequiredToSign();
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const std::string name,
			 const std::string target,
			 const int gradeRequiredToSign,
			 const int gradeRequiredToExecute) : _name(name),
												 _target(target),
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
	if (this != &assign)
		_isSigned = assign.getIsSigned();
	return *this;
}

// Getters / Setters
std::string AForm::getName() const
{
	return _name;
}

std::string AForm::getTarget() const
{
	return _target;
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

void AForm::_checkIfCanEexecute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > _gradeRequiredToExecute)
		throw GradeTooLowException();
	if (getIsSigned() == false)
		throw FormIsNotSigned();
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return "[!] Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "[!] Grade is too low!";
}

const char *AForm::FormIsNotSigned::what() const throw()
{
	return "[!] Form is not signed!";
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
