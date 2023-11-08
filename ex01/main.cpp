#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	_default;
	Bureaucrat	e1("woosekim", 1);
	Bureaucrat	copy(e1);

	_default.DecGrade();

	std::cout << _default;
	std::cout << e1;
	std::cout << copy;

	e1.IncGrade();
	copy.IncGrade();

	return (0);
}