#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : _grade(_minGrade), _name("Unnamed")
{
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	_grade = copy.getGrade();
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string name) : _name(name)
{
	_setGrade(grade);
	std::cout << "\e[0;33mFields Constructor called of Bureaucrat\e[0m" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}

// Operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign)
{
	_grade = assign.getGrade();
	return *this;
}

// Getters / Setters
int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

void Bureaucrat::_setGrade(int grade)
{
	if (grade > _minGrade)
		throw GradeTooLowException();
	else if (grade < _maxGrade)
		throw GradeTooHighException();
	else
		_grade = grade;
}

// Member Functions
void Bureaucrat::incrementGrade()
{
	_setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	_setGrade(_grade + 1);
}

void Bureaucrat::signForm(const Form &form)
{
	if (_grade > form.getGradeRequiredToSign())
		std::cout
			<< _name
			<< " couldn’t sign "
			<< form.getName()
			<< " because its grade ("
			<< _grade
			<< ") is less than the required ("
			<< form.getGradeRequiredToSign()
			<< ")."
			<< std::endl;
	else
		std::cout
			<< _name
			<< " signed "
			<< form.getName()
			<< "."
			<< std::endl;
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "\e[0;31m[!] Grade is too high\e[0m";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "\e[0;31m[!] Grade is too low\e[0m";
}

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Bureaucrat &object)
{
	stream << "" << object.getName() << ", bureaucrat grade " << object.getGrade() << "." << std::endl;
	return stream;
}

// Static variables
const int Bureaucrat::_maxGrade = 1;
const int Bureaucrat::_minGrade = 150;