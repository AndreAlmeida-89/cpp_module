#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	// Constructors
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat(int grade, const std::string _name);

	// Destructor
	~Bureaucrat();

	// Operators
	Bureaucrat &operator=(const Bureaucrat &assign);

	// Getters / Setters
	int getGrade() const;
	std::string getName() const;

	// Member Functions
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form);
	void execueteForm(AForm const &form);

	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	int _grade;
	const std::string _name;
	void _setGrade(int grade);

	// Static
	static const int _maxGrade;
	static const int _minGrade;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Bureaucrat &object);

#endif