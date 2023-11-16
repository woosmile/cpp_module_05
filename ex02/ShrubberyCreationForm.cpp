#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm("ShrubberyCreationForm", other._sign_grade, other._exec_grade), _target(other._target)
{
	if (_sign_grade < 1 || _exec_grade < 1)
	{
		this->~ShrubberyCreationForm();
		throw (AForm::GradeTooHighException());
	}
	else if (_sign_grade > 150 || _exec_grade > 150)
	{
		this->~ShrubberyCreationForm();
		throw (AForm::GradeTooLowException());
	}
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->~ShrubberyCreationForm();
		new(this) ShrubberyCreationForm(other);
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget()
{
	return (_target);
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	_target = target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	outfile;
	std::string		outfile_name;
	int				ascii_tree_height = 10;

	if (getSign() == false)
		throw (AForm::Unsigned());
	else if (checkExecGrade(executor) == false)
		throw (AForm::GradeTooLowException());
	else
	{
		outfile_name = _target;
		outfile_name.append("_shrubbery");
		outfile.open(outfile_name.c_str());
		for (int height = 0; height < ascii_tree_height; height++)
		{
			for (int blank = 0; blank < ascii_tree_height - height - 1; blank++)
			{
				outfile.write(" ", 1);
			}
			for (int star = 0; star < ((height + 1) * 2) - 1; star++)
			{
				outfile.write("*", 1);
			}
			if (height < ascii_tree_height - 1)
				outfile.write("\n", 1);
		}
		outfile.close();
	}
}