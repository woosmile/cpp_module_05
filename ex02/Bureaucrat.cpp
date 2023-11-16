#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name), _grade(grade)
{
	if (_grade < 1)
	{
		this->~Bureaucrat();
		throw (Bureaucrat::GradeTooHighException());
	}
	else if (_grade > 150)
	{
		this->~Bureaucrat();
		throw (Bureaucrat::GradeTooLowException());
	}
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
	if (_grade < 1)
	{
		this->~Bureaucrat();
		throw (Bureaucrat::GradeTooHighException());
	}
	else if (_grade > 150)
	{
		this->~Bureaucrat();
		throw (Bureaucrat::GradeTooLowException());
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->~Bureaucrat();
		new(this) Bureaucrat(other._name, other._grade);
	}
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incGrade()
{
	if (_grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		_grade--;
}

void	Bureaucrat::decGrade()
{
	if (_grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		_grade++;
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << _name << " has a lower grade than " << form.getName() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << _name << " has a lower grade than " << form.getName() << std::endl;
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
	out << t.getName() << ", bureaucrat grade " << t.getGrade() << std::endl;
	
	return (out);
}
