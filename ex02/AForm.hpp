#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		bool				_sign;
		const int			_sign_grade;
		const int			_exec_grade;
	public:
		AForm();
		AForm(const std::string name, const int sign_grade, const int exec_grade);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm&	operator=(const AForm &other);
	public:
		std::string			getName() const;
		bool				getSign() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		void				beSigned(Bureaucrat const &bureaucrat);
		bool				checkExecGrade(Bureaucrat const &bureaucrat) const;
		virtual void		execute(Bureaucrat const & executor) const = 0;
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
		class Unsigned: public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, const AForm &t);

#endif