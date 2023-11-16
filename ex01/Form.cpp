#include "Form.hpp"

Form::Form(): _name("default"), _sign(false), _sign_grade(150), _exec_grade(150)
{
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade): _name(name), _sign(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
	{
		this->~Form();
		throw (Form::GradeTooHighException());
	}
	else if (_sign_grade > 150 || _exec_grade > 150)
	{
		this->~Form();
		throw (Form::GradeTooLowException());
	}
}

Form::~Form()
{
}

Form::Form(const Form &other): _name(other._name), _sign(other._sign), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
	{
		this->~Form();
		throw (Form::GradeTooHighException());
	}
	else if (_sign_grade > 150 || _exec_grade > 150)
	{
		this->~Form();
		throw (Form::GradeTooLowException());
	}
}

Form&	Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->~Form();
		new(this) Form(other);
	}
	return (*this);
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSign() const
{
	return (_sign);
}

int	Form::getSignGrade() const
{
	return (_sign_grade);
}

int	Form::getExecGrade() const
{
	return (_exec_grade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_sign_grade >= bureaucrat.getGrade())
		_sign = true;
	else
		throw (Form::GradeTooLowException());
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low."); 
}

std::ostream& operator<<(std::ostream &out, const Form &t)
{
	out << t.getName() << ", Form sign " << t.getSign() << \
	", Form sign grade " << t.getSignGrade() << \
	", Form execute grade " << t.getExecGrade() << std::endl;
	
	return (out);
}