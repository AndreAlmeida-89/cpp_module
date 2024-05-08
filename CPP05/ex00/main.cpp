#include "Bureaucrat.hpp"

int main()
{
	{
		try
		{
			Bureaucrat b1 = Bureaucrat(150, "b1");
			std::cout << b1;
			b1.decrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "---------------" << std::endl;
	{
		try
		{
			Bureaucrat b2 = Bureaucrat(-1, "b2");
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "---------------" << std::endl;
	{
		try
		{
			Bureaucrat b3 = Bureaucrat(1, "b3");
			b3.incrementGrade();
		}
		catch (const Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << e.what() << '\n';
		}
		catch (const Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}