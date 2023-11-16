#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>

void	leak_check()
{
	std::system("leaks a.out");
}

int main()
{
	std::atexit(leak_check);
	try
	{
		Bureaucrat				w1("woosekim", 1);
		Bureaucrat				b10("woosekim", 10);
		Intern					i1;
		AForm					*f1;

		f1 = i1.makeForm("presidential pardon", "p1");

		f1->beSigned(b10);
		w1.executeForm(*f1);
		f1->execute(w1);

		delete f1;

		f1 = i1.makeForm("robotomy request", "r1");

		f1->beSigned(b10);
		w1.executeForm(*f1);
		f1->execute(w1);

		delete f1;

		f1 = i1.makeForm("shrubbery creation", "s1");

		f1->beSigned(b10);
		w1.executeForm(*f1);
		f1->execute(w1);

		delete f1;

		f1 = i1.makeForm("wrong form", "test");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}