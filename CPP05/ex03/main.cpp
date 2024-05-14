#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		Intern someRandomIntern;
		Bureaucrat bureaucrat(1, "John");
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.execueteForm(*rrf);
		std::cout << *rrf;
		delete rrf;
	}

	{
		Intern someRandomIntern;
		Bureaucrat bureaucrat(1, "John");
		AForm *rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.execueteForm(*rrf);
		std::cout << *rrf;
		delete rrf;
	}

	{
		Intern someRandomIntern;
		Bureaucrat bureaucrat(1, "John");
		AForm *rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.execueteForm(*rrf);
		std::cout << *rrf;
		delete rrf;
	}

	{
		Intern someRandomIntern;
		Bureaucrat bureaucrat(1, "John");
		AForm *rrf;
		try
		{
			rrf = someRandomIntern.makeForm("wrong", "Bender");
			bureaucrat.signForm(*rrf);
			bureaucrat.execueteForm(*rrf);
			std::cout << *rrf;
			delete rrf;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}