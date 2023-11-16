#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define FORM_COUNT 3

class Intern
{
	private:
		int		findType(const std::string form);
		AForm*	pp_form(const std::string target);
		AForm*	rr_form(const std::string target);
		AForm*	sc_form(const std::string target);
	public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern&	operator=(const Intern &other);
		AForm*	makeForm(const std::string form, const std::string target);
	public:
		class FormDoesNotExist: public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#endif