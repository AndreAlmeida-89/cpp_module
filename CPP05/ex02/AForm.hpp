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
		  const int gradeRequiredToSign,
		  int gradeRequiredToExecute);

	// Destructor
	~AForm();

	// Operators
	AForm &operator=(const AForm &assign);

	// Getters / Setters
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;

	// Member functions
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) = 0;

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	const std::string _name;
	bool _isSigned;
	const int _gradeRequiredToSign;
	const int _gradeRequiredToExecute;
	void _checkGradeRequiredToSign() const;

	// Static
	static const int _maxGrade;
	static const int _minGrade;
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const AForm &object);

#endif