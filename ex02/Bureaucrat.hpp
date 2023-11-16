#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat&		operator=(const Bureaucrat &other);
	public:
		std::string		getName() const;
		int				getGrade() const;
		void			incGrade();
		void			decGrade();
		void			signForm(AForm &form) const;
		void			executeForm(AForm const & form);
	public:
		class GradeTooHighException: public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, const Bureaucrat &t);

#endif