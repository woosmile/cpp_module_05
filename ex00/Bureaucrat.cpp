#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name)
{
	try
	{
		if (grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		else if (grade > 150)
			throw (Bureaucrat::GradeTooLowException());
		else
			_grade = grade;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name("copy")
{
	*this = other;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		try
		{
			if (other._grade < 1)
				throw (Bureaucrat::GradeTooHighException());
			else if (other._grade > 150)
				throw (Bureaucrat::GradeTooLowException());
			else
				_grade = other._grade;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (*this);
}

std::string	Bureaucrat::GetName() const
{
	return (_name);
}

int	Bureaucrat::GetGrade() const
{
	return (_grade);
}

void	Bureaucrat::IncGrade()
{
	try
	{
		if (_grade <= 1)
			throw (Bureaucrat::GradeTooHighException());
		else
			_grade--;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::DecGrade()
{
	try
	{
		if (_grade >= 150)
			throw (Bureaucrat::GradeTooHighException());
		else
			_grade++;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &t)
{
	out << t.GetName() << ", bureaucrat grade " << t.GetGrade() << "\n";
	
	return (out);
}