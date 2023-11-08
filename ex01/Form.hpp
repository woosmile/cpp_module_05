#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_sign;
		const int			_sign_grade;
		const int			_exec_grade;
	public:
		Form();
		Form(const std::string name, const int grade);
		~Form();
		Form(const Form &other);
		Form&		operator=(const Form &other);
	public:
		std::string		GetName() const;
		bool			GetSign() const;
		int				GetSignGrade() const;
		int				GetExecGrade() const;
		void			BeSigned(Bureaucrat bureaucrat);
		void			IncSignGrade();
		void			DecSignGrade();
		void			IncExecGrade();
		void			DecExecGrade();
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