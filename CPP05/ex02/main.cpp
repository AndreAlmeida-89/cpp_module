#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{

		ShrubberyCreationForm f = ShrubberyCreationForm("f1");
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
	// {
	// 	AForm f = AForm("f1", 42, 2);
	// 	Bureaucrat b = Bureaucrat(42, "John");
	// 	b.signForm(f);
	// 	std::cout << b;
	// 	std::cout << f;
	// }
	// {
	// 	AForm f = AForm("f1", 42, 2);
	// 	Bureaucrat b = Bureaucrat(42, "John");
	// 	f.beSigned(b);
	// 	std::cout << b;
	// 	std::cout << f;
	// }
	// {
	// 	AForm f = AForm("f1", 42, 2);
	// 	Bureaucrat b = Bureaucrat(43, "John");
	// 	try
	// 	{
	// 		f.beSigned(b);
	// 	}
	// 	catch (const std::exception &e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
	// 	std::cout << b;
	// 	std::cout << f;
	// }
	return (0);
}