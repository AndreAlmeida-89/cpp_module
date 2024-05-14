#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Unnamed",
													   _gradeRequiredToSign,
													   _gradeRequiredToExecute)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm(name,
																			 _gradeRequiredToSign,
																			 _gradeRequiredToExecute)
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assingn)
{
	if (this != &assingn)
		AForm::operator=(assingn);
	return (*this);
}

const char *ShrubberyCreationForm::UnableToOpenFile::what() const throw()
{
	return "[!] Unable to open file!";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	_checkIfCanEexecute(executor);
	const std::string fileName = executor.getName() + "_shrubbery";
	std::ofstream myfile(fileName.c_str());
	if (myfile.is_open())
	{
		const size_t height = 20;
		size_t spacesPerLevel = height - 1;
		for (size_t level = 0; level < height; level++)
		{
			for (size_t i = 0; i < spacesPerLevel; i++)
				myfile << " ";
			for (size_t i = 0; i < 2 * level + 1; i++)
				myfile << "#";
			if (level != height - 1)
				myfile << std::endl;
			spacesPerLevel--;
		}
		myfile.close();
	}
	else
		throw UnableToOpenFile();
}

const int ShrubberyCreationForm::_gradeRequiredToSign = 145;
const int ShrubberyCreationForm::_gradeRequiredToExecute = 137;