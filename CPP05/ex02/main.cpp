#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		ShrubberyCreationForm f = ShrubberyCreationForm("home");
		Bureaucrat b = Bureaucrat(43, "John");
		try
		{
			b.signForm(f);
			b.execueteForm(f);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << b;
		std::cout << f;
	}

	{
		RobotomyRequestForm f = RobotomyRequestForm("home");
		Bureaucrat b = Bureaucrat(1, "John");
		try
		{
			b.signForm(f);
			b.execueteForm(f);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << b;
		std::cout << f;
	}

	{
		PresidentialPardonForm f = PresidentialPardonForm("home");
		Bureaucrat b = Bureaucrat(5, "John");
		try
		{
			b.signForm(f);
			b.execueteForm(f);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << b;
		std::cout << f;
	}
	return (0);
}