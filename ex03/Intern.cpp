#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

AForm*	Intern::pp_form(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::rr_form(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::sc_form(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

int	Intern::findType(const std::string form)
{
	std::string	form_list[FORM_COUNT] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (int index = 0; index < FORM_COUNT; index++)
	{
		if (form_list[index] == form)
			return (index);
	}
	throw (Intern::FormDoesNotExist());
}

AForm*	Intern::makeForm(const std::string form, const std::string target)
{
	AForm*	(Intern::*form_generator[FORM_COUNT])(const std::string target) = {&Intern::pp_form, &Intern::rr_form, &Intern::sc_form};

	try
	{
		return ((this->*form_generator[findType(form)])(target));
	}
	catch(const std::exception& e)
	{
		std::cout << form << " is not found" << std::endl;
		return (NULL);
	}
}

const char*	Intern::FormDoesNotExist::what() const throw()
{
	return ("form does not exist.");
}