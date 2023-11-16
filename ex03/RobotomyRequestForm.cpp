#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm("RobotomyRequestForm", other._sign_grade, other._exec_grade), _target(other._target)
{
	if (_sign_grade < 1 || _exec_grade < 1)
	{
		this->~RobotomyRequestForm();
		throw (AForm::GradeTooHighException());
	}
	else if (_sign_grade > 150 || _exec_grade > 150)
	{
		this->~RobotomyRequestForm();
		throw (AForm::GradeTooLowException());
	}
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->~RobotomyRequestForm();
		new(this) RobotomyRequestForm(other);
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget()
{
	return (_target);
}

void	RobotomyRequestForm::setTarget(std::string target)
{
	_target = target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	random;

	if (getSign() == false)
		throw (AForm::Unsigned());
	else if (checkExecGrade(executor) == false)
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << "* drilling noises *" << std::endl;

		srand(static_cast<unsigned int>(time(NULL)));
		random = rand() % 10;

		if (random < 5)
			std::cout << _target << " has been robotomized SUCCESSFULLY" << std::endl;
		else
			std::cout << _target << " has been robotomized FAILED" << std::endl;
	}
}