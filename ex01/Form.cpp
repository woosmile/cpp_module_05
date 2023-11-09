#include "Form.hpp"

Form::Form(): _name("default"), _sign(false), _sign_grade(150), _exec_grade(150)
{
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade): _name(name), _sign(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	try
	{
		if (_sign_grade < 1 || _exec_grade < 1)
			throw (Form::GradeTooHighException());
		else if (_sign_grade > 150 || _exec_grade > 150)
			throw (Form::GradeTooLowException());
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Form::~Form()
{
}

Form::Form(const Form &other): _name(other._name), _sign(other._sign), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	try
	{
		if (_sign_grade < 1 || _exec_grade < 1)
			throw (Form::GradeTooHighException());
		else if (_sign_grade > 150 || _exec_grade > 150)
			throw (Form::GradeTooLowException());
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
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

std::string	Form::GetName() const
{
	return (_name);
}

bool	Form::GetSign() const
{
	return (_sign);
}

int	Form::GetSignGrade() const
{
	return (_sign_grade);
}

int	Form::GetExecGrade() const
{
	return (_exec_grade);
}

void	Form::BeSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (_sign_grade > bureaucrat.GetGrade())
			_sign = true;
		else
			throw (Form::GradeTooLowException());
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
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
	out << t.GetName() << ", Form sign " << t.GetSign() << \
	", Form sign grade " << t.GetSignGrade() << ", Form execute grade " << t.GetExecGrade() << "\n";
	
	return (out);
}