#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		Form f = Form("f1", 42, 2);
		Bureaucrat b = Bureaucrat(43, "John");
		b.signForm(f);
	}
	{
		Form f = Form("f1", 42, 2);
		Bureaucrat b = Bureaucrat(42, "John");
		b.signForm(f);
	}
	{
		Form f = Form("f1", 42, 2);
		Bureaucrat b = Bureaucrat(42, "John");
		f.beSigned(b);
	}
	{
		Form f = Form("f1", 42, 2);
		Bureaucrat b = Bureaucrat(43, "John");
		try
		{
			f.beSigned(b);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}