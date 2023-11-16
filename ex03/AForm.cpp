#include "AForm.hpp"

AForm::AForm(): _name("default"), _sign(false), _sign_grade(150), _exec_grade(150)
{
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade): _name(name), _sign(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
	{
		this->~AForm();
		throw (AForm::GradeTooHighException());
	}
	else if (_sign_grade > 150 || _exec_grade > 150)
	{
		this->~AForm();
		throw (AForm::GradeTooLowException());
	}
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other): _name(other._name), _sign(other._sign), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
	{
		this->~AForm();
		throw (AForm::GradeTooHighException());
	}
	else if (_sign_grade > 150 || _exec_grade > 150)
	{
		this->~AForm();
		throw (AForm::GradeTooLowException());
	}
}

AForm&	AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_sign = other.getSign();
	}
	return (*this);
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSign() const
{
	return (_sign);
}

int	AForm::getSignGrade() const
{
	return (_sign_grade);
}

int	AForm::getExecGrade() const
{
	return (_exec_grade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_sign_grade >= bureaucrat.getGrade())
		_sign = true;
	else
		throw (AForm::GradeTooLowException());
}

bool	AForm::checkExecGrade(Bureaucrat const &bureaucrat) const
{
	if (_exec_grade < bureaucrat.getGrade())
		return (false);
	else
		return (true);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low."); 
}

const char*	AForm::Unsigned::what() const throw()
{
	return ("Unsigned form."); 
}

std::ostream& operator<<(std::ostream &out, const AForm &t)
{
	out << t.getName() << ", Form sign " << t.getSign() << \
	", Form sign grade " << t.getSignGrade() << \
	", Form execute grade " << t.getExecGrade() << std::endl;
	
	return (out);
}