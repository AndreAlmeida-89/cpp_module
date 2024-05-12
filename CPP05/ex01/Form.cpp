#include "Form.hpp"

// Constructors
Form::Form() : _name("Unnamed"),
			   _isSigned(false),
			   _gradeRequiredToSign(_minGrade),
			   _gradeRequiredToExecute(_minGrade)
{
	_checkGradeRequiredToSign();
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()),
							   _isSigned(copy.getIsSigned()),
							   _gradeRequiredToSign(copy.getGradeRequiredToSign()),
							   _gradeRequiredToExecute(copy.getGradeRequiredToExecute())
{
	_checkGradeRequiredToSign();
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const std::string name,
		   const int gradeRequiredToSign,
		   int gradeRequiredToExecute) : _name(name),
										 _isSigned(false),
										 _gradeRequiredToSign(gradeRequiredToSign),
										 _gradeRequiredToExecute(gradeRequiredToExecute)
{
	_checkGradeRequiredToSign();
	std::cout << "\e[0;33mFields Constructor called of Form\e[0m" << std::endl;
}

// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}

// Operators
Form &Form::operator=(const Form &assign)
{
	_isSigned = assign.getIsSigned();
	return *this;
}

// Getters / Setters
std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeRequiredToExecute() const
{
	return _gradeRequiredToExecute;
}

int Form::getGradeRequiredToSign() const
{
	return _gradeRequiredToSign;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeRequiredToSign)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

void Form::_checkGradeRequiredToSign() const
{
	if (_gradeRequiredToSign < _maxGrade)
		throw GradeTooHighException();
	else if (_gradeRequiredToSign > _minGrade)
		throw GradeTooLowException();
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return "[!] Grade is too high!";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "[!] Grade is too low";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Form &object)
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
const int Form::_maxGrade = 1;
const int Form::_minGrade = 150;
