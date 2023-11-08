#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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
		std::string		GetName() const;
		int				GetGrade() const;
		void			IncGrade();
		void			DecGrade();
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