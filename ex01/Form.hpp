#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_sign;
		const int			_sign_grade;
		const int			_exec_grade;
	public:
		Form();
		Form(const std::string name, const int sign_grade, const int exec_grade);
		~Form();
		Form(const Form &other);
		Form&		operator=(const Form &other);
	public:
		std::string		getName() const;
		bool			getSign() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		void			beSigned(const Bureaucrat &bureaucrat);
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

std::ostream&	operator<<(std::ostream &out, const Form &t);

#endif