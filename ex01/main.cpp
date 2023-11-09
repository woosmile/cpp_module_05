#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	b1("woosekim", 1);
	Bureaucrat	b2("b2", 11);
	Form		f1("f1", 10, 10);
	Form		f2("f2", 20, 20);
	Form		copy(f1);

	std::cout << b1;
	std::cout << b2;
	std::cout << f1;
	std::cout << f2;
	std::cout << copy;

	f1.BeSigned(b2);
	std::cout << f1;
	f2.BeSigned(b2);
	std::cout << f2;
	f1.BeSigned(b1);
	std::cout << f1;
	copy.BeSigned(b1);
	std::cout << copy;

	copy = f2;
	std::cout << copy;

	return (0);
}