#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm &other);
	public:
		virtual std::string	getTarget();
		void				setTarget(std::string target);
		virtual	void		execute(Bureaucrat const & executor) const;
};

#endif