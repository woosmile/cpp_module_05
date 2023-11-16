#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat					w1("woosekim", 1);
		Bureaucrat					b10("woosekim", 10);	

		PresidentialPardonForm		p1("p1");
		RobotomyRequestForm			r1("r1");
		ShrubberyCreationForm		s1("s1");

		s1.beSigned(b10);
		w1.executeForm(s1);
		s1.execute(w1);

		r1.beSigned(b10);
		w1.executeForm(r1);
		r1.execute(w1);

		p1.beSigned(b10);
		w1.executeForm(p1);
		p1.execute(w1);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}