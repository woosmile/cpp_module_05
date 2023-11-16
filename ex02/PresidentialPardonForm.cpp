#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm("PresidentialPardonForm", other._sign_grade, other._exec_grade), _target(other._target)
{
	if (_sign_grade < 1 || _exec_grade < 1)
	{
		this->~PresidentialPardonForm();
		throw (AForm::GradeTooHighException());
	}
	else if (_sign_grade > 150 || _exec_grade > 150)
	{
		this->~PresidentialPardonForm();
		throw (AForm::GradeTooLowException());
	}
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->~PresidentialPardonForm();
		new(this) PresidentialPardonForm(other);
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget()
{
	return (_target);
}

void	PresidentialPardonForm::setTarget(std::string target)
{
	_target = target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (getSign() == false)
		throw (AForm::Unsigned());
	else if (checkExecGrade(executor) == false)
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}