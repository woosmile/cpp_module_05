#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	b1;
	Bureaucrat	b2("woosekim", 1);
	Bureaucrat	copy(b2);

	std::cout << b1;
	std::cout << b2;
	std::cout << copy;

	b1.DecGrade();
	b2.IncGrade();
	copy.IncGrade();

	std::cout << b1;
	std::cout << b2;
	std::cout << copy;

	b1.IncGrade();
	b2.DecGrade();
	copy.DecGrade();

	std::cout << b1;
	std::cout << b2;
	std::cout << copy;

	copy = b1;

	std::cout << copy;

	return (0);
}